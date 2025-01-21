function solution(friends, gifts) {
    const graph = getArray(friends.length, friends.length, 0);
    const friendArray = getArray(friends.length, 2, 0);
    
    
    gifts.forEach((value, index) => {
        friend1 = value.split(' ')[0];
        friend2 = value.split(' ')[1];
        firstIndex = friends.indexOf(friend1);
        secondIndex = friends.indexOf(friend2);
        graph[firstIndex][secondIndex]++;
        friendArray[firstIndex][0]++;
        friendArray[secondIndex][1]++;
    })
    
    let maxans = 0;
    
    for(let i = 0; i < friends.length; i++){
        let cnt = 0;
        for(let j = 0; j < friends.length; j++){
            if(i == j){
                continue;
            }
            if(graph[i][j] > graph[j][i]){
                cnt++;
            }
            else if(graph[i][j] == graph[j][i]){
                gift1 = friendArray[i][0] - friendArray[i][1];
                gift2 = friendArray[j][0] - friendArray[j][1];
                if(gift1 > gift2){
                    cnt++;
                }
            }
        }
        maxans = Math.max(maxans, cnt);
    }
    return maxans;
}

function getArray(r, c, value){
    const result = new Array(r);
    for(let i = 0; i < r; i++){
        result[i] = new Array(c).fill(value);
    }
    return result;
}