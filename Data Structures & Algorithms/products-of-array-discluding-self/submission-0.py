class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        product = 1
        
        zeroes = 0

        for num in nums:
            if num == 0 and zeroes == 0:
                zeroes += 1
            else:
                product *= num
         
        if product == 0: # 2 zeroes in list, everything will be zero
            res = []
            for i in nums:
                res.append(0)

            return res 
        
        if zeroes == 1:
            res = []
            for num in nums:
                if num == 0:
                    res.append(product)
                else:
                    res.append(0)
            return res

        res = []

        for num in nums:
            if num != 0:
                res.append(product // num)
            elif num == 0:
                res.append(product)

        return res