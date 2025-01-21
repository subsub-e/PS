function solution(video_len, pos, op_start, op_end, commands) {
    let videoTimeArray = video_len.split(':');
    let videoTime = Number(videoTimeArray[0]) * 60 + Number(videoTimeArray[1]);
    let posTimeArray = pos.split(':');
    let posTime = Number(posTimeArray[0]) * 60 + Number(posTimeArray[1]);
    let startTimeArray = op_start.split(':');
    let startTime = Number(startTimeArray[0]) * 60 + Number(startTimeArray[1]);
    let endTimeArray = op_end.split(':');
    let endTime = Number(endTimeArray[0]) * 60 + Number(endTimeArray[1]);
    
    
    commands.forEach((element, index) => {
        if(posTime >= startTime && posTime <= endTime){
            posTime = endTime;
        }
        if(element == "next"){
            posTime += 10;
            if(posTime > videoTime){
                posTime = videoTime;
            }
        }
        else{
            posTime -= 10;
            if(posTime < 0){
                posTime = 0;
            }
        }
    })
    if(posTime >= startTime && posTime <= endTime){
        posTime = endTime;
    }
    //console.log(posTime);
    let answer = "";
    answer += Math.floor((posTime / 60)).toString().padStart(2, '0');
    answer += ':';
    answer += (posTime % 60).toString().padStart(2, '0');
    
    //toString(pos / 60) + ":" + toString(pos % 60);
    return answer;
}