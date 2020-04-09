#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class TreeNode:
    def __init__(self, x: int):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def seek(self, root: TreeNode, sum: int):
        self.cur.append(root.val)
        if root.left is None and root.right is None:
            if root.val == sum:
                self.paths.append(self.cur[:])
        if root.left is not None:
            self.seek(root.left, sum - root.val)
        if root.right is not None:
            self.seek(root.right, sum - root.val)
        self.cur.pop()

    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if root is None:
            return []
        self.paths = []
        self.cur = []
        self.seek(root, sum)
        return self.paths


def main():
    s = Solution()
    l = [5, 4, 8, 11, 13, 4, 7, 2, 5, 1]
    tree = [TreeNode(i) for i in l]
    tree[0].left = tree[1]
    tree[0].right = tree[2]
    tree[1].left = tree[3]
    tree[2].left = tree[4]
    tree[2].right = tree[5]
    tree[3].left = tree[6]
    tree[3].right = tree[7]
    tree[5].left = tree[8]
    tree[5].right = tree[9]
    ls = s.pathSum(tree[0], 22)
    print("answer:  ")
    for a in ls:
        for b in a:
            print(b, end='\t')
        print('\n')
    return


if __name__ == "__main__":
    main()
