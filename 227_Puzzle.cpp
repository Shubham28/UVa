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
	int cases=0;
	string line,operat;
	getline(cin,line);

	while(line!="Z"){
		if(cases)
			printf("\n");

		++cases;
		VS mat(1,line),oper;

		FOR(i,0,4){
			getline(cin,line);
			PB(mat,line);
		}

		getline(cin,operat);
		while(operat[operat.size()-1]!='0'){
			PB(oper,operat);
			getline(cin,operat);
		}
		operat.erase(operat.size()-1,1);
		PB(oper,operat);

		bool leg=true;
		int posx,posy;

		FOR(r,0,mat.size())
			FOR(c,0,mat[r].size())
				if(mat[r][c]==' '){
					posx=r,posy=c;
					break;
				}

		for(int r=0;r<oper.size() && leg;r++)
			FOR(c,0,oper[r].size()){
				if( (oper[r][c]=='A' && posx==0) || (oper[r][c]=='B' && posx==mat.size()-1) || (oper[r][c]=='L' && posy==0) || (oper[r][c]=='R' && posy==mat[r].size()-1) ){
					leg=false;
					break;
				} else if(oper[r][c]=='A')
					mat[posx][posy]=mat[posx-1][posy],mat[posx-1][posy]=' ',posx-=1;
				else if(oper[r][c]=='B')
					mat[posx][posy]=mat[posx+1][posy],mat[posx+1][posy]=' ',posx+=1;
				else if(oper[r][c]=='L')
					mat[posx][posy]=mat[posx][posy-1],mat[posx][posy-1]=' ',posy-=1;
				else if(oper[r][c]=='R')
					mat[posx][posy]=mat[posx][posy+1],mat[posx][posy+1]=' ',posy+=1;
			}

		printf("Puzzle #%d:\n",cases);

		if(leg){
			FOR(r,0,mat.size()){
				FOR(c,0,mat[r].size()-1)
					printf("%c ",mat[r][c]);
				printf("%c\n",mat[r][mat[r].size()-1]);
			}
		} else
			printf("This puzzle has no final configuration.\n");

		getline(cin,line);
	}

	return 0;
}
