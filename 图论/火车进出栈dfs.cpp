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
    // 按字典序输出 则出栈先
    if(state2.size()) { // 出栈
        state1.push_back(state2.top());
        state2.pop();
        dfs();
        state2.push(state1.back()); // 回溯
        state1.pop_back();
    }
    if(state3 <= n) { // 入栈
        state2.push(state3);
        state3++;
        dfs();
        state3--; // 回溯
        state2.pop();
    }
}

int main() {
    scanf("%d", &n);
    dfs();
    printf("%d\n", res);
}
