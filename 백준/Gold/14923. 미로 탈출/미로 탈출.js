const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
let input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const [n, m] = input.shift().split(" ").map(Number)

let [stx, sty] = input.shift().split(" ").map(Number)
let [enx, eny] = input.shift().split(" ").map(Number)

const arr = input.map((i) => i.split(" ").map(Number))

stx--
sty--
enx--
eny--

const MAX_VALUE = Number.MAX_VALUE

const visited = Array.from({ length: n }, () =>
    Array.from({ length: m }, () => Array(2).fill(MAX_VALUE))
)

const dx = [-1, 0, 1, 0]
const dy = [0, -1, 0, 1]

let q = []

q.push([stx, sty, 0])

visited[stx][sty][0] = 1
visited[stx][sty][1] = 1

function bfs() {
    let index = 0
    while (index < q.length) {
        let [x, y, isWall] = q[index++]

        for (let i = 0; i < 4; i++) {
            let nx = x + dx[i]
            let ny = y + dy[i]

            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (isWall === 0) {
                    if (arr[nx][ny] === 0) {
                        if (visited[x][y][0] + 1 < visited[nx][ny][0]) {
                            visited[nx][ny][0] = visited[x][y][0] + 1
                            q.push([nx, ny, 0])
                        }
                    } else {
                        if (visited[x][y][0] + 1 < visited[nx][ny][1]) {
                            visited[nx][ny][1] = visited[x][y][0] + 1
                            q.push([nx, ny, 1])
                        }
                    }
                } else {
                    if (
                        arr[nx][ny] === 0 &&
                        visited[x][y][1] + 1 < visited[nx][ny][1]
                    ) {
                        visited[nx][ny][1] = visited[x][y][1] + 1
                        q.push([nx, ny, 1])
                    }
                }
            }
        }
    }
}

bfs()

if (Math.min(visited[enx][eny][0], visited[enx][eny][1]) === MAX_VALUE) {
    console.log(-1)
} else {
    console.log(Math.min(visited[enx][eny][0], visited[enx][eny][1]) - 1)
}
