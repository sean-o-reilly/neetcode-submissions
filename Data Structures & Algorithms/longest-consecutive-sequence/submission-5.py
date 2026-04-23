class Solution:

    # sorted..
    # starting element is ambiguous..
    # since next sequence could be longer, keep track of a max length sequence

    # [0, 1, 1, 2, 3, 4, 5, 6] works fine as one sequence
    # [0, 1, 1, 2, 3, 4, 5, 6, 10-55] needs to recognize 10 as the superior starting point 
    # [2, 3, 4, 4, 5, 10, 20]
    # [1, 2]
    # [9,1,4,7,3,-1,0,5,8,-1,6]

    # sort/O(n log n) + O(n) time

    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)

        longest = 0;

        for num in num_set: 
            # if branch makes this O(seqence starting numbers)
            if (num - 1) not in num_set: # no number comes before, it is beginning of sequence. O(1) lookup
                streak = 1

                while (num + streak) in num_set: # while next number keeps appearing.
                    streak += 1

                longest = max(longest, streak)
        
        return longest

# algorithmn as a whole will only check for sequence starting number, then every number of its sequence, therefore it is O(n)

# will check 123, then 8 9 10, then 22 23 24, etc.