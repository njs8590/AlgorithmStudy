/*
* problem: https://programmers.co.kr/learn/courses/30/lessons/42888
* algorithm:

1. ���ӽ�: "~���� ���Խ��ϴ�."
2. �����: "~���� �������ϴ�."
3. �г��Ӻ�����: ���� ��, ���ο� �г������� ����
                   ä�ù濡�� �г��Ӻ��� 
                   => ������ ä�ù濡 ��µǾ��ִ� �޽����� ���κ����
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
    vector<REC> recnum; // record ��ġ�� ����ߴٰ� �г��� ����� �� ������ �����ؼ� �ٲ۴�
    
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
        ss >> nick; // ���̸� ���ɵǳ�..

        if (trx == "Enter"){ // ����
            // ù����
            if (userdata.find(uid)==userdata.end()) {
                userdata[uid].nickname = nick;
                answer.push_back(nick + "���� ���Խ��ϴ�.");
                userdata[uid].recnum.push_back({(int)answer.size()-1,true}); // answer���� ��ġ ���
            }
            // ������
            else {
                userdata[uid].nickname = nick;
                // answer ��� ����
                for (int j = 0; j < (int)userdata[uid].recnum.size(); j++) {
                    // ������
                    if(userdata[uid].recnum[j].enter) answer[userdata[uid].recnum[j].row] = (nick + "���� ���Խ��ϴ�.");
                    // ������
                    else if (!userdata[uid].recnum[j].enter) answer[userdata[uid].recnum[j].row] = (nick + "���� �������ϴ�.");
                }
                answer.push_back(nick + "���� ���Խ��ϴ�.");
                userdata[uid].recnum.push_back({ (int)answer.size() - 1,true }); // answer���� ��ġ ���
            }
        }

        else if (trx == "Leave") { // ����
            answer.push_back(userdata[uid].nickname + "���� �������ϴ�.");
            userdata[uid].recnum.push_back({ (int)answer.size() - 1,false }); // answer���� ��ġ ���
        }

        else if (trx == "Change") {
            userdata[uid].nickname = nick;
            // answer ��� ����
            for (int j = 0; j < (int)userdata[uid].recnum.size(); j++) {
                if (userdata[uid].recnum[j].enter) answer[userdata[uid].recnum[j].row] = (nick + "���� ���Խ��ϴ�.");
                // ������
                else if (!userdata[uid].recnum[j].enter) answer[userdata[uid].recnum[j].row] = (nick + "���� �������ϴ�.");
            }
        }
        
    }


    return answer;
}