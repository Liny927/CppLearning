/*
 * @Author: Hellcat
 * @Date: 2020-03-06 19:35:30
 */
#include <bits/stdc++.h>
using namespace std;

class Disjoint_set {
private:
	/* ����ģ���������±�����Ӧ��ֵΪ��Ӧ�ĸ��ڵ� */
	vector<int> parent;
	/* �洢������ */
	vector<int> rank;
public:
	/* ��ʼ�� */
	Disjoint_set(vector<int> vec);
	/* ���� */
	int Find(int item);
	/* �ϲ� */
	void Union(int node1, int node2);
};

Disjoint_set::Disjoint_set(vector<int> vec) {
	int length = vec.size();
	for (int i = 0; i < length; i++) {
		parent[vec[i]] = vec[i];
		/* ��ʼ���� */
		rank[vec[i]] = vec[i];
	}
}

int Disjoint_set::Find(int item) {
    return parent[item] == item ? item :parent[item] =  Find(parent[item]);
}

void Disjoint_set::Union(int node1, int node2) { // ���Ⱥϲ��Ż�
	int set1 = Find(node1);
	int set2 = Find(node2);
	/* node1 �� node2 ����ͬһ������ */
	if (set1 == set2)
		return;
	/* set1���ȴ���set2���ȣ���ôset2�ϲ���set1 */
	if (rank[set1] > rank[set2]) {
		parent[set2] = set1;
	}
	/* set1����С��set2���ȣ���ôset1�ϲ���set2 */
	else if (rank[set1] < rank[set2]) {
		parent[set1] = set2;
	}
	else {
		parent[set1] = set2;
		/* ��������ȣ�������ϲ���һ���ϣ�������Ҫ������Ӧ��rank */
		rank[set2] += 1;
	}
}

/* ���ҵĵ���ʵ�� */
int Disjoint_set::Find(int item) {
	/* ����item��㣬�����¸��ڵ�Ҫʹ�� */
	int child = item;
	/* �ҵ���item */
	while (parent[item] != item) {
		item = parent[item];
	}
	while (child != item) {
		/* �ȱ��游�ڵ� */
		int tmp = parent[child];
		/* ���ڵ�ָ���item */
		parent[child] = item;
		child = tmp;
	}
	return item;
}
