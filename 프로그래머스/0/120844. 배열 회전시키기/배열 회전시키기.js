function solution(numbers, direction) {
    let num = numbers;
    if(direction == "right"){
        let temp = numbers[numbers.length - 1];
        num.pop();
        num.unshift(temp);
    }
    else{
        let temp = numbers[0];
        num.shift();
        num.push(temp);
    }
    return num;
}