// class MinHeap{

//     constructor(){
//         this.heap = [];
//     }

//     getLength(){
//         return this.heap.length;
//     }

//     push(value){
//         this.heap.push(value);
        
//         let i = this.heap.length - 1;
//         let parentI = Math.floor((i - 1) / 2);
//         while(i > 0 && heap[parentI] > heap[i]){
//             swap(i, parentI);
//             i = parentI;
//             parentI = Math.floor((i - 1) / 2);
//         }
//     }

//     pop(){
//         if(this.heap.length === 1){
//             return this.heap.pop();
//         }

//         const result = this.heap[0];
//         this.heap[0] = this.heap.pop();
//         let i = 0;

//         while(true){
//             const leftI = i * 2 + 1;
//             const rightI = i * 2 + 2;

//             if(leftI >= this.heap.length){
//                 break;
//             }

//             let nextI = i;

//             if(this.heap[nextI] > this.heap[leftI]){
//                 nextI = leftI;
//             }
//             if(rightI < this.heap.length && this.heap[nextI] > this.heap[rightI]){
//                 nextI = rightI;
//             }
//             if(nextI === i){
//                 break;
//             }
//             this.swap(i, nextI);
//             i = nextI;
//         }
//         return result;
//     }

//     swap(a, b){
//         const temp = this.heap[a];
//         this.heap[a] = this.heap[b];
//         this.heap[b] = temp;
//     }
// }



const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");




const n = Number(input.shift());
let uf = Array(n + 1).fill(0);
const pq = [];

for(let i = 1; i <= n; i++){
    uf[i] = i;
}

function find(x){
    if(uf[x] === x){
        return x;
    }
    return uf[x] = find(uf[x]);
}

function Union(x, y){
    let X = find(x);
    let Y = find(y);

    if(X < Y){
        uf[Y] = X;
    }
    else{
        uf[X] = Y;
    }
}

for(let i = 0; i < n; i++){
    pq.push({a : i + 1, b : n + 1, cost : Number(input[i])});
}

for(let i = n; i < n * 2; i++){
    const data = input[i].split(' ').map(Number);
    for(let j = 0; j < n; j++){
        if(i - n === j){
            continue;
        }
        pq.push({a : i - n + 1, b : j + 1, cost : data[j]});
    }
}

pq.sort((a, b) => a.cost - b.cost);

let answer = 0;

for(let i = 0; i < pq.length; i++){
    if(find(pq[i].a) !== find(pq[i].b)){
        Union(pq[i].a, pq[i].b);
        answer += pq[i].cost;
    }
}

console.log(answer);