//http://codekata.com/kata/kata13-counting-code-lines/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/************************ LineCounter ************************/
class LineCounter
{
public:
	LineCounter(string filename);
	~LineCounter();
	void countLines();
	void removeComments();
	unsigned getCounter() { return counter;};
private:
	ifstream file;
	unsigned counter;
	string source;
};

LineCounter::LineCounter(string filename)
{
	file.open(filename, std::fstream::in | std::fstream::app);
	getline(file, source);
}

LineCounter::~LineCounter()
{
	file.close();
}

void LineCounter::countLines()
{
	while (getline(file, source))
	{
		removeComments();
		if(source.empty()) continue;
		++counter;
	}
}

void LineCounter::removeComments()
{
	while (source.find("/*") != std::string::npos) {
		size_t Beg = source.find("/*");
		source.erase(Beg, (source.find("*/", Beg) - Beg) + 2);
	}
	while (source.find("//") != std::string::npos) {
		size_t Beg = source.find("//");
		source.erase(Beg, source.find("\n", Beg) - Beg);
	}
}


/************************ main ************************/

int main() {

	LineCounter * counter = new LineCounter("example.txt");
	counter->countLines();
	cout << counter->getCounter() << endl;

	system("pause");
}