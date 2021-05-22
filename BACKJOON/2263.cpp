#include <bits/stdc++.h>
using namespace std;

int postArr[100001];
int a[100001];

void foo(int inSt, int inEd, int pSt, int pEd) {
    if (inSt > inEd || pSt > pEd) return;
    int root = postArr[pEd];
    cout << root << " ";
    int rCnt = inEd - a[root];
    foo(inSt, a[root] - 1, pSt, pEd - rCnt - 1);
    foo(a[root] + 1, inEd, pEd - rCnt, pEd - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a[k] = i;
    }
    for (int i = 0; i < n; i++) cin >> postArr[i];
    foo(0, n - 1, 0, n - 1);
}