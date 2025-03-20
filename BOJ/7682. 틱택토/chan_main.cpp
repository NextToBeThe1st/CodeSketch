#include <iostream>
#include <vector>
using namespace std;

char Board[3][3];
char status;
vector<string> Answer;
int Num_of_Test;

int input(void) {

	for (int i = 0; i < 3; ++i) {

		if (Board[0][0] == 'e') return 1;

		for (int j = 0; j < 3; ++j) {
			cin >> Board[i][j];
		}

	}
	return 0;
}

int Count_Num(char player) {

	int count = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (Board[i][j] == player)
				count++;
		}
	}
	return count;
}

int Check_Line(char player) {

	int count = 0;
	//=================================
	for (int j = 0; j < 3; ++j) {

		count = 0;
		for (int i = 0; i < 3; ++i) {
			if (Board[i][j] == player) {
				count++;
			}
		}
		if (count == 3) return 1;
	}
	//=================================
	for (int i = 0; i < 3; ++i) {

		count = 0;
		for (int j = 0; j < 3; ++j) {
			if (Board[i][j] == player) {
				count++;
			}
		}
		if (count == 3) return 1;
	}
	//=================================
	count = 0;
	for (int i = 0; i < 3; ++i) {
		if (Board[i][i] == player) {
			count++;
		}
	}
	if (count == 3) return 1;
	//=================================
	count = 0;
	for (int i = 0; i < 3; ++i) {
		if (Board[2 - i][i] == player) {
			count++;
		}
	}
	if (count == 3) return 1;
	//=================================
	return 0; 
}

int X_O_Rule_Valid() {
	
	if (Check_Line('O') && (Count_Num('O') != Count_Num('X'))) 
		return 1;

	else if (Check_Line('X') && (Count_Num('O') == Count_Num('X'))) 
		return 1;

	else if (!Check_Line('X') && !Check_Line('O') && Count_Num('.')) 
		return 1;

	return 0;
}

int X_O_Num_Valid() {

	if (Count_Num('O')> Count_Num('X')) 
		return 1;

	else if (Count_Num('O') + 1 < Count_Num('X')) 
		return 1;

	return 0;
}

int main(void) {
	
	while (1) {

		if (input()) {

			for (int i = 0; i < Num_of_Test; i++) 
				cout << Answer[i] << endl;
			return 0;
		}
		if (X_O_Num_Valid() || X_O_Rule_Valid()) {

			Answer.push_back("invalid");
			Num_of_Test++;
			continue; 
		}
		else {

			Answer.push_back("valid");
			Num_of_Test++;
			continue;
		}
	}
}