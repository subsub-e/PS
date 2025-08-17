const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const [n, m] = input.shift().split(" ").map(Number)
const arr = []

for (let i = 0; i < n; i++) {
    const lin = input[i].split(" ").map(Number)
    arr.push(lin)
}

let [h, w, sx, sy, fx, fy] = input[n].split(" ").map(Number)

h--
w--
sx--
sy--
fx--
fy--

let flag = 0
const visited = Array.from({ length: n + 1 }, () =>
    new Array(m + 1).fill(false)
)
const dx = [-1, 0, 1, 0]
const dy = [0, -1, 0, 1]

function cango(x, y, dir) {
    if (dir === 0) {
        for (let i = y; i <= y + w; i++) {
            if (arr[x][i] === 1) {
                return false
            }
        }
    } else if (dir === 1) {
        for (let i = x; i <= x + h; i++) {
            if (arr[i][y] === 1) {
                return false
            }
        }
    } else if (dir === 2) {
        let nx = x + h
        if (nx >= n) {
            return false
        }

        for (let i = y; i <= y + w; i++) {
            if (arr[nx][i] === 1) {
                return false
            }
        }
    } else {
        let ny = y + w
        if (ny >= m) {
            return false
        }
        for (let i = x; i <= x + h; i++) {
            if (arr[i][ny] === 1) {
                return false
            }
        }
    }
    return true
}

function bfs(sx, sy) {
    visited[sx][sy] = 1
    let q = []
    q.push([sx, sy, 0])
    let index = 0
    while (q.length > index) {
        let [x, y, cnt] = q[index++]

        if (x === fx && y === fy) {
            console.log(cnt)
            flag = 1
            return
        }
        for (let i = 0; i < 4; i++) {
            let nx = x + dx[i]
            let ny = y + dy[i]
            if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny]) {
                if (cango(nx, ny, i)) {
                    q.push([nx, ny, cnt + 1])
                    visited[nx][ny] = 1
                }
            }
        }
    }
}

bfs(sx, sy)

if (flag === 0) {
    console.log(-1)
}
