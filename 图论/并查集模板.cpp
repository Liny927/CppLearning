/*
 * @Author: Hellcat
 * @Date: 2020-03-06 19:35:30
 */
#include <bits/stdc++.h>
using namespace std;

class Disjoint_set {
private:
	/* 数组模拟树，其下标所对应的值为相应的父节点 */
	vector<int> parent;
	/* 存储树的秩 */
	vector<int> rank;
public:
	/* 初始化 */
	Disjoint_set(vector<int> vec);
	/* 查找 */
	int Find(int item);
	/* 合并 */
	void Union(int node1, int node2);
};

Disjoint_set::Disjoint_set(vector<int> vec) {
	int length = vec.size();
	for (int i = 0; i < length; i++) {
		parent[vec[i]] = vec[i];
		/* 初始化秩 */
		rank[vec[i]] = vec[i];
	}
}

int Disjoint_set::Find(int item) {
    return parent[item] == item ? item :parent[item] =  Find(parent[item]);
}

void Disjoint_set::Union(int node1, int node2) { // 按秩合并优化
	int set1 = Find(node1);
	int set2 = Find(node2);
	/* node1 与 node2 属于同一个集合 */
	if (set1 == set2)
		return;
	/* set1的秩大于set2的秩，那么set2合并到set1 */
	if (rank[set1] > rank[set2]) {
		parent[set2] = set1;
	}
	/* set1的秩小于set2的秩，那么set1合并到set2 */
	else if (rank[set1] < rank[set2]) {
		parent[set1] = set2;
	}
	else {
		parent[set1] = set2;
		/* 两个秩相等，可任意合并到一个上，但是需要更新相应的rank */
		rank[set2] += 1;
	}
}

/* 查找的迭代实现 */
int Disjoint_set::Find(int item) {
	/* 保存item结点，最后更新父节点要使用 */
	int child = item;
	/* 找到根item */
	while (parent[item] != item) {
		item = parent[item];
	}
	while (child != item) {
		/* 先保存父节点 */
		int tmp = parent[child];
		/* 父节点指向根item */
		parent[child] = item;
		child = tmp;
	}
	return item;
}
