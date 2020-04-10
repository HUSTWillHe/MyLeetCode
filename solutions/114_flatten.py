#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def printTreeRight(root: TreeNode):
    if root is None:
        return
    print(root.val)
    printTreeRight(root.right)


class Solution:
    def core(self, root: TreeNode) -> TreeNode:
        print("root: " + str(root.val))
        if root.left is None and root.right is None:
            print("left none right none")
            return root
        if root.right is None:  # 没有挡住
            print("right none")
            root.right = root.left
            root.left = None
            return self.core(root.right)
        if root.left is None:
            print("left none")
            return self.core(root.right)
        temp = root.right
        root.right = root.left
        root.left = None
        left_tail = self.core(root.right)
        print("root is : " + str(root.val))
        print("left tail is: " + str(left_tail.val))
        print("temp is : " + str(temp.val))
        left_tail.right = temp
        left_tail.left = None
        return self.core(temp)

    def flatten(self, root: TreeNode) -> None:
        if root is None:
            return None
        self.core(root)
        return root


def main():
    s = Solution()
    l = [1, 2, 5, 3, 4, 6]
    tree = [TreeNode(i) for i in l]
    tree[0].left = tree[1]
    tree[0].right = tree[2]
    tree[1].left = tree[3]
    tree[1].right = tree[4]
    tree[2].right = tree[5]
    s.flatten(tree[0])
    print("after")
    printTreeRight(tree[0])
    return


if __name__ == "__main__":
    main()
