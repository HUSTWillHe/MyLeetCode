#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def allStar(self, s) -> bool:
        for i in s:
            if i != "*":
                return False
        return True

    def compare(self, s:str, sub:str) -> bool:
        for i in range(len(sub)):
            if sub[i] == "?" or sub[i] == str[i]:
                continue
            else:
                return False 
        return True

    def nearestIdx(self, s:str, sub:str) -> int:
        ans = -1
        head, tail = self.countQuestion(sub)
        new_s = s[head:-tail]
        for i in range(len(new_s)):
            if i == sub[0]:
                if self.compare(new_s[i:], sub):
                    ans = head + i
        return ans

    def isMatch(self, s, p):
        '''
        process star singly, process ? and normal characters in one method.
        '''
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
    a = "hqpgh???hgap8hg??"
    i = s.nearestIdx()
    return

if __name__ == "__main__":
    main()
