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
#define VLL vector<long long>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>

using namespace std;

void print_optimal(vector< VI>&track,int start,int end)
{
	if(start==end){
		printf("A%d",end+1);
	} else {
		printf("(");
		print_optimal(track,start,track[start][end]);
		printf(" x ");
		print_optimal(track,track[start][end]+1,end);
		printf(")");
	}
	return;
}

int main()
{
	int cases,cnt=0;
	scanf("%d",&cases);

	while(cases!=0){
		++cnt;

		int N=cases;
		VI row(N),col(N);
		FOR(i,0,N)
			scanf("%d%d",&row[i],&col[i]);

		vector< VLL >prod(N,VLL(N,999999999));
		vector< VI >track(N,VI(N));

		FOR(diag,0,N)
			prod[diag][diag]=0,track[diag][diag]=diag;

		EFOR(len,2,N)
			EFOR(pos,0,N-len)
				FOR(k,pos,pos+len-1){
					long long tmp=prod[pos][k]+prod[k+1][pos+len-1]+row[pos]*col[k]*col[pos+len-1];
					if(prod[pos][pos+len-1]>tmp)
						prod[pos][pos+len-1]=tmp,track[pos][pos+len-1]=k;
				}

		printf("Case %d: ",cnt);
		print_optimal(track,0,N-1);
		printf("\n");

		scanf("%d",&cases);
	}
	return 0;
}
