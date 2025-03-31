#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[54]; // 다른 마을까지 걸리는 최소 시간 
vector<pair<int, int>> v[54];

void dijkstra(int K) { // 가능 시간
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,1 }); // 자기자신 : 0; (시간, 마을 번호)
    arr[1] = 0;
    while (pq.size()) {
        int node = pq.top().second;
        int value = pq.top().first;
        pq.pop();

        if (arr[node] < value) continue;

        for (auto iter : v[node]) {
            int nextTime = value + iter.first; // 현재 시간 + 다음 갈 시간
            if (nextTime <= arr[iter.second]) { // 다음 노드의 시간과 비교해야 함.
                arr[iter.second] = nextTime;
                pq.push({ nextTime, iter.second });
                //cout<<"push : "<<nextTime<<", " << iter.second << " : " << arr[node]<<'\n';
            }
        }
    }

}

int solution(int N, vector<vector<int> > road, int K) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int answer = 0;

    for (auto roads : road) { // 지도 생성
        v[roads[0]].push_back({ roads[2], roads[1] });
        v[roads[1]].push_back({ roads[2], roads[0] });
    }

    fill(arr, arr + 54, 987654321);
    dijkstra(K); // 1부터 모든 집까지 최단거리 계산
    for (int i = 1;i <= N;i++) {
        if (arr[i] != 987654321 && arr[i] <= K) answer++;
        //cout<<arr[i]<<' ';
    }
    return answer;
}