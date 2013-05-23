#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)

using namespace std;

int bigMod(long long B,long long P,int M)
{
	if(B==0 || M==1)
		return 0;
	if(P==0 || B==1)
		return 1;

	int res=bigMod(B,(long long)(P/2),M);

	if(P%2)
		return (res*res*(B%M))%M;
	else 
		return (res*res)%M;
}

int main()
{
	long long B,P;
	int M,R;

	while(scanf("%lld%lld%d",&B,&P,&M)!=EOF){

		cin.ignore(1,'\n');
		string tmp;
		getline(cin,tmp);

		R=bigMod(B,P,M);
		printf("%d\n",R);
	}

	return 0;
}
