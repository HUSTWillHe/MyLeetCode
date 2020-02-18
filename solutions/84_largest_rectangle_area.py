#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List
from typing import Tuple


def print_stack(stack: List[Tuple[int, int]]) -> None:
    print("---------stack info-------------")
    for a in stack:
        print(a[0], end="\t")
        print(a[1])


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        size = len(heights)
        if size == 0:
            return 0
        stack = [(-1, 0)]
        largest_area = 0
        for i, h in enumerate(heights):
            print_stack(stack)
            if stack[-1][1] > h:
                while stack[-1][1] > h:
                    area = stack[-1][1] * (i - stack[-2][0] - 1)
                    if area > largest_area:
                        print("new largest accur: %d" % area)
                        print("i: %d" % i)
                        print("stack[-1][1]: height: %d" % stack[-1][1])
                        print("stack[-1][0]: idx: %d" % stack[-1][0])
                        print("stack[-2][0]: last idx: %d" % stack[-2][0])
                        largest_area = area
                    stack.pop()
            stack.append((i, h))
        print("=============round over==============")
        while len(stack) > 1:
            print_stack(stack)
            area = stack[-1][1] * (size - stack[-2][0] - 1)
            if area > largest_area:
                print("new largest accur: ")
                print("stack[-1][1]: height: %d" % stack[-1][1])
                print("stack[-1][0]: idx: %d" % stack[-1][0])
                print("stack[-2][0]: last idx: %d" % stack[-2][0])
                largest_area = area
            stack.pop()
        return largest_area


def main():
    s = Solution()
    heights = [2, 1, 5, 6, 2, 3]
    ans = s.largestRectangleArea(heights)
    print(ans)
    return


if __name__ == "__main__":
    main()
