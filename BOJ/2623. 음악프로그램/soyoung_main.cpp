<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> indegree;

void inputData() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    adj.resize(N + 1);
    indegree.resize(N + 1);

    for (int i = 0; i < M; ++i) {
        int s;
        cin >> s;
        vector<int> seq(s);
        for (int j = 0; j < s; ++j) {
            cin >> seq[j];
        }
        for (int j = 0; j < s - 1; ++j) {
            int from = seq[j];
            int to = seq[j + 1];
            adj[from].push_back(to);
            indegree[to]++;
        }
    }
}

void solution() {
    queue<int> q;
    vector<int> result;

    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int now = q.front(); q.pop();
        result.push_back(now);
        for (int next : adj[now]) {
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    if (result.size() != N) {
        cout << 0 << "\n";
    }
    else {
        for (int singer : result) {
            cout << singer << "\n";
        }
    }
}

int main() {
    inputData();
    solution();
    return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;

// 가수의 수 N, 보조 PD의 수 M
int N, M, S;
vector<vector<int>> singers;


void inputData();
bool checkCombi(vector<int> singerList);
void solution();


int main()
{
	inputData();
	solution();
	return 0;
}

void inputData()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	singers.resize(M);
	for (int m = 0; m < M; ++m)
	{
		cin >> S;
		singers[m].resize(S);
		for (int s = 0; s < S; ++s)
		{
			cin >> singers[m][s];
		}
	}
}

bool checkCombi(vector<int> singerList)
{
	vector<int> position(N + 1);
	for (int i = 0; i < N; ++i)
	{
		position[singerList[i]] = i;
	}

	for (const auto& seq : singers)
	{
		for (int i = 0; i < seq.size() - 1; ++i)
		{
			int before = seq[i];
			int after = seq[i + 1];
			if (position[before] >= position[after])
			{
				return false;
			}
		}
	}

	return true;
}

void solution()
{
	vector<int> singerList;
	for (int i = 1; i <= N; ++i)
	{
		singerList.push_back(i);
	}
	do
	{
		if (checkCombi(singerList))
		{
			for (auto s : singerList)
			{
				cout << s << "\n";
			}
			return;
		}
	} while (next_permutation(singerList.begin(), singerList.end()));
}
>>>>>>> 8de127e97d1bd61628226b580f55c4805b1c28ab
