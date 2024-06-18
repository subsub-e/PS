function solution(numbers) {
    let sum = 0;
    for(x of numbers){
        sum += x;
    }
    return sum / numbers.length;
}