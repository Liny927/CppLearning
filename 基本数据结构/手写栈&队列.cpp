/*
 * @Author: Hellcat
 * @Date: 2020-03-08 19:53:15
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

// ==========ջ=======
int stk[N], tt;

int opt_stk() {
    int x;
    // ����
    stk[++tt] = x;
    // ����
    tt--;
    // �ж�ջ�Ƿ�Ϊ��
    if(tt > 0) return 0;
    else return 1;
    // ����ջ��Ԫ��
    return stk[tt];
}

// ========����=========
// �ڶ�β����Ԫ�� ��ͷ����Ԫ��
int q[N], hh, tt = -1;

int opt_que() {
    int x;
    // ����
    q[++tt] = x;
    // ����
    hh++;
    // �ж϶����Ƿ�Ϊ��
    if(hh <= tt) return 0;
    else return 1;
    // ȡ����ͷԪ��
    return q[hh];
}
