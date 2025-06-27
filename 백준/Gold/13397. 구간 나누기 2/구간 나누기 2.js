const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const [n, m] = input.shift().split(" ").map(Number)
const arr = input[0].split(" ").map(Number)

function check(target) {
    let cnt = 0
    let minV = arr[0]
    let maxV = arr[0]

    for (let i = 0; i < arr.length; i++) {
        minV = Math.min(minV, arr[i])
        maxV = Math.max(maxV, arr[i])

        if (maxV - minV > target) {
            cnt++
            minV = arr[i]
            maxV = arr[i]
        }
    }

    return cnt < m
}

function solution() {
    let low = -1
    let high = 1e9
    let ans = 1e9

    while (low <= high) {
        let mid = Math.floor((low + high) / 2)
        if (check(mid)) {
            high = mid - 1
            ans = mid
        } else {
            low = mid + 1
        }
    }
    return ans
}

console.log(solution())
