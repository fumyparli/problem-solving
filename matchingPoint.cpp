#include <bits/stdc++.h>
using namespace std;

struct info {
    int idx;
    int def_point;
    double total_point;
    vector<string> ext_link;
};

map<string, info> m;

string to_upper(string s) {
    string ret = "";
    for (int i = 0; i < s.size(); i++) {
        ret += toupper(s[i]);
    }
    return ret;
}

bool cmp(pair<double, int>& a, pair<double, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int solution(string word, vector<string> pages) {
    string upper_word = to_upper(word);
    for (int i = 0; i < pages.size(); i++) {
        stringstream f(pages[i]);
        string current_link = "";
        int meta_flag = 0;
        while (true) {
            string s;
            if (!(f >> s)) break;
            if (s == "<meta") meta_flag = 1;
            if (meta_flag == 1 && s.substr(0, 7) == "content") {
                meta_flag = 0;
                int flag = 0;
                string tmp = "";
                for (int j = 0; j < s.size(); j++) {
                    if (flag == 1 && s[j] == '\"') {
                        break;
                    }
                    if (flag == 1) {
                        tmp += s[j];
                    }
                    if (flag == 0 && s[j] == '\"') {
                        flag = 1;
                    }
                }
                m[tmp] = {i, 0, 0};
                current_link = tmp;
            }
        }
        f.clear();
        f.str(pages[i]);
        string prev = "";
        while (true) {
            string s;
            if (!(f >> s)) break;
            int s_size = s.size();
            int w_size = word.size();
            if (s_size - w_size >= 0) {
                for (int j = 0; j <= s.size() - word.size(); j++) {
                    if (to_upper(s.substr(j, word.size())) == upper_word && ((j == 0 || !isupper(toupper(s[j - 1]))) && (j == s.size() - word.size() || !isupper(toupper(s[j + word.size()]))))) {
                        m[current_link].def_point++;
                    }
                }
            }
            if (prev == "<a" && s.substr(0, 4) == "href") {
                int flag = 0;
                string tmp = "";
                for (int j = 0; j < s.size(); j++) {
                    if (flag == 1 && s[j] == '\"') {
                        break;
                    }
                    if (flag == 1) {
                        tmp += s[j];
                    }
                    if (flag == 0 && s[j] == '\"') {
                        flag = 1;
                    }
                }
                m[current_link].ext_link.push_back(tmp);
            }
            prev = "";
            if (s.size() >= 2) {
                prev += s[s.size() - 2];
                prev += s[s.size() - 1];
            }
        }
    }
    vector<pair<double, int>> ans;
    for (auto i = m.begin(); i != m.end(); i++) {
        for (auto& j : i->second.ext_link) {
            if (m.find(j) != m.end()) {
                m[j].total_point += ((double)i->second.def_point / i->second.ext_link.size());
            }
        }
    }
    for (auto i = m.begin(); i != m.end(); i++) {
        i->second.total_point += i->second.def_point;
        ans.push_back({i->second.total_point, i->second.idx});
    }
    sort(ans.begin(), ans.end(), cmp);
    return ans[0].second;
}