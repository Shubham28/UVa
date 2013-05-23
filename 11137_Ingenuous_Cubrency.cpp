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
#define VL vector<long>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>

using namespace std;

int main()
{
	long dp[22][10000],coins[22];
	
	EFOR(i,1,21)
		coins[i]=i*i*i;

	memset(dp[0],0,sizeof(dp[0]);
	FOR(i,0,22)
		dp[i][0]=1;

	dp[0][0]=0;

	FOR(c,1,10000)
		FOR(r,1,22){
			if(c>=coins[r])
				dp[r][c]=dp[r-1][c]+dp[r][c-coins[r]];
			else
				dp[r][c]=dp[r-1][c];
		}

	int S;
	while(scanf("%d",&S)!=EOF){
		printf("%ld\n",dp[21][S]);
	}

	return 0;
}
