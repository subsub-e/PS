function solution(players, callings) {
    var answer = [];
    const mapName = new Map();
    const mapIndex = new Map();
    
    players.forEach((value, index) => {
        mapName.set(value, index);
        mapIndex.set(index, value);
    })
    
    
    for(const name of callings){
        let tempIndex = mapName.get(name);
        let tempName = mapIndex.get(tempIndex-1);
        mapName.set(name, tempIndex-1);
        mapIndex.set(tempIndex - 1, name);
        mapName.set(tempName, tempIndex);
        mapIndex.set(tempIndex, tempName);
        
    }
    
    
    for(let [key, value] of mapIndex){
        answer.push(value);
        //console.log(value);
    }
    return answer;
}