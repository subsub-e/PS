const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


const n = Number(input.shift());

const [mp, mf, ms, mv] = input.shift().split(' ').map(Number);

const arr = [];

for(let i = 0; i < n; i++){
    arr.push(input[i].split(' ').map(Number));
}

let visited = Array(n).fill(0);

let s = [];
let answer = [];

let min_cost = 1e9;

function calculate(){
    let temp_mp = 0;
    let temp_mf = 0;
    let temp_ms = 0;
    let temp_mv = 0;
    let cost = 0;

    for(let i = 0; i < s.length; i++){
        temp_mp += arr[s[i]][0];
        temp_mf += arr[s[i]][1];
        temp_ms += arr[s[i]][2];
        temp_mv += arr[s[i]][3];
        cost += arr[s[i]][4];
    }

    if(temp_mp >= mp && temp_mf >= mf && temp_ms >= ms && temp_mv >= mv){
        if(min_cost > cost){
            min_cost = cost;
            answer = [[...s]];
        } else if(min_cost === cost) {
            answer.push([...s]);
        }
    }
}

function solution(now, siz){
    if(s.length === siz){
        calculate();
        return;
    }

    for(let i = now; i < n; i++){
        if(!visited[i]){
            visited[i] = 1;
            s.push(i);
            solution(i + 1, siz);
            s.pop();
            visited[i] = 0;
        }
    }
}

for(let i = 0; i < n; i++){
    solution(0, i + 1);
}



if(min_cost === 1e9){
    console.log(-1);
}
else {
    answer.sort((a, b) => {
        for (let i = 0; i < Math.min(a.length, b.length); i++) {
            if (a[i] !== b[i]) return a[i] - b[i];
        }
        return a.length - b.length;
    });

    console.log(min_cost);
    //console.log(answer);
    console.log(answer[0].map(v => v + 1).join(' '));
}
