#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define VI vector<int>
#define LL long long

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

struct cube
{
	int faces[6];
	int depths[6];
	pair<int,int>parent[6];
};

int N;
struct cube each[501];

inline void prntSide(int side)
{
	switch(side){
		case 0:	printf("front\n");	break;
		case 1: printf("back\n");	break;
		case 2:	printf("left\n");	break;
		case 3:	printf("right\n");	break;
		case 4:	printf("top\n");	break;
		case 5:	printf("bottom\n");	break;
	}
	return;
}

void printSeq(int ind,int side)
{
	if(each[ind].depths[side]==1){
		printf("%d ",ind+1);
		prntSide(side);
		return;
	}

	int frnt=each[ind].parent[side].second;
	int opos=(frnt%2==1)?(frnt-1):(frnt+1);

	printSeq(each[ind].parent[side].first,opos);
	printf("%d ",ind+1);
	prntSide(side);

	return;
}

int main()
{
	int cases=0;

	Input(N);
	while(N!=0){
		int ans=1,ind=0,side=0;

		++cases;
		if(cases>=2)
			printf("\n");

		FOR(all,0,6){
			each[0].depths[all]=1;
			each[0].parent[all]=make_pair(0,all);
		}

		FOR(inp,0,N){

			FOR(col,0,6)
				Input(each[inp].faces[col]);

			FOR(all,0,6){
				each[inp].depths[all]=1;
				each[inp].parent[all]=make_pair(inp,all);
				FOR(chk,0,inp)

					FOR(mtch,0,6)

						if(each[inp].faces[all]==each[chk].faces[mtch]){
							int opos=(mtch%2==1)?(mtch-1):(mtch+1);

							if(each[inp].depths[all]<(each[chk].depths[opos]+1)){
								each[inp].depths[all]=each[chk].depths[opos]+1;
								each[inp].parent[all]=make_pair(chk,mtch);
							}
						}

					if(ans<each[inp].depths[all])
						ans=each[inp].depths[all],ind=inp,side=all;
			}
		}
		printf("Case #%d\n%d\n",cases,ans);
		printSeq(ind,side);

		Input(N);
	}

	return 0;
}
