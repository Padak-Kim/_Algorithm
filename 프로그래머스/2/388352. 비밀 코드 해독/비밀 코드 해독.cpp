#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;

    vector<int> q_mask;
    
    for (int i = 0; i < q.size(); i++)
    {
        int mask = 0;
        for (int j = 0; j < 5; j++)
            mask |= (1 << (q[i][j] - 1));
        
        q_mask.push_back(mask);
    }
    
    //n C 5
    vector<bool> select(n, false);
    fill(select.end() - 5, select.end(), true);
    do
    {
        int secret = 0;
        for (int i = 0; i < select.size(); i++)
        {
            if (select[i]) 
                secret |= (1 << i);
        }
        
        bool check = true;
        // 개수 같은지 체크
        for (int i = 0; i < ans.size(); i++)
        {
            int match = __builtin_popcount(q_mask[i] & secret);
            if (match != ans[i])
            {
                check = false;
                break;
            }
        }
        
        if (check) answer++;
        
    } while (next_permutation(select.begin(), select.end()));
    
    return answer;
}