#include "JskimGameBoard.h"
#include <iostream>

using namespace std;

int main() {

	cout << "============================== " << endl;
	cout << "카드 쌍 맞추기 게임" << endl;
	cout << "학번: 202211284 이름: 김준수" << endl;
	cout << "============================== "<<endl;

	JskimGameBoard board = JskimGameBoard(12);
	board.showGameBoard();

	return 0;
}