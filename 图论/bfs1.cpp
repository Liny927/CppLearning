/*
 * @Author: Hellcat
 * @Date: 2020-01-19 22:10:39
 * POJ3984 ��ά�Թ�bfs
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

int maze[5][5];	//�Թ�
typedef pair<int,int> P;
P nex[5][5];	//��¼ĳ�������һ������ʲô
bool vis[5][5];	//�жϸõ��Ƿ��߹�
int to[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

void bfs(){
	queue<P> que;	//����һ������
	que.push(P(4,4));	//����Ӻ���ǰ�������Ȱѵ�һ��״̬�������
	vis[4][4] = true;	//����߹�
	while(que.size()){	//������в�Ϊ�վͼ���ѭ��
		//�Ӷ���ǰ��ȡ��Ԫ��
		P p = que.front(); que.pop();
		//����ﵽ���Ͻ�(�յ�)����ֹ
		if(p.first == 0 && p.second == 0) break;
		for(int i = 0; i < 4; i++){	//�����������ĸ�������������������ͼ������
			int nx = p.first + to[i][1], ny = p.second + to[i][0];
			if(0 <= nx && nx < 5 && ny >= 0 && ny < 5 && vis[nx][ny] == 0 && maze[nx][ny] != 1){	//�ж��Ƿ����
				//�������� �������
				que.push(P(nx,ny));
				vis[nx][ny] = true;  //���һ��
				nex[nx][ny].first = p.first;		//��¼�õ����һ������
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
    memset(vis,false,sizeof(vis));	//������Ϊδ�߹�
    bfs();
    printf();
}