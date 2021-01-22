function solution(n) {
    let answer = 0;
    while (true) {
        if (n === 0) break;
        answer += n % 2;
        n = Math.floor(n / 2);
    }
    return answer;
}
