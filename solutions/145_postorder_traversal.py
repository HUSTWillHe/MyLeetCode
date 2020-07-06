#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def traversalRecursively(self, root: TreeNode, ans: List[int]) -> None:
        if root is None:
            return
        self.traversalRecursively(root.left, ans)
        self.traversalRecursively(root.right, ans)
        ans.append(root.val)

    def postorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        self.traversalRecursively(root, ans)
        return ans


def main():
    s = Solution()
    tns = [TreeNode(i) for i in range(3)]
    tns[0].left = tns[1]
    tns[0].right = tns[2]
    ans = s.postorderTraversal(tns[0])
    print(ans)
    return


if __name__ == "__main__":
    main()
