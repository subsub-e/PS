const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
let input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const [k, e, w, s, n] = input[0].split(" ").map(Number)
const dx = [0, 0, 1, -1]
const dy = [1, -1, 0, 0]

const prob = [e / 100, w / 100, s / 100, n / 100]

const visited = Array.from({ length: k * 2 + 1 }, () =>
    new Array(k * 2 + 1).fill(false)
)

visited[k][k] = 1
let answer = 0

function dfs(cnt, x, y, probability) {
    if (cnt === k) {
        answer += probability
        return
    }

    for (let i = 0; i < 4; i++) {
        let nx = x + dx[i]
        let ny = y + dy[i]

        if (!visited[nx][ny]) {
            visited[nx][ny] = 1
            dfs(cnt + 1, nx, ny, probability * prob[i])
            visited[nx][ny] = 0
        }
    }
}

dfs(0, k, k, 1)

console.log(answer)
