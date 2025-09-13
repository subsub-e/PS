const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split("\n")

const n = Number(input.shift())

const graph = Array.from({ length: n + 1 }, () => [])
const arr = []

for (let i = 0; i < n; i++) {
    arr.push(input[i].split(" ").map(Number))
}

const answer = new Array(n + 1).fill(-1)
const rumorCnt = new Array(n + 1).fill(0)

// M (최초 유포자 수) 읽기
const m = Number(input[n])
// 루머 최초 유포자들 읽기
const rumor = input[n + 1].split(" ").map(Number)

// 그래프 구성
for (let i = 0; i < arr.length; i++) {
    for (let now of arr[i]) {
        if (now === 0) {
            break
        }
        graph[i + 1].push(now)
    }
}

let q = []
let qIndex = 0 // 큐의 현재 읽기 위치
let t = 0

// 초기 루머 유포자들을 큐에 추가
for (let now of rumor) {
    q.push(now)
    answer[now] = 0
}

while (qIndex < q.length) {
    let temp = []
    let currentLevelSize = q.length - qIndex // 현재 레벨의 크기

    // 현재 시간에 루머를 가진 모든 사람들 처리
    for (let i = 0; i < currentLevelSize; i++) {
        let x = q[qIndex++] // 인덱스를 사용해 큐에서 읽기

        for (let now of graph[x]) {
            if (answer[now] === -1) {
                // 아직 루머를 믿지 않는 사람
                rumorCnt[now]++
                // 절반 이상의 친구가 루머를 믿으면 다음 시간에 루머를 믿게 됨
                if (rumorCnt[now] >= Math.ceil(graph[now].length / 2)) {
                    temp.push(now)
                }
            }
        }
    }

    // 다음 시간으로 넘어가기
    if (temp.length > 0) {
        t++
        for (let person of temp) {
            if (answer[person] === -1) {
                // 중복 체크
                answer[person] = t
                q.push(person)
            }
        }
    }
}

answer.shift()
console.log(answer.join(" "))
