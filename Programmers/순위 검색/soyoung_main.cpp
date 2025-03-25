#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

typedef struct _applier {
    unsigned int val;
    int score;
} applier;

vector<string> split(string str, string delimiter) {
    vector<string> result;
    int start = 0;
    int end = str.find(delimiter);
    while (end != string::npos) {
        result.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }
    result.push_back(str.substr(start));
    return result;
}

vector<applier> organize(vector<string> info, unordered_map<string, int> dictionary) {
    vector<applier> organizedResult;
    for (auto i : info) {
        applier app = { 0, 0 };
        vector<string> j = split(i, " ");
        app.val = (dictionary[j[0]] << 6) | (dictionary[j[1]] << 4) | (dictionary[j[2]] << 2) | dictionary[j[3]];
        app.score = stoi(j[j.size() - 1]);
        organizedResult.push_back(app);
    }
    return organizedResult;
}

vector<int> getAnswer(vector<applier> infoOrganized, vector<string> query, unordered_map<string, int> dictionary) {
    vector<int> answer;
    for (auto q : query) {
        vector<string> q_split = split(q, " and ");
        vector<string> last = split(q_split[3], " ");
        q_split[3] = last[0];
        int q_score = stoi(last[1]);

        unsigned int q_val = 0;
        unsigned int mask = 0;
        int pos = 6;

        for (auto splitted : q_split) {
            if (splitted != "-") {
                q_val |= (dictionary[splitted] << pos);
                mask |= (3 << pos); // 각 카테고리(2비트) 마스킹
            }
            pos -= 2;
        }

        int count = 0;
        for (auto inf : infoOrganized) {
            if (((inf.val & mask) == (q_val & mask)) && inf.score >= q_score) {
                count++;
            }
        }
        answer.push_back(count);
    }
    return answer;
}

vector<int> solution(vector<string> info, vector<string> query) {
    unordered_map<string, int> dictionary = {
        {"cpp", 0}, {"java", 1}, {"python", 2},
        {"backend", 0}, {"frontend", 1},
        {"junior", 0}, {"senior", 1},
        {"chicken", 0}, {"pizza", 1},
        {"-", 0}
    };

    vector<int> answer;
    vector<applier> infoOrganized = organize(info, dictionary);
    answer = getAnswer(infoOrganized, query, dictionary);

    return answer;
}


int main() {
    vector<int> answer;
    
    vector<string> info = { "java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50" };
    vector<string> query = { "java and backend and junior and pizza 100", "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150" };
    answer = solution(info, query);
    for (auto ans : answer) {
        cout << ans << " ";
    }
    cout << endl;
}