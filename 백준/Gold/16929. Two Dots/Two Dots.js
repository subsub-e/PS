const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const [n, m] = input.shift().split(" ").map(Number)

let visited = Array.from({ length: 50 }, () =>
    Array.from({ length: 50 }).fill(0)
)

const dx = [-1, 0, 1, 0]
const dy = [0, -1, 0, 1]

let flag = 0

function dfs(start_x, start_y, now_x, now_y, target, cnt) {
    // console.log(now_x, now_y)
    for (let i = 0; i < 4; i++) {
        let next_x = now_x + dx[i]
        let next_y = now_y + dy[i]

        if (
            0 <= next_x &&
            next_x < n &&
            0 <= next_y &&
            next_y < m &&
            input[next_x][next_y] === target
        ) {
            if (next_x === start_x && next_y === start_y && cnt >= 3) {
                flag = 1
                return
            }
            if (!visited[next_x][next_y]) {
                visited[next_x][next_y] = 1
                dfs(start_x, start_y, next_x, next_y, target, cnt + 1)
                visited[next_x][next_y] = 0
            }
        }
    }
}

function solution() {
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (!visited[i][j]) {
                visited[i][j] = 1
                flag = 0
                dfs(i, j, i, j, input[i][j], 0)
                visited[i][j] = 0
                if (flag === 1) {
                    return true
                }
            }
        }
    }
    return false
}

if (solution()) {
    console.log("Yes")
} else {
    console.log("No")
}
