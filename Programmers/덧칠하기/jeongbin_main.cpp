#if 0
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool arr[100004];
int solution(int n, int m, vector<int> section) {
    int answer = 0;
    sort(section.begin(), section.end()); // �������� ����
    for (int i : section) {
        bool flag = false; // ���� ������� Ȯ���ϱ����� 
        if (arr[i] == true || i > n) continue;
        for (int j = i;j < i + m;j++) {
            if (j > n) break;
            arr[j] = true; // �ѷ� ���̸�ŭ ĥ�ϱ�
        }
        answer++;
    }

    return answer;
}
#endif // 0
