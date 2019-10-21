#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        size = len(nums)
        if size == 0 or size == 1:
            return 0
        cur_idx = 0
        cnt = 0
        while True:
            print("circle:{0}==================================".format(cnt))
            print("current indxe: ", cur_idx)
            max = cur_idx + nums[cur_idx]
            next_idx = cur_idx + nums[cur_idx]
            for i in range(nums[cur_idx]):
                if cur_idx + i >= size:
                    break
                if i + nums[cur_idx + i] > max:
                    max = i + nums[cur_idx + i]
                    next_idx = cur_idx + i
            cur_idx = next_idx
            if max >= size:
                break;
            cnt += 1
        return cnt


def main():
    s = Solution()
    nums = [2, 3, 1, 1, 4]
    n=s.jump(nums)
    print("answer is: ", n)
    return

if __name__ == "__main__":
    main()
