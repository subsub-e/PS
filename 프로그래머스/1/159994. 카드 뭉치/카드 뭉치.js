let flag = 0;

function simulate(arr1, arr2, goal, target){
    
    if(flag === 1){
        return;
    }
    
    if(target.join('') === goal.join('')){
        flag = 1;
        return;
    }
    
    if(arr1.length !== 0){
        let word = arr1.shift();
        target.push(word);
        simulate(arr1, arr2, goal, target);
        target.pop();
        arr1.unshift(word);
    }
    
    if(arr2.length !== 0){
        let word = arr2.shift();
        target.push(word);
        simulate(arr1, arr2, goal, target);
        target.pop();
        arr2.unshift(word);
    }
    
    return;
}


function solution(cards1, cards2, goal) {
    simulate(cards1, cards2, goal, []);
    
    if(flag){
        return "Yes";
    }
    else{
        return "No";
    }
}