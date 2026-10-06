#include "JskimMemoryGameManager.h"
#include <iostream>

using namespace std;

JskimMemoryGameManager::JskimMemoryGameManager()
{
	m_player = JskimPlayer();
	int numberOfCard=inputNumberOfCard();
	m_gameBoard = JskimGameBoard(numberOfCard);
	//생성자 강의자료 한번 더 보고 수정하기 
	cout << "보드 크기: " << m_gameBoard.getRow() << "행x" << m_gameBoard.getCol() << "열" << endl;
	m_gameBoard.showGameBoard();
}

int JskimMemoryGameManager::inputNumberOfCard()
{
	int inputNumber;
	while (true) {
		cout << "카드 개수를 입력하세요 (짝수, 4~52): ";
		cin >> inputNumber;

		if (cin.fail() || cin.peek() != '\n') {
			cout << "오류: 숫자만 입력하세요." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		else if (inputNumber < 4 || inputNumber>52) {
			cout << "오류: 숫자 범위를 벗어났습니다." << endl;
			continue;
		}

		else if (inputNumber % 2 != 0) {
			cout << "오류: 짝수를 입력해야 합니다." << endl;
			continue;
		}
		else {
			break;
		}
	}
	return inputNumber;
	
}
