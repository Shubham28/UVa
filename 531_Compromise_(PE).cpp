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

VS text1,text2;

void comb(vector< VI >&len,string &seq,int xpos,int ypos)
{
	while(xpos>=0 && ypos>=0 && len[xpos][ypos]>=1){

		if(ypos>=1 && len[xpos][ypos]==len[xpos][ypos-1]){
			comb(len,seq,xpos,ypos-1);
			return;
		}
		if(xpos>=1 && len[xpos][ypos]==len[xpos-1][ypos]){
			comb(len,seq,xpos-1,ypos);
			return;
		}
		seq=" "+text1[ypos]+seq,xpos-=1,ypos-=1;
	}
	return;
}


int main()
{
	string line;
	getline(cin,line);

	while(line.size()!=0){

		text1.clear(),text2.clear();		

		string tmp=line;
		while(tmp!="#"){
			tmp+=" ";

			string wrd="";
			FOR(c,0,tmp.size()){
				if(tmp[c]==' '){
					PB(text2,wrd);
					wrd="";
				} else
					wrd+=tmp[c];
			}
			getline(cin,tmp);
		}

		getline(cin,tmp);
		while(tmp!="#"){
			tmp+=" ";

			string wrd="";
			FOR(c,0,tmp.size()){
				if(tmp[c]==' '){
					PB(text1,wrd);
					wrd="";
				} else
					wrd+=tmp[c];
			}
			getline(cin,tmp);
		}

		vector< VI >len(text2.size(),VI(text1.size(),0));

		FOR(i,0,text2.size())
			FOR(j,0,text1.size()){
				if(text2[i]==text1[j]){
					if(i>=1 && j>=1)
						len[i][j]=len[i-1][j-1]+1;
					else
						len[i][j]=1;
				} else {
					if(i==0 && j==0)
						len[i][j]=0;
					else if(i==0)
						len[i][j]=len[i][j-1];
					else if(j==0)
						len[i][j]=len[i-1][j];
					else
						len[i][j]=(len[i-1][j]>len[i][j-1])?len[i-1][j]:len[i][j-1];
				}
			}

		string seq="";
		comb(len,seq,text2.size()-1,text1.size()-1);
		if(seq.size())
			seq.erase(0,1);
		cout<<seq<<"\n";

		getline(cin,line);
	}

	return 0;
}
