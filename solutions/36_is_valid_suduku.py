#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def printSudoku(self, board:List[List[str]]):
        for a in range(9):
            for b in range(9):
                print(board[a][b],end="")
                print('\t',end="")
                if b % 3 == 2:
                    print('\t',end="")
            print('\n',end="")
            if a % 3 == 2:
                print('\n',end="")

    def isValidSudoku(self, board:List[List[str]])->bool:
        row = [[False]*9 for i in range(9)]
        col = [[False]*9 for i in range(9)]
        square = [[False]*9 for i in range(9)]

        for i in range(9):
            for k in range(9):
                if board[i][k] != '.':
                    n = int(board[i][k]) - 1
                    print("current i: %d, current k: %d, current n: %d" %(i, k, n))
                    if row[i][n] == True:
                        print("row false")
                        return False
                    else:
                        row[i][n] = True
                    if col[k][n] == True:
                        print("col false")
                        return False
                    else:
                        col[k][n] = True
                    if square[int(k/3) * 3 + int(i/3)][n] == True:
                        print("square false")
                        return False
                    else:
                        square[int(k/3) * 3 + int(i/3)][n] = True
        return True

def main():
    board = [[".",".",".",".","5",".",".","1","."],[".","4",".","3",".",".",".",".","."],[".",".",".",".",".","3",".",".","1"],["8",".",".",".",".",".",".","2","."],[".",".","2",".","7",".",".",".","."],[".","1","5",".",".",".",".",".","."],[".",".",".",".",".","2",".",".","."],[".","2",".","9",".",".",".",".","."],[".",".","4",".",".",".",".",".","."]]
    s = Solution()
    s.printSudoku(board)
    b = s.isValidSudoku(board)
    print(b)

if __name__ == "__main__":
    main()
