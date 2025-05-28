const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

let answer = 0
let [n, m, l] = input.shift().split(" ").map(Number)
const arr = input.shift().split(" ").map(Number)
const ani = []
for (let i = 0; i < input.length; i++) {
    ani.push(input[i].split(" ").map(Number))
}

arr.sort((a, b) => a - b)

for (let i = 0; i < ani.length; i++) {
    let [x, y] = ani[i]

    let left = 0
    let right = n - 1
    while (left <= right) {
        let mid = Math.floor((left + right) / 2)
        //console.log(x, y, mid, arr[mid])
        let dis = Math.abs(arr[mid] - x) + y
        if (l >= dis) {
            answer++
            break
        }
        if (x < arr[mid]) {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }
}

console.log(answer)
