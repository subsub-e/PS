const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const n = Number(input.shift())
const arr = input[0].split(" ").map(Number)
const m = Number(input[1])

const dp = new Array(m + 1).fill(-1n) // BigInt -1

for (let i = n - 1; i >= 0; i--) {
    let now = arr[i]
    for (let j = now; j <= m; j++) {
        const candidate1 = dp[j]
        const candidate2 = BigInt(i)
        const candidate3 = dp[j - now] * 10n + BigInt(i)

        dp[j] =
            candidate1 > candidate2
                ? candidate1 > candidate3
                    ? candidate1
                    : candidate3
                : candidate2 > candidate3
                ? candidate2
                : candidate3
    }
}

console.log(dp[m].toString())
