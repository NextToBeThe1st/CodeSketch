#if 01
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

char arr[4][4];
string str;

bool checkBingo(char c) {
	for (int i = 0; i < 3; i++) {
		if (arr[i][0] == c && arr[i][1] == c && arr[i][2] == c) return true;
	}
	for (int i = 0; i < 3; i++) {
		if (arr[0][i] == c && arr[1][i] == c && arr[2][i] == c) return true;
	}
	if (arr[0][0] == c && arr[1][1] == c && arr[2][2] == c) return true;
	if (arr[0][2] == c && arr[1][1] == c && arr[2][0] == c) return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> str;
		if (str == "end") break;
		fill(&arr[0][0], &arr[0][0] + 4 * 4, 0); // ÀÔ·Â ¼ø¼­µµ ºÁÁà¾ßÇÔ.

		for (int i = 0; i < str.length(); i++) {
			arr[i / 3][i % 3] = str[i];
		}

		if ((checkBingo('X') && !checkBingo('O')) // X ºù°í
			&& (count(str.begin(), str.end(), 'X') - 1 == count(str.begin(), str.end(), 'O'))) {
			cout << "valid" << '\n';
		}
		else if((!checkBingo('X') && checkBingo('O')) // O ºù°í
			&& (count(str.begin(), str.end(), 'X') == count(str.begin(), str.end(), 'O'))) {
			cout << "valid" << '\n';
		}
		else if (!checkBingo('X') && !checkBingo('O') // °¡µæ Ã¡´Âµ¥ ºù°í ¾ø´Â °æ¿ì
			&& count(str.begin(), str.end(), 'X') == 5 && count(str.begin(), str.end(), 'O') == 4) {
			cout << "valid" << '\n';
		}
		else
			cout << "invalid" << '\n';

	}

	return 0;
}

#endif