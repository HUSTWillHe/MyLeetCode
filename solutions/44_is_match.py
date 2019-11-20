#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def allStar(self, s) -> bool:
        if s == "":
            return False
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
        if len(sub) > len(s):
            return False
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
        if head == len(sub):
            return 0
        if tail == 0:
            new_s = s[head:]
            new_sub = sub[head:]
        else:
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
        if self.allStar(p):
            return True
        if p == "" and s == "":
            return True
        if p == "" and s != "":
            return False
        if s == "" and p != "":
            return False
        if p.find("*") == -1:
            if len(s) != len(p):
                return False
            for i in range(len(p)):
                if p[i] == "?" or s[i] == p[i]:
                    continue
                else:
                    return False
            return True
        head = p[:p.find("*")]
        tail = p[p.rfind("*")+1:]
        if len(head) + len(tail) > len(s):
            return False
        for i in range(len(head)):
            if head[i] == "?" or head[i] == s[i]:
                continue
            else:
                return False
        for i in range(len(tail)):
            if tail[i] == "?" or tail[i] == s[i-len(tail)]:
                continue
            else:
                return False
        if len(tail) == 0:
            mid_s = s[len(head):]
            mid_p = p[len(head):]
        else:
            mid_s = s[len(head): -len(tail)]
            mid_p = p[len(head): -len(tail)]
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
    full = "aa"
    sub = "aa"
    i = s.isMatch(full, sub)
    print("the ans is:")
    print(i)
    return

if __name__ == "__main__":
    main()
