#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;
deque<int> dq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string func;
        cin >> func;
        int n;
        cin >> n;
        string arr;
        cin >> arr;

        string num = "";

        for (int i = 0; i < arr.length(); i++)
        {
            if (arr[i] == '[')
                continue;
            
            if (arr[i] >= '0' && arr[i] <= '9')
            {
                num.push_back(arr[i]);
            }
            if (arr[i] == ',' || arr[i] == ']')
            {
                if (num != "") 
                {
                    dq.push_back(stoi(num));
                    num = "";
                }
            }
        }

        bool reverse = false;
        bool error = false;
        for (int i = 0; i < func.length(); i++)
        {
            if (func[i] == 'D')
            {
                if (dq.empty())
                {
                    cout << "error" << "\n";
                    error = true;
                    break;
                }
                if (reverse)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
            else
            {
                reverse = !reverse;
            }
        }
        
        if (error)
            continue;

        cout << "[";
        while (!dq.empty())
        {
            if (reverse)
            {
                cout << dq.back();
                dq.pop_back();
            }
            else
            {
                cout << dq.front();
                dq.pop_front();
            }         
            if (dq.empty())
                break;
            else
                cout << ",";
        }
        cout << "]\n";

        reverse = false;
    }

    return 0;
}