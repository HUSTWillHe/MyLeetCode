#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) <= 2:
            return 0
        size = len(height)
        ans = 0
        left = 0
        right = size -1
        l_max = height[0]
        r_max = height[-1]
        while left < right:
            l_max = l_max if l_max > height[left] else height[left]
            r_max = r_max if r_max > height[right] else height[right]
            if l_max < r_max:
                ans += l_max - height[left]
                left+=1
            else:
                ans += r_max - height[right]
                right-=1
        return ans

def main():
    s = Solution()
    height = [0,1,0,2,1,0,1,3,2,1,2,1]
    # height = [5, 4, 1, 2]

    result = s.trap(height)
    print("result is:")
    print(result)
    return

if __name__ == "__main__":
    main()

