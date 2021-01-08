#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
string answer = "";

void get_ternary(int n) {
    if (n == 0) return;
    if (n % 3 == 0) {
        a.push_back(3);
        n -= 3;
    }
    a.push_back(n % 3);
    get_ternary(n / 3);
}

void get_124() {
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 3) {
            a[i] = 4;
        }
        if (a[i] != 0) {
            answer += to_string(a[i]);
        }
    }
}

string solution(int n) {
    get_ternary(n);
    get_124();
    return answer;
}