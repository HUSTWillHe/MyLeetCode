#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    ans = []

    def one_step(self, ori: set, dst: List[int]):
        print("new circle=================")
        print("ori: ", ori)
        print("dst: ", dst)
        if len(ori) == 0:
            self.ans.append(dst)
        inner_ori = set(ori)
        inner_dst = list(dst)
        for i in ori:
            inner_dst.append(i)
            inner_ori.remove(i)
            self.one_step(inner_ori, inner_dst)

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
