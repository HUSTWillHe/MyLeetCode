#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        if len(t) > len(s):
            return 0
        if len(t) == 0:
            return 1
        if len(s) == 0:
            return 0
        note = [1 for i in range(len(s))]
        new_note = [0 for i in range(len(s))]
        first_row = [0 for i in range(len(t))]
        if s[0] == t[0]:
            first_row[0] = 1
        for i in range(len(t)):
            new_note[0] = first_row[i]
            for k in range(1, len(s)):
                if t[i] == s[k]:
                    new_note[k] = note[k - 1] + new_note[k - 1]
                else:
                    new_note[k] = new_note[k - 1]
            note = new_note[:]
            print("-----------------------")
            print("i: " + str(i))
            print(new_note)
        return new_note[-1]


def main():
    s = Solution()
    ss = "babgbag"
    t = "bag"
    ans = s.numDistinct(ss, t)
    print("ans: " + str(ans))
    return


if __name__ == "__main__":
    main()
