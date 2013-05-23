#include <vector>
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
	int N;
	scanf("%d",&N);

	FOR(i,0,N){
		int stops;
		scanf("%d",&stops);

		VI val(stops-1);
		FOR(j,0,stops-1)
			scanf("%d",&val[j]);

		int maxim=val[0],len=0,strStop=0,endStop=0;
		VI S(stops-1),track(stops-1);
		S[0]=val[0],track[0]=0;

		FOR(j,1,stops-1){
			if(S[j-1]>=0)
				S[j]=val[j]+S[j-1],track[j]=j-1;
			else
				S[j]=val[j],track[j]=j;
			maxim=max(maxim,S[j]);
		}
		if(maxim>0){
			FOR(j,0,stops-1)
				if(maxim==S[j]){
					int strt=j;
					while(track[strt]!=strt)
						strt=track[strt];
				
					if(j-strt+1>len)
						len=j-strt+1,strStop=strt,endStop=j;
					if(j-strt+1==len && strStop>strt)
						strStop=strt,endStop=j;
				}
			printf("The nicest part of route %d is between stops %d and %d\n",i+1,strStop+1,endStop+2);
		} else
			printf("Route %d has no nice parts\n",i+1);

	}

	return 0;
}
