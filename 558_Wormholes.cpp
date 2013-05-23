#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int V,E,S;
VI dist,parent;
vector< VI >adjaclist,weights;

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

bool RelaxAllChk()
{
	bool change=false;
	FOR(allv,0,V)
		FOR(alled,0,SZ(adjaclist[allv])){
			int fr=allv,to=adjaclist[allv][alled];
			if(dist[to]>dist[fr]+weights[fr][alled])
				change=true,dist[to]=dist[fr]+weights[fr][alled];
		}

	return change;
}

bool BellmanFord()
{
	dist.assign(V,99999999),parent.assign(V,-1);
	dist[S]=0,parent[S]=S;

	bool change=true;
	for(int cnt=1;cnt+1<=V && change;cnt++)
		change=RelaxAllChk();

	if(RelaxAllChk())
		return false;
	return true;
}

int main()
{//	freopen("Input.txt","r",stdin);
	int T;
	Input(T);
	while(T--){
		Input(V),Input(E);
		adjaclist.assign(V,VI()),weights.assign(V,VI());

		FOR(inp,0,E){
			int fr,to,wt;
			Input(fr),Input(to),Input(wt);
			PB(adjaclist[fr],to);
			PB(weights[fr],wt);
		}
		S=0;

		if(BellmanFord())
			printf("not possible\n");
		else
			printf("possible\n");
	}
	return 0;
}
