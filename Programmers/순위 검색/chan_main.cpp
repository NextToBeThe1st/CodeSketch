#include <string>
#include <vector>
#include <iostream>

using namespace std;
string Splited_Info[5];
string Splited_Query[5];
int Splited_Query_Index = 0;
int Splited_Info_Index = 0;

void Get_Splited_Info(string info) {

    if (Splited_Info_Index == 5) {

        Splited_Info_Index = 0;
        return;
    }
    Splited_Info[Splited_Info_Index++] = info.substr(0, info.find(' '));
    Get_Splited_Info(info.substr(info.find(' ') + 1));
}

void Get_Splited_Query(string query) {

    if (Splited_Query_Index == 5) {

        Splited_Query_Index = 0;
        return;
    }
    if (query.substr(0, query.find(' ')) != "and") {
        Splited_Query[Splited_Query_Index++] = query.substr(0, query.find(' '));
    }
    Get_Splited_Query(query.substr(query.find(' ') + 1));
}

int Check_Query_Info() {

    for (int i = 0; i < 4; ++i) {

        if (Splited_Query[i] == "-") {
            continue;
        }
        else if (Splited_Query[i] != Splited_Info[i]) {
            return 0;
        }
    }
    if (stoi(Splited_Info[4]) < stoi(Splited_Query[4])) {
        return 0;
    }
    return 1;
}

vector<int> solution(vector<string> info, vector<string> query) {

    int count = 0;
    vector<int> answer;
    answer.resize(query.size());

    for (int i = 0; i < query.size(); ++i) {

        count = 0;
        Get_Splited_Query(query[i]);

        for (int j = 0; j < info.size(); ++j) {

            Get_Splited_Info(info[j]);

            if (Check_Query_Info()) {
                count++;
            }
        }
        answer[i] = count;
    }
    return answer;
}