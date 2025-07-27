const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
let input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const n = Number(input[0])
const arr = input[1]
    .split(" ")
    .map(Number)
    .sort((a, b) => a - b)

let answer = 1

for (let i = 0; i < n; i++) {
    if (arr[i] > answer) {
        break
    }
    answer += arr[i]
}

console.log(answer)
