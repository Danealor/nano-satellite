#ifndef ANALYZER__H
#define ANALYZER__H

#include <iostream>
#include <vector>

struct Word
{
	std::string str;
	int count;

	Word(std::string = "", int = 1);
};

std::ostream& operator<<(std::ostream&, const Word&);
	
std::vector<Word> analyze(std::istream&);
int findIndex(const std::vector<Word>&, const std::string&, int = 0, int = -2);
void removeCharsFromString(std::string &str, char*);

#endif