const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

let [n, m] = input.shift().split(" ").map(Number)
m--

const position = input.shift().split(" ").map(Number)
const energy = input.shift().split(" ").map(Number)

const answer = []

let low = m
let high = m
let l = position[m] - energy[m]
let h = position[m] + energy[m]
let minAns = 1e9
let maxAns = 0

while (1) {
    for (let i = low - 1; i >= 0; i--) {
        if (position[i] >= l) {
            minAns = Math.min(minAns, position[i] - energy[i])
            maxAns = Math.max(maxAns, position[i] + energy[i])
            low = i
        } else {
            break
        }
    }

    for (let i = high + 1; i < n; i++) {
        if (position[i] <= h) {
            minAns = Math.min(minAns, position[i] - energy[i])
            maxAns = Math.max(maxAns, position[i] + energy[i])
            high = i
        } else {
            break
        }
    }

    if (l === minAns && h === maxAns) {
        break
    }

    l = minAns
    h = maxAns
}

for (let i = low; i <= high; i++) {
    answer.push(i + 1)
}

console.log(answer.join(" "))
