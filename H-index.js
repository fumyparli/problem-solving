function solution(citations) {
    var answer = 0;
    citations.sort((a, b) => a - b);
    const len = citations.length;
    for (let i = 0; i < citations.length; i++) {
        for (let j = citations[i]; j > 0; j--) {
            if (len - i >= j) {
                if (answer < j) answer = j;
                break;
            }
        }
    }
    return answer;
}
