#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>

using namespace std;

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

int main()
{
	int V,E;
	int adjlist[201][201];
	int len[201],color[201];

	Input(V);
	while(V!=0){
		Input(E);
		memset(len,0,sizeof(len));
		memset(color,-1,sizeof(color));

		FOR(inp,0,E){
			int from,to;
			Input(from),Input(to);
			adjlist[from][len[from]]=to;
			++len[from];
		}

		queue<int>brdth;
		bool flag=true;
		brdth.push(0);
		color[0]=0;

		while(!brdth.empty()){
			int node=brdth.front();
			brdth.pop();

			FOR(vis,0,len[node]){
				int to=adjlist[node][vis];
				if(color[to]==-1){
					color[to]=color[node]^1;
					brdth.push(to);
				} else if(color[to]==color[node]){
					flag=false;
					break;
				}
			}
			if(!flag)
				break;
		}
		if(flag)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");

		Input(V);
	}

	return 0;
}
