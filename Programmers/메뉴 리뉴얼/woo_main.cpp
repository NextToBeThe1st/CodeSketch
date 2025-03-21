#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ���� ����� �Լ�
void generateCombinations(const string& order, int r, int start, string current, unordered_map<string, int>& courseMap) {
    if (current.size() == r) {
        courseMap[current]++; // ������ ���� ī��Ʈ ����
        return;
    }

    for (int i = start; i < order.size(); i++) {
        generateCombinations(order, r, i + 1, current + order[i], courseMap);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (auto& order : orders) {
        sort(order.begin(), order.end()); // ���ĺ� ����
    }

    for (int r : course) {
        unordered_map<string, int> courseMap;
        for (auto& order : orders) {
            if (order.size() >= r) {
                generateCombinations(order, r, 0, "", courseMap);
            }
        }

        int maxCount = 2; // �ּ� �� �� �̻� �ֹ��� ���ո� ����
        vector<string> candidates;
        for (auto& [key, value] : courseMap) {
            if (value > maxCount) {
                maxCount = value;
                candidates.clear();
                candidates.push_back(key);
            }
            else if (value == maxCount) {
                candidates.push_back(key);
            }
        }

        for (auto& c : candidates) {
            answer.push_back(c);
        }
    }

    sort(answer.begin(), answer.end()); // ���� ����� ������ ����
    return answer;
}

//Test Code
int main() {
    vector<string> orders1 = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> course1 = { 2, 3, 4 };
    vector<string> result1 = solution(orders1, course1);
    for (const auto& r : result1) cout << r << " ";
    cout << endl;

    vector<string> orders2 = { "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" };
    vector<int> course2 = { 2, 3, 5 };
    vector<string> result2 = solution(orders2, course2);
    for (const auto& r : result2) cout << r << " ";
    cout << endl;

    vector<string> orders3 = { "XYZ", "XWY", "WXA" };
    vector<int> course3 = { 2, 3, 4 };
    vector<string> result3 = solution(orders3, course3);
    for (const auto& r : result3) cout << r << " ";
    cout << endl;

    return 0;
}