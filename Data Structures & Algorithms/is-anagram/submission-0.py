class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_dict = {}
        t_dict = {}

        alphabet = "abcdefghijklmnopqrstuvwxyz"
        for char in alphabet:
            s_dict[char] = 0
            t_dict[char] = 0

        for char in s:
            s_dict[char] = s_dict[char] + 1
        for char in t:
            t_dict[char] = t_dict[char] + 1

        return s_dict == t_dict

