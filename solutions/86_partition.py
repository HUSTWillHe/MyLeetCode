#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def print_list(head: ListNode) -> None:
    current = head
    while current != None:
        print(current.val, end=" -> ")
        current = current.next
    print("\n")


class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        head_left = None
        head_right = None
        current_left = None
        current_right = None
        current = head
        while current != None:
            if current.val < x:
                if current_left == None:
                    head_left = current
                else:
                    current_left.next = current
                current_left = current
            else:
                if current_right == None:
                    head_right = current
                else:
                    current_right.next = current
                current_right = current
            current = current.next
        if current_right != None:
            current_right.next = None
        if current_left == None:
            return head_right
        else:
            current_left.next = head_right
            return head_left


def main():
    l = [1, 4, 3, 2, 5, 2]
    lln = []
    for i in l:
        lln.append(ListNode(i))
    for i, ln in enumerate(lln):
        if i < len(lln) - 1:
            ln.next = lln[i + 1]
    print_list(lln[0])
    s = Solution()
    head = s.partition(lln[0], -31)
    print_list(head)
    return


if __name__ == "__main__":
    main()
