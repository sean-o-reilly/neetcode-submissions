class Solution:

    encryption_key = "*(&ASDNASP#@!)"

    # [neet, code, love, you]
    # "neet_code_love_you"
    # [neet, code, love, you]

    def encode(self, strs: List[str]) -> str:
        res = ""

        for word in strs:
            res = res + word + self.encryption_key

        return res

    def decode(self, s: str) -> List[str]:
        res = []

        word = ""
        i = 0

        while i < len(s):
            char = s[i]

            if s.startswith(self.encryption_key, i):
                i += len(self.encryption_key)
                res.append(word)
                word = ""
            else:
                word = word + char
                i += 1
                
        return res