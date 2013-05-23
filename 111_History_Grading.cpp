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
	int n,first;
	scanf("%d",&n);

	VI event(n);
	FOR(i,0,n)
		scanf("%d",&event[i]);

	while(scanf("%d",&first)!=EOF){
		
		VI seq(n),longSeq(1);
		seq[first-1]=event[0];

		FOR(i,1,n){
			int tmp;
			scanf("%d",&tmp);
			seq[tmp-1]=event[i];
		}

		longSeq[0]=seq[0];

		FOR(i,1,n){
			int start=0,end=longSeq.size()-1;

			if(longSeq[end]<seq[i]){
				PB(longSeq,seq[i]);
			} else if(longSeq[end]==seq[i]){
				continue;
			} else if(longSeq[start]>seq[i])
				longSeq[0]=seq[i];
			else {

				while(start<=end){
					int mid=(start+end)/2;

					if(longSeq[mid]==seq[i]){
						break;
					} else if(longSeq[mid]<seq[i] && longSeq[mid+1]>seq[i]){
						longSeq[mid+1]=seq[i];
						break;
					} else if(longSeq[mid]<seq[i])
						start=mid+1;
					else
						end=mid-1;
				}
			}
		}
		printf("%d\n",longSeq.size());
	}

	return 0;
}
