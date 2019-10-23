#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    def find_next(self, cur_idx: int, nums: List[int]) -> int:
        if cur_idx + nums[cur_idx] >= len(nums) - 1:
            return -1
        max = cur_idx + nums[cur_idx]
        next_idx = cur_idx + nums[cur_idx]
        for i in range(cur_idx + 1, cur_idx + nums[cur_idx] + 1, 1):
            if i + nums[i] > max:
                max = i + nums[i]
                next_idx = i
        return next_idx

    def jump(self, nums: List[int]) -> int:
        size = len(nums)
        if size == 0 or size == 1:
            return 0
        cur_idx = 0
        cnt = 0
        while True:
            cnt += 1
            cur_idx = self.find_next(cur_idx, nums)
            if cur_idx == -1:
                return cnt


def main():
    s = Solution()
    nums = [2, 3, 1, 1, 4]
    n = s.jump(nums)
    print("answer is: ", n)
    return


if __name__ == "__main__":
    main()
