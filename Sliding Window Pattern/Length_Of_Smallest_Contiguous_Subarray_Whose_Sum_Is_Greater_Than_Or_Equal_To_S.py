import math

def samllestSubarrayWithGivenSum(array, s): # Time Complexity : O(n)
    window_sum = 0
    min_length = math.inf
    window_start = 0

    for window_end in range(len(array)):
        window_sum = window_sum + array[window_end]
        while window_sum >= s:
            min_length = min(min_length, window_end - window_start + 1)
            window_sum = window_sum - array[window_start]
            window_start = window_start + 1
    if min_length == math.inf:
        return 0
    return min_length

if __name__ == "__main__":
    array = [2, 1, 5, 2, 3, 2]
    s = 7
    print(samllestSubarrayWithGivenSum(array, s))