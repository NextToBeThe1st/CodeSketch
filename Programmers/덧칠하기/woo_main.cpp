#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int count = 0; // 페인트칠 횟수
    int index = 0; // 현재 section 리스트 위치

    while (index < section.size()) {
        count++; // 롤러 사용 횟수
        int start = section[index]; // 칠해야 하는 구역 시작점
        index++; // 다음 구역으로 이동

        // 롤러의 범위 내에 있는 모든 section 점프
        while (index < section.size() && section[index] < start + m) {
            index++;
        }
    }

    return count;
}

// Test code
int main() {
    cout << solution(8, 4, { 2, 3, 6 }) << endl;  // 2
    cout << solution(5, 4, { 1, 3 }) << endl;    // 1
    cout << solution(4, 1, { 1, 2, 3, 4 }) << endl;  // 4
    return 0;
}