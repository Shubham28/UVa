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
#define SZ(A) int(A.size())

using namespace std;

int ch,sign;

inline void Input(int &N)
{
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+ch-'0';
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}


int main()
{
	int N;
	Input(N);
	int array[N+1][N+1];
	EFOR(row,1,N)
		EFOR(col,1,N)
			Input(array[row][col]);

	int vert[N+1][N+1];
	memset(vert,0,sizeof(vert));

	EFOR(bottom,1,N)
		EFOR(col,1,N)
			vert[bottom][col]=vert[bottom-1][col]+array[bottom][col];


	int horiz[N+1][N+1][N+1];
	memset(horiz,0,sizeof(horiz));
	int maxim=-99999999;

	EFOR(top,1,N)
		EFOR(bottom,top,N)
			EFOR(pos,1,N){
				int tmp=max(horiz[top][bottom][pos-1],0);
				horiz[top][bottom][pos]=(vert[bottom][pos]-vert[top-1][pos])+tmp;
				maxim>?=horiz[top][bottom][pos];
			}

	printf("%d\n",maxim);

	return 0;
}
