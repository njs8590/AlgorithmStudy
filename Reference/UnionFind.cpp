//unionFind, disjointSet, MST, Kruskal,,,

#define ARRMAX 10000

int parent[ARRMAX];
int weight[ARRMAX];

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

void m_union(int x, int y) {
	x = find(x);
	y = find(y);

	if (x != y) {
		parent[x] = y;
	}
}

void m_union_weight(int x, int y) {
	x = find(x);
	y = find(y);

	if (x != y) {
		parent[x] = y;	//x의 루트를 y로
		weight[y] += weight[x];	//y까지가는데 걸리는 값을 x에 추가
		weight[x] = 1;	//y가중치는 초기화
	}
}