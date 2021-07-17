#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;
vector<int> list;

void foo(int x) {
	if (a.size() == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
		return;
	}
	if (x == n) {
		return;
	}
	a.push_back(list[x]);
	foo(x + 1);
	a.pop_back();
	foo(x + 1);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		list.push_back(k);
	}
	sort(list.begin(), list.end());
	foo(0);
}
