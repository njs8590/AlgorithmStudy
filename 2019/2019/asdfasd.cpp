int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

union(int x, int y) {
	x = find(x);
	y = find(y);

	if (x != y) {
		parent[x] = y;
		weight[y] += weight[x];
		weight[x] = 1
	}

	return weight[y];
}