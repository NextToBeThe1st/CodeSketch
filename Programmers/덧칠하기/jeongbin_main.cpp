#if 0
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool arr[100004];
int solution(int n, int m, vector<int> section) {
    int answer = 0;
    sort(section.begin(), section.end()); // 오름차순 정렬
    for (int i : section) {
        bool flag = false; // 범위 벗어났는지 확인하기위함 
        if (arr[i] == true || i > n) continue;
        for (int j = i;j < i + m;j++) {
            if (j > n) break;
            arr[j] = true; // 롤러 길이만큼 칠하기
        }
        answer++;
    }

    return answer;
}
#endif // 0
