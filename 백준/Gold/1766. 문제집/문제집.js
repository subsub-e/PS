
class MinHeap {
    constructor(){
        this.heap = [];
    }

    getLength(){
        return this.heap.length;
    }

    push(value){
        this.heap.push(value);
        let i = this.heap.length - 1;
        let parentI = Math.floor((i - 1) / 2);
        while(i > 0 && this.heap[parentI] > this.heap[i]){
            this.swap(i, parentI);
            i = parentI;
            parentI = Math.floor((i - 1) / 2);
        }
    }

    pop(){
        if(this.heap.length === 1){
            return this.heap.pop();
        }

        const result = this.heap[0];
        this.heap[0] = this.heap.pop();
        let i = 0;

        while(true){
            const leftI = i * 2 + 1;
            const rightI = i * 2 + 2;

            if(leftI >= this.heap.size){
                break;
            }

            let nextI = i;

            if(this.heap[nextI] > this.heap[leftI]){
                nextI = leftI;
            }

            if(rightI < this.heap.length && this.heap[nextI] > this.heap[rightI]){
                nextI = rightI;
            }
            
            if(nextI === i){
                break;
            }

            this.swap(nextI, i);
            i = nextI;

        }
        return result;
    }

    swap(a, b){
        const temp = this.heap[a];
        this.heap[a] = this.heap[b];
        this.heap[b] = temp;
    }
}


const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const [n, m] = input[0].split(' ').map(Number);

let pq = new MinHeap();

const graph = Array.from({length : n + 1}, () => []);
let indig = Array(n + 1).fill(0);

for(let i = 0; i < m; i++){
    const [left, right] = input[i + 1].split(' ').map(Number);
    graph[left].push(right);
    indig[right]++;
}

for(let i = 1; i <= n; i++){
    if(indig[i] === 0){
        pq.push(i);
    }
}

const result = [];

while(pq.getLength()){
    let now = pq.pop();
    result.push(now);

    for(const next of graph[now]){
        indig[next]--;
        if(indig[next] === 0){
            pq.push(next);
        }
    }
}

console.log(result.join(' '));