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

void comb(int htmp,int wtmp,int dtmp,VI &dimen)
{
	PB(dimen,htmp);
	PB(dimen,wtmp);
	PB(dimen,dtmp);
}

int main()
{
	int n,cases=1;
	scanf("%d",&n);
	
	while(n!=0){

		VI ht,wd,dp;
		FOR(i,0,n){
			VI dimen(3);
			scanf("%d%d%d",&dimen[0],&dimen[1],&dimen[2]);
			SORT(dimen);

			comb(dimen[0],dimen[1],dimen[2],ht);
			comb(dimen[1],dimen[0],dimen[0],wd);
			comb(dimen[2],dimen[2],dimen[1],dp);
		}

		FOR(i,0,3*n)
			FOR(j,i+1,3*n){
				if(wd[j]*dp[j]>=wd[i]*dp[i]){
					int htmp=ht[i],wtmp=wd[i],dtmp=dp[i];
					ht[i]=ht[j],ht[j]=htmp,wd[i]=wd[j],wd[j]=wtmp,dp[i]=dp[j],dp[j]=dtmp;
				}
			}

		VI S(3*n,0);
		int highest=0;
	
		FOR(i,0,3*n){
			S[i]=ht[i];
			FOR(j,0,i){
				if(wd[i]<wd[j] && dp[i]<dp[j] && S[i]<S[j]+ht[i])
					S[i]=S[j]+ht[i];
			}
			highest=max(highest,S[i]);
		}

		printf("Case %d: maximum height = %d\n",cases,highest);
		++cases;
		scanf("%d",&n);
	}

	return 0;
}
