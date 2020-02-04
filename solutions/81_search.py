#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List
import math
import sys


class Solution:
    def search(self, nums, target):
        if len(nums) == 0:
            return False
        if nums[0] == target or nums[-1] == target:
            return True
        begin = 0
        end = len(nums)
        if nums[-1] > nums[0]:
            print("increase type: ")
            return self.recursion(nums, target, 0, end)
        if nums[0] == nums[-1]:
            for i in range(1, end):
                if nums[i] != nums[0]:
                    begin = i - 1
                    break
            for i in range(end - 2, -1, -1):
                if nums[i] != nums[-1]:
                    end = i + 2
                    break
            if end - begin < 1:
                return False
            print("new begin: " + str(begin))
            print("new end: " + str(end))
        if target < nums[0] and target > nums[-1]:
            return False
        if target > nums[0]:
            print("search left: ")
            return self.recursion_left(nums, target, begin, end)
        if target < nums[-1]:
            print("search right: ")
            return self.recursion_right(nums, target, begin, end)

    def recursion_left(self, nums, target, begin, end) -> bool:
        print("current begin: " + str(begin))
        print("current end: " + str(end))
        if end - begin <= 1:
            if nums[begin] == target:
                return True
            return False
        mid = math.floor((end + begin) / 2)
        print("current mid: " + str(mid))
        if nums[mid] == target:
            return True
        if nums[mid] < target:
            if nums[mid] <= nums[-1]:
                return self.recursion_left(nums, target, begin, mid)
            else:
                return self.recursion_left(nums, target, mid, end)
        else:
            return self.recursion_left(nums, target, begin, mid)

    def recursion_right(self, nums, target, begin, end) -> bool:
        if end - begin <= 1:
            if nums[begin] == target:
                return True
            return False
        mid = math.floor((end + begin) / 2)
        print("current begin: " + str(begin))
        print("current end: " + str(end))
        print("current mid: " + str(mid))
        if nums[mid] == target:
            return True
        if nums[mid] < target:
            return self.recursion_right(nums, target, mid, end)
        else:
            if nums[mid] >= nums[0]:
                return self.recursion_right(nums, target, mid, end)
            else:
                return self.recursion_right(nums, target, begin, mid)

    def recursion(self, nums, target, begin, end) -> bool:
        if end - begin <= 1:
            return False
        mid = math.floor((begin + end) / 2)
        if nums[mid] == target:
            return True
        if nums[mid] > target:
            return self.recursion(nums, target, begin, mid)
        else:
            return self.recursion(nums, target, mid, end)


def main():
    s = Solution()
    a = [2, 2, 2, 0, 1]
    b = sys.argv[1]
    ans = s.search(a, int(b))
    print(ans)
    return


if __name__ == "__main__":
    main()
