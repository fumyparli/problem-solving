#include <iostream>
using namespace std;

int a[200000];
int cycle[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, v;
    cin >> n >> m >> v;
    v--;
    for (int i = 0; i < n; i++) {
        int node;
        cin >> node;
        if (i < v) {
            a[i] = node;
        } else {
            cycle[i - v] = node;
        }
    }
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        if (k < v) {
            cout << a[k] << '\n';
        } else {
            cout << cycle[(k - v) % (n - v)] << '\n';
        }
    }
}