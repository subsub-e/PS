const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const n = Number(input.shift())
const map = []
let visited = []

for (let i = 0; i < n; i++) {
    let str = input[i]

    for (let j = 0; j < str.length; j++) {
        const obj = map.find(({ key }) => key === str[j])
        const value = Math.pow(10, str.length - j - 1)
        if (!obj) {
            map.push({ key: str[j], value })
        } else {
            obj.value += value
        }
        if (j == 0) {
            visited[str[j]] = 1
        }
    }
}

map.sort((a, b) => b.value - a.value)

const ans = new Map()

if (map.length === 10) {
    for (let i = 9; i >= 0; i--) {
        const key = map[i].key
        if (!visited[key]) {
            ans.set(key, 0)
            break
        }
    }
}

let num = 9

map.forEach(({ key, value }) => {
    if (!ans.has(key)) {
        ans.set(key, num--)
    }
})

let sum = 0

map.forEach(({ key, value }) => {
    sum += value * ans.get(key)
})

console.log(sum)
