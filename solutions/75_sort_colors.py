#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        p0 = -1
        p1 = -1
        p2 = -1
        for i in nums:
            if i == 0:
                p0 += 1
                p1 += 1
                p2 += 1
                nums[p0] = 0
                if p1 != p0:
                    nums[p1] = 1
                if p2 != p1:
                    nums[p2] = 2
            if i == 1:
                p1 += 1
                p2 += 1
                nums[p1] = 1
                if p2 != p1:
                    nums[p2] = 2
            if i == 2:
                p2 += 1


def main():
    s = Solution()
    l = [0, 0, 0, 1, 1, 2, 0, 2, 1]
    s.sortColors(l)
    print(l)
    return


if __name__ == "__main__":
    main()
