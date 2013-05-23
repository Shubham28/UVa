#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int row,col;
char isl[20][20];
pair<int,int>cord[17];
int dist[17][17];
int tot;
int cost[1<<16][16];

int evalcost(int comb,int pos)										// 'pos' tells present nut number
{
	if(comb==(1<<pos))
		return dist[pos][0];										// Last nut to initial Position

	int &ret=cost[comb][pos];										// Dynamic change to cost[][]

	if(ret>=0)
		return ret;

	ret=999999;
	FOR(all,0,tot)
		if(all!=pos && (comb&(1<<all)) ){
			ret=min(ret,dist[pos][all]+evalcost(comb-(1<<pos),all));
		}

	return ret;
}

int main()
{
	while(scanf("%d%d",&row,&col)!=EOF){

		FOR(inp,0,row)
			scanf("%s",isl[inp]);

		tot=1;
		FOR(r,0,row)
			FOR(c,0,col){
				if(isl[r][c]=='L')
					cord[0]=make_pair(r,c);
				else if(isl[r][c]=='#'){
					cord[tot]=make_pair(r,c);
					++tot;
				}
			}

		FOR(i,0,tot)
			FOR(j,0,tot)
				dist[i][j]=max(abs(cord[i].first-cord[j].first),abs(cord[i].second-cord[j].second));

		memset(cost,-1,sizeof(cost));
		printf("%d\n",evalcost((1<<tot)-1,0));
	}
}
