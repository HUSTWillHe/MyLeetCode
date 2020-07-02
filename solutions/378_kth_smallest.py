#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List
import heapq


class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        height = len(matrix)
        if height == 0:
            return 0
        width = len(matrix[0])
        if width == 0:
            return 0
        x_idx = set({0})
        y_idx = set({0})
        pnt_vals = [PntVal(Point(0, 0), matrix[0][0])]
        for i in range(k - 1):
            cur_pnt_val = heapq.heappop(pnt_vals)
            cur_x = cur_pnt_val.pnt.x
            cur_y = cur_pnt_val.pnt.y
            x_idx.remove(cur_x)
            y_idx.remove(cur_y)
            for x, y in ((cur_x + 1, cur_y), (cur_x, cur_y + 1)):
                if x not in x_idx and y not in y_idx and x < height and y < width:
                    pnt_val = PntVal(Point(x, y), matrix[x][y])
                    heapq.heappush(pnt_vals, pnt_val)
                    x_idx.add(pnt_val.pnt.x)
                    y_idx.add(pnt_val.pnt.y)
        return heapq.heappop(pnt_vals).val


class Point:
    def __init__(self, xx=0, yy=0):
        self.x = xx
        self.y = yy


class PntVal:
    def __init__(self, point, value):
        self.pnt = Point(point.x, point.y)
        self.val = value

    def __lt__(self, other):
        if self.val < other.val:
            return True
        else:
            return False


def main():
    s = Solution()
    matrix = [[1, 5, 9], [10, 11, 13], [12, 13, 15]]
    for k in range(1, 10):
        ans = s.kthSmallest(matrix, k)
        print("%d : %d" % (k, ans))
    return


if __name__ == "__main__":
    main()
