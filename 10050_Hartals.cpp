#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0'||ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0'&&ch<='9');

	N*=sign;
	return;
}

int main()
{
//	freopen("Input.txt","r",stdin);
	int T;
	int har[105];

	Input(T);
	while(T--){
		int N,P;
		Input(N),Input(P);
		FOR(inp,0,P)
			Input(har[inp]);

		list<int>days;
		EFOR(all,1,N)
			PB(days,all);

		for(list<int>::iterator it=days.begin();it!=days.end();){
			int num=(*it);
			bool inc=true;

			FOR(chk,0,P)
				if(num%har[chk]==0 && num%7!=0 && num%7!=6){
					it=days.erase(it);
					inc=false;
					break;
				}

			if(inc)
				++it;
		}
		printf("%d\n",N-SZ(days));
	}

//	fclose(stdin);
	return 0;
}
