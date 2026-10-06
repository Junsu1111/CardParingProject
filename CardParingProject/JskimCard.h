#pragma once
class JskimCard
{
private:
	char m_shape;
	bool m_matached = false;

public:
	JskimCard(const char shape);
	char getShape();
	void setShape(const char shape);
	bool getMatched();
	void setMatched();
};

