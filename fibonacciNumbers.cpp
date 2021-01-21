#include <iostream>
using namespace std;

int d[100001];

int foo(int i) {
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }
    if (d[i]) {
        return d[i];
    }
    d[i] = (foo(i - 1) + foo(i - 2)) % 1234567;
    return d[i];
}

int solution(int n) {
    return foo(n);
}
