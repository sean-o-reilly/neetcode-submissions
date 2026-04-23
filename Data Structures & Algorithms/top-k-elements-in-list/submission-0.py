class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        num_count = {}

        for num in nums:
            num_count[num] = num_count.get(num, 0) + 1 # if num isnt in set, 0 will be the default value!

        res = []

        for i in range(k):
            max_key = max(num_count, key=num_count.get)

            res.append(max_key)

            num_count.pop(max_key)

        return res
        