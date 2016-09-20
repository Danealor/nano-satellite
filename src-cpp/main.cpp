#include <cstdio>
#include <fstream>
#include "analyzer.h"

using namespace std;

int main(int argc, const char* argv[])
{
	if (argc != 2)
	{
		cout << "Incorrect number of arguments." << endl;
		cout << "Correct usage: " << argv[0] << " [Filename]" << endl;
		return 1;
	}
	string filename = argv[1];
	ifstream file;
	file.open(filename);

	if (file)
	{
		for (Word word : analyze(file))
			cout << word << endl;
	}
	else
	{
		cout << "File failed to open." << endl;
		return 2;
	}

	return 0;
}