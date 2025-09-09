#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// ["코드 번호(code)", "제조일(date)", "최대 수량(maximum)", "현재 수량(remain)"]
// 어떤 정보를 기준으로 데이터를 뽑아낼지를 의미하는 문자열 ext
// 뽑아낼 정보의 기준값을 나타내는 정수 val_ext
// 정보를 정렬할 기준이 되는 문자열 sort_by

// data에서 ext 값이 val_ext보다 작은 데이터만 뽑은 후, sort_by에 해당하는 값을 기준으로 오름차순으로 정렬

int StringToIdx(string s)
{
    int idx = -1;
    if (s == "code")
        idx = 0;
    else if (s == "date")
        idx = 1;
    else if (s == "maximum") 
        idx = 2;
    else 
        idx = 3;
    
    return idx;
}
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    int ext_idx = StringToIdx(ext);
    
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][ext_idx] >= val_ext)
            continue;
        
        //cout << data[i][ext_idx] << " >= " << val_ext << endl;
        answer.push_back(data[i]);
    }
    
    int sort_idx = StringToIdx(sort_by);
    sort(answer.begin(), answer.end(), [&](const vector<int>& a, const vector<int>& b){
         return a[sort_idx] < b[sort_idx];
    });
    return answer;
}