/*
 * @Author: Hellcat
 * @Date: 2020-03-07 22:29:20
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

// head ͷ�����±�
// e[i] �ڵ�i��ֵ
// ne[i] �ڵ�i��nextָ��
// idx �洢��ǰ�Ѿ��õ����ĸ���(��ǰָ��)
int head, e[N], ne[N], idx;

void init() {
    head = -1;
    idx = 0;
}

void add_to_head(int x) { // ��x����ͷ�ڵ�
    e[idx] = x, ne[idx] = head, head = idx, idx++;
}

void add(int k, int x) { // ��x�����±�Ϊk�ĵ�ĺ���
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

// ���±�Ϊk�ĵ�ĺ�һ��ɾ��
void remove(int k) {
    ne[k] = ne[ne[k]];
}

// ����ÿ����k����һ���������洢k���п����ߵ��ĵ㡣h[k]�洢����������ͷ���
int h[N], e[N], ne[N], idx;

// ���һ����a->b
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// ��ʼ��
void init() {
    idx = 0;
    memset(h, -1, sizeof h);
}
