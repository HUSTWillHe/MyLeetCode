#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows <= 0:
            return []
        if numRows == 1:
            return [[1]]
        ans = [[1]]
        for i in range(1, numRows):
            cur = []
            for k in range(i + 1):
                if k == 0 or k == i:
                    cur.append(1)
                else:
                    cur.append(ans[i - 1][k - 1] + ans[i - 1][k])
            ans.append(cur)
        return ans


def main():
    s = Solution()
    ans = s.generate(5)
    print(ans)
    return


if __name__ == "__main__":
    main()
