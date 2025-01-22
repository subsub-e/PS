const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


const [m, n, h] = input.shift().split(" ").map(Number);

let queue = [];
let visited = [...Array(h)].map((h) =>
    [...Array(n)].map((n) => Array(m).fill(0))
  );

const dir = [[-1, 0, 0], [1, 0, 0], [0, -1, 0], [0, 1, 0], [0, 0, -1], [0, 0, 1]];
let full = n * m * h;
let cnt = 0;
let z = 0;
let answer;


for(let i = 0; i < input.length; i++){
    let box = input[i].split(' ').map(Number);
    box.forEach((tomato, index) => {
        if(tomato === 1){
            visited[z][i % n][index] = 1;
            queue.push([i % n, index, z, 0]);
            cnt++;
        }
        else if(tomato === -1){
            visited[z][i % n][index] = 1;
            cnt++;
        }
    })
    if((i + 1) % n === 0){
        z++;
    }
}


let idx = 0;
while(queue.length != idx){
    let [x, y, z, day] = queue[idx];

    for(let i = 0; i < 6; i++){
        let nx = x + dir[i][0];
        let ny = y + dir[i][1];
        let nz = z + dir[i][2];

        if(0 <= nx && nx < n && 0 <= ny && ny < m && 0 <= nz && nz < h && !visited[nz][nx][ny]){
            visited[nz][nx][ny] = 1;
            queue.push([nx, ny, nz, day + 1]);
            cnt++;
        }
    }

    idx++;
    answer = day;
}


if(full === cnt){
    console.log(answer);
}
else{
    console.log(-1);
}