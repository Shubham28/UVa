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
#define SZ(A) int(A.size())

using namespace std;

char dict[25001][17];
short len[25001];
int depth[25001];
int N;
vector< VI >adjacList;

inline bool connected(int from, int to)
{
	bool del=false;
	if(abs(len[from]-len[to])>=2)
		return false;
	else if(abs(len[from]-len[to])==1)
		del=true;

	bool differ=false;
	for(short fir=0,sec=0;fir<len[from] && sec<len[to];fir++,sec++)

		if(dict[from][fir]!=dict[to][sec]){
			if(differ)
				return false;
			differ=true;
			if(del){
				if(len[from]<len[to])
					--fir;
				else
					--sec;
			}
		}

	return true;
}

inline void Visit(int root)
{
	FOR(all,0,SZ(adjacList[root])){
		int to=adjacList[root][all];
		depth[root]>?=(1+depth[to]);
	}
	return;
}

int main()
{
	N=0;
	char ch;

	ch=getchar();
	while(ch!=EOF){
		if(ch=='\n'){
			dict[N][len[N]]=0;
			++N;
		} else {
			dict[N][len[N]]=ch;
			++len[N];
		}
		ch=getchar();
	}
	dict[N][len[N]]=0;
	++N;

	adjacList.assign(N,VI());
	FOR(chk,0,N)
		FOR(pair,chk+1,N){
			if(connected(chk,pair))
				PB(adjacList[chk],pair);
		}

	int ans=0;
	memset(depth,-1,sizeof(depth));

	RFOR(from,N-1,0){
		depth[from]=1;
		Visit(from);
		ans>?=depth[from];
	}
	printf("%d\n",ans);

	return 0;
}
