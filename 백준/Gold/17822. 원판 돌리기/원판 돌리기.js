const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
let input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const [n, m, t] = input.shift().split(" ").map(Number)
const arr = []
const spinArr = []

for (let i = 0; i < n; i++) {
    arr.push(input[i].split(" "))
}

for (let i = n; i < t + n; i++) {
    spinArr.push(input[i].split(" ").map(Number))
}

function spin(now) {
    const [x, d, k] = spinArr[now]
    if (d === 0) {
        for (let i = 1; i <= n; i++) {
            if (i % x === 0) {
                let tempArr = []
                for (let j = 0; j < m; j++) {
                    tempArr.push(arr[i - 1][(m - k + j) % m])
                }
                arr[i - 1] = tempArr
            }
        }
    } else {
        for (let i = 1; i <= n; i++) {
            if (i % x === 0) {
                let tempArr = []
                for (let j = 0; j < m; j++) {
                    tempArr.push(arr[i - 1][(k + j) % m])
                }
                arr[i - 1] = tempArr
            }
        }
    }
}

function find() {
    let findArr = []

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (arr[i][j] !== "x" && arr[i][j] === arr[i][(j + 1) % m]) {
                findArr.push([i, j])
                findArr.push([i, (j + 1) % m])
            }
        }
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n - 1; j++) {
            if (arr[j][i] !== "x" && arr[j][i] === arr[j + 1][i]) {
                findArr.push([j, i])
                findArr.push([j + 1, i])
            }
        }
    }

    // console.log(findArr.length)

    if (findArr.length > 0) {
        for (let i = 0; i < findArr.length; i++) {
            let [x, y] = findArr[i]
            arr[x][y] = "x"
        }
    } else {
        calculate()
    }
}

function calculate() {
    let avg = 0
    let cnt = 0

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (arr[i][j] !== "x") {
                avg += Number(arr[i][j])
                cnt++
            }
        }
    }
    avg = avg / cnt
    // console.log(avg)
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (arr[i][j] !== "x") {
                if (avg > Number(arr[i][j])) {
                    arr[i][j] = String(Number(arr[i][j]) + 1)
                } else if (avg < Number(arr[i][j])) {
                    arr[i][j] = String(Number(arr[i][j]) - 1)
                }
            }
        }
    }
}

for (let i = 0; i < t; i++) {
    spin(i)
    find()
    // for (let i = 0; i < n; i++) {
    //     console.log(arr[i])
    // }
    // console.log("\n")
}

let answer = 0
for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
        if (arr[i][j] !== "x") {
            answer += Number(arr[i][j])
        }
    }
}
console.log(answer)
