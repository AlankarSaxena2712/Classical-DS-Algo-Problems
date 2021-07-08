def findSubString(s:str):
    windowStart = 0
    maxLength = 0
    dictionary = {}

    for windowEnd in range(len(s)):
        currChar = s[windowEnd]
        if currChar in dictionary:
            windowStart = max(windowStart, dictionary[currChar] + 1)
        dictionary[currChar] = windowEnd
        maxLength = max(maxLength, windowEnd - windowStart + 1)
    return maxLength


if __name__ == "__main__":
    s = "abcabcbb"
    print(findSubString(s))