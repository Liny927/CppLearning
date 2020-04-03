/*
 * @Author: Hellcat
 * @Date: 2020-01-19 22:10:39
 * POJ3984 二维迷宫bfs
 */
#include<iostream>
#include<cstring>
#include<queue>
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qaq(a,b) for(int k = (a); k > (b); --k)
using namespace std;

int maze[5][5];	//迷宫
typedef pair<int,int> P;
P nex[5][5];	//记录某个点的下一个点是什么
bool vis[5][5];	//判断该点是否走过
int to[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

void bfs(){
	queue<P> que;	//创建一个队列
	que.push(P(4,4));	//假设从后往前遍历，先把第一个状态加入队列
	vis[4][4] = true;	//标记走过
	while(que.size()){	//如果队列不为空就继续循环
		//从队列前端取出元素
		P p = que.front(); que.pop();
		//如果达到左上角(终点)就终止
		if(p.first == 0 && p.second == 0) break;
		for(int i = 0; i < 4; i++){	//往上下左右四个方向遍历，满足条件就加入队列
			int nx = p.first + to[i][1], ny = p.second + to[i][0];
			if(0 <= nx && nx < 5 && ny >= 0 && ny < 5 && vis[nx][ny] == 0 && maze[nx][ny] != 1){	//判断是否符合
				//满足条件 加入队列
				que.push(P(nx,ny));
				vis[nx][ny] = true;  //标记一下
				nex[nx][ny].first = p.first;		//记录该点的下一个坐标
				nex[nx][ny].second = p.second;
			}
		}
	}
}

void printf(){
	int x=0,y=0;
	while(!(x == 4 && y == 4)){
		cout<<"("<<x<<", "<<y<<")"<<endl;
		int tempX = x, tempY = y;
		x = nex[tempX][tempY].first;
		y = nex[tempX][tempY].second;
	}
	cout<<"("<<x<<", "<<y<<")";
}

int main(){
	qwq(0,5)
		qeq(0,5)
            cin>>maze[i][j];
    memset(vis,false,sizeof(vis));	//将其置为未走过
    bfs();
    printf();
}