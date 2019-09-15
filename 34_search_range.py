#! /usr/bin/python3

from typing import List

class Solution:
    def search(self, nums:List[int], left:int, right:int, target:int)->int:
        if right - left == 1:
            return -1
        mid = (int)((right + left)/2)
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            return self.search(nums, mid, right, target)
        elif nums[mid] > target:
            return self.search(nums, left, mid, target)

    def left_idx(self, nums:List[int], left:int, right:int, target:int):
        if right - left == 1:
            if nums[right] == target and nums[left] < target:
                return right
        mid = (int)((right + left)/2)
        if nums[mid] == target and nums[mid - 1] < target:
            return mid
        if nums[mid] < target:
            return self.left_idx(nums, mid, right, target)
        elif nums[mid] == target and nums[mid -1] == target:
            return self.left_idx(nums, left, mid, target)

    def right_idx(self, nums:List[int], left:int, right:int, target:int):
        if right - left == 1:
            if nums[right] > target and nums[left] == target:
                return left
        mid = (int)((right + left)/2)
        if nums[mid]==target and nums[mid + 1]>target:
            return mid
        elif nums[mid] > target:
            return self.right_idx(nums, left, mid, target)
        elif nums[mid] == target and nums[mid+1] == target:
            return self.right_idx(nums, mid, right, target)

    def searchRange(self, nums:List[int], target:int)->List[int]:
        if len(nums) == 0:
            return [-1, -1]
        if nums[0] > target or nums[-1] < target:
            return [-1, -1]
        if len(nums) == 1:
            if nums[0] == target:
                return [0,0]
            else:
                return [-1, -1]
        if nums[0] == target and nums[-1] == target:
            return [0, len(nums)-1]
        if nums[0] == target:
            right = self.right_idx(nums, 0, len(nums)-1, target)
            return [0, right]
        if nums[-1] == target:
            left = self.left_idx(nums, 0, len(nums)-1, target)
            return [left, len(nums)-1]
        else:
            middle = self.search(nums, 0, len(nums)-1, target)
            if middle == -1:
                return [-1,-1]
            left = self.left_idx(nums, 0, middle, target)
            right = self.right_idx(nums, middle, len(nums)-1, target)
            return [left, right]

def main():
    l = [1,2,2,2,2,2,2,4,4,4,4,4,6,6,7,7]
    s = Solution()
    ll = s.searchRange(l, 6)
    for i in ll:
        print(i)

if __name__ == "__main__":
    main()
