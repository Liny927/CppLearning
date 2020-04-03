/*
 * @Author: Hellcat
 * @Date: 2020-03-06 21:25:08
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int heap[N], n;

int GetTop() {
    return heap[1];
}

void up(int p) {
    while(p > 1) {
        if(heap[p] < heap[p/2]) { // 比较子节点父节点
            swap(heap[p], heap[p/2]);
            p /= 2;
        }
        else break;
    }
}

void Insert(int val) {
    heap[++n] = val;
    up(n);
}

void down(int p) {
    int s = p*2;
    while(s <= n) {
        if(s < n && heap[s] > heap[s + 1]) s++;
        if(heap[s] < heap[p]) {
            swap(heap[s], heap[p]);
            p = s, s = p*2;
        }
        else break;
    }
}

void Extract() { // 移除堆顶
    heap[1] = heap[n--];
    down(1);
}

void Remove(int k) {
    heap[k] = heap[n--];
    up(k), down(k);
}

