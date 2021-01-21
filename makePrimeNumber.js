let check = new Array(3001);
check.fill(0);

function era(num) {
    if (check[num] === 0) return 1;
    return 0;
}

let v = [];
let n;
let answer = 0;
function foo(x) {
    if (v.length === 3) {
        let sum = 0;
        for (let i = 0; i < 3; i++) {
            sum += v[i];
        }
        answer += era(sum);
        return;
    }
    for (let i = x; i < n.length; i++) {
        v.push(n[i]);
        foo(i + 1);
        v.pop();
    }
}

function solution(nums) {
    n = nums;
    check[1] = 1;
    for (let i = 2; i * i <= 3001; i++) {
        if (check[i] === 0) {
            for (let j = i + i; j < 3001; j += i) {
                if (check[j] === 0) check[j] = 1;
            }
        }
    }
    foo(0);
    return answer;
}
