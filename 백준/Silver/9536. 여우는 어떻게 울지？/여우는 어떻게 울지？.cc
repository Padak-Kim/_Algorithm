#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        string line;

        getline(cin >> ws, line);

        stringstream ss(line);
        vector<string> tokens;
        string word;

        while (ss >> word)
            tokens.push_back(word);

        unordered_set<string> us;

        string s;
        while (true) {
            s = "";
            getline(cin, s);

            if (s == "what does the fox say?")
                break;

            stringstream ss2(s);
            string left, mid, right;

            ss2 >> left >> mid >> right;

            us.insert(right);
        }

        int idx = 0;
        for (auto& token : tokens)
        {
            if (us.find(token) != us.end())
                continue;
            cout << token;

            idx++;
            if (tokens.size() != idx)
                cout << " ";
        }
    }

}
