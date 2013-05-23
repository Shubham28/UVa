#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
#define PII pair<int,int>

using namespace std;

PII lines[10005];
int N=0;

bool cmp(const PII p1,const PII p2){
	if(p1.first<p2.first)		return 1;
	if(p2.first<p1.first)		return 0;

	if(p1.second*p2.second<0)
		return p1.second>0;

	return (p1.second>=p2.second);
}

int main()
{
	int L,R,H;
	while(scanf("%d",&L)!=EOF){
		scanf("%d%d",&H,&R);
		if(L==R)	continue;

		lines[N++]=PII(L,H);
		lines[N++]=PII(R,-H);
	}
	sort(lines,lines+N,cmp);

	multiset<int>hts;
	multiset<int>::iterator it;
	bool first=1;

	FOR(j,0,N){
		PII prs=lines[j];
		int mx=(SZ(hts)>0)?*(--hts.end()):-1;

		if(prs.second>0 && prs.second>mx){
			if(!first)		printf(" ");

			first=0;
			printf("%d %d",prs.first,prs.second);
		} else if(prs.second<0 && -prs.second>=mx){
			int scMx=(SZ(hts)>1)?*(--(--hts.end())):0;

			if(scMx!=mx){
				if(!first)		printf(" ");
				printf("%d %d",prs.first,scMx);
			}
		}

		if(prs.second>0)
			hts.insert(prs.second);
		else {
			it=hts.find(-prs.second);
			hts.erase(it);
		}
	}
	cout<<"\n";

	return 0;
}
