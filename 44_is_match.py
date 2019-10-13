#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def allStar(self, s) -> bool:
        for i in s:
            if i != "*":
                return False
        return True

    def countQuestion(self, s:str)->List[int]:
        head = tail = 0
        for i in s:
            if i == "?":
                head += 1
            else:
                break;
        for i in range(len(s)-1, -1, -1):
            if s[i] == "?":
                tail += 1
            else:
                break;
        return [head, tail]

    def compare(self, s:str, sub:str) -> bool:
        for i in range(len(sub)):
            if sub[i] == "?" or sub[i] == s[i]:
                continue
            else:
                return False
        return True

    def nearestIdx(self, s:str, sub:str) -> int:
        '''
        if ans equals -1 means no result found
        '''
        if len(s) < len(sub):
            return -1
        ans = -1
        head, tail = self.countQuestion(sub)
        print("head %d, tail %d" %(head, tail))
        if head == len(sub):
            return 0
        new_s = s[head:-tail]
        new_sub = sub[head:-tail]
        for i in range(len(new_s)):
            if new_s[i] == new_sub[0]:
                if self.compare(new_s[i:], new_sub):
                    ans = i
                    break
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
        head = p[:p.find("*")]
        tail = p[p.rfind("*"):]
        if s.find(head) != 0:
            return False
        if s.rfind(tail) ==-1 or s.rfind(tail) + len(tail) != len(s):
            return False
        mid_s = s[len(head), -len(tail)]
        mid_p = p[len(head), -len(tail)]
        split_p = mid_p.split("*")
        last = mid_s
        for sub_p in split_p:
            cur_idx = self.nearestIdx(last, sub_p)
            if cur_idx == -1:
                return False
            else:
                last = last[cur_idx + len(sub_p):]
        return True

def main():
    s = Solution()
    sub = "????????"
    full = "abcdefg"
    i = s.nearestIdx(full, sub)
    print("the ans is: %d" %i)
    return

if __name__ == "__main__":
    main()
