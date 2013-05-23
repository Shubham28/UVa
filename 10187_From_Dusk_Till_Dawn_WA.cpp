#include <vector>
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
#define VS vector<string>
#define SZ(A) int(A.size())

using namespace std;

struct vert{
	int conectd,weight,clks;
	struct vert *next;
};

int V,E;
int source,dest;

inline bool possible(int &start, int &tot)
{
	if( (start<=6 || (18<=start && start<=30)) && (start+tot<=6 || (18<=start+tot && start+tot<=30)) )
		return true;
	return false;
}

inline int index(VS &vertnum,string &vrtx)
{
	FOR(pos,0,SZ(vertnum))
		if(vertnum[pos]==vrtx)
			return pos;
	return -1;
}

inline int match(int cur, int depar, int tot)
{
	int rem=cur%24,slot=depar;
	if(rem<=6){
		if(slot<=6)
			return (rem<=slot)?(cur-(cur%24)+depar+tot):(cur+24-(cur%24)+depar+tot);
		else
			return (cur-(cur%24)+depar+tot);
	} else {
		if(slot<=6)
			return (cur+24-cur%24+depar+tot);
		else
			return (rem<=slot)?(cur-(cur%24)+depar+tot):(cur+24-(cur%24)+depar+tot);
	}
}

int modDijkstra(struct vert *vertex[])
{
	VB span(V);
	VI dist(V,9999999);

	dist[source]=0;
	int ver=source,done=18;

	while(span[ver]==false){
		span[ver]=true;
		struct vert *tmp;
		tmp=vertex[ver];	//cout<<"\n"<<ver<<"\t";

		while(tmp!=NULL){
			int wt=tmp->weight,takes=tmp->clks;
			int chk=tmp->conectd;//	cout<<chk<<":"<<takes<<","<<wt<<"\t";
			int sched=match(done,takes,wt);

			if(dist[chk]>sched)
				dist[chk]=sched;
			tmp=tmp->next;
		}

		int chosen=0,minim=9999999;
		FOR(all,0,V)
			if(span[all]==false && minim>dist[all])
				minim=dist[all],chosen=all;
		done=minim,ver=chosen;	//	FOR(pr,0,V)	cout<<dist[pr]<<" ";	cout<<"\n";
	}

	if(dist[dest]>=999999)
		return -1;

	return dist[dest];
}

int main()
{
//	freopen("Input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	EFOR(cases,1,T){
		scanf("%d",&E);

		struct vert *vertex[101];
		FOR(init,0,101)
			vertex[init]=NULL;

		char frmver[33],tover[33];
		int from,to,start,hrs;
		string cnvfr,cnvto;

		VS name;

		FOR(inp,0,E){
			scanf("%s%s%d%d",frmver,tover,&start,&hrs);
			if(!possible(start,hrs))
				continue;

			cnvfr.assign(frmver),cnvto.assign(tover);

			int fir=index(name,cnvfr);
			if(fir==-1)
				PB(name,cnvfr);
			from=(fir==-1)?SZ(name)-1:fir;

			int sec=index(name,cnvto);
			if(sec==-1)
				PB(name,cnvto);
			to=(sec==-1)?SZ(name)-1:sec;

			struct vert *tmp;
			tmp=new vert;
			tmp->conectd=to,tmp->weight=hrs,tmp->clks=start;
			tmp->next=vertex[from];
			vertex[from]=tmp;
		}
		V=SZ(name);
		bool done=true;

		scanf("%s%s",frmver,tover);
		cnvfr.assign(frmver),cnvto.assign(tover);
		source=index(name,cnvfr),dest=index(name,cnvto);

		if(source==-1 || dest==-1)
			done=false;

		int shrtst=(done)?modDijkstra(vertex):-1;
		printf("Test Case %d.\n",cases);
		if(shrtst==-1)
			printf("There is no route Vladimir can take.\n");
		else {
			int blood=shrtst/24+(shrtst%24>=12)-1;
			printf("Vladimir needs %d litre(s) of blood.\n",blood);
		}
	}

	return 0;
}
