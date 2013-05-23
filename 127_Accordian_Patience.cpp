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

int main()
{
	char card[3];
	char piles[54][54][3];
	int plen[54];

	scanf("%s",card);
	while(card[0]!='#'){
		list<int>seq;

		EFOR(fill,0,54)
			plen[fill]=0;

		memcpy(piles[0][plen[0]++],card,sizeof(card));
		PB(seq,0);

		EFOR(inp,1,51){
			scanf("%s",card);
			memcpy(piles[inp][plen[inp]++],card,sizeof(card));
			PB(seq,inp);
		}

		int cnt=0,cr1,cr2;

		for(list<int>::iterator it=seq.begin();it!=seq.end();it++,cnt++){
			list<int>::iterator tmp=it;

			if(cnt>=3){
				--tmp,--tmp,--tmp;
				cr1=(*it);
				cr2=(*tmp);

				if(piles[cr1][plen[cr1]-1][0]==piles[cr2][plen[cr2]-1][0] || piles[cr1][plen[cr1]-1][1]==piles[cr2][plen[cr2]-1][1]){

					memcpy(piles[cr2][plen[cr2]++],piles[cr1][plen[cr1]-1],sizeof(piles[cr1][plen[cr1]-1]));
					plen[cr1]--;
					if(plen[cr1]==0)
						seq.erase(it);

					if(cnt==3)
						it=tmp,cnt=0;
					else
						it=--tmp,cnt-=4;
					}
				}

			tmp=it;
			if(cnt>=1){
				--tmp;
				cr1=(*it);
				cr2=(*tmp);

				if(piles[cr1][plen[cr1]-1][0]==piles[cr2][plen[cr2]-1][0] || piles[cr1][plen[cr1]-1][1]==piles[cr2][plen[cr2]-1][1]){

					memcpy(piles[cr2][plen[cr2]++],piles[cr1][plen[cr1]-1],sizeof(piles[cr1][plen[cr1]-1]));
					plen[cr1]--;
					if(plen[cr1]==0)
						seq.erase(it);

					if(cnt==1)
						it=tmp,cnt=0;
					else
						it=--tmp,cnt-=2;
				}
			}
		}

		if(SZ(seq)==1)
			printf("1 pile remaining: 52\n");
		else {
			printf("%d piles remaining: ",SZ(seq));

			list<int>::iterator it=seq.begin();
			printf("%d",plen[(*it)]);
			it++;

			for(;it!=seq.end();it++)
				printf(" %d",plen[(*it)]);
			printf("\n");
		}

		scanf("%s",card);
	}
	return 0;
}
