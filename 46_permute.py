#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    ans = []

    def one_step(self, ori: set, dst: List[int]) -> None:
        if len(ori) == 0:
            self.ans.append(dst)
            return
        for i in ori:
            dst.append(i)
            ori.remove(i)
            self.one_step(ori, dst)

    def premute(self, nums: List[int]) -> List[List[int]]:
        dst = []
        self.one_step(nums, dst)
        return self.ans


def main():
    s = Solution()
    n = [1, 2, 3]
    l = s.premute(n)
    for i in l:
        print(i)
    return


if __name__ == "__main__":
    main()
