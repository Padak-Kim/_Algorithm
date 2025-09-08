#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;

    sort(mats.begin(), mats.end(), greater<int>());
    
    for (int n : mats)
    {
        if (n >= park.size() && n >= park[0].size())
            continue;
        
        bool ok = false;
        for(int y = 0; y + n - 1 < park.size() && !ok; y++)
        {
            for (int x = 0; x + n - 1 < park[0].size() && !ok; x++)
            {
                bool can = true;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if (park[y+i][x+j] != "-1"){
                            can = false;
                            break;
                        }
                    }      
                }
                if (can) ok = true;
            }
        }
        if (ok) return n;
    }
    
    return -1;
}