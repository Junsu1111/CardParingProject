#include "JskimPlayer.h"


JskimPlayer::JskimPlayer():JskimPlayer("202211284","김준수"){}

JskimPlayer::JskimPlayer(const string studentNumber, const string name)
{
    setStudentNumber(studentNumber);
    setName(name);
}

string JskimPlayer::getStudentNumber()
{
    return m_studentNumber;
}

string JskimPlayer::getName()
{
    return m_name;
}

int JskimPlayer::getTrials()
{
    return m_trials;
}

int JskimPlayer::getMatchedPairCount()
{
    return m_matchedPairCount;
}

void JskimPlayer::setStudentNumber(const string studentNumber)
{
    m_studentNumber = studentNumber;
}

void JskimPlayer::setName(const string name)
{
    m_name = name;
}

void JskimPlayer::setTrials()
{
    m_trials++;
}

void JskimPlayer::setMatchedPairCount()
{
    m_matchedPairCount++;
}

double JskimPlayer::getSuccessRate()
{
    double successRate= static_cast<double>(getMatchedPairCount())/getTrials();
    return truncate1(successRate);
}

double JskimPlayer::truncate1(double value)
{
    return trunc(value * 10) / 10;
}
