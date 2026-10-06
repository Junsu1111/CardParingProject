#include "JskimGameBoard.h"
#include <cmath>
#include <memory>
#include <random>    // random_device, mt19937, uniform_int_distribution
#include <utility>   // swap
#include <iostream>

using namespace std;

JskimGameBoard::JskimGameBoard(){}

JskimGameBoard::JskimGameBoard(const int number_of_card)
{
	setNumberOfCard(number_of_card);
	makeGameBoard();
}

JskimGameBoard::~JskimGameBoard(){}

void JskimGameBoard::setRow(const int row)
{
	m_row = row;
}


void JskimGameBoard::setCol(const int col)
{
	m_col = col;
}

int JskimGameBoard::getRow()
{
	return m_row;
}

int JskimGameBoard::getCol()
{
	return m_col;
}

void JskimGameBoard::setNumberOfCard(const int number_of_card)
{
	m_numberOfCard = number_of_card;
}

int JskimGameBoard::getNumberOfCard()
{
	return m_numberOfCard;
}


void JskimGameBoard::setCardShapeByIndex(const int row, const int col, const char shape)
{
	m_gameBoard[row][col].setShape(shape);
}

void JskimGameBoard::setCardMatchedByIndex(const int row, const int col)
{
	m_gameBoard[row][col].setMatched();
}

void JskimGameBoard::makeRectangle(const int number_of_card)
{
	int row = (int)sqrt(number_of_card);     // √n 이하의 가장 큰 정수에서 시작
	while (number_of_card % row != 0) {      // 나누어떨어질 때까지
		row--;                  // 1씩 줄이기
	}
	setRow(row);
	setCol(number_of_card / row);
}

void JskimGameBoard::makeRandomCard()
{
	const int numberOfCard = getNumberOfCard();
	char* temp = new char[numberOfCard];
	for (int i = 0; i < numberOfCard; ++i)
		temp[i] = 'A' + i / 2;

	// 2) Fisher–Yates 셔플
	random_device rd;
	mt19937 gen(rd());
	for (int i = numberOfCard - 1; i > 0; --i) {
		uniform_int_distribution<int> dist(0, i);
		int j = dist(gen);
		swap(temp[i], temp[j]);
	}

	// 3) 2차원 보드로 옮기기
	const int row = getRow();
	const int col = getCol();
	int idx = 0;
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			setCardShapeByIndex(r, c, temp[idx++]);
		}
	}


	delete[] temp;
}

void JskimGameBoard::makeGameBoard()
{
	makeRectangle(m_numberOfCard);
	m_gameBoard = make_unique<unique_ptr<JskimCard[]>[]>(getRow());
	for (int i = 0; i < getRow(); i++) {
		m_gameBoard[i] = make_unique<JskimCard[]>(getCol());
	}
	makeRandomCard();
}

void JskimGameBoard::showGameBoard()
{
	const int row = getRow();
	const int col = getCol();
	for (int i = 0; i < col; i++) {
		cout << '\t' << i + 1;
	}
	cout << endl;
	for (int r = 0; r < row; r++) {
		cout << static_cast<char>('A' + r) << '\t';
		for (int c = 0; c < col; c++) {
			cout << ( m_gameBoard[r][c].getMatched() ? m_gameBoard[r][c].getShape() : '*') << '\t';
		}
		cout << endl;
	}
}
