function solution(arr) {
    let answer = [];
    let flag = 0;
    for (let i = 0; i < arr.length; i++) {
        if (i === 0 || arr[i] !== arr[i - 1]) answer.push(arr[i]);
    }
    return answer;
}
