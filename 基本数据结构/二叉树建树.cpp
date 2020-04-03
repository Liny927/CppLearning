/*
 * @Author: Hellcat
 * @Date: 2019-12-23 20:01:34
 * UVA 122 二叉树遍历 bfs + 队列
 */

#pragma GCC optime(2)
#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <ctype.h>
#include <algorithm>
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qaq(a,b) for(int k = (a); k > (b); --k)
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

char s[1010];
bool failed;

struct Node {
    bool have_value;
    int v;
    Node *left, *right;
    Node(void):have_value(false), left(nullptr), right(nullptr) {}
};
Node *root;
Node *newnode() { return new Node(); }

void addnode(int v, char *s) {
    int n = strlen(s);
    Node *u = root;
    qwq(0,n)
        if(s[i] == 'L') {
            if(u->left == nullptr) u->left = newnode();
            u = u->left;
        }
        else if(s[i] == 'R') {
            if(u->right == nullptr) u->right = newnode();
            u = u->right;
        }
    if(u->have_value) failed = 1;
    u->v = v;
    u->have_value = 1;
}

bool read_input() {
    failed = 0;
    remove_tree(root);
    root = newnode();
    for(;;) {
        if(scanf("%s", s) != 1) return 0;
        if(!strcmp(s, "()")) break;
        int v;
        sscanf(&s[1], "%d", &v);
        addnode(v,strchr(s, ',') + 1);
    }
    return 1;
}

void remove_tree(Node *u) {
    if(u == nullptr) return ;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}

bool bfs(vector<int> &ans) {
    queue<Node*> q;
    ans.clear();
    q.push(root);
    while(!q.empty()) {
        Node *u = q.front(); q.pop();
        if(!u->have_value) return 0;
        ans.push_back(u->v);
        if(u->left != nullptr) q.push(u->left);
        if(u->right != nullptr) q.push(u->right);
    }
    return 1;
}


int main()
{
    vector<int> ans;
    while(read_input())//录入
    {
        if(failed||!bfs(ans))   //构建的树不符合条件的
            printf("not complete\n");
        else
        {
            for(auto it = ans.begin(); it != ans.end(); it++){
                cout<<*it;
                if(it != ans.end() -1) cout<<' ';
            }
        cout<<endl;
        }
    }
    return 0;
}