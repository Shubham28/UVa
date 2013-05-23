#include <list>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0'||ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

int V;
list<int>con[5005];
int levl[5005],P[5005];
int E[15005],L[15005],H[5005];

int dn;
void DFS(int vrt,int lv)
{
	levl[vrt]=lv;
	E[dn]=vrt,L[dn]=lv;
	if(H[vrt]==-1)
		H[vrt]=dn;
	dn++;

	for(list<int>::iterator nb=con[vrt].begin();nb!=con[vrt].end();nb++)
		if(levl[*nb]==-1){
			P[*nb]=vrt;
			DFS(*nb,lv+1);

			E[dn]=vrt,L[dn]=lv;
			dn++;
		}

	return;
}

int N,fr,to;
int RM[1<<15];

void init(int ind,int st,int end)
{
	if(st==end)		RM[ind]=st;
	else {
		int nxt=ind<<1,mid=(st+end)>>1;
		init(nxt,st,mid);
		init(nxt+1,mid+1,end);

		if(L[RM[nxt]]<=L[RM[nxt+1]])
			RM[ind]=RM[nxt];
		else
			RM[ind]=RM[nxt+1];
	}
	return;
}

int query(int ind,int st,int end)
{
	int p1,p2;

	if(fr>end || to<st)		return -1;

	if(st>=fr && end<=to)		return RM[ind];

	int nxt=ind<<1,mid=(st+end)>>1;
	p1=query(nxt,st,mid);
	p2=query(nxt+1,mid+1,end);

	if(p1==-1)		return p2;
	if(p2==-1)		return p1;
	if(L[p1]<=L[p2])		return p1;

	return p2;
}

int main()
{
	Input(V);
	while(V!=0){

		EFOR(cl,0,V)
			con[cl].clear();

		FOR(ed,0,V-1){
			int fr,to;
			Input(fr),Input(to);
			PB(con[fr-1],to-1);
			PB(con[to-1],fr-1);
		}

		int root=V>>1;

		P[root]=root;
		MEM(levl,-1);	MEM(H,-1);		dn=0;
		DFS(root,0);

		init(1,0,dn-1);

		int Q;
		Input(Q);
		while(Q--){
			int src,dest;
			Input(src),Input(dest);
			src--,dest--;

			fr=H[src],to=H[dest];
			if(fr>to)	swap(fr,to);

			int LCA=E[query(1,0,dn-1)];
			int dis=levl[src]+levl[dest]-2*levl[LCA];

			if(dis&1){
				int nb1,nb2;
				int mid=dis>>1,mt;

				if(levl[src]-levl[LCA]>=mid+1){
					mt=src;
					for(int jmp=1;jmp<=mid;mt=P[mt],jmp++);
				} else{
					mt=dest;
					for(int jmp=1;jmp<=mid;mt=P[mt],jmp++);
				}
				nb1=mt+1,nb2=P[mt]+1;

				if(nb1>=nb2)	swap(nb1,nb2);
				printf("The fleas jump forever between %d and %d.\n",nb1,nb2);

			} else {
				int mid=dis>>1,mt;

				if(levl[src]-levl[LCA]>=mid){
					mt=src;
					for(int jmp=1;jmp<=mid;mt=P[mt],jmp++);
				} else {
					mt=dest;
					for(int jmp=1;jmp<=mid;mt=P[mt],jmp++);
				}
				printf("The fleas meet at %d.\n",mt+1);
			}
		}

		Input(V);
	}

	return 0;
}
