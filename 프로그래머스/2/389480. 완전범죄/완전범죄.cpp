#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b)
{
    if (a[0] - a[1] == b[0] - b[1])
        return a[0] / a[1] > b[0] / b[1];
    else
        return a[0] - a[1] > b[0] - b[1];
}

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    sort(info.begin(), info.end(), compare);
    
    int resA = 0;
    int resB = 0;
    for(auto& a : info)
    {
        if (m > resB + a[1])
        {
            resB += a[1];
            continue;
        }
        else if (n > resA + a[0])
        {
            resA += a[0];
            continue;
        }
        else
        {
            return -1;
        }
        // cout << a[0] << ", " << a[1] << endl;
    }
    return resA;
}