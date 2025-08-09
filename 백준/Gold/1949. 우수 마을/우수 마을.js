const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const n = Number(input.shift())
const arr = input.shift().split(" ").map(Number)
const graph = Array.from({ length: n + 1 }, () => [])
const visited = new Array(n + 1).fill(false)
const dp = Array.from({ length: n + 1 }, () => new Array(2).fill(-1))

for (let i = 0; i < input.length; i++) {
    const [x, y] = input[i].split(" ").map(Number)
    graph[x - 1].push(y - 1)
    graph[y - 1].push(x - 1)
}

function dfs(now) {
    dp[now][0] = 0
    dp[now][1] = arr[now]

    for (let next of graph[now]) {
        if (!visited[next]) {
            visited[next] = 1
            dfs(next)
            dp[now][0] += Math.max(dp[next][0], dp[next][1])
            dp[now][1] += dp[next][0]
        }
    }
}

dp[0][0] = 0
dp[0][1] = arr[0]
visited[0] = 1
dfs(0)

console.log(Math.max(dp[0][0], dp[0][1]))
