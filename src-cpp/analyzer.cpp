#include <algorithm>
#include <string>
#include "analyzer.h"

using namespace std;

Word::Word(string Str, int Count) : str(Str), count(Count) {};

std::ostream& operator<<(std::ostream& os, const Word& word)
{
	os << word.str << ": " << word.count;
	return os;
}

vector<Word> analyze(istream& stream)
{
	vector<Word> words;
	words.reserve(25);

	string str;
	while (stream >> str)
	{
		removeCharsFromString(str, ",.:;'`~?!@#$%^&*()[]{}-_+=<>/|\\\""); // Remove punctuation
		transform(str.begin(), str.end(), str.begin(), tolower); // Remove capitalization
		int index = findIndex(words, str);
		if (index < words.size() && words[index].str == str)
			words[index].count++;
		else
			words.insert(words.begin() + index, Word(str));
	}
	return words;
}

int findIndex(const vector<Word>& words, const string& str, int begin, int end)
{
	if (words.size() == 0)
		return 0;
	if (begin == end + 1)
		return begin; // both extremes
	if (end == -2)
		end = words.size() - 1;
	int mid = (begin + end) / 2;
	string test = words[mid].str;
	if (test == str)
		return mid;
	if (test < str)
		return findIndex(words, str, mid + 1, end); // Bisection method by recursion
	else
		return findIndex(words, str, begin, mid - 1);
}

void removeCharsFromString(string &str, char* const charsToRemove) 
{
	str.erase(remove_if(str.begin(), str.end(), [&](const char& c) { return strchr(charsToRemove, c); }), str.end());
}