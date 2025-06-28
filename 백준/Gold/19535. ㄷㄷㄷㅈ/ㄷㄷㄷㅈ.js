const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const N = parseInt(input[0])
const incidenceLi = Array.from({ length: N + 1 }, () => [])
const edgeLi = []

for (let i = 1; i < N; i++) {
    const [u, v] = input[i].split(" ").map(Number)
    incidenceLi[u].push(v)
    incidenceLi[v].push(u)
    edgeLi.push([u, v])
}

function comb3(n) {
    if (n < 3) return 0
    return (n * (n - 1) * (n - 2)) / 6
}

let cntG = 0
let cntD = 0

// G (정삼각형 모양)
for (let i = 1; i <= N; i++) {
    cntG += comb3(incidenceLi[i].length)
}

// D (갈고리 모양)
for (const [u, v] of edgeLi) {
    cntD += (incidenceLi[u].length - 1) * (incidenceLi[v].length - 1)
}

// 결과 판단
if (cntD > cntG * 3) {
    console.log("D")
} else if (cntD < cntG * 3) {
    console.log("G")
} else {
    console.log("DUDUDUNGA")
}
