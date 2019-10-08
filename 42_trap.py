#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def slipList(self, height: List[int]) -> List[List[int]]:
        idx = []
        ans = []
        for i in range(len(height)):
            if i > 0 or i < len(height)-1:
                if height[i] > height[i - 1] and height[i] > height[i + 1]:
                    idx.append(i)
        for i in range(len(idx) - 1):
            ans.append(height[idx[i]:idx[i+1]+1])
        return ans

    def trap(self, height: List[int]) -> int:
        return 0

def main():
    s = Solution()
    height = [0,1,0,2,1,0,1,3,2,1,2,1]
    ans = s.slipList(height)
    print("slip list result: ")
    for i in ans:
        print(i)
    return

if __name__ == "__main__":
    main()
