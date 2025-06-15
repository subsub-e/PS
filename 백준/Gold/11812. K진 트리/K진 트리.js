const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const [n, k, q] = input.shift().split(" ").map(Number)

function calculateHeight(x) {
    let i = 1
    let h = 1
    while (1) {
        if (x <= i) {
            return h
        }
        i += Math.pow(k, h++)
    }
}

function findParent(x) {
    return Math.floor((x - 2) / k) + 1
}

function solution(x, y) {
    //console.log(x, y)
    let h1 = calculateHeight(x)
    let h2 = calculateHeight(y)
    //console.log(h1, h2)
    let answer = 0

    while (h1 !== h2) {
        if (h1 < h2) {
            y = findParent(y)
            answer++
            h2--
        } else {
            x = findParent(x)
            answer++
            h1--
        }
    }
    //console.log(x, y)

    while (1) {
        if (x === y) {
            return answer
        }
        x = findParent(x)
        y = findParent(y)
        answer += 2
    }
}

for (let i = 0; i < q; i++) {
    const [x, y] = input[i].split(" ").map(Number)
    if (k === 1) {
        console.log(Math.abs(x - y))
    } else {
        console.log(solution(x, y))
    }
}
