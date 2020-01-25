#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    def assemblePath(self, arr) -> str:
        if len(arr) == 0:
            return "/"
        s = ""
        for a in arr:
            s += "/"
            s += a
        return s

    def simplifyPath(self, path: str) -> str:
        arr = path.split('/')
        new_arr = []
        for i, s in enumerate(arr):
            if i == 0:
                if not len(s) == 0:
                    return '/'
            else:
                if len(s) == 0:
                    continue
                else:
                    if s == "..":
                        if(len(new_arr) == 0):
                            continue
                        new_arr.pop()
                    elif s == ".":
                        continue
                    else:
                        new_arr.append(s)
        return self.assemblePath(new_arr)


def main():
    s = Solution()
    ans = s.simplifyPath("/bin/env/bash/..//")
    print(ans)
    return


if __name__ == "__main__":
    main()
