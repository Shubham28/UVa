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

string x,y;

void print_Code(vector< vector<char> >&track,int r,int c)
{
	if(r==0 && c==0)
		return;

	if(track[r][c]=='S')
		print_Code(track,r-1,c-1);
	else if(track[r][c]=='D'){
		print_Code(track,r-1,c);
		cout<<"D"<<x[r-1];
		if(c<10)
			cout<<"0";
		cout<<r;
	} else if(track[r][c]=='C'){
		print_Code(track,r-1,c-1);
		cout<<"C"<<y[c-1];
		if(c<10)
			cout<<"0";
		cout<<c;
	} else if(track[r][c]=='I'){
		print_Code(track,r,c-1);
		cout<<"I"<<y[c-1];
		if(c<10)
			cout<<"0";
		cout<<c;
	}
	return;
}

int main()
{
	int ins=1,del=1,replace=1,cases=0;

	cin>>x;
	while(x!="#"){
		++cases;
		if(cases>=2)
			cout<<"\n";

		cin>>y;
		vector< VI >cost(x.size()+1,VI(y.size()+1,9999));
		vector< vector<char> >track(x.size()+1,vector<char>(y.size()+1));

		FOR(r,0,cost.size())
			cost[r][0]=del*r,track[r][0]='D';
		FOR(c,0,cost[0].size())
			cost[0][c]=ins*c,track[0][c]='I';

		FOR(i,0,x.size())
			FOR(j,0,y.size()){
				int cstI=9999,cstD=9999,cstR=9999;
				
				if(x[i]==y[j])
					cost[i+1][j+1]=cost[i][j];
				else if(x[i]!=y[j])
					cstR=cost[i][j]+replace;

				cstD=cost[i][j+1]+del;
				cstI=cost[i+1][j]+ins;

				cost[i+1][j+1]=min(cost[i+1][j+1],min(cstI,min(cstD,cstR)));
				if(cost[i+1][j+1]==cost[i][j])
					track[i+1][j+1]='S';
				if(cost[i+1][j+1]==cstI)
					track[i+1][j+1]='I';
				if(cost[i+1][j+1]==cstD)
					track[i+1][j+1]='D';
				if(cost[i+1][j+1]==cstR)
					track[i+1][j+1]='C';
			}
		print_Code(track,track.size()-1,track[0].size()-1);
		cout<<"E";

		cin>>x;
	}

	return 0;
}
