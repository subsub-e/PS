const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const n = Number(input.shift());

let arr = input.map(Number);

arr.sort((a, b) => a - b);

let sumArr = new Array();

for(let i = 0; i < n; i++){
    for(let j = 0; j < n; j++){
        sumArr.push(arr[i] + arr[j]);
    }
}

sumArr.sort((a, b) => a - b);
let maxans = 0;
//console.log(sumArr);


function binary_serach(x){
    let left = 0;
    let right = sumArr.length - 1;
    while(left < right){
        // console.log(left);
        // console.log(right);
        let mid = Math.floor((left + right) / 2);
        if(sumArr[mid] == x){
            return true;
        }
        else if(sumArr[mid] < x){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return false;
}

for(let i = n - 1; i >= 0; i--){
    for(let j = 0; j < i; j++){
        let temp = arr[i] - arr[j];
        if(binary_serach(temp)){
            //console.log(temp);
            maxans = Math.max(maxans, arr[i]);
        }
    }
}

console.log(maxans);