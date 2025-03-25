#if 0

//그냥 if문 5중첩으로 시도, 효율성이 끔찍했음.
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

struct Applicant {
    string lang;
    string job;
    string career;
    string food;
    int score;
};

//query 파싱?
vector<string> split(string s) {
    vector<string> res;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        if (word == "and") continue; // "and"는 무시
        res.push_back(word);
    }
    return res;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<Applicant> applicants;
    vector<int> answer;

    // info 파싱
    for (const auto& s : info) {
        stringstream ss(s);
        string a, b, c, d;
        int score;
        ss >> a >> b >> c >> d >> score;
        applicants.push_back({a, b, c, d, score});
    }

    // query 처리
    for (const auto& q : query) {
        vector<string> cond = split(q);
        string lang = cond[0], job = cond[1], career = cond[2], food = cond[3];
        int score = stoi(cond[4]); //점수 대조 위해 int형으로 변경

        //일일이 대조해봄
        int count = 0;
        for (const auto& a : applicants) {
            if ((lang == "-" || a.lang == lang) &&
                (job == "-" || a.job == job) &&
                (career == "-" || a.career == career) &&
                (food == "-" || a.food == food) &&
                (a.score >= score)) {
                count++; //전부 일치시 카운트 추가
            }
        }
        answer.push_back(count);
    }

    return answer;
}
#endif

//사전에 가능한 가짓수 미리 생성, 효율성 테스트 통과
#if 01
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

unordered_map<string, vector<int>> db;

//비트마스킹 방식으로 진행 (feat.ChatGPT)
void makeCombinationsIterative(vector<string>& tokens, int score) {
    // 총 2^4 = 16개의 조합 생성
    for (int mask = 0; mask < (1 << 4); ++mask) {
        string key = "";
        for (int i = 0; i < 4; ++i) {
            if (mask & (1 << i)) {
                key += tokens[i];  // 해당 항목 포함
            } else {
                key += "-";        // 해당 항목 제외
            }
        }
        db[key].push_back(score);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    //info 파싱 및 조합 생성
    for (string s : info) {
        stringstream ss(s);
        string a, b, c, d;
        int score;
        ss >> a >> b >> c >> d >> score;
        vector<string> tokens = {a, b, c, d};
        makeCombinationsIterative(tokens, score);
    }

    // 점수순 정렬(효율성과는 직접 관련 x, 실행시간과 관련 o)
    for (auto& [key, vec] : db) {
        sort(vec.begin(), vec.end());
    }

    //query 처리
    vector<int> answer;
    for (string q : query) {
        stringstream ss(q);
        string a, b, c, d, temp;
        int score;
        ss >> a >> temp >> b >> temp >> c >> temp >> d >> score;
        string key = a + b + c + d;

        if (db.find(key) == db.end()) {
            answer.push_back(0);
            continue;
        }
        
        
        //이진탐색 메서드로 점수 필터링
        vector<int>& scores = db[key];
        int idx = lower_bound(scores.begin(), scores.end(), score) - scores.begin();
        answer.push_back(scores.size() - idx);
    }

    return answer;
}

/*
int main() {
    vector<string> info = {
        "java backend junior pizza 150",
        "python frontend senior chicken 210",
        "python frontend senior chicken 150",
        "cpp backend senior pizza 260",
        "java backend junior chicken 80",
        "python backend senior chicken 50"
    };
    vector<string> query = {
        "java and backend and junior and pizza 100",
        "python and frontend and senior and chicken 200",
        "cpp and - and senior and pizza 250",
        "- and backend and senior and - 150",
        "- and - and - and chicken 100",
        "- and - and - and - 150"
    };

    vector<int> result = solution(info, query);
    for (int r : result) cout << r << '\n';
    return 0;
}
*/


#endif