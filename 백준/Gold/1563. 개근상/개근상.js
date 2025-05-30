const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const n = Number(input[0])

const arr = Array.from({ length: n }, () =>
    Array.from({ length: 2 }, () => Array(3).fill(0))
)

function func(o, l, a) {
    if (l === 2 || a === 3) {
        return 0
    }
    if (o === n) {
        return 1
    }
    if (arr[o][l][a] !== 0) {
        return arr[o][l][a]
    }

    arr[o][l][a] += func(o + 1, l, 0)
    arr[o][l][a] += func(o + 1, l + 1, 0)
    arr[o][l][a] += func(o + 1, l, a + 1)

    return arr[o][l][a] % 1000000
}

console.log(func(0, 0, 0))
