#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class ListNode:
    def __init__(self, x: int):
        self.val = x
        self.next = None


def list2node(l: List[int]) -> List[ListNode]:
    ln = []
    for i in l:
        ln.append(ListNode(i))
    for i in range(len(ln) - 1):
        ln[i].next = ln[i + 1]
    return ln


def printNode(ln: ListNode):
    currentNode = ln
    while currentNode.next is not None:
        print(currentNode.val, end="-> ")
        currentNode = currentNode.next
    print(currentNode.val)


class Solution:
    def findNext(self, l: ListNode) -> ListNode:
        currentNode = l.next
        while currentNode is not None:
            if currentNode.val != l.val:
                return currentNode
            currentNode = currentNode.next
        return None

    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head is None:
            return None
        currentNode = head
        while currentNode.next is not None:
            if currentNode.next.val == currentNode.val:
                currentNode.next = self.findNext(currentNode)
            currentNode = currentNode.next
            if currentNode is None:
                break
        return head


def main():
    l = [1, 2, 2, 4, 4]
    k = [1, 1, 3, 3, 5]
    ln = list2node(l)
    kn = list2node(k)
    s = Solution()
    head = s.deleteDuplicates(ln[0])
    printNode(head)
    head = s.deleteDuplicates(kn[0])
    printNode(head)
    return


if __name__ == "__main__":
    main()
