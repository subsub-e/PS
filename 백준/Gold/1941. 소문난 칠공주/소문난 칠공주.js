const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
let input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const arr = input.map((line) => line.split(""))

const dx = [-1, 0, 1, 0]
const dy = [0, -1, 0, 1]

const queue = []

let answer = 0

function bfs() {
    const visited = Array.from({ length: 5 }, () => new Array(5).fill(true))

    for (const [x, y] of queue) {
        visited[x][y] = 0
    }

    let q = []
    q.push(queue[0])
    visited[queue[0][0]][queue[0][1]] = 1
    let cnt = 1
    let index = 0
    while (q.length > index) {
        let [x, y] = q[index++]

        for (let i = 0; i < 4; i++) {
            let nx = x + dx[i]
            let ny = y + dy[i]

            if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && !visited[nx][ny]) {
                visited[nx][ny] = 1
                q.push([nx, ny])
                cnt++
            }
        }
    }

    return cnt === 7
}

function dfs(cur, count) {
    if (count >= 4) {
        return
    }

    if (queue.length === 7) {
        if (bfs()) {
            answer++
        }
        return
    }

    for (let i = cur; i < 25; i++) {
        let x = Math.floor(i / 5)
        let y = i % 5

        queue.push([x, y])

        if (arr[x][y] === "Y") {
            dfs(i + 1, count + 1)
        } else {
            dfs(i + 1, count)
        }

        queue.pop()
    }
}

dfs(0, 0)

console.log(answer)
