const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


const [n, m] = input[0].split(' ').map(Number);

const graph = Array.from({length : n + 1}, () => []);
let indig = Array(n + 1).fill(0);
let queue = [];

for(let i = 1; i <= m; i++){
    const [pa, ch] = input[i].split(' ').map(Number);
    graph[pa].push(ch);
    indig[ch]++;
}

for(let i = 1; i <= n; i++){
    if(indig[i] === 0){
        queue.push(i);
    }
}


let index = 0;
const result = [];

while(queue.length > index){
    let now = queue[index++];
    result.push(now);
    for(const next of graph[now]){
        indig[next]--;
        if(indig[next] === 0){
            queue.push(next);
        }
    }
}


console.log(...result);

