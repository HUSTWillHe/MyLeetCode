#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List
import math


class Solution:
    def recursive(self, begin: int, end: int, result: int) -> int:
        if(end - begin <= 1):
            return begin
        mid = math.floor((begin + end) / 2)
        if mid*mid == result:
            return mid
        elif mid*mid < result:
            return self.recursive(mid, end, result)
        else:
            return self.recursive(begin, mid, result)

    def mySqrt(self, x: int) -> int:
        if x < 0:
            return -1
        if x == 0:
            return 0
        if x <= 3:
            return 1
        if x == 4 or x == 5:
            return 2
        end = math.floor(x / 2)
        return self.recursive(1, end, x)


def main():
    s = Solution()
    s.mySqrt(5)
    return


if __name__ == "__main__":
    main()
