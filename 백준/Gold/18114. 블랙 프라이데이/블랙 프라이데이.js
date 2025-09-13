const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const [n, m] = input.shift().split(" ").map(Number)
const arr = input[0].split(" ").map(Number)

function find(x) {
    if (x === m) {
        return 1
    }
    return 0
}

function solution() {
    arr.sort((a, b) => a - b)
    for (let i = 0; i < arr.length; i++) {
        let left = i + 1
        let right = n - 1

        while (left <= right) {
            if (left === right) {
                break
            }

            let a = arr[i]
            let b = arr[left]
            let c = arr[right]
            if (
                find(a) ||
                find(b) ||
                find(c) ||
                find(a + b) ||
                find(b + c) ||
                find(a + c) ||
                find(a + b + c)
            ) {
                console.log(1)
                return
            }

            if (a + b + c < m) {
                left++
            } else {
                right--
            }
        }
    }
    console.log(0)
}

solution()
