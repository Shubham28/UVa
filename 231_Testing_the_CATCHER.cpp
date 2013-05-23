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

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

int main()
{
	int num,cases=0;
	Input(num);

	while(num!=-1){

		VI seq(1,num),longSeq(1,num);
		++cases;
		if(cases>=2)
			printf("\n");

		Input(num);
		while(num!=-1){
			PB(seq,num);
			Input(num);
		}

		int maxim=1;

		FOR(i,1,seq.size()){
			int start=0,end=longSeq.size()-1;

			if(longSeq[end]>=seq[i]){
				PB(longSeq,seq[i]);
			} else if(longSeq[start]<=seq[i])
				longSeq[0]=seq[i];
			else {

				while(start<=end){
					int mid=(start+end)/2;

					if(longSeq[mid]==seq[i])
						break;
					else if(longSeq[mid]>seq[i] && longSeq[mid+1]<seq[i]){
						longSeq[mid+1]=seq[i];
						break;
					} else if(longSeq[mid]>seq[i])
						start=mid+1;
					else
						end=mid-1;
				}
			}
		}

		printf("Test #%d:\n  maximum possible interceptions: %d\n",cases,longSeq.size());
		Input(num);
	}

	return 0;
}
