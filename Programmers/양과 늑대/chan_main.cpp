#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Puddle_Start;
vector<int> Puddle_End;

int Num_Puddle;
int Board_Length;
int ResultCount = 0;

void Input() {

	Puddle_Start.resize(Num_Puddle);
	Puddle_End.resize(Num_Puddle);

	for (int i = 0; i < Num_Puddle; ++i) {
		cin >> Puddle_Start[i] >> Puddle_End[i];
	}
}
void SortPuddle() {

	sort(Puddle_Start.begin(), Puddle_Start.end());
	sort(Puddle_End.begin(), Puddle_End.end());
}
void CountBoard() {

	int Position = Puddle_Start[0];
	int CurrCount = 0;

	for (int i = 0; i < Num_Puddle; ++i) {

		CurrCount = 0;

		if (Position >= Puddle_End[i])
			continue;

		else if (Position <= Puddle_Start[i])
			Position = Puddle_Start[i];

		CurrCount += (Puddle_End[i] - Puddle_Start[i]) / Board_Length;
		Position += (Board_Length * CurrCount);
		//cout <<"본 루프 추가 pos" << Position << endl;

		if (Position < Puddle_End[i]) {

			CurrCount += 1;
			Position += Board_Length;
			//cout <<"나머지 추가 pos"<< Position << endl;
		}
		ResultCount += CurrCount;
		//cout << ResultCount <<" " << Position << endl;
	}
}
int main(void) {

	cin >> Num_Puddle >> Board_Length;
	Input();
	SortPuddle();
	CountBoard();

	cout << ResultCount;
}