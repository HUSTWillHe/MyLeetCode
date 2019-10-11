#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def allStar(self, s) ->bool:
        for i in s:
            if i != "*":
                return False
        return True

    def simpleFind(self, s:str, sub:str) -> List[int]:
        ans = []
        last = s
        while len(last) < len(sub):
            idx = last.find(sub)
            if idx == -1:
                return ans
            else:
                ans.append(idx)
                last = s[idx+1:]
        return ans

    def findIdx(self, s:str, sub:str) -> List[int]:
        ans = []
        if s.find("?") == -1:
            return self.simpleFind(s,sub)
        while s.find("?") != -1:


    def isMatch(self, s, p):
        if p == "" and s == "":
            return True
        if p == "" and s != "":
            return False
        if s == "" and p != "":
            if self.allStar(p):
                return True
            return False



def main():
    s = Solution()
    return

if __name__ == "__main__":
    main()
