const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const [n, m] = input.shift().split(" ").map(Number)
const arr = input.map((v) => v.trim().split(""))
let coin = []
let dx = [-1, 0, 1, 0]
let dy = [0, -1, 0, 1]

for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
        if (arr[i][j] == "o") {
            coin.push([i, j])
            arr[i][j] = "."
        }
    }
}

let answer = 999
function func(arr1, arr2, cnt) {
    if (cnt <= 10) {
        for (let i = 0; i < 4; i++) {
            let newArr1 = [arr1[0] + dx[i], arr1[1] + dy[i]]
            let newArr2 = [arr2[0] + dx[i], arr2[1] + dy[i]]
            let flag1 = false
            let flag2 = false
            if (
                0 <= newArr1[0] &&
                newArr1[0] < n &&
                0 <= newArr1[1] &&
                newArr1[1] < m
            ) {
                flag1 = true
            }
            if (
                0 <= newArr2[0] &&
                newArr2[0] < n &&
                0 <= newArr2[1] &&
                newArr2[1] < m
            ) {
                flag2 = true
            }
            if (flag1 ^ flag2) {
                if (cnt < answer) {
                    answer = cnt
                    return
                }
            } else if (flag1 && flag2) {
                if (arr[newArr1[0]][newArr1[1]] == "#") {
                    newArr1 = arr1
                }
                if (arr[newArr2[0]][newArr2[1]] == "#") {
                    newArr2 = arr2
                }

                if (newArr1[0] != newArr2[0] || newArr1[1] != newArr2[1]) {
                    func(newArr1, newArr2, cnt + 1)
                }
            }
        }
    }
}

func(coin[0], coin[1], 1)
if (answer === 999) {
    console.log(-1)
} else {
    console.log(answer)
}
