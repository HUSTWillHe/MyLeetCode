#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort(reverse=True)
        head_sum = 0
        nums_sum = sum(nums)
        for idx, n in enumerate(nums):
            head_sum += n
            if head_sum > nums_sum/2:
                return nums[0: idx + 1]


def main():
    s = Solution()
    ans = s.minSubsequence([4, 3, 10, 9, 8])
    print(ans)
    return


if __name__ == "__main__":
    main()
