#include "JskimCard.h"

JskimCard::JskimCard(const char shape)
{
	setShape(shape);
}

char JskimCard::getShape() {
	return m_shape;
}
void JskimCard::setShape(char shape) {
	m_shape = shape;
}
bool JskimCard::getMatched() {
	return m_matached;
}
void JskimCard::setMatched() {
	m_matached = !m_matached;
}
