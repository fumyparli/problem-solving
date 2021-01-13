function solution(people, limit) {
    var answer = 0;
    let i = 0;
    let j = people.length - 1;
    people.sort((a, b) => a - b);
    let idx = people.length - 1;
    while (true) {
        if (i == j) {
            answer++;
            break;
        }
        if (i > j) break;
        answer++;
        if (people[i] + people[j] <= limit) {
            i++;
            j--;
        } else {
            j--;
        }
    }
    return answer;
}
