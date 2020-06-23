#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from typing import List
from typing import Dict
import pdb
from collections import defaultdict


class Solution:
    def __init__(self):
        self.pattern_words = {}
        self.size = 0
        self.used_words = []

    def init_pattern_words(self, beginWord: str, wordList: List[str]):
        for i in range(self.size):
            pattern = beginWord[0:i] + '*' + beginWord[i + 1:]
            if pattern not in self.pattern_words:
                self.pattern_words[pattern] = [beginWord]
            else:
                self.pattern_words[pattern].append(beginWord)
        for word in wordList:
            for i in range(self.size):
                pattern = word[0:i] + '*' + word[i + 1:]
                if pattern not in self.pattern_words:
                    self.pattern_words[pattern] = [word]
                else:
                    self.pattern_words[pattern].append(word)

    def find_neighbor(self, target: str) -> List[str]:
        result = []
        for i in range(self.size):
            pattern = target[0: i] + '*' + target[i + 1:]
            for neighbor in self.pattern_words[pattern]:
                if neighbor != target and (neighbor not in self.used_words):
                    result.append(neighbor)
                    self.used_words.append(neighbor)
        return result

    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if len(wordList) < 1:
            return 0
        self.size = len(beginWord)
        self.init_pattern_words(beginWord, wordList)
        word_queue = [beginWord]
        last_queue_size = 1
        current_level = 1
        while True:
            current_level += 1
            for current in word_queue:
                current_neighbors = self.find_neighbor(current)
                word_queue.extend(current_neighbors)
                if endWord in current_neighbors:
                    return current_level
            word_queue = word_queue[last_queue_size:]









def main():
    s = Solution()
    ans = s.ladderLength("hit", "cog", ["hot","dot","dog","lot","log","cog"])
    print("ans is : " + str(ans))
    return


if __name__ == "__main__":
    main()
