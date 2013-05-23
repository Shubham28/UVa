#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>

#define FOR(A,B,C) for(short A=B;A<C;A++)
#define EFOR(A,B,C) for(short A=B;A<=C;A++)
#define RFOR(A,B,C) for(short A=B;A>=C;A--)

using namespace std;

short panck[101];
short N;

inline void flipcakes()
{
	FOR(tim,0,N){
		short maxim=0,ind;
		FOR(pos,0,N-tim)
			if(maxim<panck[pos])
				maxim=panck[pos],ind=pos;

		if(ind!=(N-tim-1)){
			if(ind!=0){
				printf("%hd ",N-ind);
				reverse(panck,panck+ind+1);
			}
			ind=0;
			printf("%hd ",tim+1);
			reverse(panck,panck+N-tim);
		}
	}
	printf("0\n");

	return;
}

int main()
{
	N=0;
	short tmp=0,ch;
	while(true){
		ch=getchar();

		if('0'<=ch && ch<='9'){
			printf("%d",ch-'0');
			tmp=(tmp<<3)+(tmp<<1)+(ch-'0');
		} else {
			if(tmp>=1)
				panck[N]=tmp,N+=1,tmp=0;

			if(ch==' ')
				printf(" ");
			else if(ch==EOF){
				printf("\n");
				flipcakes();
				break;
			} else {
				putchar(ch);
				if(N>=1)
					flipcakes();
				N=0;
			}
		}
	}

	return 0;
}
