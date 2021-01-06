function solution(progresses, speeds) {
    let answer = [];
    let time_to_do = [];
    time_to_do.fill(0);
    for (let i = 0; i < progresses.length; i++) {
        time_to_do.push(Math.ceil((100 - progresses[i]) / speeds[i]));
    }
    let pivot = time_to_do[0];
    let cnt = 1;
    for (let i = 1; i < time_to_do.length; i++) {
        if (time_to_do[i] <= pivot) {
            cnt++;
        } else {
            pivot = time_to_do[i];
            answer.push(cnt);
            cnt = 1;
        }
    }
    answer.push(cnt);
    return answer;
}
