#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        self.__subsets(nums, 0, len(nums), [], ans)
        return ans

    def __subsets(self, nums: List[int], start: int, length: int, temp: List[int], ans: List[List[int]]):
        ans.append(temp[:])
        for i in range(start, length):
            temp.append(nums[i])
            self.__subsets(nums, i + 1, length, temp, ans)
            temp.pop()


def main():
    s = Solution()
    l = [1, 2, 3, 4]
    ans = s.subsets(l)
    print(ans)
    return


if __name__ == "__main__":
    main()
