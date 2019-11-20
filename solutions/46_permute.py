#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    size = 0

    def one_step(self, nums: List[int], sub_ans: List[int], ans: List[List[int]]):
        if len(sub_ans) == self.size:
            ans.append(sub_ans[:])
        for i in nums:
            if i not in sub_ans:
                sub_ans.append(i)
                self.one_step(nums, sub_ans, ans)
                sub_ans.pop()

    def permute(self, nums: List[int]) -> List[List[int]]:
        self.size = len(nums)
        ans = []
        self.one_step(nums, [], ans)
        return ans


def main():
    s = Solution()
    n = [1, 2, 3]
    l = s.permute(n)
    for i in l:
        print(i)

    return


if __name__ == "__main__":
    main()
