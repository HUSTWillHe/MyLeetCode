#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def firstMissingPositive(self, nums:List[int]) -> int:
        size = len(nums)
        ans = 1
        status = [False for i in range(size)]
        for i in nums:
            if( i <= 0 or i > size):
                continue
            else:
                status[i- 1] = True

        for i in status:
            if i == True:
                ans += 1
            if i == False:
                return ans
        return ans



def main():
    s = Solution()
    nums = [7, 8, -1, 9]
    ans = s.firstMissingPositive(nums)
    print("answer is: %d" %ans)
    return

if __name__ == "__main__":
    main()
