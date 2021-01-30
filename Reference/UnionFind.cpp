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
		parent[x] = y;	//x�� ��Ʈ�� y��
		weight[y] += weight[x];	//y�������µ� �ɸ��� ���� x�� �߰�
		weight[x] = 1;	//y����ġ�� �ʱ�ȭ
	}
}