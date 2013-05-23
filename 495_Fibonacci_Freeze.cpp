#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VLL vector<long long>
#define LL long long

using namespace std;

void calc_next(vector< VLL > &digits,int pres)
{
	LL sum,carry=0;

	FOR(m,0,digits[pres-2].size()){
		sum=carry+digits[pres-1][m]+digits[pres-2][m];

		if(sum<=999999999){
			PB(digits[pres],sum);
			carry=0;
		} else {
			PB(digits[pres],sum%1000000000);
			carry=sum/1000000000;
		}
	}
	if(digits[pres-2].size()<digits[pres-1].size()){
		carry+=digits[pres-1][digits[pres-1].size()-1];
		PB(digits[pres],carry);
		carry=0;
	}

	if(carry>0)
		PB(digits[pres],carry);

	return;
}

int main()
{
	vector< VLL >digits(5001);
	PB(digits[0],0);
	PB(digits[1],1);

	EFOR(i,2,5000)
		calc_next(digits,i);

	int n;
	while(scanf("%d",&n)!=EOF){
		printf("The Fibonacci number for %d is ",n);

		printf("%lld",digits[n][digits[n].size()-1]);
		RFOR(r,digits[n].size()-2,0){

			for(LL st=digits[n][r];st<100000000;st*=10)
				printf("0");

			printf("%lld",digits[n][r]);
		}

		printf("\n");
	}

	return 0;
}
