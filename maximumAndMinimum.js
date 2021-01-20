function solution(s) {
    let k = s.split(" ")[0];
    var answer = [k, k];
    s.split(" ").forEach((a) => {
        if (answer[0] > +a) {
            answer[0] = +a;
        }
        if (answer[1] < +a) {
            answer[1] = +a;
        }
    });
    return answer.join(" ");
}
