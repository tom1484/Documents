from cv2 import imdecode, resize
from cv2 import INTER_CUBIC

from numpy import zeros, array, empty
from numpy import sum, fromfile
from numpy import uint8

from utils.omr import OMR

from os import walk, path

from math import ceil


# ==================================================================================================

def generate_positions(fmt):
    C_DIS = fmt.W / (fmt.COL - 1) if fmt.COL > 1 else 0
    R_DIS = fmt.H / (fmt.ROW - 1) if fmt.ROW > 1 else 0
    CONT_DIS = fmt.LEN / (fmt.N - 1) if fmt.N > 1 else 0

    positions = zeros((fmt.ROW * fmt.COL, fmt.N, 2), dtype=int)

    for i in range(fmt.ROW):
        y = fmt.SY + i * R_DIS
        for j in range(fmt.COL):
            sx = fmt.SX + j * C_DIS
            idx = j * fmt.ROW + i
            for k in range(fmt.N):
                x = sx + k * CONT_DIS
                positions[idx][k][0] = x
                positions[idx][k][1] = y

    return positions


# ==================================================================================================

# convert OMR judge result to symbol 
def convert_omr_result_to_symbol(fmt, result):
    symbols = [""] * fmt.TOT

    for (i, comb) in enumerate(result):
        if i >= fmt.TOT:
            break
        for (j, v) in enumerate(comb):
            if v == 1:
                symbols[i] += fmt.DICT[j]

    return array(symbols)


# ==================================================================================================

# convert OMR judge result to binary 
def convert_omr_result_to_binary(fmt, result):
    binaries = empty((fmt.TOT, fmt.N), dtype=int)

    for (i, comb) in enumerate(result):
        if i >= fmt.TOT:
            break
        for (j, v) in enumerate(comb):
            binaries[i][j] = 1 if v == 1 else 0

    return binaries


# ==================================================================================================

def detect_id(fmt, omr):
    positions = generate_positions(fmt)

    # get id
    res = omr.judge(fmt, positions)
    # convert res
    symbols = convert_omr_result_to_symbol(fmt, res)

    student_id = ""
    for c in symbols:
        student_id += c

    return student_id


# ==================================================================================================

def detect_answer(fmt, omr, judger):
    positions = generate_positions(fmt)

    # get answers and scores
    res = omr.judge(fmt, positions)
    # convert res
    symbols = convert_omr_result_to_symbol(fmt, res)
    # calculate scores and grade
    binaries = convert_omr_result_to_binary(fmt, res)
    scores = judger.judge(binaries)
    # calculate grade
    grade = sum(scores)

    return symbols, scores, grade


def read_sheets(sheet_dir, fmts, judger, progress_updater, processed_num_updater):
    # paths = []
    # available = ['png', 'PNG', 'jpg', 'jpeg']
    #
    # for (_, _, filenames) in walk(sheet_dir):
    #
    #     for (i, fn) in enumerate(filenames):
    #         suffix = fn.split('.')[-1]
    #         if suffix in available:
    #             paths.append((sheet_dir, fn))
    #
    #     break

    paths = []

    for (_, _, filenames) in walk(sheet_dir):
        for (i, fn) in enumerate(filenames):
            paths.append((sheet_dir, fn))
        break

    # ==================================================================================================

    results = []
    failures = []
    count = 0

    for sheet_dir, fn in paths:

        # process counting
        count += 1

        progress = ceil(count / len(paths) * 100)
        progress_updater(progress)

        processed_num_updater(count)

        sheet_name = path.join(sheet_dir, fn)
        print(sheet_name)

        infile = open(sheet_name, 'r')
        np_file = fromfile(infile, dtype=uint8)
        infile.close()

        sheet = imdecode(np_file, -1)
        sheet = resize(sheet, (1166, 1654), interpolation=INTER_CUBIC)

        # build omr and recognize contours
        omr = OMR(fmts['answer_format'], sheet)

        # ==================================================================================================

        result = {}

        student_id = detect_id(fmts['id_format'], omr)
        result['id'] = student_id
        # print(student_id)

        symbols, scores, grade = detect_answer(fmts['answer_format'], omr, judger)
        result['symbols'] = symbols
        result['scores'] = scores
        result['grade'] = grade

        # ==================================================================================================

        results.append(result)

        break

    return results, failures
