#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int count_num;
int curr_pos;

int solution(int n, int m, vector<int> section) {

    int count_num = 0;
    int curr_pos = 0;

    for (int i = 0; i < section.size(); ++i) {
        if (curr_pos > section[i]) continue;

        curr_pos = section[i] + m;
        count_num++;
    }

    return count_num;
}