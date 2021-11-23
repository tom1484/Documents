from cv2 import minAreaRect, boxPoints, contourArea


class Contour(object):

    def __init__(self, contour):
        self.contour = contour

        rect = minAreaRect(contour)
        self.boxPoints = boxPoints(rect)

        (x, y), (w, h), deg = rect
        if abs(deg) > 85:
            w, h = h, w
            deg += 90

        self.x = x
        self.y = y
        self.w = w
        self.h = h
        self.deg = deg

        self.area = contourArea(contour)
        self.rectArea = w * h
