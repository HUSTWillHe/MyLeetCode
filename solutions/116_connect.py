#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


def printNode(root: Node):
    if root is None:
        return
    if root.next is None:
        print("root is: " + str(root.val) + "  next is: None")
    else:
        print("root is: " + str(root.val) + "  next is: " + str(root.next.val))
    printNode(root.left)
    printNode(root.right)


class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return root
        level = [root]
        while(len(level) != 0):
            temp = []
            for l in level:
                if l.left is not None:
                    temp.append(l.left)
                if l.right is not None:
                    temp.append(l.right)
            level = temp
            for i in range(len(level) - 1):
                level[i].next = level[i + 1]
        return root


def main():
    s = Solution()
    n = [Node(i) for i in range(7)]
    n[0].left = n[1]
    n[0].right = n[2]
    n[1].left = n[3]
    n[1].right = n[4]
    n[2].left = n[5]
    n[2].right = n[6]
    ans = s.connect(n[0])
    printNode(ans)
    return


if __name__ == "__main__":
    main()
