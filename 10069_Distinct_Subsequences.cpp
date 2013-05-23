#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define VS vector<string>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define ULL unsigned long long

using namespace std;

// NealWu's BigInteger Library

// MAXD: Maximum number of Digits in Number
const int MAXD=101,DIG=9,BASE=1000000000;
const ULL BOUND=ULLONG_MAX-(ULL)(BASE*BASE);

struct bignum
{
	/* digits: Stores the digits in reverse Order
	 * D: Stores the number of elements in digits[] */
	int D,digits[MAXD/DIG+2];

	inline void trim()
	{
		while(D>1 && digits[D-1]== 0)
			D--;
	}

	inline void init(long long x)
	{
		memset(digits,0,sizeof(digits));
		D=0;

		do
		{
			digits[D++]=x%BASE;
			x/=BASE;
		} while(x>0);
	}

	inline bignum(int x=0)
	{
		init(x);
	}

	inline char *toStr()
	{
		trim();
		char *buf=new char[DIG*D+1];
		int pos=0,d=digits[D-1];

		do
		{
			buf[pos++]=d%10+'0';
			d/=10;
		} while(d>0);

		reverse(buf,buf+pos);

		for(int i=D-2;i>=0;i--,pos+=DIG)
			for(int j=DIG-1,t=digits[i];j>=0;j--){
				buf[pos+j]=t%10+'0';
				t/=10;
			}

		buf[pos]='\0';
		return buf;
	}

	inline bignum operator + (const bignum &o) const
	{
		bignum sum=o;
		int carry=0;

		for(sum.D=0;sum.D<D || carry>0;sum.D++){
			sum.digits[sum.D]+=(sum.D<D?digits[sum.D]:0)+carry;

			if(sum.digits[sum.D]>=BASE){
				sum.digits[sum.D]-=BASE;
				carry=1;
			} else
				carry=0;
		}

		sum.D=max(sum.D,o.D);
		sum.trim();
		return sum;
	}

};

int main()
{
	int T;
	scanf("%d",&T);

	bignum count[2][10001];
	bignum sum[10001];
	bignum last,seclast,zero=0;
	char orig[10001],subseq[101];

	while(T--){
		scanf("%s%s",orig,subseq);

		int lenorig=strlen(orig),lensub=strlen(subseq);
		int chan=0;

		FOR(fill,0,lenorig)
			count[0][fill]=0,sum[fill]=0;

		FOR(pos,0,lensub){
			FOR(mat,0,lenorig){

				if(mat==0)
					last=sum[0],seclast=0;
				else if(mat>=1){
					bignum tmp=last;
					last=sum[mat];
					seclast=tmp;
				}

				count[chan^1][mat]=0,sum[mat]=0;
				if(orig[mat]==subseq[pos]){

					if(pos==0)
						count[chan^1][mat]=1,sum[mat]=1;
					else {
						count[chan^1][mat]=(mat==0)?0:seclast;
						sum[mat]=(mat==0)?0:count[chan^1][mat];
					}
				}

				sum[mat]=sum[mat]+((mat>=1)?sum[mat-1]:zero);
			}
			chan^=1;
		}

		printf("%s\n",sum[lenorig-1].toStr());
	}

	return 0;
}
