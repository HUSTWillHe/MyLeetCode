#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def slipList(self, height: List[int]) -> List[List[int]]:
        idx = []
        ans = []
        if height[0] > height[1]:
            idx.append(0)
        for i in range(1,len(height)-1):
            if height[i] > height[i - 1] and height[i] > height[i + 1]:
                idx.append(i)
        if height[-1] > height[-2]:
            idx.append(len(height)-1)
        for i in range(len(idx) - 1):
            ans.append(height[idx[i]:idx[i+1]+1])
        print("sliped result: ")
        for i in ans:
            print(i)
        return ans

    def trap(self, height: List[int]) -> int:
        if len(height) <= 2:
            return 0
        ans = 0
        slip = self.slipList(height)
        for i in slip:
            smaller = i[0] if i[0] < i[-1] else i[-1]
            sum = 0
            for k in i[1:-1]:
                if smaller > k:
                    sum += smaller - k
            ans += sum
        return ans

def main():
    s = Solution()
    # height = [0,1,0,2,1,0,1,3,2,1,2,1]
    height = [5, 4, 1, 2]

    result = s.trap(height)
    print("result is:")
    print(result)
    return

if __name__ == "__main__":
    main()

