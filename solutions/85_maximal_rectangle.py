#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


def printMat(mat: List[List[int]]) -> None:
    for i in range(len(mat)):
        for k in range(len(mat[0])):
            print(mat[i][k], end="\t")
        print("\n")


class Solution:
    def largest_area(self, height: List[int]) -> int:
        size = len(height)
        stack = [(-1, 0)]
        largest_area = 0
        for i, h in enumerate(height):
            while h < stack[-1][1]:
                area = stack[-1][1] * (i - stack[-2][0] - 1)
                if area > largest_area:
                    largest_area = area
                stack.pop()
            stack.append((i, h))
        while len(stack) > 1:
            area = stack[-1][1] * (size - stack[-2][0] - 1)
            if area > largest_area:
                largest_area = area
            stack.pop()
        return largest_area

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        height = len(matrix)
        if height == 0:
            return 0
        width = len(matrix[0])
        if width == 0:
            return 0
        line = [0 for x in range(width)]
        mat = [line[:] for x in range(height)]
        print("mat.height: %d" % len(mat))
        print("mat.width: %d" % len(mat[0]))
        for i in range(width):
            k = 0
            while k < height and matrix[k][i] == "1":
                k += 1
            mat[0][i] = k
        for i in range(1, height):
            for k in range(width):
                if mat[i - 1][k] > 0:
                    mat[i][k] = mat[i - 1][k] - 1
                else:
                    if matrix[i][k] == "0":
                        mat[i][k] = 0
                    else:
                        ii = i
                        while ii < height and matrix[ii][k] == "1":
                            ii += 1
                        mat[i][k] = ii - i
        print("***********ALL PREPARE****************")
        printMat(mat)

        largest_area = 0
        for i in range(height):
            area = self.largest_area(mat[i])
            print("line %d, area: %d" % (i, area))
            if area > largest_area:
                largest_area = area

        return largest_area


def main():
    s = Solution()
    mat = [["1", "0", "1", "0", "0"], ["1", "0", "1", "1", "1"], ["1", "1", "1", "1", "1"], ["1", "0", "0", "1", "0"]]
    ans = s.maxmalRectangle(mat)
    print("answer: %d" % ans)
    return


if __name__ == "__main__":
    main()
