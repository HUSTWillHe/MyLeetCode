#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def allStar(self, s) -> bool:
        for i in s:
            if i != "*":
                return False
        return True

    def countQuestion(self, s:str) -> List[int]:
        size = len(s)
        if size == 0:
            return [0, 0]
        head = tail = 0
        for i in range(size):
            if s[i] == '?':
                head += 1
            else:
                break;
        for i in range(size - 1, -1, -1):
            if s[i] == '?':
                tail += 1
            else:
                break
        return [head, tail]

    def indexAllQuesion(self, s:str)->List[int]:
        ans = []
        for i in range(len(s)):
            if s[i] == "?":
                ans.append(i)
        return ans

    def nearestIdx(self, s:str, sub:str) -> int:
        head, tail = self.countQuestion(sub)
        new_s = s[head:-tail]
        idx_q = self.indexAllQuesion(new_s)

        return 0

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
    l = s.indexAllQuesion(a)
    for i in l:
        print(i)
    return

if __name__ == "__main__":
    main()
