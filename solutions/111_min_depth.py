#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def recursive(self, root: TreeNode) -> int:
        if root.left is None and root.right is None:
            return 1
        if root.left is None:
            return self.recursive(root.right) + 1
        if root.right is None:
            return self.recursive(root.left) + 1
        l_dep = self.recursive(root.left)
        r_dep = self.recursive(root.right)
        return l_dep + 1 if l_dep < r_dep else r_dep + 1

    def minDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        return self.recursive(root)


def main():
    s = Solution()
    ltn = [TreeNode(i) for i in range(4)]
    ltn[0].left = ltn[1]
    ltn[1].left = ltn[2]
    ltn[0].right = ltn[3]
    ans = s.minDepth(ltn[0])
    print("ans is: " + str(ans))
    return


if __name__ == "__main__":
    main()
