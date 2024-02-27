def count_ways(n, k):
    dp = [0] * (n + 1)
    dp[0] = 1

    for i in range(1, n + 1):
        for j in range(1, k + 1):
            if i - j >= 0:
                dp[i] += dp[i - j]

    return dp[n]

n = 5
k = 2
print("Количество способов:", count_ways(n, k))
