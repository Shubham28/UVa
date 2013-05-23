#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0' || ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

int main()
{
	int T,N;
	int times[1001];
	char outpt[100001],tmp[50];

	Input(T);
	EFOR(cases,1,T){
		if(cases!=1)
			printf("\n");

		Input(N);
		FOR(inp,0,N)
			Input(times[inp]);

		if(N==1)
			printf("%d\n%d\n",times[0],times[0]);
		else if(N==2){
			if(times[0]>times[1])
				swap(times[0],times[1]);
			printf("%d\n%d %d\n",times[1],times[0],times[1]);
		} else {
			tmp[0]=0,outpt[0]=0;
			sort(times,times+N);
			int minim,secmin,pos=N-1,tot=0;

			minim=times[0],secmin=times[1];

			while(pos>2){
				int meth1=(minim+2*secmin+times[pos]);
				int meth2=(minim*2+times[pos-1]+times[pos]);

				if(meth1<meth2)
					sprintf(tmp,"%d %d\n%d\n%d %d\n%d\n",minim,secmin,minim,times[pos-1],times[pos],secmin);
				else
					sprintf(tmp,"%d %d\n%d\n%d %d\n%d\n",minim,times[pos-1],minim,minim,times[pos],minim);

				tot+=(meth1<meth2)?meth1:meth2;

				strcat(outpt,tmp);
				pos-=2;
			}
			if(pos==2){
				tot+=(minim+times[pos]);
				sprintf(tmp,"%d %d\n%d\n",minim,times[pos],minim);
				strcat(outpt,tmp);
			}
			tot+=(secmin);
			sprintf(tmp,"%d %d\n",minim,secmin);
			strcat(outpt,tmp);

			printf("%d\n%s",tot,outpt);
		}
	}

	return 0;
}
