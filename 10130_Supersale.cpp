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
#define VL vector<long>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	FOR(i,0,T){

		int n,G;
		scanf("%d",&n);
		VI wt(n),val(n);

		FOR(obj,0,n)
			scanf("%d%d",&val[obj],&wt[obj]);

		scanf("%d",&G);
		VI tot(G);
		FOR(p,0,G)
			scanf("%d",&tot[p]);

		int maxim=0;
		FOR(p,0,G){
			vector< VI >S(n+1,VI(tot[p]+1,0));

			EFOR(r,1,n)
				EFOR(c,1,tot[p]){
					if(wt[r-1]>c)
						S[r][c]=S[r-1][c];
					else
						S[r][c]=max(S[r-1][c],S[r-1][c-wt[r-1]]+val[r-1]);
				}

			maxim+=S[n][tot[p]];
		}
		printf("%d\n",maxim);
	}

	return 0;
}
