const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const n = Number(input.shift());

let arr = input[0].split(' ').map(Number);

let ans1, ans2;
let minans = Number.MAX_VALUE;

let left = 0;
let right = n - 1;

while(left < right){
    if(arr[right] + arr[left] == 0){
        ans1 = arr[left];
        ans2 = arr[right];
        break;
    }
    else if(arr[right] + arr[left] < 0){
        if(minans > Math.abs(arr[right] + arr[left])){
            minans = Math.abs(arr[right] + arr[left]);
            ans1 = arr[left];
            ans2 = arr[right];
        }
        left++;
    }
    else{
        if(minans > Math.abs(arr[right] + arr[left])){
            minans = Math.abs(arr[right] + arr[left]);
            ans1 = arr[left];
            ans2 = arr[right];
        }
        right--;
    }
}

if(arr[0] >= 0){
    console.log(arr[0], arr[1]);
    process.exit();
}

if(arr[n-1] <= 0){
    console.log(arr[n-2], arr[n-1]);
    process.exit();
}

console.log(ans1, ans2);