#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    def isPalindrome(self, s: str) -> bool:
        if s is None:
            return True
        size = len(s)
        left, right = 0, size - 1
        while left < right:
            print("left: " + str(left))
            print("right: " + str(right))
            while left < size and (not(s[left].isalpha() or s[left].isdigit())):
                left += 1
            while right >= 0 and (not(s[right].isalpha() or s[right].isdigit())):
                right -= 1
            if left >= right:
                return True
            print("--------------------")
            print("left: " + s[left])
            print("right: " + s[right])
            if not s[right].lower() == s[left].lower():
                return False
            left += 1
            right -= 1
        return True


def main():
    s = Solution()
    ss = ".,"
    ans = s.isPalindrome(ss)
    print(ss + " ans is: " + str(ans))
    return


if __name__ == "__main__":
    main()
