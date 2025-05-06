#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto command : commands)
    {
        int i = command[0] - 1;
        int j = command[1] - 1;
        int k = command[2] - 1;
        
        //cout << i << "," << j << "," << k << endl;
        
        vector<int> v(array.begin() + i, array.begin() + j + 1);
        sort(v.begin(), v.end());
        
        answer.push_back(v[k]);
    }
    
    return answer;
}