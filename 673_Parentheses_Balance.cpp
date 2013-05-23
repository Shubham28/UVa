#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stack>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define SZ(A) int(A.size())

using namespace std;

int main()
{
	int T;
	char inp[150];
	scanf("%d",&T);
	cin.ignore(1,'\n');

	while(T--){
		gets(inp);
		stack<char>brac;

		int N=strlen(inp);
		bool corec=true;

		FOR(pos,0,N){
			if(inp[pos]=='(')
				brac.push('(');
			else if(inp[pos]=='[')
				brac.push('[');
			else if(inp[pos]==')'){
				if(brac.empty() || brac.top()!='('){
					corec=false;
					break;
				} else
					brac.pop();
			} else if(inp[pos]==']'){
				if(brac.empty() || brac.top()!='['){
					corec=false;
					break;
				} else
					brac.pop();
			}
		}

		if(!brac.empty())
			corec=false;
		printf((corec)?"Yes\n":"No\n");
	}

	return 0;
}
