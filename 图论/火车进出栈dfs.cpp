/*
 * @Author: Hellcat
 * @Date: 2020-02-25 14:34:48
 */
#include <bits/stdc++.h>
using namespace std;

int n, cnt = 20;
vector<int> state1;
stack<int> state2;
int state3 = 1;

int res = 0;

void dfs() {
    if(!cnt) return;
    if(state1.size() == n) {
        res++;
        cnt--;
        for(auto x : state1) cout<<x;
        puts("");
        return;
    }
    // ���ֵ������ ���ջ��
    if(state2.size()) { // ��ջ
        state1.push_back(state2.top());
        state2.pop();
        dfs();
        state2.push(state1.back()); // ����
        state1.pop_back();
    }
    if(state3 <= n) { // ��ջ
        state2.push(state3);
        state3++;
        dfs();
        state3--; // ����
        state2.pop();
    }
}

int main() {
    scanf("%d", &n);
    dfs();
    printf("%d\n", res);
}
