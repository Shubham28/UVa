#include <algorithm>
#include <iostream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)

using namespace std;

int main()
{
	char S[100000],T[100000];

	while(scanf("%s%s",&S,&T)!=EOF){

		int sLen=strlen(S),tLen=strlen(T);

		int pos=0;
		FOR(i,0,tLen)
			if(T[i]==S[pos])
				++pos;

		if(pos==sLen)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
