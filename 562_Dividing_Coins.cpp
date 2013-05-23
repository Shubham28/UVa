#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() );
#define VI vector<int>

using namespace std;

int main()
{
	int cases;
	scanf("%d",&cases);

	while(cases--){
		int N,sum=0;
		scanf("%d",&N);

		VI num(N);
		FOR(c,0,N){
			scanf("%d",&num[c]);
			sum+=num[c];
		}

		vector< VI >S(sum/2+1,VI(N+1,0));

		EFOR(col,0,sum/2)
			S[col][0]=0;
		EFOR(row,0,N)
			S[0][row]=1;

		FOR(tot,1,S.size())
			FOR(pos,1,S[tot].size()){
				if(tot-num[pos-1]<0)
					S[tot][pos]=S[tot][pos-1];
				else 
					S[tot][pos]=max(S[tot][pos-1],S[tot-num[pos-1]][pos-1]);
			}

		bool found=false;
		int pos=sum/2,dif=-1;

		while(!found){
			++dif;
			FOR(col,0,S[pos].size())
				if(S[pos][col]==1){
					found=true;
					break;
				}
			--pos;
		}
		dif*=2;
		if(sum%2==1)
			++dif;

		printf("%d\n",dif);
	}

	return 0;
}
