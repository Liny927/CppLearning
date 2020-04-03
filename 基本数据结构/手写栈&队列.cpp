/*
 * @Author: Hellcat
 * @Date: 2020-03-08 19:53:15
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

// ==========栈=======
int stk[N], tt;

int opt_stk() {
    int x;
    // 插入
    stk[++tt] = x;
    // 弹出
    tt--;
    // 判断栈是否为空
    if(tt > 0) return 0;
    else return 1;
    // 返回栈顶元素
    return stk[tt];
}

// ========队列=========
// 在队尾插入元素 队头弹出元素
int q[N], hh, tt = -1;

int opt_que() {
    int x;
    // 插入
    q[++tt] = x;
    // 弹出
    hh++;
    // 判断队列是否为空
    if(hh <= tt) return 0;
    else return 1;
    // 取出队头元素
    return q[hh];
}
