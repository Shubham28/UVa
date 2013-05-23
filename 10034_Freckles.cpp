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

using namespace std;

struct edge{
	int from,to;
	float wt;
};

int V,E;
float xcor[101],ycor[101];
int parent[101],len[101];
struct edge netw[5050];

int partition(int p,int r)
{
	int k=rand()%(r-p);
	swap(netw[p],netw[p+k]);

	int i=p;
	EFOR(j,p+1,r)
		if(netw[j].wt<=netw[p].wt){
			swap(netw[j],netw[i+1]);
			++i;
		}

	swap(netw[i],netw[p]);
	return i;
}

void quickSort(int p,int r)
{
	if(p<r){
		int q=partition(p,r);
		quickSort(p,q-1);
		quickSort(q+1,r);
	}
	return;
}

int findparent(int node)
{
	if(parent[node]==node)
		return node;
	else
		return findparent(parent[node]);
}

bool samecomp(int from,int to)
{
	return (findparent(from)==findparent(to));
}

void unioncomp(int fir,int sec)
{
	int parfr=findparent(fir),parsc=findparent(sec);
	if(parfr==parsc)
		return;

	if(len[parfr]>=len[parsc])
		len[parfr]+=len[parsc],parent[parsc]=parfr;
	else
		len[parsc]+=len[parfr],parent[parfr]=parsc;
	return;
}

float Kruskal()
{
	quickSort(0,E-1);

	FOR(init,0,V)
		parent[init]=init,len[init]=1;

	float cost=0.0f;
	FOR(span,0,E){
		int frm=netw[span].from,tonode=netw[span].to;
		if(!samecomp(frm,tonode)){
			unioncomp(frm,tonode);
			cost+=netw[span].wt;
		}
	}
	return cost;
}

int main()
{
	int T;
	scanf("%d",&T);

	EFOR(cases,1,T){
		if(cases>=2)
			printf("\n");

		scanf("%d",&V);
		E=(V*(V-1))/2;

		FOR(inp,0,V)
			scanf("%f%f",&xcor[inp],&ycor[inp]);

		int cnt=0;
		FOR(i,0,V-1)
			FOR(j,i+1,V){
				netw[cnt].from=i,netw[cnt].to=j;
				netw[cnt].wt=sqrt(pow(float(xcor[i]-xcor[j]),2.0f)+pow(float(ycor[i]-ycor[j]),2.0f));
				++cnt;
			}

		float span=Kruskal();
		printf("%.2f\n",span);
	}

	return 0;
}
