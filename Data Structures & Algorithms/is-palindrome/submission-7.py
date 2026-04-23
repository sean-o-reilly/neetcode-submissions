# try to reverse and check equal
# two pointer approach, move left and right ptr to the center until they aren't equal, if they hit the center return true, if they aren't equal at any point return false

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()

        left = 0
        right = len(s) - 1

        while (left < right):

            while (left < len(s) - 1 and s[left].isalnum() == False):
                left += 1 # skip non alnum
            while (right > 0 and s[right].isalnum() == False):
                right -= 1

            if left >= len(s) or right < 0:
                return False

            if (s[left].isalnum() and s[right].isalnum()):
                if (s[left] != s[right]): # at any point not equal, return false
                    return False

            left += 1
            right -= 1

        return True # every character left and right was equal