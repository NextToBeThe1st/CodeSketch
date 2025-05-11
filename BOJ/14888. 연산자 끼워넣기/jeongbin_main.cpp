#if 0
#include <iostream>
using namespace std;

int n, a, cnt, mn = INT32_MAX, mx = INT32_MIN;
int arr[4], num[12];

void combi(int idx, int ret) {
    if (idx == n) {
        mn = min(mn, ret);
        mx = max(mx, ret);
        return;
    }
	for (int i = 0; i < 4; i++) { // �� �����ں� ��Ž ����
        if (arr[i] > 0) {
            arr[i]--; // ������ ���� --
            if (i == 0) combi(idx + 1, ret + num[idx]);
            else if (i == 1) combi(idx + 1, ret - num[idx]);
            else if (i == 2) combi(idx + 1, ret * num[idx]);
            else if (i == 3) combi(idx + 1, ret / num[idx]);
            arr[i]++; // ������ ���� ++
        }
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
    for (int i = 0; i < n; i++) { // ����� ���� �Է�
        cin >> num[i];
    }
	for (int i = 0; i < 4; i++) { // �� ������ �� �Է�
		cin >> arr[i];
	}

    combi(1, num[0]);
    cout << mx << '\n' << mn;
	return 0;
}

#endif // 01
