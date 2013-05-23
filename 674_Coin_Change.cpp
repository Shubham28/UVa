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

	VL C(7490,0);
	int coins[]={1,5,10,25,50};
	C[0]=1;

	FOR(i,0,5){
		EFOR(j,coins[i],7489)
			C[j]+=C[j-coins[i]];
	}

	int amt;
	while(scanf("%d",&amt)!=EOF)
		printf("%d\n",C[amt]);

	return 0;
}
