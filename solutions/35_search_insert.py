#! /usr/bin/python3
# -*- coding: utf-8 -*-

from typing import List

class Solution:
    def search(self, nums:List[int], left:int, right:int, target:int):
        if right - left == 1:
            nums.insert(right, target)
            return right
        mid = (int)((right + left)/2)
        if nums[mid] == target:
            return mid
        if nums[mid] < target:
            return self.search(nums, mid, right, target)
        if nums[mid] > target:
            return self.search(nums, left, mid, target)

    def searchInsert(self, nums:List[int], target:int)->int:
        if len(nums) == 0:
            nums.insert(0, target)
            return 0
        if target == nums[0]:
            return 0
        if target == nums[-1]:
            return len(nums) - 1
        if target < nums[0]:
            nums.insert(0, target)
            return 0
        if target > nums[-1]:
            nums.insert(len(nums), target)
            return len(nums)-1
        index = self.search(nums, 0, len(nums) - 1, target)
        return index
def main():
    a=[1,3,5,6]
    s = Solution()
    i = s.searchInsert(a, 7)
    print(i)
    print(a)

if __name__ == "__main__":
    main()
