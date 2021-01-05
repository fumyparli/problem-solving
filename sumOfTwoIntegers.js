function solution(a, b) {
    let answer = 0;
    let c = Math.max(a, b);
    a = Math.min(a, b);
    for (let i = a; i <= c; i++) {
        answer += i;
    }
    return answer;
}
