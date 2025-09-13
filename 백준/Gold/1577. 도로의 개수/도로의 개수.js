const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const [n, m] = input.shift().split(" ").map(Number)
let t = Number(input.shift())
const arr = input.map((line) => line.split(" ").map(Number))

const dp = Array.from({ length: n + 1 }, () => new Array(m + 1).fill(0n))
dp[0][0] = 1n

let dx = [0, 1]
let dy = [1, 0]

const s = new Set()
for (let i = 0; i < t; i++) {
    const [x1, y1, x2, y2] = arr[i]
    if (x1 < x2 || y1 < y2) {
        s.add(`${x1}, ${y1}, ${x2}, ${y2}`)
    } else {
        s.add(`${x2}, ${y2}, ${x1}, ${y1}`)
    }
}

for (let i = 0; i <= n; i++) {
    for (let j = 0; j <= m; j++) {
        for (let k = 0; k < 2; k++) {
            let prevX = i - dx[k]
            let prevY = j - dy[k]
            if (prevX >= 0 && prevY >= 0) {
                if (!s.has(`${prevX}, ${prevY}, ${i}, ${j}`)) {
                    dp[i][j] += dp[prevX][prevY]
                }
            }
        }
    }
}

console.log(dp[n][m].toString())
