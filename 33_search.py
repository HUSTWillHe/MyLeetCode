#!/usr/bin/python3
# -*- coding: utf-8 -*-
from typing import List

class Solution:
    def normal_search(self, nums:List[int], left:int, right:int, target:int)->int:
        mid = (int)((left + right)/2)
        if right - left == 1:
            return -1
        if nums[mid] == target :
            return mid
        elif nums[mid] < target:
            return self.normal_search(nums, mid, right, target)
        elif nums[mid] > target:
            return self.normal_search(nums, left, mid, target)

    def left_search(self, nums:List[int], left:int, right:int, target:int) ->int:
        mid = (int)((left + right)/2);
        print("mid index is: %2d, mid valued is: %2d" %(mid, nums[mid]))
        if right - left == 1:
            return -1
        if nums[mid] == target:
            return mid
        elif nums[mid] < nums[-1] or nums[mid] > target:
            print("target between left and mid")
            return self.left_search(nums, left, mid, target)
        elif nums[mid] > nums[0] and nums[mid] < target:
            print("target between mid and right")
            return self.left_search(nums, mid, right, target)

    def right_search(self, nums:List[int], left:int, right:int, target:int) ->int:
        mid = (int)((right + left)/2)
        print("mid index is: %2d, mid valued is: %2d" %(mid, nums[mid]))
        if right - left == 1:
            return -1
        if nums[mid]==target:
            return mid
        elif nums[mid] > nums[0] or nums[mid] < target:
            print("target between mid and right")
            return self.right_search(nums, mid, right, target)
        elif nums[mid] > target and nums[mid] < nums[-1]:
            print("target between left and mid")
            return self.right_search(nums, left, mid, target)

    def search(self, nums: List[int], target:int)->int:
        if(len(nums) == 0):
            return -1
        if(len(nums)==1):
            if(nums[0] == target):
                return 0
            else:
                return -1
        if target == nums[0]:
            return 0
        if target == nums[-1]:
            return len(nums)-1
        if nums[0] < nums[-1]:
            return self.normal_search(nums, 0, len(nums)-1, target)
        if target > nums[0]:
            print("target is in the left part.")
            return self.left_search(nums, 0, len(nums)-1, target)
        elif target < nums[-1]:
            print("target is in the right part.")
            return self.right_search(nums, 0, len(nums)-1, target)
        else:
            return -1

def main():
    nums = [1, 2, 3, 5]
    s = Solution()
    i = s.search(nums, 3)
    print("the search result is: %d" %i)

if __name__ =="__main__":
    main();
