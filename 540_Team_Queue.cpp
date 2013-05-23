#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <list>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())

using namespace std;

int teamID[1000001];
char comd[10];
queue<int>tmQu;
list<int>tmEl[1001];

int main()
{
//	freopen("Input.txt","r",stdin);
	int T,cases=0;

	scanf("%d",&T);
	while(T!=0){
		++cases;
		printf("Scenario #%d\n",cases);

		FOR(cnt,0,T){
			int mem,tmp;
			scanf("%d",&mem);

			FOR(inp,0,mem){
				scanf("%d",&tmp);
				teamID[tmp]=cnt;
			}
		}
		while(!tmQu.empty())
			tmQu.pop();

		FOR(cl,0,1001)
			tmEl[cl].clear();

		int en,id;
		scanf("%s",comd);
		while(comd[0]!='S'){

			if(comd[0]=='E'){
				scanf("%d",&en);
				id=teamID[en];

				PB(tmEl[id],en);
				if(SZ(tmEl[id])==1)
					tmQu.push(id);

			} else if(comd[0]=='D'){
				id=tmQu.front();
				printf("%d\n",tmEl[id].front());

				tmEl[id].pop_front();
				if(SZ(tmEl[id])==0)
					tmQu.pop();
			}

			scanf("%s",comd);
		}

		printf("\n");
		scanf("%d",&T);
	}

//	fcloseall();
	return 0;
}
