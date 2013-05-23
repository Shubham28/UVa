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
	int leng,num;
	scanf("%d",&leng);

	while(leng!=0){
		scanf("%d",&num);

		int cuts[52];
		EFOR(i,1,num)
			scanf("%d",&cuts[i]);
		cuts[0]=0,cuts[num+1]=leng;

		long cost[52][52];
		memset(cost,0,sizeof(cost));

		FOR(len,2,num+2)
			FOR(pos,0,num+2-len){
				long tmp=99999;
				FOR(k,1,len)
					tmp=min(tmp,cost[pos][pos+k]+cost[pos+k][pos+len]);
				cost[pos][pos+len]=tmp+cuts[pos+len]-cuts[pos];
			}

		printf("The minimum cutting is %ld.\n",cost[0][num+1]);
		scanf("%d",&leng);
	}

	return 0;
}
