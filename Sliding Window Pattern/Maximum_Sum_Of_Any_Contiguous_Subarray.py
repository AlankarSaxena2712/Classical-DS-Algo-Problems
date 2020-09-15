def contiguousSubarrayOfSizeKWithMaxSum(array, k): # O(n) Time Complexity
    max_sum = 0
    window_sum = 0
    window_start = 0
    for window_end in range(len(array)):
        window_sum = window_sum + array[window_end]
        if window_end >= k - 1:
            max_sum = max(window_sum, max_sum)
            window_sum = window_sum - array[window_start]
            window_start = window_start + 1
    return max_sum

if __name__ == "__main__":
    array = [2, 1, 5, 1, 3, 2]
    k = 3
    result = contiguousSubarrayOfSizeKWithMaxSum(array, k)
    print(result)