#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def __init__(self):
        self.sum = 0

    def getSum(self, root: TreeNode, current: int):
        if root.left is None and root.right is None:
            self.sum += current + root.val
        if root.left is not None:
            self.getSum(root.left, (current + root.val) * 10)
        if root.right is not None:
            self.getSum(root.right, (current + root.val) * 10)

    def sumNumbers(self, root: TreeNode) -> int:
        if root is None:
            return 0
        self.getSum(root, 0)
        return self.sum


def main():
    s = Solution()
    tree_list = [TreeNode(i) for i in [1, 2, 3]]
    tree_list[0].left = tree_list[1]
    tree_list[0].right = tree_list[2]
    ans = s.sumNumbers(tree_list[0])
    print(ans)
    return


if __name__ == "__main__":
    main()
