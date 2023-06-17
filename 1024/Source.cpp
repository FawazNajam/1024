//#include <iostream>
//#include <iomanip>
//#include <ctime>
//#include <cstdlib>
//
//using namespace std;
//
//int grid[4][4];
//
//pair<int, int> rowpos() {
//	int row = rand() % 4;
//	int row2 = rand() % 4;
//
//	return make_pair(row, row2);
//}
//pair<int, int> colpos() {
//	int col = rand() % 4;
//	int col2 = rand() % 4;
//	return make_pair(col, col2);
//
//}
//void generate1() {
//	pair<int, int> i = rowpos();
//	pair<int, int> j = colpos();
//	grid[i.first][j.first] = (rand() % 2) + 1;
//}
//void generate2() {
//	pair<int, int> i = rowpos();
//	pair<int, int> j = colpos();
//	grid[i.second][j.second] = (rand() % 2) + 1;
//}
//void newgame() {
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			grid[i][j] = 0;
//		}
//	}
//	generate1();
//	generate2();
//}
//void UI() {
//	system("cls");
//
//	for (int i = 0; i < 4; i++) {
//		for (int i = 0; i < 21; i++) {
//			cout << "-";
//		}
//		cout << endl;
//		cout << "|";
//		for (int j = 0; j < 4; j++) {
//			if (grid[i][j] == 0) {
//				cout << setw(4) << left << " ";
//			}
//			else
//				cout << setw(4) << left << grid[i][j];
//			cout << "|";
//		}
//		cout << endl;
//	}
//	for (int i = 0; i < 21; i++) {
//		cout << "-";
//	}
//	cout << endl << "FOR NEW GAME PRESS 'N'" << endl;
//	cout << "TO QUIT GAME PRESS 'Q'" << endl;
//	cout << "FOR UP PRESS 'W'" << endl;
//	cout << "FOR DOWN PRESS 'S'" << endl;
//	cout << "FOR LEFT PRESS 'A'" << endl;
//	cout << "FOR RIGHT PRESS 'D'" << endl;
//
//}
//void addpiece() {
//	bool occ = true;
//	while (occ) {
//		int row = (rand() % 4);
//		int col = (rand() % 4);
//		if (grid[row][col] == 0) {
//			int n = (rand() % 2) + 1;
//			grid[row][col] = n;
//			occ = false;
//		}
//	}
//}
//void move(char key) {
//
//		if (key == 'w') {
//			for (int i = 1; i < 4; i++) {
//				for (int j = 0; j < 4; j++) {
//					if (grid[i - 1][j] == 0) {
//						for (int k = i;k > 0;k--) {
//							if (grid[k - 1][j] != 0)
//								break;
//							if (grid[k - 1][j] == grid[k][j]) {
//								grid[k - 1][j] = grid[k][j] + grid[k - 1][j];
//								grid[k][j] = 0;
//								continue;
//							}
//							int temp = grid[k][j];
//							grid[k][j] = grid[k - 1][j];
//							grid[k - 1][j] = temp;
//						}
//					}
//					else if (grid[i - 1][j] == grid[i][j]) {
//						grid[i - 1][j] = grid[i][j] + grid[i - 1][j];
//						grid[i][j] = 0;
//					}
//				}
//			}
//			UI();
//		}
//
//		else if (key == 's') {
//			for (int i = 2; i >= 0; i--) {
//				for (int j = 0; j < 4; j++) {
//					if (grid[i + 1][j] == 0) {
//						for (int k = i;k < 3;k++) {
//							if (grid[k + 1][j] != 0)
//								break;
//							if (grid[k + 1][j] == grid[k][j]) {
//								grid[k + 1][j] = grid[k][j] + grid[k + 1][j];
//								grid[k][j] = 0;
//								continue;
//							}
//							int temp = grid[k][j];
//							grid[k][j] = grid[k + 1][j];
//							grid[k + 1][j] = temp;
//						}
//					}
//					else if (grid[i + 1][j] == grid[i][j]) {
//						grid[i + 1][j] = grid[i][j] + grid[i + 1][j];
//						grid[i][j] = 0;
//					}
//				}
//			}
//			UI();
//		}
//
//		if (key == 'a') {
//			for (int i = 0; i < 4; i++) {
//				for (int j = 1; j < 4; j++) {
//					if (grid[i][j - 1] == 0) {
//						for (int k = j;k > 0;k--) {
//							if (grid[i][k - 1] != 0)
//								break;
//							if (grid[i][k - 1] == grid[i][k]) {
//								grid[i][k - 1] = grid[i][k] + grid[i][k - 1];
//								grid[i][k] = 0;
//								continue;
//							}
//							int temp = grid[i][k];
//							grid[i][k] = grid[i][k - 1];
//							grid[i][k - 1] = temp;
//						}
//					}
//					else if (grid[i][j - 1] == grid[i][j]) {
//						grid[i][j - 1] = grid[i][j] + grid[i][j - 1];
//						grid[i][j] = 0;
//					}
//				}
//			}
//			UI();
//		}
//
//		if (key == 'd') {
//			for (int i = 0; i < 4; i++) {
//				for (int j = 2; j >= 0; j--) {
//					if (grid[i][j + 1] == 0) {
//						for (int k = j;k < 3;k++) {
//							if (grid[i][k + 1] != 0)
//								break;
//							if (grid[i][k + 1] == grid[k][j]) {
//								grid[i][k + 1] = grid[i][k + 1] + grid[i][k];
//								grid[i][k] = 0;
//								continue;
//							}
//							int temp = grid[i][k];
//							grid[i][k] = grid[i][k + 1];
//							grid[i][k + 1] = temp;
//						}
//					}
//					else if (grid[i][j + 1] == grid[i][j]) {
//						grid[i][j + 1] = grid[i][j + 1] + grid[i][j];
//						grid[i][j] = 0;
//					}
//				}
//			}
//			UI();
//		}
//	//addpiece();
//}
//int main() {
//	srand(time(0));
//	newgame();
//	UI();
//	int n = 1;
//	char key;
//	while (n == 1) {
//		cin >> key;
//		move(key);
//		//addpiece();
//	}
//	return 0;
//}