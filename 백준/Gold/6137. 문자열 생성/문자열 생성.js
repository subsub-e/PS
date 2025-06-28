const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

let s = input.slice(1).map((_) => _.trim())

//console.log(input)
let ans = ""
let reall = 0
let realr = s.length - 1

function check() {
    let left = reall
    let right = realr

    while (left < right) {
        if (s[left] > s[right]) {
            return true
        } else if (s[left] < s[right]) {
            return false
        } else {
            left++
            right--
        }
    }
    return false
}

let cnt = 0

while (reall <= realr) {
    if (cnt !== 0 && cnt % 80 === 0) {
        ans += "\n"
    }

    if (s[reall] > s[realr]) {
        ans += s[realr]
        realr--
    } else if (s[reall] < s[realr]) {
        ans += s[reall]
        reall++
    } else {
        if (check()) {
            ans += s[realr]
            realr--
        } else {
            ans += s[reall]
            reall++
        }
    }
    cnt++
}

console.log(ans)
