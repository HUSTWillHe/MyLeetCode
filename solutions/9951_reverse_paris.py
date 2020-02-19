#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    def recursive(self, nums: List[int], beg: int, end: int) -> int:
        ans = 0
        print("---------recursive-------------")
        print("ans: %d" % ans)
        print("begin: %d" % beg)
        print("end: %d" % end)
        print(nums[beg: end])
        if end - beg <= 1:
            return ans
        small = beg
        large = beg
        for i in range(beg + 1, end):
            if nums[i] >= nums[beg]:
                large += 1
            else:
                small += 1
                large += 1
                tmp = nums[small]
                nums[small] = nums[large]
                nums[large] = tmp
        ans += small - beg + 1
        tmp = nums[beg]
        nums[beg] = nums[small]
        nums[small] = tmp
        print("ans: %d" % ans)
        print("small: %d" % small)
        left = self.recursive(nums, beg, small)
        right = self.recursive(nums, small + 1, end)
        ans = ans + left + right
        return ans

    def reversePairs(self, nums: List[int]) -> int:
        size = len(nums)
        if size == 0:
            return 0
        ans = self.recursive(nums, 0, size)
        print("========after all===========")
        print(nums)
        return ans


def main():
    s = Solution()
    nums = [7, 5, 6, 4]
    ans = s.reversePairs(nums)
    print("ans: %d" % ans)
    return


if __name__ == "__main__":
    main()
