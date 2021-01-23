function solution(skill, skill_trees) {
    let answer = 0;
    let array = "";
    skill_trees.forEach((e) => {
        array = "";
        for (let i = 0; i < e.length; i++) {
            for (let j = 0; j < skill.length; j++) {
                if (e[i] === skill[j]) {
                    array += skill[j];
                    break;
                }
            }
        }
        console.log(array);
        let flag = 0;
        for (let i = 0; i < array.length; i++) {
            if (array[i] !== skill[i]) {
                flag = 1;
            }
        }
        if (flag == 0) {
            answer++;
        }
    });
    return answer;
}
