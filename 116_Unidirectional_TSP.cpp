#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <sstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() );
#define VI vector<int>
#define VL vector<long>
#define VS vector<string>

using namespace std;

inline string lexic(string fir,string sec)
{
	VI fNum,sNum;
	int tmp=0,pos=0;

	FOR(pos,0,fir.size()){
		if(fir[pos]==' '){
			PB(fNum,tmp);
			tmp=0;
		} else
			tmp=tmp*10+(fir[pos]-48);
	}

	tmp=0;
	FOR(pos,0,sec.size()){
		if(sec[pos]==' '){
			PB(sNum,tmp);
			tmp=0;
		} else
			tmp=tmp*10+(sec[pos]-48);
	}

	for(;pos<fNum.size() && pos<sNum.size();++pos){
		if(fNum[pos]<sNum[pos])
			return fir;
		else if(fNum[pos]>sNum[pos])
			return sec;
	}
	if(pos==fNum.size())
		return fir;
	return sec;
}

int main()
{
	int row,col;
	char buff[5];

	while(scanf("%d%d",&row,&col)!=EOF){

		vector< VI >matr(row,VI(col));
		FOR(r,0,row)
			FOR(c,0,col)
				scanf("%d",&matr[r][c]);

		vector< VL >cost(row,VL(col,900000000l));
		vector< VS >track(row,VS(col,""));

		FOR(r,0,row){
			cost[r][0]=matr[r][0];
			sprintf(buff,"%d",r+1);
			string tmp(buff);
			track[r][0]+=(tmp+" ");
		}

		FOR(c,1,col)
			FOR(r,0,row){

				EFOR(i,-1,1){
					int pos=r+i;
					pos=(pos<0)?row-1:pos;
					pos=(pos==row)?0:pos;

					if(cost[r][c]>cost[pos][c-1]+matr[r][c]){
						cost[r][c]=cost[pos][c-1]+matr[r][c];
						track[r][c]=track[pos][c-1];
					} else if(cost[r][c]==cost[pos][c-1]+matr[r][c])
						track[r][c]=lexic(track[r][c],track[pos][c-1]);
				}
				sprintf(buff,"%d",r+1);
				string tmp(buff);
				track[r][c]+=(tmp+" ");
		}

		long minWt=900000000l;
		FOR(r,0,row)
			minWt=(minWt<=cost[r][col-1])?minWt:cost[r][col-1];

		string minPath="99 ";

		FOR(r,0,row){
			if(minWt==cost[r][col-1])
				minPath=lexic(minPath,track[r][col-1]);
		}

		minPath.erase(minPath.size()-1,1);
		FOR(prnt,0,minPath.size())
			printf("%c",minPath[prnt]);

		printf("\n%ld\n",minWt);
	}

	return 0;
}
