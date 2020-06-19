#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    def longestConsecutive(self, num: List[int]) -> int:
        if not num:
            return 0
        num_first = {}
        for n in num:
            if n + 1 in num_first:
                num_first[n + 1] = False
            if n - 1 in num_first:
                num_first[n] = False
            else:
                num_first[n] = True
        max_cnt = 1
        for n, is_first in num_first.items():
            if is_first:
                current_num = n + 1
                while current_num in num_first:
                    current_num += 1
                if current_num - n > max_cnt:
                    max_cnt = current_num - n
        return max_cnt


def main():
    s = Solution()
    ans = s.longestConsecutive([100, 4, 200, 1, 3, 2])
    print(ans)
    return


if __name__ == "__main__":
    main()
