def solution(array, k):
    result = []
    window_sum = 0
    window_start = 0

    for window_end in range(len(array)):
        window_sum = window_sum + array[window_end]
        if window_end >= k - 1:
            result.append(window_sum / k)
            window_sum = window_sum - array[window_start]
            window_start = window_start + 1
    return result

# Time Comlpexity : O(n)

if __name__ == "__main__":
    array = [1, 3, 6, 2, -1, 4, 1, 8, 2]
    k = 5
    ans = solution(array, k)
    for i in ans:
        print(i, end = "   ")