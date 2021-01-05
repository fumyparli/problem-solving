function solution(n) {
    console.log([...n]);
    let answer = parseInt(
        n.toString(3).split("").reverse().join().replace(/,/gi, ""),
        3
    );
    return answer;
}
