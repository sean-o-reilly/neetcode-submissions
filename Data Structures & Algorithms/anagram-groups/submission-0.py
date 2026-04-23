import string

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # container of containers
        # anagram "identity/group" can be represented by a dict from char->count
        # dict of (anagram identity dict -> array of strings)
        # convert that dict into list of lists later on

        groups = defaultdict(list)
        for w in strs:
            key = ''.join(sorted(w))  # same for all anagrams
            groups[key].append(w)
        return list(groups.values())