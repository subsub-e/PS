const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const [n, m] = input.shift().split(" ").map(Number)

let minus = []
let plus = []

const arr = input.shift().split(" ").map(Number)
let answer = 0

for (let i = 0; i < arr.length; i++) {
    if (arr[i] < 0) {
        minus.push(arr[i])
    } else {
        plus.push(arr[i])
    }
}

minus.sort((a, b) => b - a)
plus.sort((a, b) => a - b)

// console.log(minus)
// console.log(plus)

if (minus.length === 0) {
    answer += plus.pop()
    for (let i = 0; i < m - 1; i++) {
        if (plus.length === 0) {
            break
        }
        plus.pop()
    }
} else if (plus.length === 0) {
    answer += Math.abs(minus.pop())
    for (let i = 0; i < m - 1; i++) {
        if (minus.length === 0) {
            break
        }
        minus.pop()
    }
} else if (plus[plus.length - 1] > Math.abs(minus[minus.length - 1])) {
    answer += plus.pop()
    for (let i = 0; i < m - 1; i++) {
        if (plus.length === 0) {
            break
        }
        plus.pop()
    }
} else {
    answer += Math.abs(minus.pop())
    for (let i = 0; i < m - 1; i++) {
        if (minus.length === 0) {
            break
        }
        minus.pop()
    }
}

while (plus.length > 0) {
    answer += plus.pop() * 2
    for (let i = 0; i < m - 1; i++) {
        if (plus.length === 0) {
            break
        }
        plus.pop()
    }
}

while (minus.length > 0) {
    answer += Math.abs(minus.pop()) * 2
    for (let i = 0; i < m - 1; i++) {
        if (minus.length === 0) {
            break
        }
        minus.pop()
    }
}

console.log(answer)
