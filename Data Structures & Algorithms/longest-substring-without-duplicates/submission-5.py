class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        substring = {}
        left = 0
        right = 1
        max_len = 1
        substring[s[left]] = left

        while right < len(s):
            if s[right] in substring:
                if substring[s[right]] == left:
                    left += 1
                else:
                    substring = {}
                    left = right
            substring[s[right]] = right
            right += 1
            max_len = max(max_len, len(substring))

        return max_len

