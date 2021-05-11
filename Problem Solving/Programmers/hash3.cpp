#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>

using namespace std;

typedef struct MUSIC {
	string genre;
	int play;
	int index;
};

bool desc(int a, int b) {
	return a > b;
}

int main()
{
	cout << "hello world" << endl;

	vector<string> genres = { "classic","pop","classic","classic","pop","hip" };
	vector<int> plays = { 500, 600, 150, 800, 2500,100 };

	//map<string,vector<int>>
	map<string, int> hash_sum;

	vector<MUSIC> struct_map;

	vector<int> rank;

	for (int i = 0; i < genres.size(); i++) {
		struct_map.push_back({ genres[i], plays[i], i });
		hash_sum[genres[i]] += plays[i];
	}
	
	for (auto it = hash_sum.begin(); it != hash_sum.end(); it++) {
		rank.push_back(it->second);
	}
	
	sort(rank.begin(), rank.end(), desc);

	queue<string> sequence;



	return 0;
}