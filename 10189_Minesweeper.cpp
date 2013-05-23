#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define VB vector<bool>

using namespace std;

int main()
{
	int R,C,T=0;
	scanf("%d%d",&R,&C);

	while(R!=0 && C!=0){
		++T;
		if(T>=2)
			printf("\n");

		int mines[R][C];
		memset(mines,0,sizeof(mines));

		int dirY[]={-1,-1,-1,0,0,1,1,1};
		int dirX[]={-1,0,1,-1,1,-1,0,1};

		FOR(row,0,R){
			char inp[C];
			scanf("%s",&inp);

			FOR(col,0,C)
				if(inp[col]=='*'){
					mines[row][col]=-1;
					FOR(i,0,8)
						if(0<=row+dirX[i] && row+dirX[i]<R && 0<=col+dirY[i] && col+dirY[i]<C)
							if(mines[row+dirX[i]][col+dirY[i]]!=-1)
								++mines[row+dirX[i]][col+dirY[i]];
				}
		}

		printf("Field #%d:\n",T);
		FOR(row,0,R){
			FOR(col,0,C){
				if(mines[row][col]==-1)
					printf("*");
				else
					printf("%d",mines[row][col]);
			}
			printf("\n");
		}

		scanf("%d%d",&R,&C);
	}

	return 0;
}
