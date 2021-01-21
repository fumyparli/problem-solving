function makeArr(s) {
    let tmp = "";
    let arr = [];
    for (let i = 0; i < s.length; i++) {
        if (s[i] !== "+" && s[i] !== "-" && s[i] !== "*") {
            tmp += s[i];
        } else {
            arr.push(tmp);
            arr.push(s[i]);
            tmp = "";
        }
    }
    arr.push(tmp);
    return [...arr];
}

function foo(oper, e) {
    let arr = makeArr(e);
    for (let i = 0; i < oper.length; i++) {
        for (let j = 1; j < arr.length - 1; j++) {
            let result;
            let flag = 0;
            if (oper[i] === "-" && arr[j] === "-") {
                flag = 1;
                result = +arr[j - 1] - +arr[j + 1];
            }
            if (oper[i] === "+" && arr[j] === "+") {
                flag = 1;
                result = +arr[j - 1] + +arr[j + 1];
            }
            if (oper[i] === "*" && arr[j] === "*") {
                flag = 1;
                result = +arr[j - 1] * +arr[j + 1];
            }
            if (flag === 1) {
                arr[j] = result;
                arr.splice(j - 1, 1);
                arr.splice(j, 1);
                j--;
            }
        }
    }
    return Math.abs(arr[0]);
}

function solution(expression) {
    let operList = ["+-*", "+*-", "*-+", "*+-", "-+*", "-*+"];
    let answer = 0;
    for (let i = 0; i < 6; i++) {
        let tmp = foo(operList[i], expression);
        if (answer < tmp) {
            answer = tmp;
        }
    }
    return answer;
}
