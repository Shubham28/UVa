#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>

#define FOR(A,B,C) for(short A=B;A<C;A++)
#define EFOR(A,B,C) for(short A=B;A<=C;A++)
#define RFOR(A,B,C) for(short A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<short>
#define SZ(A) short(A.size())

using namespace std;

int main()
{
	vector< VI >cost(1001),track(1001);

	EFOR(fill,1,1000)
		EFOR(col,1,1001-fill){
			PB(cost[fill-1],9999);
			PB(track[fill-1],-1);
		}

	char inp[1001];
	short fir,sec;

	while(scanf("%s",inp)!=EOF){
		short N=strlen(inp);

		FOR(init,0,N)
			cost[init][0]=0,track[init][0]=0;

		EFOR(len,2,N)
			EFOR(start,0,N-len){

				if(inp[start]==inp[start+len-1])
					cost[start][len-1]=(len==2)?0:cost[start+1][len-3],track[start][len-1]=1;
				else {
					fir=cost[start+1][len-2]+1;
					sec=cost[start][len-2]+1;

					if(fir<=sec)
						cost[start][len-1]=fir,track[start][len-1]=2;
					else
						cost[start][len-1]=sec,track[start][len-1]=3;
				}
		}
		printf("%hd ",cost[0][N-1]);

		short tot=N+cost[0][N-1];
		char ans[tot+1];
		ans[tot]=0;

		short posr=0,posc=N-1,strt=0,end=tot-1;
		while(strt<=end){

			if(track[posr][posc]==0){
				ans[strt]=inp[posr];
				break;
			} else if(track[posr][posc]==1){
				ans[strt]=inp[posr],ans[end]=inp[posr];
				posr+=1,posc-=2;
			} else if(track[posr][posc]==2){
				ans[strt]=inp[posr],ans[end]=inp[posr];
				posr+=1,posc-=1;
			} else if(track[posr][posc]==3){
				ans[strt]=inp[posr+posc],ans[end]=inp[posr+posc];
				posc-=1;
			}
			strt+=1,end-=1;
		}
		FOR(prnt,0,tot+1)
			printf("%c",ans[prnt]);
		printf("\n");
	}

	return 0;
}
