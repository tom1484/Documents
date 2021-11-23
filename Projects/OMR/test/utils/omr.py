from cv2 import cvtColor, threshold, GaussianBlur
from cv2 import COLOR_BGR2GRAY

from cv2 import findContours, drawContours, circle, imwrite

from cv2 import THRESH_BINARY
from cv2 import RETR_TREE, CHAIN_APPROX_TC89_L1

from cv2 import warpAffine, getRotationMatrix2D

from numpy import array, zeros
from numpy import sum
from numpy import float32

import math

from utils.contour import Contour


class OMR(object):

    def __init__(self, fmt, sheet):
        # define bubble shape
        self.WR = int(fmt.BW / 2)
        self.HR = int(fmt.BH / 2)

        # ==================================================================================================

        self.sheet = sheet

        # convert BGR to GRAY
        self.sheet = cvtColor(self.sheet, COLOR_BGR2GRAY)

        # apply threshold
        self.threshold()

        # remove small stains
        self.recognize_contour()
        self.remove_stains()

        # apply gaussian blur and re-recognize contours
        self.sheet = GaussianBlur(self.sheet, (3, 3), 0)
        self.recognize_contour()

        # correct sheet
        self.locate()

    def threshold(self):
        thres = 210

        self.sheet[self.sheet < thres] = 0
        self.sheet[self.sheet >= thres] = 255
        self.sheet = 255 - self.sheet

    def recognize_contour(self, ):
        # get contours
        self.contours, _ = findContours(self.sheet, RETR_TREE, CHAIN_APPROX_TC89_L1)

        results = []
        for c in self.contours:
            results.append(Contour(c))

        self.contours = array(results)

    def remove_stains(self):
        for c in self.contours:
            if c.area < 30:
                drawContours(self.sheet, [c.contour], -1, 0, -1)

    def find_corr_cross(self):
        shape_ratio = 1
        area_ratio = 3 / 7
        deg = 45

        max_shape_ratio_err = 0.1
        max_area_ratio_err = 0.2
        max_deg_err = 0.2

        # ==================================================================================================

        for c in self.contours:
            if c.x > 500 and c.y > 1500:
                if c.rectArea > 500:
                    shape_ratio_err = abs(shape_ratio - c.w / c.h) / shape_ratio
                    area_ratio_err = abs(area_ratio - c.area / c.rectArea) / area_ratio
                    deg_err = abs(deg - abs(c.deg)) / deg

                    if shape_ratio_err < max_shape_ratio_err and \
                            area_ratio_err < max_area_ratio_err and \
                            deg_err < max_deg_err:
                        return c

    def find_corr_anchors(self):
        shape_ratio = 2.3
        area_ratio = 1

        max_shape_ratio_err = 0.2
        max_area_ratio_err = 0.2

        # ==================================================================================================

        res = []

        for c in self.contours:
            if c.x > 1100:
                if c.rectArea > 400:
                    shape_ratio_err = abs(shape_ratio - c.w / c.h) / shape_ratio
                    area_ratio_err = abs(area_ratio - c.area / c.rectArea) / area_ratio

                    if shape_ratio_err < max_shape_ratio_err and \
                            area_ratio_err < max_area_ratio_err:
                        res.append(c)

        return res

    def find_corr_horizontal_bar(self):
        for c in self.contours:
            if c.w > 850:
                return c

    def get_delta_pos(self, tar_x, tar_y):
        cross = self.find_corr_cross()
        x, y = cross.x, cross.y

        dx = tar_x - x
        dy = tar_y - y

        return dx, dy

    def get_degree(self):
        anchors = self.find_corr_anchors()

        anchors.sort(reverse=False, key=lambda c: c.y)

        x1, y1 = anchors[0].x, anchors[0].y
        x2, y2 = anchors[-1].x, anchors[-1].y

        tan = -(x2 - x1) / (y2 - y1)
        rad = math.atan(tan)
        deg = math.degrees(rad)

        return deg

    def translate_image(self, x, y):
        translate = array([[1, 0, x], [0, 1, y]], dtype=float32)
        self.sheet = warpAffine(self.sheet, translate, (self.sheet.shape[1], self.sheet.shape[0]))

    def rotate_image(self, x, y, deg):
        rotate = getRotationMatrix2D((x, y), deg, 1.0)
        self.sheet = warpAffine(self.sheet, rotate, (self.sheet.shape[1], self.sheet.shape[0]))

    def locate(self):
        tar_x = 600
        tar_y = 1600

        # ==================================================================================================

        # translate
        dx, dy = self.get_delta_pos(tar_x, tar_y)
        # rotate
        deg = self.get_degree()

        self.translate_image(dx, dy)
        self.rotate_image(tar_x, tar_y, deg)

    def count_bits(self, image, position):
        mx, my = position[0], position[1]

        sx, sy = mx - self.WR, my - self.HR
        ex, ey = mx + self.WR, my + self.HR

        cropped = image[sy:ey, sx:ex] > 0
        count = sum(cropped)

        return count

    def judge(self, fmt, positions):
        # calculate results
        thresh = threshold(self.sheet, 220, 255, THRESH_BINARY)[1]

        results = zeros((fmt.TOT, fmt.N))

        for i in range(fmt.TOT):
            for p in range(fmt.N):
                if self.count_bits(thresh, positions[i][p]) > fmt.THRES:
                    results[i][p] = 1

        for row in positions:
            for pos in row:
                circle(self.sheet, tuple(pos), 4, 255)

        imwrite("res.png", self.sheet)

        return results

