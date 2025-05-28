const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const n = Number(input.shift())

const arr = []
for (let i = 0; i < n; i++) {
    arr.push(input[i].split(" ").map(Number))
}

arr.sort((a, b) => b[0] - a[0])

let answer = 0
const visited = new Array(n).fill(false)

for (let i = arr[0][0]; i >= 1; i--) {
    let max = 0
    let index = 0

    for (let j = 0; j < n; j++) {
        if (visited[j]) {
            continue
        }
        if (i <= arr[j][0] && max < arr[j][1]) {
            max = arr[j][1]
            index = j
        }
    }
    answer += max
    visited[index] = 1
}

console.log(answer)
