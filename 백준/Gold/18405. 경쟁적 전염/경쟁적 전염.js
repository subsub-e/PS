const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


const [n, m] = input.shift().split(' ').map(Number);
const graph = [];
let queue = [];

for(let i = 0; i < n; i++){
    const line = input[i].split(' ').map(Number);
    for(let j = 0; j < n; j++){
        if(line[j] != 0){
            queue.push([line[j], i, j, 0]);
        }
    }
    graph.push(line);
}

const [s, tar_x, tar_y] = input[n].split(' ').map(Number);

queue.sort((a, b) => a[0] - b[0]);

const dx = [-1, 0, 1, 0];
const dy = [0, -1, 0, 1];


function bfs(){
    let index = 0;
    let t = 0;

    while(queue.length > index){
        const [target, x, y, now_t] = queue[index++];

        if(now_t === s){
            return;
        }

        for(let i = 0; i < 4; i++){
            let nx = x + dx[i];
            let ny = y + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < n && graph[nx][ny] === 0){
                //console.log(t, target, nx, ny);
                graph[nx][ny] = target;
                queue.push([target, nx, ny, now_t + 1]);
            }
        }
    }
}

bfs();

//console.log(graph);

console.log(graph[tar_x - 1][tar_y - 1]);