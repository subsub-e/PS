const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
let input = require("fs").readFileSync(filePath).toString().trim().split("\n")

function game(a, b, c, aStr, bStr, cIdx, visited) {
    if (cIdx === c.length) {
        return aStr === a && bStr === b
    }

    const cur = c[cIdx]
    const aIdx = aStr.length
    const bIdx = bStr.length

    if (visited[aIdx][bIdx]) return false
    visited[aIdx][bIdx] = true

    if (a[aIdx] === cur) {
        const isNextOK = game(a, b, c, aStr + cur, bStr, cIdx + 1, visited)
        if (isNextOK) return true
    }

    if (b[bIdx] === cur) {
        const isNextOK = game(a, b, c, aStr, bStr + cur, cIdx + 1, visited)
        if (isNextOK) return true
    }

    return false
}

function solution() {
    const n = Number(input[0])
    const arr = input.slice(1).map((item) => item.split(" "))
    let ans = []

    for (let i = 0; i < n; i++) {
        const [a, b, c] = arr[i]

        const visited = Array.from({ length: a.length + 1 }, () =>
            Array(b.length + 1).fill(false)
        )
        const res = game(a, b, c, "", "", 0, visited)

        ans.push(`Data set ${+i + 1}: ${res ? "yes" : "no"}`)
    }

    return ans.join("\n")
}

console.log(solution())
