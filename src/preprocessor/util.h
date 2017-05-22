#ifndef IOSTREAM_INCLUDED
	#define IOSTREAM_INCLUDED
	#include <iostream>
#endif

#ifndef VECTOR_INCLUDED
	#define VECTOR_INCLUDED	
	#include <vector>
#endif

using namespace std;

const vector<string> explode(const string &, const char &);
int indexOf(vector<string>, const string &);
bool isBlockComment(const string &, const int);
bool isComment(const string &, const int);
bool isLineComment(const string &, const int);
void trim(string &);

/* Split string into vector elements */
const vector<string> explode(const string& s, const char& c)
{
	string buff{""};
	vector<string> v;
	
	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);
	
	return v;
}

/* find the index of a element in a vector */
int indexOf(vector<string> v, const string & elem)
{
	for (int i = 0; (unsigned) i < v.size(); i++)
	{
		if (elem.compare(v[i]) == 0) return i;
	}

	return -1;
}

/* Return true if the character at pos is inside of a block comment */
bool isBlockComment(const string & code, const int pos)
{
	int blockCommentStartBefore = code.rfind("/*", pos);
	int blockCommentEndBefore = code.rfind("*/", pos);
	if (blockCommentStartBefore <= blockCommentEndBefore) return false;
	
	return true;
}

/* Return true if the character at pos is inside of a comment */
bool isComment(const string & code, const int pos)
{
	return (isLineComment(code, pos) || isBlockComment(code, pos));
}

/* Return true if the character at pos is inside of a line comment */
bool isLineComment(const string & code, const int pos)
{
	int newLineBefore = code.rfind("\n", pos) + 1;
	int newLineAfter = code.find("\n", pos);

	string line;
	if (newLineAfter == -1) code.substr(newLineBefore);
	else line = code.substr(newLineBefore, newLineAfter - newLineBefore);
	int lineComment = line.find("//");
	
	return ((lineComment != -1) && (lineComment < newLineBefore));
}

/* Remove the leading and trailing spaces */
void trim(string & s)
{
	size_t p = s.find_first_not_of(" \t\n");
	s.erase(0, p);

	p = s.find_last_not_of(" \t");
	if (string::npos != p)
		s.erase(p+1);
}

