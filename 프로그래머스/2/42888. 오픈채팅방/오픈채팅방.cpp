#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> DB; // id, name
    unordered_map<string, string> RDB; // id, name
    vector<pair<string, string>> cmdList; // id, cmd
    for (string& str : record)
    {
        stringstream ss(str);
        
        string cmd;
        ss >> cmd;
        
        if (cmd == "Enter")
        {
            string id, name;
            ss >> id >> name;
            auto it = RDB.find(id);
            if (it != RDB.end())
                RDB.erase(id);
            DB.insert({id, name});
            cmdList.push_back({id, cmd});
        }
        else if (cmd == "Leave")
        {
            string id;
            ss >> id;
            string name = DB[id];
            DB.erase(id);
            RDB.insert({id, name});
            cmdList.push_back({id, cmd});
        }
        else // Change
        {
            string id, name;
            ss >> id >> name;
            DB[id] = name;
        }
    }
    
    for(int i = 0; i < cmdList.size(); i++)
    {
        auto [id, cmd] = cmdList[i];
        
        string str = "";
        auto it = DB.find(id);
        
        if (it == DB.end())
            str = RDB[id];
        else
            str = DB[id];
        
        if (cmd == "Enter")
            str += "님이 들어왔습니다.";
        else // Leave
            str += "님이 나갔습니다.";
        
        answer.push_back(str);
    }
    return answer;
}