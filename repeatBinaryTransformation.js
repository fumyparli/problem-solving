function solution(s) {
    var answer = [0, 0];
    while (true) {
        if (s === "1") {
            break;
        }
        let k = "";
        for (let i = 0; i < s.length; i++) {
            if (s[i] === "1") {
                k += s[i];
            } else {
                answer[1]++;
            }
        }
        s = k.length.toString(2);
        answer[0]++;
    }
    return answer;
}
