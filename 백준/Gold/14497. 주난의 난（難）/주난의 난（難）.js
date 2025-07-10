const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
let input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const [n, m] = input.shift().split(" ").map(Number)
const [stx, sty, enx, eny] = input.shift().split(" ").map(Number)

const startX = stx - 1
const startY = sty - 1
const endX = enx - 1
const endY = eny - 1

const arr = input.map((line) => line.trim().split(""))
const visited = Array.from({ length: n }, () => Array(m).fill(-1))

const dx = [-1, 1, 0, 0]
const dy = [0, 0, -1, 1]

let deque = []
deque.push([startX, startY])
visited[startX][startY] = 0

while (deque.length > 0) {
    let [x, y] = deque.shift()

    for (let i = 0; i < 4; i++) {
        let nx = x + dx[i]
        let ny = y + dy[i]

        if (0 <= nx && nx < n && 0 <= ny && ny < m && visited[nx][ny] === -1) {
            if (arr[nx][ny] === "0") {
                visited[nx][ny] = visited[x][y]
                deque.unshift([nx, ny])
            } else if (arr[nx][ny] === "1" || arr[nx][ny] === "#") {
                visited[nx][ny] = visited[x][y] + 1
                deque.push([nx, ny])
            }
        }
    }
}

console.log(visited[endX][endY])
