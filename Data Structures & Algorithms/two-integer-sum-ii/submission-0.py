# cannot use O(n) additional space, can only view these nums

        # if using O(n) space, you could use a map from a seen num -> index seen
        # for each number, see if target - current num is seen, if it is that is the pair that makes the two sum

        # O(n^2) is possible, 
        # for each num, check all other numbers to see which other number adds up to the target

        # advantage is array is already sorted
        # if x is in the array, its not guranteed that x + 1 is in the array, could be [x, x, x, x, x + 999]
        # guranteed valid solution..
        # numbers CAN BE NEGATIVE

        # [1,2,3,4], at 1, you know you need 2 to get to 3


        # maybe start from either end, using a two pointer approach? There's probably a way to leverage the sort

        # [2,3,5,7], and target is 10, you can't hold onto 2 and wait for 7 to come along. You can't store a set of all seen numbers
            # does 2 + 7 == 10, no 9 is less than two, left pointer ++?
            # 3 + 7 == 0, okay

        # [-5,-3,-1,0,5] target is 2, 
            
            # does -5 + 5 == 2? no, 0 is less than two
            # does -3 + 5 == 2? yes

        # [1,2,3,4]
            # does 1 + 4 == 3, no, 5 > 3, move right pointer --
            # does 1 + 3 == 2, no 4 > 3, --right
            # does 1 + 2 == 3, yes return left and right

        # [1, 2], target must be 3, algo covers this

        # [-3,-1,1,2,7,8,12], target must be 0
            # -3 and 12 == 9, greater than target so move right down
            # -3 and 8 == 5, greater, --right
            # -3 and 7 == 4, greater, --right
            # -3 and 2, lesser, ++left
            # -1 and 2, greater, --right
            # -1 and 1, equals target of 0

        # two pointer approach looks solid, O(1) space and O(n) complexity

        # binary search?

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        
        left = 0
        right = len(numbers) - 1

        while (left < right):
            curr_sum = numbers[left] + numbers[right]

            if curr_sum == target:
                break
            elif curr_sum < target:
                left += 1
            elif curr_sum > target:
                right -= 1

        return [left + 1, right + 1]
