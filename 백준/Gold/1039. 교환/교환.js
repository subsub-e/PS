const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
let input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const arr = input[0].split(" ")
const n = arr[0].split("")
const m = Number(arr[1])

let max = -1
let visited = Array.from({ length: m + 1 }, () =>
    new Array(1000001).fill(false)
)

function dfs(now, count) {
    const tar = Number(now.join(""))

    if (visited[count][tar]) {
        return
    }

    if (count === m) {
        if (tar > max) {
            max = tar
        }
        return
    }

    for (let i = 0; i < now.length - 1; i++) {
        for (let j = i + 1; j < now.length; j++) {
            ;[now[i], now[j]] = [now[j], now[i]]
            if (now[0] !== "0") {
                dfs(now, count + 1)
            }
            ;[now[i], now[j]] = [now[j], now[i]]
        }
    }
    visited[count][tar] = 1
}

dfs(n, 0)

console.log(max)
