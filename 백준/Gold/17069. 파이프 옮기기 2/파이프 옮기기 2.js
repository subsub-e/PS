const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
let input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const n = Number(input.shift())
const arr = input.map((line) => line.split(" ").map(Number))

const dp = Array.from({ length: n }, () =>
    Array.from({ length: n }, () => [0, 0, 0])
)

dp[0][1][0] = 1

for (let i = 0; i < n; i++) {
    for (let j = 1; j < n; j++) {
        if (j + 1 < n && arr[i][j + 1] === 0) {
            dp[i][j + 1][0] = dp[i][j][2] + dp[i][j][0]
        }
        if (i + 1 < n && arr[i + 1][j] === 0) {
            dp[i + 1][j][1] = dp[i][j][2] + dp[i][j][1]
        }
        if (
            i + 1 < n &&
            j + 1 < n &&
            arr[i][j + 1] === 0 &&
            arr[i + 1][j] === 0 &&
            arr[i + 1][j + 1] === 0
        ) {
            dp[i + 1][j + 1][2] = dp[i][j][0] + dp[i][j][1] + dp[i][j][2]
        }
    }
}

console.log(dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2])
