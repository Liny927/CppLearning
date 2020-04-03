/*
 * @Author: Hellcat
 * @Date: 2020-03-07 22:29:20
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

// head 头结点的下标
// e[i] 节点i的值
// ne[i] 节点i的next指针
// idx 存储当前已经用到了哪个点(当前指针)
int head, e[N], ne[N], idx;

void init() {
    head = -1;
    idx = 0;
}

void add_to_head(int x) { // 将x插入头节点
    e[idx] = x, ne[idx] = head, head = idx, idx++;
}

void add(int k, int x) { // 将x插入下标为k的点的后面
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

// 将下标为k的点的后一点删除
void remove(int k) {
    ne[k] = ne[ne[k]];
}

// 对于每个点k，开一个单链表，存储k所有可以走到的点。h[k]存储这个单链表的头结点
int h[N], e[N], ne[N], idx;

// 添加一条边a->b
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 初始化
void init() {
    idx = 0;
    memset(h, -1, sizeof h);
}
