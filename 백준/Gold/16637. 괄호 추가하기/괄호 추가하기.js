const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const n = Number(input.shift())

let str = input.shift()

let minAns = Number.MIN_SAFE_INTEGER

let nums = []
let oper = []

for (let i = 0; i < n; i++) {
    if (i % 2 == 0) {
        nums.push(Number(str[i]))
    } else {
        oper.push(str[i])
    }
}

function calc(a, b, c) {
    if (c === "+") {
        return a + b
    } else if (c === "*") {
        return a * b
    } else {
        return a - b
    }
}

function func(index, answer) {
    if (index === nums.length - 1) {
        minAns = Math.max(minAns, answer)
        return
    }

    func(index + 1, calc(answer, nums[index + 1], oper[index]))
    if (index + 2 < nums.length) {
        const temp = calc(nums[index + 1], nums[index + 2], oper[index + 1])
        func(index + 2, calc(answer, temp, oper[index]))
    }
}

func(0, nums[0])

console.log(minAns)
