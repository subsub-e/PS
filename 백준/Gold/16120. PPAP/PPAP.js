const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const str = input[0]

let arr = []
let flag = 0

for (let i = 0; i < str.length; i++) {
    if (str[i] === "A") {
        if (i === str.length - 1) {
            console.log("NP")
            flag = 1
            break
        }
        if (str[i + 1] === "A") {
            console.log("NP")
            flag = 1
            break
        }
        if (arr.length < 2) {
            console.log("NP")
            flag = 1
            break
        }
        arr.pop()
        arr.pop()
        arr.push("P")
        i++
    } else {
        arr.push("P")
    }
}

if (flag === 0) {
    if (arr.length !== 1) {
        console.log("NP")
    } else {
        console.log("PPAP")
    }
}
