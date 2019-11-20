#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    def getIndexs(self, size: int) -> List[List[int]]:
        ans = []
        self.recursive(size, [], ans)
        for i in ans:
            print(i)
        return ans

    def recursive(self, size: int, sub_ans: List[int], ans: List[List[int]]):
        if len(sub_ans) == size:
            ans.append(list(sub_ans))
        for i in range(size):
            if i not in sub_ans:
                sub_ans.append(i)
                self.recursive(size, sub_ans, ans)
                sub_ans.pop()

    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        pre_ans = self.getIndexs(len(nums))
        ans = []
        for i in pre_ans:
            cur = [nums[k] for k in i]
            if cur not in ans:
                ans.append(cur)
        return ans


def main():
    s = Solution()
    a = [1, 2, 2]
    b = s.permuteUnique(a)
    for i in b:
        print(i)
    return


if __name__ == "__main__":
    main()
