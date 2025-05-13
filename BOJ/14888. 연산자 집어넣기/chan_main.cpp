#include <iostream>
#include <vector>

#define add 0
#define sub 1
#define mul 2
#define div 3

using namespace std;

int num;
vector<int> numbers;
int op[4];

int Max = -1e10;
int Min = 1e10;

bool isOpRemain() {
    return op[add] || op[sub] || op[mul] || op[div];
}

void input() {

    cin >> num;
    numbers.resize(num);

    for (int i = 0; i < num; ++i) {
        cin >> numbers[i];
    }
    cin >> op[add] >> op[sub] >> op[mul] >> op[div];
}

void solution(int start, int startIdx) {

    if (!isOpRemain()) {

        if (start > Max) Max = start;
        if (start < Min) Min = start;
    }

    if (op[add]) {
        op[add]--;
        solution(start + numbers[startIdx + 1], startIdx + 1);
        op[add]++;
    }
    if (op[sub]) {
        op[sub]--;
        solution(start - numbers[startIdx + 1], startIdx + 1);
        op[sub]++;
    }
    if (op[mul]) {
        op[mul]--;
        solution(start * numbers[startIdx + 1], startIdx + 1);
        op[mul]++;
    }
    if (op[div]) {
        op[div]--;
        solution(start / numbers[startIdx + 1], startIdx + 1);
        op[div]++;
    }
}

int main(void) {

    input();
    solution(numbers[0], 0);

    cout << Max << endl;
    cout << Min << endl;

}