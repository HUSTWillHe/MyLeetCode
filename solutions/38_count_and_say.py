#!/usr/bin/python3
# -*- coding: UTF-8 -*-

class Solution:
    def countAndSay(self, n: int) -> str:
        ans = '1'
        for i in range(n-1):
            ans = self.oneCycle(ans)
        return ans

    def oneCycle(self, s:str) -> str:
        cnt = 1
        size = len(s)
        pre = s[0]
        ans = ''
        if size == 1:
            ans += '1'
            ans += s[0]

        for i in range(1, size):
            if pre != s[i]:
                ans += str(cnt)
                ans += pre
                pre = s[i]
                cnt = 1
            else:
                cnt+=1
            if i == size - 1:
                ans+=str(cnt)
                ans+=pre
        return ans



def main():
    s = Solution()
    for i in range(1, 5):
        ans = s.countAndSay(i)
        print(ans)
    return

if __name__ == "__main__":
    main()
