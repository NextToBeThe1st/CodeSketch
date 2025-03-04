#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, L;
vector<pair<int, int>> puddles;

void inputData();
int calculatePlanks();

int main() {
    inputData();  // 웅딩이 입력 및 정렬
    cout << calculatePlanks() << endl;  // 널빤지 개수 계산 및출력
    return 0;
}

void inputData() {
    cin >> N >> L;
    puddles.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> puddles[i].first >> puddles[i].second;
    }

    sort(puddles.begin(), puddles.end()); // 웅덩이를 시작 위치 기준으로 정렬
}

int calculatePlanks() {
    int plank_count = 0;  // 널빤지 개수
    int covered_pos = 0;  // 마지막으로 덮은 위치

    for (auto& puddle : puddles) {
        int start = puddle.first;
        int end = puddle.second;

        
        if (covered_pos > start) { // 이미 덮인 부분이면 다음 널빤지 시작 위치 조정
            start = covered_pos;
        }

        int length_to_cover = end - start;

        if (length_to_cover > 0) {  // 덮어야 할 부분이 남아있을 경우
            int needed_planks = (length_to_cover + L - 1) / L;  // 널빤지 개수 계산
            plank_count += needed_planks;
            covered_pos = start + needed_planks * L;  // 마지막 위치 갱신
        }
    }

    return plank_count;
}