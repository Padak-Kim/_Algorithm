#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int max_width = 0;
    int max_height = 0;
    
    for (auto size : sizes)
    {
        if (size[0] < size[1])
        {
            swap(size[0], size[1]);
        }
        
        max_width = max(max_width, size[0]);
        max_height = max(max_height, size[1]);
    }
    answer = max_width * max_height;
    return answer;
}