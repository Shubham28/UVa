#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VLL vector<long long>
#define VS vector<string>
#define LL long long

using namespace std;

void calc_next(vector< VLL > &digits,int pres)
{
	LL sum,carry=0;

	FOR(m,0,digits[pres-2].size()){
		sum=carry+digits[pres-1][m]+digits[pres-2][m];

		if(sum<=999999999){
			PB(digits[pres],sum);
			carry=0;
		} else {
			PB(digits[pres],sum%1000000000);
			carry=sum/1000000000;
		}
	}
	if(digits[pres-2].size()<digits[pres-1].size()){
		carry+=digits[pres-1][digits[pres-1].size()-1];
		PB(digits[pres],carry);
		carry=0;
	}

	if(carry>0)
		PB(digits[pres],carry);

	return;
}

int main()
{
	vector< VLL >digits(501);
	PB(digits[0],0);
	PB(digits[1],1);

	EFOR(i,2,500)
		calc_next(digits,i);

	VS ret(501,"");

	int n;
	EFOR(n,0,500){

		char buff[250];
		sprintf(buff,"%lld",digits[n][digits[n].size()-1]);
		string last(buff);
		ret[n]=last;

		RFOR(r,digits[n].size()-2,0){

			for(LL st=digits[n][r];st<100000000;st*=10)
				ret[n]+="0";

			sprintf(buff,"%lld",digits[n][r]);
			string fir(buff);
			ret[n]+=fir;
		}
	}

	char tmpA[105],tmpB[105];
	scanf("%s%s",&tmpA,&tmpB);
	
	while(tmpA[0]!='0' || tmpB[0]!='0'){
		int cnt=0;
		string a(tmpA),b(tmpB);

		FOR(srch,2,ret.size()){
			if( (ret[srch].size()>a.size()) || (ret[srch].size()==a.size() && ret[srch]>=a) )
				if( (ret[srch].size()<b.size()) || (ret[srch].size()==b.size() && ret[srch]<=b) )
					++cnt;
		}

		printf("%d\n",cnt);
		scanf("%s%s",&tmpA,&tmpB);
	}

	return 0;
}
