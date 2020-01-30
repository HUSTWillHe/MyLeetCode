#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List
from typing import Dict


class Solution:
    def move_right(self, s: str, miss: str, right_idx: int, dict_s) -> int:
        for i in range(right_idx + 1, len(s)):
            if s[i] in dict_s.keys():
                dict_s[s[i]] += 1
                if s[i] == miss:
                    return i
        return -1

    def move_left(self, s: str, left_idx: int, dict_s, dict_t) -> (int, str):
        for i in range(left_idx, len(s)):
            if s[i] in dict_s.keys():
                dict_s[s[i]] -= 1
                if dict_s[s[i]] < dict_t[s[i]]:
                    return (i + 1, s[i])

    def minWindow(self, s: str, t: str) -> str:
        len_s = len(s)
        len_t = len(t)
        if len_s == 0 or len_t == 0:
            return ""
        dict_t = {}
        for a in t:
            if a not in dict_t.keys():
                dict_t[a] = 1
            else:
                dict_t[a] += 1
        dict_s = {i: 0 for i in dict_t.keys()}
        tl = [i for i in t]
        left_idx = 0
        right_idx = 0
        miss = ""
        print("tl")
        print(tl)
        for i, a in enumerate(s):
            if a in tl:
                tl.remove(a)
            if a in t:
                dict_s[a] += 1
            if len(tl) == 0:
                right_idx = i
                break
        if len(tl) != 0:
            return ""
        print("dict_t")
        print(dict_t)
        print("first right idx: " + str(right_idx))
        print(dict_s)
        left_idx, miss = self.move_left(s, 0, dict_s, dict_t)
        print("first left idx: " + str(left_idx))
        print("first miss: " + miss)
        min_begin = left_idx - 1
        min_length = right_idx - min_begin + 1

        print("=============================")
        while right_idx != len_s - 1:
            right_idx = self.move_right(s, miss, right_idx, dict_s)
            print("right_idx: " + str(right_idx))
            print(dict_s)
            if right_idx == -1:
                break
            left_idx, miss = self.move_left(s, left_idx, dict_s, dict_t)
            print("left_idx: " + str(left_idx))
            print("miss: " + miss)
            print(dict_s)
            length = right_idx - left_idx + 2
            if length < min_length:
                min_length = length
                min_begin = left_idx - 1
        return s[min_begin: min_begin + min_length]


def main():
    solution = Solution()
    s = "bba"
    t = "ab"
    ans = solution.minWindow(s, t)
    print(ans)
    return


if __name__ == "__main__":
    main()
