import time
from functools import wraps

def show_process_time(method):
    """(5 pts) Method decorator

    Show the processing time of the decorated method
    """
    @wraps(method)
    def wrapper(self, *args, **kwargs):
        start = time.time()
        method(self, *args, **kwargs)
        end = time.time()
        ellapse_time = end - start
        print(f"ellapsed time: {ellapse_time} s")

    return wrapper


class Sudoku:
    """Sudoku solver

    A sudoku is represented by a 9x9 matrix. Each element
    in the matrix is an integer value from 1 to 9.

    For example:

            columns
                                      +-----+    +-----+   +-----+
       9,5,7,6,1,3,2,8,4              |9,5,7|    |6,1,3|   |2,8,4|
       4,8,3,2,5,7,1,9,6              |4,8,3|    |2,5,7|   |1,9,6|
    r  6,1,2,8,4,9,5,3,7              |6,1,2|    |8,4,9|   |5,3,7|
    o  1,7,8,3,6,4,9,5,2   ------->   +-----+    +-----+   +-----+
    w  5,2,4,9,7,1,3,6,8   ------->   block0     block1    block2
    s  3,6,9,5,2,8,7,4,1
       8,4,5,7,9,2,6,1,3              +-----+    +-----+   +-----+
       2,9,1,4,3,6,8,7,5              |1,7,8|    |3,6,4|   |9,5,2|
       7,3,6,1,8,5,4,2,9              |5,2,4|    |9,7,1|   |3,6,8|
                                      |3,6,9|    |5,2,8|   |7,4,1|
                                      +-----+    +-----+   +-----+
                                      block3     block4    block5

                                      +-----+    +-----+   +-----+
                                      |8,4,5|    |7,9,2|   |6,1,3|
                                      |2,9,1|    |4,3,6|   |8,7,5|
                                      |7,3,6|    |1,8,5|   |4,2,9|
                                      +-----+    +-----+   +-----+
                                      block6     block7    block8

    A finished sudoku must satisfy following requirements:
        1. Each row consists of a sequence of numbers from 1 to 9
            ,and each digit can only occur once
        2. Each col consists of a sequence of numbers from 1 to 9
            ,and each digit can only occur once
        3. Each block consists of a sequence of numbers from 1 to 9
            ,and each digit can only occur once

    Argument:
        fname (str): sudoku file name
    """
    def __init__(self, fname):
        """(5 pt) Construct the sudoku 2D matrix from file named as 'fname'"""
        with open(f'sudoku/{fname}', 'r') as sudoku_file:
            self.sudoku = [[int(col) for col in row.split(',')] for row in sudoku_file.read().split('\n')[:9]]

    def __str__(self):
        """(5 pt) Return printable string representing current sudoku 2D matrix

        For example:

            9 5 7 6 1 3 2 8 4
            4 8 3 2 5 7 1 9 6
            6 1 2 8 4 9 5 3 7
            1 7 8 3 6 4 9 5 2
            5 2 4 9 7 1 3 6 8
            3 6 9 5 2 8 7 4 1
            8 4 5 7 9 2 6 1 3
            2 9 1 4 3 6 8 7 5
            7 3 6 1 8 5 4 2 9
        """
        result = ""
        for row in self.sudoku:
            for col in row:
                result += f"{col} "
            result += "\n"
        return result

    def check_block(self, block_idx):
        """(10 pt) Return True if the block with index 'block_idx' is valid

        Note:
            Refer the docstring of the Sudoku class. `block_idx` is an integer from 0 to 8.
            valid means no repeated numbers in the block except 0
        """
        vis = [False] * 9
        row_init = block_idx // 3 * 3
        col_init = block_idx % 3 * 3
        for i in range(row_init, row_init + 3):
            for j in range(col_init, col_init + 3):
                val = self.sudoku[i][j] - 1
                if val == -1:
                    continue
                if not vis[val]:
                    vis[val] = True
                else:
                    return False
        return True

    def check_row(self, row_idx):
        """(5 pt) Return True if the row with index 'row_idx' is valid

        Note:
            Refer the docstring of the Sudoku class. `row_idx` is an integer from 0 to 8.
            valid means no repeated numbers in the row except 0
        """
        vis = [False] * 9
        for j in range(9):
            val = self.sudoku[row_idx][j] - 1
            if val == -1:
                continue
            if not vis[val]:
                vis[val] = True
            else:
                return False
        return True

    def check_col(self, col_idx):
        """(5 pt) Return True if the col with index 'col_idx' is valid

        Note:
            Refer the docstring of the Sudoku class. `col_idx` is an integer from 0 to 8.
            valid means no repeated numbers in the col except 0
        """
        vis = [False] * 9
        for i in range(9):
            val = self.sudoku[i][col_idx] - 1
            if val == -1:
                continue
            if not vis[val]:
                vis[val] = True
            else:
                return False
        return True

    def is_solved(self):
        """(5 pt) Return True if the sudoku is solved

        Note:
            A solve sudoku must satisfy following requirements:
                1. Each row consists of a sequence of numbers from 1 to 9
                    ,and each digit can only occur once
                2. Each col consists of a sequence of numbers from 1 to 9
                    ,and each digit can only occur once
                3. Each block consists of a sequence of numbers from 1 to 9
                    ,and each digit can only occur once
        """
        vis_row = [[False] * 9 for _ in range(9)]
        vis_col = [[False] * 9 for _ in range(9)]
        vis_block = [[False] * 9 for _ in range(9)]
        for i in range(9):
            for j in range(9):
                val = self.sudoku[i][j] - 1
                block = i // 3 * 3 + j // 3
                if val < 0 or vis_row[i][val] or vis_col[j][val] or vis_block[block][val]:
                    return False
                vis_row[i][val] = True
                vis_col[j][val] = True
                vis_block[block][val] = True
        return True

    # Uncomment the line below when you finish the decorator show_process_time
    @show_process_time
    def solve(self):
        """(60 pt) Solve the sudoku puzzle automatically

        Note:
            You can define others functions inside this method to help you solve the puzzle
        """
        blank = []
        for i in range(9):
            for j in range(9):
                if self.sudoku[i][j] == 0:
                    blank.append((i, j))
        N = len(blank)

        def dfs(s):
            i, j = blank[s]
            block = i // 3 * 3 + j // 3
            for v in range(1, 10):
                self.sudoku[i][j] = v
                if (not self.check_row(i)) or (not self.check_col(j)) or (not self.check_block(block)):
                    continue
                if s == N - 1:
                    return True
                if dfs(s + 1):
                    return True
            self.sudoku[i][j] = 0

        if N > 0:
            dfs(0)
        print(self)

# check
# sudoku = Sudoku("sudoku3.txt")
# print(sudoku.is_solved())
# print(sudoku.is_solved())
# print(sudoku.check_block(0))
# print(sudoku.check_block(3))
# print(sudoku.check_block(6))

# sudoku.solve()
# print(sudoku.is_solved())
