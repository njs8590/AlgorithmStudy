#include<iostream>
#include<map>

using namespace std;

int main(void)
{
	map<string, int> m_map;

	m_map["key11"] = 1;
	m_map["key22"] = 2;
	m_map["key33"] = 3;
	m_map["key44"] = 4;
	m_map["key55"] = 5;

	for (auto& map_temp : m_map) {
		cout << map_temp.first << ":" << map_temp.second << endl;
	}

	return 0;
}