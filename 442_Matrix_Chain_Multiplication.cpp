#include <vector>
#include <map>
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
	map<char,int>row;
	map<char,int>col;

	int n,r,c;
	scanf("%d",&n);
	FOR(i,0,n){
		char ch;
		cin>>ch;
		scanf("%d%d",&r,&c);
		row[ch]=r,col[ch]=c;
	}
	
	string line;
	while(cin>>line){
		if(line.size()==1)
			printf("0\n");
		else {
			vector<char>operat;
			FOR(c,0,line.size())
				PB(operat,line[c]);

			bool ch=true;
			int pos,tmp=97;
			long tot=0;
			while(operat.size()>1){

				FOR(c,2,operat.size()){	
					if( operat[c]!='(' && operat[c]!=')' && operat[c-1]!='(' && operat[c-1]!=')' )
						pos=c-1;
				}

				if(col[operat[pos]]!=row[operat[pos+1]]){
					printf("error\n");
					ch=false;
					break;
				}

				tot=tot+row[operat[pos]]*col[operat[pos]]*col[operat[pos+1]];	
				row[(char)tmp]=row[operat[pos]],col[(char)tmp]=col[operat[pos+1]];
				operat.erase(operat.begin()+pos-1,operat.begin()+pos+3);
				operat.insert(operat.begin()+pos-1,1,(char)tmp);
				++tmp;
			}
			if(ch)
				printf("%d\n",tot);
		}
	}
	
	return 0;
}
