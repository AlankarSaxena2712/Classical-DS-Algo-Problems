def longest_repeating_character_replacement(s:str, k:int):
    windowStart = 0
    maxLength = 0
    maxRepeatLetter = 0
    dictionary = {}
    for windowEnd in range(len(s)):
        currChar = s[windowEnd]
        dictionary[currChar] = 1 + dictionary.get(currChar, 0)
        maxRepeatLetter = max(maxRepeatLetter, dictionary[currChar])
        if (windowEnd - windowStart + 1 - maxRepeatLetter) > k:
            leftChar = s[windowStart]
            dictionary[leftChar] -= 1
            windowStart += 1
        maxLength = max(maxLength, windowEnd - windowStart + 1)
    return maxLength

if __name__ == "__main__":
    s = "aabccbb"
    k = 2
    print(longest_repeating_character_replacement(s, k))