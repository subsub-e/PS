const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


const map = new Map();
let cnt = 0;
let rightCnt = 0;

for(let i = 1; i <= input[0]; i++){
    const [n, left, right] = input[i].split(' ').map(Number);
    map.set(n, {left, right});
}

function inorder(now){
    const {left, right} = map.get(now);
    if(left > 0){
        cnt++;
        inorder(left);
    }
    if(right > 0){
        cnt++;
        inorder(right);
    }
}

inorder(1);

let now = 1;

while(true){
    const {right} = map.get(now);
    if(right === -1){
        break;
    }
    rightCnt++;
    now = right;
}

console.log(cnt * 2 - rightCnt);