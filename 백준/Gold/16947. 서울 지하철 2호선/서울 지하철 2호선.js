const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const n = Number(input.shift())

const graph = Array.from({ length: n + 1 }, () => [])

const visited = new Array(n + 1).fill(false)

const cycle = new Array(n + 1).fill(10000)

let flag = 0

for (let i = 0; i < input.length; i++) {
    const [start, to] = input[i].split(" ").map(Number)

    graph[start].push(to)
    graph[to].push(start)
}

function dfs(arr) {
    if (flag) {
        return
    }

    for (const v of graph[arr[arr.length - 1]]) {
        if (v === arr[0] && arr.length >= 3) {
            flag = 1
            arr.forEach((x) => (cycle[x] = 0))
            return
        }
        if (!visited[v]) {
            visited[v] = 1
            dfs(arr.concat(v))
            visited[v] = 0
        }
    }
}

for (let i = 1; i <= n; i++) {
    if (flag === 0) {
        visited[i] = 1
        dfs([i])
        visited[i] = 0
    }
}

let q = []
let qIndex = 0

for (let i = 1; i <= n; i++) {
    if (cycle[i] === 0) {
        q.push([i, 1])
    }
}

while (q.length > qIndex) {
    let [now, d] = q[qIndex++]

    for (const v of graph[now]) {
        if (cycle[v] === 10000) {
            cycle[v] = d
            q.push([v, d + 1])
        }
    }
}

const answer = cycle.slice(1)
console.log(answer.join(" "))
