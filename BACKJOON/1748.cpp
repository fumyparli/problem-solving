#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int i = 1;
	long long sum = 0;
	while (true) {
		int k = 9 * pow(10, i - 1);
		if (n >= k) {
			n -= k;
			sum += k * i;
		}
		else {
			sum += n * i;
			break;
		}
		i++;
	}
	cout << sum;
}
