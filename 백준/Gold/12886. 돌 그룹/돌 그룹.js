const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


const [n, m, t] = input[0].split(' ').map(Number).sort((a,b) => a- b);
const sum = n + m + t;

let visited = Array.from({length : 1501}, () => Array.from({length : 1501}).fill(0));

let q = [];

function bfs(){
  let index = 0;
  while(q.length > index){
    const [one, two] = q[index++];

    let arr = [one, two, sum - one - two].sort((a, b) => a - b);

    for(let i = 0; i < 3; i++){
      for(let j = i + 1; j < 3; j++){
        if(arr[i] < arr[j]){
          let num1 = arr[i] * 2;
          let num2 = arr[j] - arr[i];
          let a = Math.min(num1, num2);
          let b = Math.max(num1, num2);
          if(!visited[a][b]){
            q.push([a, b]);
            visited[a][b] = 1;
          }
        }
      }
    }
  }
}

function check(){
  if((n + m + t) % 3 !== 0){
    return 0;
  }
  else{
    q.push([n, m]);
    visited[n][m] = 1;
    bfs();
  } 
  return visited[sum / 3][sum / 3];
}



console.log(check());