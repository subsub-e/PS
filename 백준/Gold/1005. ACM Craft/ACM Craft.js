const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


let t = Number(input.shift());
let ind = 0;


function solution(){
    const [n, m] = input[ind++].split(' ').map(Number);
    const graph = Array.from({length : n + 1}, () => []);
    let sum = Array(n + 1).fill(0);
    let ans = Array(n + 1).fill(0);
    let indig = Array(n + 1).fill(0);
    let q = [];

    const sumArr = input[ind++].split(' ').map(Number);
    for(let i = 0; i < sumArr.length; i++){
        sum[i + 1] = sumArr[i];
    }

    for(let i = ind; i < ind + m; i++){
        const [pa, ch] = input[i].split(' ').map(Number);
        graph[pa].push(ch);
        indig[ch]++;
    }

    ind += m;

    for(let i = 1; i <= n; i++){
        if(indig[i] === 0){
            ans[i] = sum[i];
            q.push(i);
        }
    }

    let qind = 0;
    while(q.length > qind){
        let now = q[qind++];
        
        for(const next of graph[now]){
            indig[next]--;
            ans[next] = Math.max(ans[next], sum[next] + ans[now]);
            if(indig[next] === 0){
                q.push(next);
            }
        }
    }

    const ansStr = Number(input[ind++]);
    ind = ind;
    //console.log(ans);
    console.log(ans[ansStr]);
}

while(t--){
    solution();
}