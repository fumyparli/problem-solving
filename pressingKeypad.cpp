#include <bits/stdc++.h>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    if (hand == "right")
        hand = 'R';
    else
        hand = 'L';
    for (auto& i : numbers) {
        if (i == 0)
            i = 10;
        else
            i--;
    }
    int left = 9;
    int right = 11;
    for (auto& i : numbers) {
        if (i == 0 || i == 3 || i == 6) {
            answer += 'L';
            left = i;
            cout << "i: " << i << '\n';
        } else if (i == 2 || i == 5 || i == 8) {
            answer += 'R';
            right = i;
            cout << "i: " << i << '\n';
        } else {
            int l_d = abs(left / 3 - i / 3) + abs(left % 3 - i % 3);
            int r_d = abs(right / 3 - i / 3) + abs(right % 3 - i % 3);
            cout << "i: " << i << " l_d: " << l_d << " r_d: " << r_d << '\n';
            if (l_d == r_d) {
                answer += hand;
                string R = "R";
                if (hand == R)
                    right = i;
                else
                    left = i;
            } else if (l_d < r_d) {
                answer += 'L';
                left = i;
            } else {
                answer += 'R';
                right = i;
            }
        }
    }
    return answer;
}