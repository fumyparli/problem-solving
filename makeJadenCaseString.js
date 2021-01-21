function solution(s) {
    let answer = "";
    let k = "";
    for (let i = 0; i <= s.length; i++) {
        if (s[i] === " " || i === s.length) {
            if (k !== "") {
                answer += k[0].toUpperCase() + k.substring(1).toLowerCase();
                k = "";
            }
            if (i !== s.length) answer += " ";
        } else {
            k += s[i];
        }
    }
    return answer;
}
