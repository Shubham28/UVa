#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cmath>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)


using namespace std;

int main()
{
	int cases;
	scanf("%d",&cases);

	EFOR(T,1,cases){
		int N;
		scanf("%d",&N);
		int cnt=__builtin_popcount(N);

		bitset<16>conv(N);

		int times=0;
		bool flag=false;

		EFOR(i,0,int(log(N)/log(2)+1e-7)){
			if(flag && conv[i]==1)
				++times;
			if(conv[i]==0)
				flag=true;
		}

		printf("Case %d: %d %d\n",T,times,int(pow(2.0,cnt+0.0)+1e-7-1.0));
	}

	return 0;
}
