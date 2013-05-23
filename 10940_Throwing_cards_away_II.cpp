#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)

using namespace std;

int fir[500001],sec[500001];

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

int main()
{
	fir[1]=1,sec[1]=1,fir[2]=2,sec[2]=1;

	EFOR(done,3,500000){
		if(done%2){
			fir[done]=sec[(done-1)/2]<<1;
			sec[done]=(fir[(done+1)/2]<<1)-1;
		} else {
			fir[done]=fir[done/2]<<1;
			sec[done]=(sec[done/2]<<1)-1;
		}
	}

	int inp;
	Input(inp);
	while(inp!=0){
		printf("%d\n",fir[inp]);
		Input(inp);
	}

	return 0;
}
