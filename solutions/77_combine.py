#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        if n <= 0 or k <= 0 or k > n:
            return []
        ans = []
        self.__combine(n, k, 1, [], ans)
        return ans

    def __combine(self, n: int, k: int, start: int, temp: List[int], ans: List[List[int]]):
        temp.append(start)
        if len(temp) == k:
            ans.append(temp[:])
            return

        for i in range(start, n + 1):
            self.__combine(n, k, i + 1, temp, ans)
            temp.pop()


def main():
    s = Solution()
    ans = s.combine(6, 5)
    print("answer: ")
    print(ans)
    return


if __name__ == "__main__":
    main()
