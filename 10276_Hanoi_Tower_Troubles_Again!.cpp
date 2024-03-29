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

using namespace std;

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
	int T,N;
	int pegs[50];
	Input(T);

	while(T--){
		Input(N);
		memset(pegs,-1,sizeof(pegs));

		bool done=true;
		int balls;

		for(balls=1;done;balls++){
			done=false;
			FOR(sel,0,N){
				if(pegs[sel]==-1){
					pegs[sel]=balls;
					done=true;
					break;
				}

				int chk=pegs[sel]+balls;
				if(floor(sqrt(chk+0.))==sqrt(chk+0.)){
					pegs[sel]=balls;
					done=true;
					break;
				}
			}
		}
		printf("%d\n",balls-2);
	}

	return 0;
}
