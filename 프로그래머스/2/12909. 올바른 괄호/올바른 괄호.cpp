#include <string>
#include <vector>
#include <stack>
using namespace std;

bool solution(string str)
{
	// '(' push ')' pop
	stack<char> s;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
			s.push('(');
		else // ')'
		{
			if (!s.empty())
				s.pop();
			else
				return false;
		}
	}
	if (!s.empty())
		return false;
	else
		return true;
}