#include <bits/stdc++.h>
using namespace std;

int solution(string d) {
    int i = 0;
    int j = 0;
    int a[3] = {0};
    for (int i = 0; i < d.size(); i++) {
        if (isdigit(d[i])) {
            if (d[i + 1] == '0') {
                a[j++] = 10;
                i++;
            } else {
                a[j++] = d[i] - '0';
            }
        }
        if (d[i] == 'D') {
            a[j - 1] = pow(a[j - 1], 2);
        }
        if (d[i] == 'T') {
            a[j - 1] = pow(a[j - 1], 3);
        }
        if (d[i] == '*') {
            if (j - 2 >= 0)
                a[j - 2] *= 2;
            a[j - 1] *= 2;
        }
        if (d[i] == '#') {
            a[j - 1] = -a[j - 1];
        }
    }
    return a[0] + a[1] + a[2];
}