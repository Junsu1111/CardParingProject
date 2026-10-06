#pragma once
#include <string>

using namespace std;

class JskimPlayer
{
private:
	string m_studentNumber;
	string m_name;
	int m_trials=0;
	int m_matchedPairCount=0;
public:
	JskimPlayer();
	JskimPlayer(const string studentNumber, const string name);
	string getStudentNumber();
	string getName();
	int getTrials();
	int getMatchedPairCount();
	void setStudentNumber(const string studentNumber);
	void setName(const string name);
	void setTrials();
	void setMatchedPairCount();
	double getSuccessRate();
	double truncate1(double value);
};

