function solution(arr) {
    let max = 0;
    for (let i = 0; i < arr.length; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    let lcm = max;
    while (true) {
        let flag = 0;
        for (let i = 0; i < arr.length; i++) {
            if (lcm % arr[i] !== 0) {
                flag = 1;
                break;
            }
        }
        if (flag === 0) {
            return lcm;
        }
        lcm += max;
    }
}
