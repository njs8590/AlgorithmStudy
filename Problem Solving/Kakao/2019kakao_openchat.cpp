/*
* problem: https://programmers.co.kr/learn/courses/30/lessons/42888
* algorithm:

1. 접속시: "~님이 들어왔습니다."
2. 퇴장시: "~님이 나갔습니다."
3. 닉네임변경방법: 나간 후, 새로운 닉네임으로 접속
                   채팅방에서 닉네임변경 
                   => 기존에 채팅방에 출력되어있던 메시지도 전부변경됨
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<sstream>
#include<map>

using namespace std;

// typedef
typedef struct REC
{
    int row;
    bool enter;
}REC;

typedef struct USER
{
    string nickname;
    vector<REC> recnum; // record 위치를 기억했다가 닉네임 변경시 이 변수를 참조해서 바꾼다
    
}USER;

// function pre-defined
vector<string> solution(vector<string> record);

// global var


int main(void)
{
    vector<string> record, answer;
    record.push_back("Enter uid1234 Muzi");
    record.push_back("Enter uid4567 Prodo");
    record.push_back("Leave uid1234");
    record.push_back("Enter uid1234 Prodo");
    record.push_back("Change uid4567 Ryan");

    answer = solution(record);

    for (int i = 0; i < (int)answer.size(); i++) {
        cout << answer[i] << endl;
    }
	return 0;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, USER> userdata; // key == userid

    for (int i = 0; i < (int)record.size(); i++) {
        stringstream ss(record[i]);
        string trx, uid, nick;

        ss >> trx;
        ss >> uid;
        ss >> nick; // 널이면 어케되냐..

        if (trx == "Enter"){ // 입장
            // 첫입장
            if (userdata.find(uid)==userdata.end()) {
                userdata[uid].nickname = nick;
                answer.push_back(nick + "님이 들어왔습니다.");
                userdata[uid].recnum.push_back({(int)answer.size()-1,true}); // answer에서 위치 기록
            }
            // 재입장
            else {
                userdata[uid].nickname = nick;
                // answer 기록 변경
                for (int j = 0; j < (int)userdata[uid].recnum.size(); j++) {
                    // 입장기록
                    if(userdata[uid].recnum[j].enter) answer[userdata[uid].recnum[j].row] = (nick + "님이 들어왔습니다.");
                    // 퇴장기록
                    else if (!userdata[uid].recnum[j].enter) answer[userdata[uid].recnum[j].row] = (nick + "님이 나갔습니다.");
                }
                answer.push_back(nick + "님이 들어왔습니다.");
                userdata[uid].recnum.push_back({ (int)answer.size() - 1,true }); // answer에서 위치 기록
            }
        }

        else if (trx == "Leave") { // 퇴장
            answer.push_back(userdata[uid].nickname + "님이 나갔습니다.");
            userdata[uid].recnum.push_back({ (int)answer.size() - 1,false }); // answer에서 위치 기록
        }

        else if (trx == "Change") {
            userdata[uid].nickname = nick;
            // answer 기록 변경
            for (int j = 0; j < (int)userdata[uid].recnum.size(); j++) {
                if (userdata[uid].recnum[j].enter) answer[userdata[uid].recnum[j].row] = (nick + "님이 들어왔습니다.");
                // 퇴장기록
                else if (!userdata[uid].recnum[j].enter) answer[userdata[uid].recnum[j].row] = (nick + "님이 나갔습니다.");
            }
        }
        
    }


    return answer;
}