#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>

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
	string word;
	while(cin>>word){

		set<string>palin;
		FOR(pos,0,word.size())
			EFOR(len,1,word.size()-pos){
				string sub=word.substr(pos,len);
				string rev(sub.rbegin(),sub.rend());
				if(sub==rev)
					palin.insert(sub);
			}

		printf("The string '");
		cout<<word;
		printf("' contains %d palindromes.\n",palin.size());
	}

	return 0;
}
