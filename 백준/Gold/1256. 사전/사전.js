const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const [n, m, k] = input[0].split(" ").map(Number)

function combination(n, r) {
    let answer = 1
    for (let i = n; i > n - r; i--) {
        answer *= i
    }
    for (let i = r; i > 0; i--) {
        answer /= i
    }

    return answer
}

function divide(a, z, k) {
    if (a === 0 || z === 0) {
        let answer = ""
        for (let i = 0; i < a; i++) {
            answer += "a"
        }
        for (let i = 0; i < z; i++) {
            answer += "z"
        }
        return answer
    }

    let target = combination(a + z - 1, Math.min(a - 1, z))

    if (target >= k) {
        return "a" + divide(a - 1, z, k)
    } else {
        return "z" + divide(a, z - 1, k - target)
    }
}

if (combination(n + m, Math.min(n, m)) < k) {
    console.log(-1)
} else {
    console.log(divide(n, m, k))
}
