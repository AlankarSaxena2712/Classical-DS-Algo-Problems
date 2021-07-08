def findLength(string, k):
    if ((len(string) == 0) or (len(string) == None) or (len(string) < k)):
        return -1
    
    windowStart = 0
    maxLength = 0
    dictionary = {}

    for windowEnd in range(len(string)):
        rightCharacter = string[windowEnd]
        if rightCharacter not in dictionary:
            dictionary[rightCharacter] = 1
        else:
            dictionary[rightCharacter] = dictionary[rightCharacter] + 1
        while len(dictionary) > k:
            dictionary[string[windowStart]] = dictionary[string[windowStart]] - 1
            if dictionary[string[windowStart]] == 0:
                dictionary.pop(string[windowStart])
            windowStart += 1
        maxLength = max(maxLength, windowEnd - windowStart + 1)
    return maxLength
    

if __name__ == "__main__":
    string = "aabacbebebe"
    k = 3
    length = findLength(string, k)
    print(length)