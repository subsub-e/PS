const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const [n, m] = input.shift().split(" ").map(Number)

const arr = input.map((line) => line.split(" ").map(Number))

const minValue = -10000000

const dp = Array.from({ length: n }, () => new Array(m).fill(minValue))

dp[0][0] = arr[0][0]

for (let i = 1; i < m; i++) {
    dp[0][i] = dp[0][i - 1] + arr[0][i]
}

for (let i = 1; i < n; i++) {
    let left = new Array(m).fill(minValue)
    let right = new Array(m).fill(minValue)

    left[0] = dp[i - 1][0] + arr[i][0]
    right[m - 1] = dp[i - 1][m - 1] + arr[i][m - 1]

    for (let j = 1; j < m; j++) {
        left[j] = Math.max(dp[i - 1][j], left[j - 1]) + arr[i][j]
    }
    for (let j = m - 2; j >= 0; j--) {
        right[j] = Math.max(dp[i - 1][j], right[j + 1]) + arr[i][j]
    }

    for (let j = 0; j < m; j++) {
        dp[i][j] = Math.max(left[j], right[j])
    }
}

console.log(dp[n - 1][m - 1])
