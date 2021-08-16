#include <bits/stdc++.h>
using namespace std;

int scoreBoard[] = {'F', 'F', 'F', 'F', 'F', 'D', 'D', 'C', 'B', 'A', 'A'};

string solution(vector<vector<int>> scores) {
    string answer = "";
    for (int j = 0; j < scores.size(); j++) {
        int mypoint;
        int maxpoint = -1;
        int minpoint = 101;
        int sum = 0;
        for (int i = 0; i < scores[j].size(); i++) {
            sum += scores[i][j];
            if (i == j) {
                mypoint = scores[i][j];
            } else {
                maxpoint = max(scores[i][j], maxpoint);
                minpoint = min(scores[i][j], minpoint);
            }
        }
        if (mypoint > maxpoint || mypoint < minpoint) {
            sum -= mypoint;
            answer.push_back(scoreBoard[sum / ((int)scores.size() - 1) / 10]);
        } else {
            answer.push_back(scoreBoard[sum / scores.size() / 10]);
        }
    }
    return answer;
}