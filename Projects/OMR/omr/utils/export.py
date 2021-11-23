from xlsxwriter import Workbook


# ==================================================================================================

# write a series of data in one row
def write_row(ws, start, end, row, arr, fmt):
    for i in range(start, end):
        ws.write(row, i, arr[i - start], fmt)


# ==================================================================================================

# convert index to column string
def get_range_char(n):
    res = ""
    n += 1

    while n > 0:
        n, remainder = divmod(n - 1, 26)
        res = chr(65 + remainder) + res

    return res


# ==================================================================================================

# convert index to range string
def get_range_str(start, end):
    sr, sc = start
    er, ec = end

    sr, sc = sr + 1, sc
    er, ec = er + 1, ec

    res = get_range_char(sc) + str(sr) + ":"
    res += get_range_char(ec) + str(er)

    return res


# ==================================================================================================

def export(start, end, results, failures, output_path):
    # clear file
    f = open(output_path, "w")
    f.close()

    # create file
    wb = Workbook(output_path)
    ws = wb.add_worksheet()

    ws.freeze_panes(1, 3)

    # ==================================================================================================

    colHeaderFormat = wb.add_format({'align': 'center',
                                     'valign': 'vcenter',
                                     'bg_color': '#FFDDDD'})

    rowHeaderFormat = wb.add_format({'align': 'center',
                                     'valign': 'vcenter',
                                     'bg_color': '#D7E4BC',
                                     'top': 1})

    normCellFormat1 = wb.add_format({'align': 'center',
                                     'valign': 'vcenter',
                                     'top': 1})

    normCellFormat2 = wb.add_format({'align': 'center',
                                     'valign': 'vcenter'})

    emptyCellFormat = wb.add_format({'align': 'center',
                                     'valign': 'vcenter',
                                     'bg_color': '#F2AD92',
                                     'top': 1})

    # ==================================================================================================

    # write numbers of answers
    length = end - start

    write_row(ws, 3, length + 3, 0, [i + 1 for i in range(start, end)], colHeaderFormat)
    write_row(ws, 0, 3, 0, ['編號', '學號', '分數'], rowHeaderFormat)

    # ==================================================================================================

    for i, result in enumerate(results):
        r1 = i * 2 + 1
        r2 = i * 2 + 2

        # ==================================================================================================

        # write row number in merged cell
        ws.merge_range(get_range_str((r1, 0), (r2, 0)), i + 1, rowHeaderFormat)
        # write id in merged cell
        ws.merge_range(get_range_str((r1, 1), (r2, 1)), result['id'], rowHeaderFormat)
        # write grade in merged cell
        ws.merge_range(get_range_str((r1, 2), (r2, 2)), result['grade'], rowHeaderFormat)

        # ==================================================================================================

        # write symbols
        for j in range(start, end):
            v = result['symbols'][j]
            if v == "":
                ws.write(r1, j - start + 3, v, emptyCellFormat)
            else:
                ws.write(r1, j - start + 3, v, normCellFormat1)
        # write scores
        for j in range(start, end):
            v = result['scores'][j]
            if v == "":
                ws.write(r2, j - start + 3, v, emptyCellFormat)
            else:
                ws.write(r2, j - start + 3, v, normCellFormat2)

    # ==================================================================================================

    rf = len(results) * 2 + 1

    ws.merge_range(get_range_str((rf, 0), (rf, 2)), "讀取失敗", emptyCellFormat)

    for i, fn in enumerate(failures):
        r = rf + i + 1
        ws.merge_range(get_range_str((r, 0), (r, 2)), fn, emptyCellFormat)

    wb.close()
