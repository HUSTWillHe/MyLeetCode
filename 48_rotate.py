#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List
import math

class Solution:
    def rotate(self, matrix:List[List[int]]) -> None:
        for i in matrix:
            print(i)
        size = len(matrix)
        mid = float(size - 1) / 2
        pnts = []
        for i in range(math.ceil(mid),size,1):
            for k in range(math.ceil(mid), size, 1):
                if i - mid >= 0 and k - mid > 0:
                    pnts.append([i, k])
        print("pnts length: ", len(pnts))
        for pnt in pnts:
            x, y = pnt
            trans_x, trans_y = x - mid, y - mid
            temp = matrix[int(mid - trans_y)][int(mid + trans_x)]
            matrix[int(mid - trans_y)][int(mid + trans_x)] = matrix[int(mid - trans_x)][int(mid - trans_y)]
            matrix[int(mid - trans_x)][int(mid - trans_y)] = matrix[int(mid + trans_y)][int(mid - trans_x)]
            matrix[int(mid + trans_y)][int(mid - trans_x)] = matrix[int(mid + trans_x)][int(mid + trans_y)]
            matrix[int(mid + trans_x)][int(mid + trans_y)] = temp
        for i in matrix:
            print(i)

def main():
    s = Solution()
    m = [[1,2,3],[4,5,6],[7,8,9]]
    s.rotate(m)
    return

if __name__ == "__main__":
    main()
