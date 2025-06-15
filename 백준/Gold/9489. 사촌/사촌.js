const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

function solution(n, m, arr) {
    let index = -1

    let parent = [-1]
    let target = arr.length - 1
    let before = arr[0]

    for (let i = 1; i < arr.length; i++) {
        if (before + 1 !== arr[i]) {
            index++
        }
        if (m === arr[i]) {
            target = i
        }
        parent.push(index)
        before = arr[i]
    }

    let answer = 0
    for (let i = 1; i < n; i++) {
        if (
            parent[i] !== parent[target] &&
            parent[parent[i]] === parent[parent[target]]
        ) {
            answer++
        }
    }
    return answer
}

for (let i = 0; i < input.length; i += 2) {
    const [n, m] = input[i].split(" ").map(Number)
    if (n === 0 && m === 0) {
        break
    }
    const arr = input[i + 1].split(" ").map(Number)

    console.log(solution(n, m, arr))
}
