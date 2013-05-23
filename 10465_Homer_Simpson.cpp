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
	int m,n,t;

	while(scanf("%d%d%d",&m,&n,&t)!=EOF){

		if(m>n)
			swap(m,n);

		int burg[t+1];
		int waste[t+1];
		memset(burg,0,sizeof(burg));
		memset(waste,0,sizeof(waste));

		EFOR(i,1,t){
			if(i<m && i<n)
				waste[i]=1+waste[i-1];
			else {
				if(i>=m)
					waste[i]=waste[i-m],burg[i]=1+burg[i-m];
				if(i>=n && waste[i-n]<waste[i])
					waste[i]=waste[i-n],burg[i]=1+burg[i-n];

				if(i>=n && waste[i-m]==waste[i-n])
					burg[i]=1+max(burg[i-m],burg[i-n]);
			}
		}
		printf("%d",burg[t]);
		if(waste[t])
			printf(" %d\n",waste[t]);
		else
			printf("\n");
	}

	return 0;
}
