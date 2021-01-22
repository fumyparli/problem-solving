function isAlpha(str) {
    let alpha = "qwertyuiopasdfghjklzxcvbnm";
    if (!alpha.split("").includes(str[0])) return false;
    if (!alpha.split("").includes(str[1])) return false;
    return true;
}

function solution(str1, str2) {
    let a = [];
    let b = [];
    str1 = str1.toLowerCase();
    str2 = str2.toLowerCase();
    for (let i = 1; i < str1.length; i++) {
        if (isAlpha(str1[i - 1] + str1[i])) {
            a.push(str1[i - 1] + str1[i]);
        }
    }
    for (let i = 1; i < str2.length; i++) {
        if (isAlpha(str2[i - 1] + str2[i])) {
            b.push(str2[i - 1] + str2[i]);
        }
    }
    let inter = [];
    let union = [];
    let check = new Array(1001);
    check.fill(0);
    for (let i = 0; i < a.length; i++) {
        for (let j = 0; j < b.length; j++) {
            if (check[j] === 0 && a[i] === b[j]) {
                check[j] = 1;
                inter.push(a[i]);
                break;
            }
        }
    }
    union = a.concat(b);
    for (let i = 0; i < inter.length; i++) {
        for (let j = 0; j < union.length; j++) {
            if (inter[i] === union[j]) {
                union.splice(j, 1);
                break;
            }
        }
    }
    if (inter.length === 0 && union.length === 0) return 65536;
    else if (inter.length === 0) return 0;
    return Math.floor((inter.length * 65536) / union.length);
}
