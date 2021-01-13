function isRightP(u) {
    let stack = [];
    for (let i = 0; i < u.length; i++) {
        if (stack[stack.length - 1] === "(" && u[i] == ")") stack.pop();
        else stack.push(u[i]);
    }
    if (stack.length === 0) return 1;
    else return 0;
}

function getReverse(u) {
    u.shift();
    u.pop();
    for (let i = 0; i < u.length; i++) {
        if (u[i] === "(") u[i] = ")";
        else u[i] = "(";
    }
    return u;
}

function getP(p) {
    let u = [];
    let v = [];
    let cnt = 0;
    let i = 0;
    for (; i < p.length; i++) {
        if (i !== 0 && cnt === 0) break;
        u.push(p[i]);
        if (p[i] === "(") cnt++;
        else cnt--;
    }
    for (; i < p.length; i++) v.push(p[i]);
    return [u, v].slice();
}

function foo(p) {
    if (p.length === 0) return [];
    let [u, v] = getP(p);
    if (isRightP(u)) {
        return u.concat(foo(v));
    } else {
        let arr = ["("];
        arr = arr.concat(foo(v));
        arr.push(")");
        return arr.concat(getReverse(u));
    }
}

function solution(p) {
    return foo(p.split("")).join("");
}
