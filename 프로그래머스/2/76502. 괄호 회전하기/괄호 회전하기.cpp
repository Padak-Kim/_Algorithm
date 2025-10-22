#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool IsValid(string str)
{
    stack<char> s;
    for(char& c : str)
    {
        if (c == '[' || c == '(' || c == '{')
            s.push(c);
        else
        {
            if (s.empty())
                return false;
            else
            {
                char t = s.top();
                
                if ((c == ']' && t == '[') || (c == ')' && t == '(') || (c == '}' && t == '{'))
                    s.pop();
                else
                    return false;
            }
        }
    }
    if (s.empty())
        return true;
    else
        return false;
}

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if (IsValid(s))
            answer++;
        string temp = "";
        char c = s.front();
        temp = s.substr(1);
        temp += c;
        
        s = temp;
    }
    
    return answer;
}