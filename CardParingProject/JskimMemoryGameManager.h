#pragma once
#include "JskimGameBoard.h"
#include "JskimPlayer.h"

class JskimMemoryGameManager
{
private:
	JskimGameBoard m_gameBoard;
	JskimPlayer m_player;


public:
	JskimMemoryGameManager();
	int inputNumberOfCard();


};

