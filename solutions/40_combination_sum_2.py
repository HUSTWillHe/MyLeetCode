#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List
from queue import Queue

class Solution:
    def delRep(self, origin:List[List[int]]) -> List[List[int]]:
        ans = []
        for i in origin:
            if i not in ans:
                ans.append(i)
        return ans

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        if len(candidates) == 0:
            return []
        candidates.sort()
        q = Queue()
        ans = []
        l = len(candidates)
        for i in range(l):
            if candidates[i] < target:
                q.put([candidates[i],i])
            elif candidates[i] == target:
                ans.append([candidates[i]])
            else:
                break
        while not q.empty():
            size = q.qsize()
            print("new cycle--------------")
            print("size %d" %size)
            for k in range(size):
                current = q.get()
                print("current is:")
                print(current)
                for i in range(l):
                    if i <= current[-1]:
                        continue
                    if current[0] + candidates[i] > target:
                        break
                    elif current[0] + candidates[i] == target:
                        new_l = [candidates[i] for i in current[1:]]
                        new_l.append(candidates[i])
                        ans.append(new_l)
                        print("ans has append:")
                        print(new_l)
                    else:
                        new_l = [i for i in current]
                        new_l.append(i)
                        new_l[0] += candidates[i]
                        q.put(new_l)
                        print("add to new queue:")
                        print(new_l)
        ans = self.delRep(ans)
        return ans


def main():
    s = Solution()
    l = [10, 1, 2, 7, 6, 1, 5]
    ans = s.combinationSum2(l, 8)
    for i in ans:
        print(i)
    return

if __name__ == "__main__":
    main()
