#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        if n <= 0 or k <= 0 or n < k:
            return [[]]
        d = dict()
        d[(1, 1)] = [[1]]
        for i in range(2, n + 1):
            d[(i, 1)] = d[(i - 1, 1)] + [[i]]
        if k == 1:
            return d[(n, 1)]

        for i in range(2, k + 1):
            d[(i, i)] = [d[(i - 1, i - 1)][0] + [i]]
        if k == n:
            return d[(n, k)]

        for i in range(2, k + 1):
            for j in range(i + 1, n + 1):
                d[(j, i)] = d[(j - 1, i)][:]
                for m in d[(j - 1, i - 1)]:
                    new_ele = [m + [j]]
                    d[(j, i)] += new_ele
                print("d[(%d, %d)]" % (j, i))
                print(d[(j, i)])
        return d[(n, k)]


def main():
    s = Solution()
    ans = s.combine(6, 5)
    print("answer: ")
    print(ans)
    return


if __name__ == "__main__":
    main()
