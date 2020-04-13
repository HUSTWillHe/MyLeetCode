#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if len(triangle) == 0:
            return 0
        for i in range(1, len(triangle)):
            print("---------------------")
            print("round :  " + str(i))
            print(triangle[i])
            for k in range(i + 1):
                if k == 0:
                    triangle[i][0] += triangle[i - 1][0]
                elif k == i:
                    triangle[i][i] += triangle[i - 1][i - 1]
                else:
                    triangle[i][k] += triangle[i - 1][k - 1] if triangle[i - 1][k - 1] < triangle[i - 1][k] else triangle[i - 1][k]
            print(triangle[i])
        return min(triangle[-1])


def main():
    s = Solution()
    l = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]
    print(l)
    ans = s.minimumTotal(l)
    print(l)
    print(ans)
    return


if __name__ == "__main__":
    main()
