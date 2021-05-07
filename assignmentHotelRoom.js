let parent = new Map();

function find(x) {
    if (parent.get(x) === undefined) {
        return x;
    }
    let tmp = find(parent.get(x));
    parent.set(x, tmp);
    return tmp;
}

function merge(x, y) {
    x = find(x);
    y = find(y);
    if (x === y) {
        return;
    }
    if (x > y) {
        [x, y] = [y, x];
    }
    parent.set(x, y);
}

function solution(k, room) {
    let ans = [];
    for (let i = 0; i < room.length; i++) {
        let tmp = find(room[i]);
        if (tmp) {
            merge(tmp, tmp + 1);
            ans.push(tmp);
        } else {
            merge(room[i], room[i] + 1);
            ans.push(room[i]);
        }
    }
    return ans;
}
