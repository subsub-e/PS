const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const [n, m, k] = input.shift().split(' ').map(Number);
let fireballs = [];
let dx = [-1, -1, 0, 1, 1, 1, 0, -1];
let dy = [0, 1, 1, 1, 0, -1, -1, -1];
let firemap = new Map();

for(let i = 0; i < m; i++){
  let k = input[i].split(' ').map(Number);
  fireballs.push({r : k[0], c : k[1], m : k[2], s : k[3], d : k[4]});
}

function convert(value){
  if(value < 0){
    return n + (value % n);
  }
  else{
    let temp = (value + n) % n;
    if(temp === 0){
      return n;
    }
    else{
      return temp;
    }
  }
}

function addValueToMap(key, value){
  if(!firemap.has(key)){
    firemap.set(key, []);
  }
  firemap.get(key).push(value);
}


function check(arr){
  let flag = 0;

  for(let i = 0; i < arr.length; i++){
    if(i === 0){
      flag = arr[i] % 2;
      continue;
    }
    if(flag !== arr[i] % 2){
      return false;
    }
  }
  return true;
}

for(let i = 0; i < k; i++){
  
  for(let j = 0; j < fireballs.length; j++){
    let dir = fireballs[j].d;
    let nx = fireballs[j].r + fireballs[j].s * dx[dir];
    let ny = fireballs[j].c + fireballs[j].s * dy[dir];
    nx = convert(nx);
    ny = convert(ny);
    fireballs[j].r = nx;
    fireballs[j].c = ny;
    addValueToMap(`${nx},${ny}`, fireballs[j]);
  }

  fireballs = [];

  for (let [key, arr] of firemap) {
    let sumM = 0;
    let sumS = 0;
    

    if(arr.length >= 2){
      let dirArray = [];

      for(let i = 0; i < arr.length; i++){
        sumM += arr[i].m;
        sumS += arr[i].s;
        dirArray.push(arr[i].d);
      }

      sumM = Math.floor(sumM / 5);
      sumS = Math.floor(sumS / arr.length);

      if(sumM === 0){
        continue;
      }

      if(check(dirArray)){
        for(let i = 0; i <= 6; i += 2){
          fireballs.push({r : arr[0].r, c : arr[0].c, m : sumM, s : sumS, d : i});
        }
      }
      else{
        for(let i = 1; i <= 7; i += 2){
          fireballs.push({r : arr[0].r, c : arr[0].c, m : sumM, s : sumS, d : i});
        }
      }
    }
    else{
      fireballs.push(...arr);
    }
  }
  firemap.clear()
}

let ans = 0;
for(let i = 0; i < fireballs.length; i++){
  ans += fireballs[i].m;
}

console.log(ans);