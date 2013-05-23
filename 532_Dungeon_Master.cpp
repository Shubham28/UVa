#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define VS vector<string>
#define VB vector<bool>

using namespace std;

int L,R,C;
char dung[35][35][35];
int vis[35][35][35];

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

inline void visitDung(queue<int>&nodeL,queue<int>&nodeR,queue<int>&nodeC,int cellL,int cellR,int cellC,int depth)
{
	if(cellL<0 || cellL>=L || cellR<0 || cellR>=R || cellC<0 || cellC>=C)
		return;

	if(vis[cellL][cellR][cellC]!=-1 || dung[cellL][cellR][cellC]=='#')
		return;

	nodeL.push(cellL),nodeR.push(cellR),nodeC.push(cellC);
	vis[cellL][cellR][cellC]=depth+1;
	return;
}

int findPath()
{
	queue<int>nodeL,nodeR,nodeC;
	memset(vis,-1,sizeof(vis));

	FOR(stL,0,L)
		FOR(stR,0,R)
			FOR(stC,0,C)
				if(dung[stL][stR][stC]=='S'){
					nodeL.push(stL),nodeR.push(stR),nodeC.push(stC);
					vis[stL][stR][stC]=0;
					break;
				}

	while(!nodeL.empty()){
		int prsL=nodeL.front(),prsR=nodeR.front(),prsC=nodeC.front();
		nodeL.pop(),nodeR.pop(),nodeC.pop();

		int dpth=vis[prsL][prsR][prsC];
		if(dung[prsL][prsR][prsC]=='E')
			return dpth;

		visitDung(nodeL,nodeR,nodeC,prsL-1,prsR,prsC,dpth);visitDung(nodeL,nodeR,nodeC,prsL+1,prsR,prsC,dpth);
		visitDung(nodeL,nodeR,nodeC,prsL,prsR-1,prsC,dpth);visitDung(nodeL,nodeR,nodeC,prsL,prsR+1,prsC,dpth);
		visitDung(nodeL,nodeR,nodeC,prsL,prsR,prsC-1,dpth);visitDung(nodeL,nodeR,nodeC,prsL,prsR,prsC+1,dpth);
	}
	return -1;
}

int main()
{
	Input(L);Input(R);Input(C);

	while(L!=0 && R!=0 && C!=0){

		FOR(lev,0,L)
			FOR(row,0,R)
				scanf("%s",dung[lev][row]);

		int len=findPath();
		if(len!=-1)
			printf("Escaped in %d minute(s).\n",len);
		else
			printf("Trapped!\n");

		Input(L);Input(R);Input(C);
	}

	return 0;
}
