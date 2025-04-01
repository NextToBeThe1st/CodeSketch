#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[54]; // �ٸ� �������� �ɸ��� �ּ� �ð� 
vector<pair<int, int>> v[54];

void dijkstra(int K) { // ���� �ð�
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,1 }); // �ڱ��ڽ� : 0; (�ð�, ���� ��ȣ)
    arr[1] = 0;
    while (pq.size()) {
        int node = pq.top().second;
        int value = pq.top().first;
        pq.pop();

        if (arr[node] < value) continue;

        for (auto iter : v[node]) {
            int nextTime = value + iter.first; // ���� �ð� + ���� �� �ð�
            if (nextTime <= arr[iter.second]) { // ���� ����� �ð��� ���ؾ� ��.
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

    for (auto roads : road) { // ���� ����
        v[roads[0]].push_back({ roads[2], roads[1] });
        v[roads[1]].push_back({ roads[2], roads[0] });
    }

    fill(arr, arr + 54, 987654321);
    dijkstra(K); // 1���� ��� ������ �ִܰŸ� ���
    for (int i = 1;i <= N;i++) {
        if (arr[i] != 987654321 && arr[i] <= K) answer++;
        //cout<<arr[i]<<' ';
    }
    return answer;
}