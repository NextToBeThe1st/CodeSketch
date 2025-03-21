#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int count = 0; // ����Ʈĥ Ƚ��
    int index = 0; // ���� section ����Ʈ ��ġ

    while (index < section.size()) {
        count++; // �ѷ� ��� Ƚ��
        int start = section[index]; // ĥ�ؾ� �ϴ� ���� ������
        index++; // ���� �������� �̵�

        // �ѷ��� ���� ���� �ִ� ��� section ����
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