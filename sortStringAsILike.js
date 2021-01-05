function solution(strings, n) {
    let answer = [];
    let tmp = [];
    for (let i = 0; i < strings.length; i++) {
        tmp[i] = [strings[i][n], strings[i]];
    }
    tmp.sort();
    for (let i = 0; i < tmp.length; i++) {
        answer.push(tmp[i][1]);
    }
    return answer;
}
