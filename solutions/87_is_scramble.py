#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        size = len(s1)
        if size == 1:
            return s1 == s2
        dp = {}
        for i in range(size):
            for k in range(size):
                if s1[i] == s2[k]:
                    dp[(i, i + 1, k)] = True
                else:
                    dp[(i, i + 1, k)] = False
        for l in range(2, size + 1):
            for i in range(0, size - l + 1):
                for k in range(0, size - l + 1):
                    dp[(i, i + l, k)] = False
                    for sub in range(1, l):
                        left = dp[(i, i + sub, k)] and dp[(i + sub, i + l, k + sub)]
                        right = dp[(i, i + sub, k + l - sub)] and dp[(i + sub, i + l, k)]
                        if left or right:
                            dp[(i, i + l, k)] = True
                            break
        print(dp)
        return dp[(0, size, 0)]


def main():
    s = Solution()
    a = "aa"
    b = "ab"
    ans = s.isScramble(a, b)
    print("%s and %s: ans: %s" %(a, b, ans))
    return


if __name__ == "__main__":
    main()
