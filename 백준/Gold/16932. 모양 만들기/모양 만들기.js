const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
let input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const [n, m] = input.shift().split(" ").map(Number)
const arr = input.map((line) => line.split(" ").map(Number))

const visited = Array.from({ length: n }, () => Array(m).fill(0))

const cnt = Array.from({ length: n }, () =>
    Array.from({ length: m }, () => [0, 0])
)

const dx = [-1, 0, 1, 0]
const dy = [0, -1, 0, 1]

let q = []

let glob = 1

function bfs() {
    let index = 0
    let temp_q = []
    while (index < q.length) {
        const [x, y] = q[index++]
        temp_q.push([x, y])

        for (let i = 0; i < 4; i++) {
            let nx = x + dx[i]
            let ny = y + dy[i]

            if (
                0 <= nx &&
                nx < n &&
                0 <= ny &&
                ny < m &&
                !visited[nx][ny] &&
                arr[nx][ny] === 1
            ) {
                q.push([nx, ny])
                visited[nx][ny] = 1
            }
        }
    }

    for (let i = 0; i < temp_q.length; i++) {
        let [x, y] = temp_q[i]
        cnt[x][y] = [glob, temp_q.length]
    }
    glob++
    q = []
}

for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
        if (!visited[i][j] && arr[i][j] === 1) {
            q.push([i, j])
            visited[i][j] = 1
            bfs()
        }
    }
}

let maxCnt = -1

for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
        if (arr[i][j] === 0) {
            let temp_cnt = 0
            let check_num = new Set()
            for (let k = 0; k < 4; k++) {
                let nx = i + dx[k]
                let ny = j + dy[k]
                if (
                    0 <= nx &&
                    nx < n &&
                    0 <= ny &&
                    ny < m &&
                    cnt[nx][ny][0] !== 0 &&
                    !check_num.has(cnt[nx][ny][0])
                ) {
                    check_num.add(cnt[nx][ny][0])
                    temp_cnt += cnt[nx][ny][1]
                }
            }
            maxCnt = Math.max(maxCnt, temp_cnt)
        }
    }
}

console.log(maxCnt + 1)
