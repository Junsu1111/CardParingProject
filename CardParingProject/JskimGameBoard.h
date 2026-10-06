#pragma once
#include <memory>
#include "JskimCard.h"

using std::unique_ptr;

class JskimGameBoard
{
private:
	int m_row;
	int m_col;
	int m_numberOfCard;
	unique_ptr<unique_ptr<JskimCard[]>[]> m_gameBoard;

public:
	JskimGameBoard()=default;
	JskimGameBoard(const int number_of_card);
	~JskimGameBoard();
	void setRow(const int row);
	void setCol(const int col);
	int getRow();
	int getCol();
	void setNumberOfCard(const int number_of_card);
	int getNumberOfCard();
	void setCardShapeByIndex(const int row, const int col, const char shape);
	void setCardMatchedByIndex(const int row, const int col);
	void makeRectangle(const int number_of_card);
	void makeRandomCard();
	void makeGameBoard();
	void showGameBoard();
};

