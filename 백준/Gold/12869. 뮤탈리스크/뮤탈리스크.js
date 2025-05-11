const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const n = Number(input[0])
const arr = input[1].split(" ").map(Number)

const x = [
    [9, 3, 1],
    [9, 1, 3],
    [3, 9, 1],
    [3, 1, 9],
    [1, 9, 3],
    [1, 3, 9],
]

const q = []
const visited = new Set()

function normalize(state) {
    const pad = [0, 0, 0]
    for (let i = 0; i < n; i++) {
        pad[i] = Math.max(0, state[i])
    }
    return pad.join(",")
}

q.push([arr, 0])
visited.add(normalize(arr))

let answer

function bfs() {
    let index = 0
    while (q.length > index) {
        const now = q[index][0]
        const cnt = q[index++][1]

        if (now.every((hp) => hp === 0)) {
            answer = cnt
            return
        }

        for (let i = 0; i < 6; i++) {
            const next = []
            for (let j = 0; j < n; j++) {
                next.push(Math.max(0, now[j] - x[i][j]))
            }
            const key = normalize(next)
            if (!visited.has(key)) {
                visited.add(key)
                q.push([next, cnt + 1])
            }
        }
    }
}

bfs()
console.log(answer)
