let arr;
let cnt0 = 0;
let cnt1 = 0;
function loop(a, b, n) {
    let value = arr[a][b];
    if (value === -1) return;
    let flag = 0;
    for (let i = a; i < a + n; i++) {
        for (let j = b; j < b + n; j++) {
            if (arr[i][j] !== value) {
                flag = 1;
                break;
            }
        }
    }
    if (flag === 0) {
        if (arr[a][b] === 0) {
            cnt0++;
        } else {
            cnt1++;
        }
        for (let i = a; i < a + n; i++) {
            for (let j = b; j < b + n; j++) {
                arr[i][j] = -1;
            }
        }
    }
}
function foo(a, b, n) {
    if (n === 1) return;
    loop(a, b, n);
    n /= 2;
    foo(a, b, n);
    foo(a, b + n, n);
    foo(a + n, b, n);
    foo(a + n, b + n, n);
    return;
}
function solution(array) {
    arr = array;
    foo(0, 0, arr.length);
    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < arr.length; j++) {
            if (arr[i][j] === 0) {
                cnt0++;
            } else if (arr[i][j] === 1) {
                cnt1++;
            }
        }
    }
    return [cnt0, cnt1];
}
