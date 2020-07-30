#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    def __init__(self):
        self.point_num = {}  # dict[int, dict[int, int]]
        self.line_record = {}  # dict[float, dict[float, set{list[int]}]]
        self.vertical_record = {}  # dict[int, [int]]

    def cntPoints(self, points: List[List[int]]):
        for point in points:
            if point[0] in self.point_num:
                if point[1] in self.point_num[point[0]]:
                    self.point_num[point[0]][point[1]] += 1
                else:
                    self.point_num[point[0]][point[1]] = 1
            else:
                self.point_num[point[0]] = {point[1]: 1}

    def getSlope(self, a: List[int], b: List[int]):
        if a[0] == b[0]:
            if a[0] in self.vertical_record:
                self.vertical_record[a[0]].add(a[1])
                self.vertical_record[a[0]].add(b[1])
            else:
                self.vertical_record[a[0]] = set([a[1], b[1]])
            return
        slope = (b[1] - a[1])/(b[0] - a[0])
        height = (a[1] * b[0] - a[0] * b[1])/(b[0] - a[0])
        if slope in self.line_record:
            if height in self.line_record[slope]:
                self.line_record[slope][height].add(tuple(a))
                self.line_record[slope][height].add(tuple(b))
            else:
                self.line_record[slope] = {height: set([tuple(a), tuple(b)])}
        else:
            self.line_record[slope] = {height: set([tuple(a), tuple(b)])}

    def maxPoints(self, points: List[List[int]]) -> int:
        if len(points) <= 2:
            return len(points)
        self.cntPoints(points)
        for i in range(len(points)):
            for k in range(i + 1, len(points)):
                self.getSlope(points[i], points[k])
        max = 2
        for x, ys in self.vertical_record.items():
            sum = 0
            for y in ys:
                sum += self.point_num[x][y]
            if sum > max:
                max = sum
        for slope, height_points_set in self.line_record.items():
            for height, points_set in height_points_set.items():
                sum = 0
                for point in points_set:
                    sum += self.point_num[point[0]][point[1]]
                if sum > max:
                    max = sum
        return max


def main():
    s = Solution()
    ans = s.maxPoints([[0, 0], [1, 1], [2, 2]])
    print("ans is: " + str(ans))
    return


if __name__ == "__main__":
    main()
