class Node {
  constructor(value = "") {
    this.value = value;
    this.children = [];
  }
}

class Trie {
  constructor() {
    this.root = new Node();
    this.output = "";
  }
  insert(line) {
    let currentNode = this.root;
    const words = line.split(" ");
    words.shift();
    for (const word of words) {
      if (!currentNode.children[word]) {
        currentNode.children[word] = new Node(currentNode.value + word);
      }
      currentNode = currentNode.children[word];
    }
  }
  makeOutputForm(length, curNode) {
    if (length === 0) {
      curNode = this.root;
    }
    for (const child of Object.keys(curNode.children).sort()) {
      this.output += "--".repeat(length) + child + "\n";
      this.makeOutputForm(length + 1, curNode.children[child]);
    }
  }
  print() {
    this.makeOutputForm(0);
    console.log(this.output.trim());
  }
}

const solution = (input) => {
  const trie = new Trie();
  const loop = Number(input.shift());
  for (let i = 0; i < loop; i++) {
    trie.insert(input[i]);
  }
  trie.print();
};

const readline = require("readline");
let input = [];
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on("line", (line) => {
  input.push(line);
  if (input.length === Number(input[0]) + 1) {
    solution(input);
  }
});