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

inline bool Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch==EOF)
		return false;

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return true;
}

inline void print_LIS(VI &seq,VI &track,int max_Pos)
{
	if(track[max_Pos]==-1)
		printf("%d\n",seq[max_Pos]);
	else {
		print_LIS(seq,track,track[max_Pos]);
		printf("%d\n",seq[max_Pos]);
	}
	return;
}

int main()
{
	VI seq;
	int num;

	while(Input(num))
		PB(seq,num);

	int n=seq.size(),maxim=1,max_Pos=0;

	VI longSeq(1,seq[0]),Seq_Pos(1,0),track(n,0);
	track[0]=-1;

	FOR(i,1,n){
		int pos,start=0,end=longSeq.size()-1,len;

		if(longSeq[end]<seq[i]){
			PB(longSeq,seq[i]);
			len=end+2,track[i]=Seq_Pos[end];
			PB(Seq_Pos,i);
		} else if(longSeq[end]==seq[i])
			len=end+1,track[i]=Seq_Pos[end-1];
		else if(longSeq[start]>seq[i]){
			longSeq[0]=seq[i];
			len=1,track[i]=-1,Seq_Pos[0]=i;
		} else {

			while(start<=end){
				int mid=(start+end)/2;

				if(longSeq[mid]==seq[i]){
					pos=mid;
					break;
				} else if(longSeq[mid]<seq[i] && longSeq[mid+1]>seq[i]){
					pos=mid+1,longSeq[pos]=seq[i],Seq_Pos[pos]=i;
					break;
				} else if(longSeq[mid]<seq[i])
					start=mid+1;
				else
					end=mid-1;
			}
			len=pos+1,track[i]=Seq_Pos[pos-1];
		}
		if(maxim<=len)
			maxim=len,max_Pos=i;
	}

	printf("%d\n-\n",maxim);
	print_LIS(seq,track,max_Pos);

	return 0;
}
