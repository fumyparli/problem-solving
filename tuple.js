function solution(s) {
    var ans = [];
    let start = 0;
    let a = new Array(1000000);
    for (let i = 0; i <= 1000000; i++) {
        a[i] = new Array(0);
    }
    let str = "";
    let r = 0;
    let c = 0;
    for (let i = 1; i < s.length - 1; i++) {
        if (s[i] === "{") {
            start = 1;
        } else if (s[i] === "}") {
            a[r][c++] = str;
            str = "";
            start = 0;
            r++;
            c = 0;
        } else if (start === 1 && s[i] === ",") {
            a[r][c++] = str;
            str = "";
        } else if (start === 1) {
            str += s[i];
        }
    }
    a.sort((a, b) => {
        if (a.length === 0 || b.length === 0) {
            return 0;
        }
        return a.length - b.length;
    });
    for (let i = 0; i < a.length; i++) {
        for (let j = 0; j < a[i].length; j++) {
            let flag = 0;
            for (let k = 0; k < ans.length; k++) {
                if (+a[i][j] === ans[k]) {
                    flag = 1;
                    continue;
                }
            }
            if (flag === 0) {
                ans.push(+a[i][j]);
                break;
            }
        }
    }
    return ans;
}
