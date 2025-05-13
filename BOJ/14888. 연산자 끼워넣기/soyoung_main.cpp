#include <bits/stdc++.h>
using namespace std;

int maxResult = INT32_MIN;
int minResult = INT32_MAX;
int N;

vector<int> operands;
int inputOperands;
int numbers[11] = { 0, };
bool visited[11] = { false, };

void inputData();
void solution(int idx, vector<int> resultArr);
void circulate(vector<int> resultAr);

int main()
{
	inputData();
	solution(0, vector<int>());
	cout << maxResult << "\n" << minResult << endl;
}

void inputData()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int n = 0; n < N; ++n)
	{
		cin >> numbers[n];
	}

	for (int i = 0; i < 4; ++i)
	{
		cin >> inputOperands;
		for (int j = 0; j < inputOperands; ++j)
		{
			operands.push_back(i);
		}
	}

}

void circulate(vector<int> resultArr)
{
	int circulateResult = numbers[0];
	for (int i = 0; i < N-1; ++i)
	{
		switch (resultArr[i])
		{
			case 0:
				circulateResult += numbers[i + 1];
				break;
			case 1:
				circulateResult -= numbers[i + 1];
				break;
			case 2:
				circulateResult *= numbers[i + 1];
				break;
			case 3:
				circulateResult /= numbers[i + 1];
				break;
			default:
				break;
		}
	}
	minResult = min(minResult, circulateResult);
	maxResult = max(maxResult, circulateResult);
	return;
}

void solution(int idx, vector<int> resultArr)
{
	if (resultArr.size() == N - 1)
	{
		circulate(resultArr);
	}

	for (int i = 0; i < operands.size(); ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			resultArr.push_back(operands[i]);
			solution(idx + 1, resultArr);
			resultArr.pop_back();
			visited[i] = false;
		}
	}

}
