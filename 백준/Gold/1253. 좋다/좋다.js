const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


const n = Number(input.shift());

let arr = input[0].split(' ').map(Number);

let ans = 0;

arr.sort((a, b) => a - b);

for(let i = 0; i < n; i++){
    let left = 0;
    let right = n - 1;
    while(left < right){
        if(i === left){
            left++;
            continue;
        }
        if(i === right){
            right--;
            continue;
        }
        if(arr[left] + arr[right] === arr[i]){
            ans++;
            break;
        }
        if(arr[left] + arr[right] > arr[i]){
            right--;
            continue;
        }
        if(arr[left] + arr[right] < arr[i]){
            left++;
            continue;
        }
    }
}

console.log(ans);