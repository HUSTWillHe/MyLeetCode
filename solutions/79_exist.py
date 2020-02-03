#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        length = len(word)
        if length == 0:
            return True
        height = len(board)
        if height == 0:
            return False
        width = len(board[0])
        if width == 0:
            return False
        for i in range(height):
            for k in range(width):
                if board[i][k] == word[0]:
                    if self.back_trace(board, word, "", [],i, k, height, width, length):
                        return True
        return False

    def back_trace(self, board: List[List[str]], word: str, temp: str, route, i: int, k: int, height: int, width: int, length: int) -> bool:
        print("back trace=================")
        print("i: " + str(i))
        print("k: " + str(k))
        if i < 0 or i >= height or k < 0 or k >= width:
            return False
        if (i, k) in route:
            return False
        length_temp = len(temp)
        if board[i][k] != word[length_temp]:
            return False
        temp += board[i][k]
        route.append((i, k))
        print("temp: " + temp)
        print("route: ")
        print(route)
        if length == length_temp + 1:
            if temp == word:
                return True
        if self.back_trace(board, word, temp, route, i - 1, k, height, width, length) or self.back_trace(board, word, temp, route, i, k - 1, height, width, length) or self.back_trace(board, word, temp, route, i + 1, k, height, width, length) or self.back_trace(board, word, temp, route, i, k + 1, height, width, length):
            return True
        temp = temp[:-1]
        route.pop()
        return False


def main():
    s = Solution()
    board = [['a', 'b', 'c', 'e'], ['s', 'f', 'c', 's'], ['a', 'd', 'e', 'e']]
    board1 = [['a', 'b'], ['c', 'd']]
    ans = s.exist(board1, "cdba")
    print(ans)
    return


if __name__ == "__main__":
    main()
