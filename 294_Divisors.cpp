#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define VI vector<int>
#define VL vector<long>

using namespace std;

int Divisors(long L,long U,long &P)
{
	int range=(U-L)+1;

	int divis[range];
	memset(divis,0,sizeof(divis));

	for(long i=1;i*i<=U;i++){

		long j=(L/i)*i;
		if(j<L)
			j+=i;

		j-=L;
		for(;j<range;j+=i){
			if(i*i<=(j+L)){
				++divis[j];
				if(i!=(j+L)/i)
					++divis[j];
			}
		}
	}

	int maxim=0;
	FOR(i,0,range)
		if(maxim<divis[i]){
			maxim=divis[i];
			P=L+i;
		}

	return maxim;
}

int main()
{
	int N,div;
	scanf("%d",&N);
	long L,U,P;

	FOR(cases,0,N){

		scanf("%ld%ld",&L,&U);
		div=Divisors(L,U,P);

		printf("Between %ld and %ld, %ld has a maximum of %d divisors.\n",L,U,P,div);
	}

	return 0;
}
