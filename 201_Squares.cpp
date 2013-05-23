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
#define VB vector<bool>

using namespace std;

int main()
{

	int N,lines;
	int cases=0;

	while(scanf("%d",&N)!=EOF){

		if(cases>=1)
			printf("\n**********************************\n\n");

		++cases;
		printf("Problem #%d\n\n",cases);

		scanf("%d",&lines);

		vector< VB >hor(N,VB(N-1,false));
		vector< VB >ver(N,VB(N,false));

		char dir;
		int r,c;

		FOR(i,0,lines){
			scanf(" %c%d%d",&dir,&r,&c);

			if(dir=='H')
				hor[r-1][c-1]=true;
			else
				ver[c-1][r-1]=true;
		}

		bool tot=true;

		FOR(len,1,N){
			int cnt=0;

			FOR(rpos,0,N-len)
				FOR(cpos,0,N-len){

					bool flag=true;

					for(int sq=0;sq<len && flag;sq++)
						if(!hor[rpos][cpos+sq])
							flag=false;

					for(int sq=0;sq<len && flag;sq++)
						if(!ver[rpos+sq][cpos])
							flag=false;

					for(int sq=0;sq<len && flag;sq++)
						if(!hor[rpos+len][cpos+sq])
							flag=false;

					for(int sq=0;sq<len && flag;sq++)
						if(!ver[rpos+sq][cpos+len])
							flag=false;

					if(flag)
						++cnt;
				}

			if(cnt>=1){
				printf("%d square (s) of size %d\n",cnt,len);
				tot=false;
			}
		}

		if(tot)
			printf("No completed squares can be found.\n");
	}

	return 0;
}
