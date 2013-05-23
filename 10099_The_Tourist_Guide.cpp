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
#define VB vector<bool>

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!=EOF)
		ch=getchar();

	sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

struct vert{
	int conectd,weight;
	struct vert *next;
};

int V,E;
int source,targ,tot;
int dist[101],span[101];

inline int modifDijkstra(struct vert *vertex[],int start)
{
	memset(span,0,sizeof(span));
	memset(dist,0,sizeof(dist));

	dist[start]=999999999;
	int ver=start;

	while(span[ver]==false){
		span[ver]=true;
		struct vert *tmp;
		tmp=vertex[ver];

		while(tmp!=NULL){
			int wt=tmp->weight;
			int chk=tmp->conectd;
			if(dist[chk]<min(dist[ver],wt))
				dist[chk]=min(dist[ver],wt);
			tmp=tmp->next;
		}

		int chosen=0,minim=0;
		FOR(all,0,V)
			if(span[all]==false && minim<dist[all])
				minim=dist[all],chosen=all;
		ver=chosen;
	}
	return dist[targ-1];
}

int main()
{
	int cases=0;
	Input(V),Input(E);

	while(V!=0 && E!=0){
		++cases;
		struct vert *vertex[V];

		FOR(init,0,V)
			vertex[init]=NULL;

		FOR(inp,0,E){
			int from,to,wt;
			Input(from),Input(to),Input(wt);
			from-=1,to-=1;

			struct vert *tmp;
			tmp=new vert;
			tmp->conectd=to,tmp->weight=wt;
			tmp->next=vertex[from];
			vertex[from]=tmp;
			struct vert *rev;
			rev=new vert;
			rev->conectd=from,rev->weight=wt;
			rev->next=vertex[to];
			vertex[to]=rev;
		}

		Input(source),Input(targ),Input(tot);
		if(source==targ)
			printf("Scenario #%d\nMinimum Number of Trips = 0\n\n",cases);
		else {
			int tmp=modifDijkstra(vertex,source-1);
			--tmp;
			tmp=(tot%tmp!=0)?(tot/tmp+1):(tot/tmp);
			printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",cases,tmp);
		}

		Input(V),Input(E);
	}

	return 0;
}
