#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def printListNode(l: ListNode):
    currentNode = l
    while currentNode is not None:
        print(currentNode.val, end=' -> ')
        currentNode = currentNode.next


class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head is None:
            return None
        safeNode = None
        firstSafeNode = None
        currentNode = head
        while currentNode is not None:
            if currentNode.next is None or currentNode.next.val != currentNode.val:
                safeNode = currentNode
                if firstSafeNode is None:
                    firstSafeNode = safeNode
                currentNode = currentNode.next
            else:
                currentNode = self.findNext(currentNode)
                if safeNode is not None:
                    safeNode.next = currentNode

        return firstSafeNode

    def findNext(self, now: ListNode) -> ListNode:
        currentNode = now.next
        while currentNode is not None:
            if currentNode.val != now.val:
                return currentNode
            currentNode = currentNode.next
        return None


def main():
    s = Solution()
    example = [1, 1, 2, 2, 3, 4, 4]
    list_exam = []
    for i, e in enumerate(example):
        list_exam.append(ListNode(e))
    for i in range(len(example) - 1):
        list_exam[i].next = list_exam[i + 1]

    print("before: ")
    printListNode(list_exam[0])
    head = s.deleteDuplicates(list_exam[0])
    print("after: ")
    printListNode(head)
    return


if __name__ == "__main__":
    main()
