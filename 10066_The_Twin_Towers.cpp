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

void LCS_Memoized(VI &s1,VI &s2,vector< VL > &len,int i,int j)
{
	if(s1[j]==s2[i]){
		if(i>=1 && j>=1){
			if(len[i-1][j-1]==-1)
				LCS_Memoized(s1,s2,len,i-1,j-1);
			len[i][j]=len[i-1][j-1]+1;
		} else
			len[i][j]=1;
	} else {
		if(i==0 && j==0)
			len[i][j]=0;
		else if(i==0){
			if(len[i][j-1]==-1)
				LCS_Memoized(s1,s2,len,i,j-1);
			len[i][j]=len[i][j-1];
		} else if(j==0){
			if(len[i-1][j]==-1)
				LCS_Memoized(s1,s2,len,i-1,j);
			len[i][j]=len[i-1][j];
		} else {
			if(len[i-1][j]==-1)
				LCS_Memoized(s1,s2,len,i-1,j);
			if(len[i][j-1]==-1)
				LCS_Memoized(s1,s2,len,i,j-1);

			len[i][j]=(len[i-1][j]>len[i][j-1])?len[i-1][j]:len[i][j-1];
		}
	}
	return;
}

int main()
{
	int L1,L2,cases=0;
	scanf("%d%d",&L1,&L2);

	while(!(L1==0 && L2==0)){

		++cases;
		VI s1(L1),s2(L2);
		FOR(i,0,L1)
			scanf("%d",&s1[i]);
		FOR(i,0,L2)
			scanf("%d",&s2[i]);

		vector< VL >len(L2,VL(L1,-1));
		LCS_Memoized(s1,s2,len,L2-1,L1-1);

		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",cases,len[L2-1][L1-1]);
		scanf("%d%d",&L1,&L2);
	}

	return 0;
}
