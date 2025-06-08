const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
let input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const [n, t, goal] = input[0].split(" ").map(Number)

let cnt = Array(100001).fill(Number.MAX_VALUE)

let q = []

cnt[n] = 0

q.push(n)

function bfs() {
    let index = 0
    while (index < q.length) {
        let now = q[index++]

        if (now >= 50000) {
            if (cnt[now] + 1 < cnt[now + 1]) {
                cnt[now + 1] = cnt[now] + 1
                q.push(now + 1)
            }
        } else {
            if (cnt[now] + 1 < cnt[now + 1]) {
                cnt[now + 1] = cnt[now] + 1
                q.push(now + 1)
            }
            let next = String(now * 2)
            let first = Number(next[0]) - 1
            let nextNumber = Number(String(first) + next.slice(1))
            if (cnt[now] + 1 < cnt[nextNumber]) {
                cnt[nextNumber] = cnt[now] + 1
                q.push(nextNumber)
            }
        }
    }
}

bfs()

if (cnt[goal] === Number.MAX_VALUE || cnt[goal] > t) {
    console.log("ANG")
} else {
    console.log(cnt[goal])
}
