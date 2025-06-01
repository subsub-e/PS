const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
let input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const cases = Number(input[0])
input = input[1].split(" ").map((v) => Number(v))
const dp = [input[0]]
const dp2 = [input[0]]
for (let i = 1; i < cases; i++) {
    dp[i] = input[i] > input[i] + dp[i - 1] ? input[i] : input[i] + dp[i - 1]
}
for (let i = 1; i < cases; i++) {
    dp2[i] =
        dp[i - 1] > input[i] + dp2[i - 1] ? dp[i - 1] : input[i] + dp2[i - 1]
}
const dpMax = Math.max(...dp)
const dp2Max = Math.max(...dp2)
console.log(Math.max(dpMax, dp2Max))
