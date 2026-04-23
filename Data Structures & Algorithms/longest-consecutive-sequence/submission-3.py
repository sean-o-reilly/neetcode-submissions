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
        if len(nums) == 0:
            return 0
            
        nums = sorted(nums)

        curr_seq = 1
        max_seq = 1

        for i in range(len(nums) - 1): # size 2 sliding window
            num = nums[i]
            next_num = nums[i + 1]
            
            if next_num == num + 1: # seq continue
                curr_seq += 1
            elif next_num != num: #seq break
                max_seq = max(max_seq, curr_seq)
                curr_seq = 1 # reset the seq

        return max(max_seq, curr_seq)
        