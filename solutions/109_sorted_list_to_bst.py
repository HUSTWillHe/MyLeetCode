#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List
import math


class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def printTreeInorder(root: TreeNode):
    if root is None:
        print("current root: none")
        return
    printTreeInorder(root.left)
    print("current root: " + str(root.val))
    printTreeInorder(root.right)


def printTreePreorder(root: TreeNode):
    if root is None:
        print("current root: none")
        return
    print("current root: " + str(root.val))
    printTreePreorder(root.left)
    printTreePreorder(root.right)


class Solution:
    def getLen(self, head: ListNode) -> int:
        cur = head  # 这里会不会导致head指向变化
        cnt = 0
        while cur is not None:
            cur = cur.next
            cnt += 1
        return cnt

    def genTree(self, size: int) -> TreeNode:
        if size <= 0:
            return None
        tn = TreeNode(0)
        tn.left = self.genTree(math.ceil((size - 1)/2))
        tn.right = self.genTree((size - 1)//2)
        return tn

    def putValue(self, root: TreeNode):
        if root is None:
            return
        self.putValue(root.left)
        root.val = self.cur.val
        self.cur = self.cur.next
        self.putValue(root.right)

    def sortedListToBST(self, head: ListNode) -> TreeNode:
        size = self.getLen(head)
        root = self.genTree(size)
        self.cur = head
        self.putValue(root)
        return root


def main():
    s = Solution()
    lln = [ListNode(i) for i in range(8)]
    for i in range(len(lln) - 1):
        lln[i].next = lln[i + 1]
    root = s.sortedListToBST(lln[0])
    printTreeInorder(root)
    print("---------------")
    printTreePreorder(root)
    return


if __name__ == "__main__":
    main()
