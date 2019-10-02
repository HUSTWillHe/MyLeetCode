#!/usr/bin/python3
# -*- coding: UTF-8 -*-

import queue
from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target:int) -> List[List[int]]:
        if len(candidates)== 0:
            return []
        candidates.sort()
        ans = []
        q = queue.Queue()
        for c in candidates:
            if c > target:
                continue
            elif c == target:
                ans.append([target])
            else:
                q.put([c,c])
                print(c)

        while not q.empty():
            size = q.qsize()
            for i in range(size):
                l = q.get()
                for k in candidates:
                    if k < l[-1]:
                        continue
                    if l[0] + k > target:
                        continue
                    else:
                        new_l = [i for i in l]
                        new_l[0] = l[0] + k
                        new_l.append(k)
                        if new_l[0] == target:
                            ans.append(new_l[1:])
                        if new_l[0] < target:
                            q.put(new_l)
        return ans


def main():
    s = Solution()
    ans = s.combinationSum([1], 2)
    print("the answer is:\n")
    for l in ans:
        print(l)
    return

if __name__ == "__main__":
    main()
