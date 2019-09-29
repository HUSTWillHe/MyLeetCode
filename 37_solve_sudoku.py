#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from collections import defaultdict

class Solution:
    def solveSudoku(self, board):
        def could_place(d, row, col):
            return not(d in rows[row] or d in columns[col] or \
                       d in boxes[box_index(row, col)])

        def replace_number(d,row,col):
            rows[row][d] += 1
            columns[col][d] += 1
            boxes[box_index(row, col)][d] += 1
            board[row][col] = str(d)

        def remove_number(d, row, col):
            del rows[row][d]
            del columns[col][d]
            del boxes[box_index(row, col)][d]
            board[row][col]='.'

        def place_next_numbers(row, col):
            if col == N-1 and row == N-1:
                nonlocal sudoku_solved
                sudoku_solved = True
            else:
                if col == N -1:
                    backtrace(row+1,0)
                else:
                    backtrace(row, col+1)

        def bactrace(row = 0, col = 0):
            if board[row][col] == '.'
            for d in range(1, 10)
def main():
    return

if __name__ == "__main__":
    main()
