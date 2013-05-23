#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define VB vector<bool>

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!=EOF)
		ch=getchar();

	sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

int comb[10000],depth[10000];
int init,targ;

inline int toNum(int fir,int sec,int thr,int frth){
	int num=(fir*1000+sec*100+thr*10+frth);
	return num;
}

inline bool chkVis(int from, queue<int> &brdth, int &dep)
{
	if(depth[from]==-1 && comb[from]!=-1){
		depth[from]=dep+1;
		brdth.push(from);
		if(from==targ){
			printf("%d\n",depth[from]);
			return true;
		}
	}
	return false;
}

int main()
{
	int T;
	Input(T);

	int dig0,dig1,dig2,dig3,tmp;

	EFOR(cases,1,T){
		if(cases>=2){
			char blnk;
			blnk=getchar();
		}

		memset(comb,0,sizeof(comb));
		memset(depth,-1,sizeof(depth));

		Input(dig0),Input(dig1),Input(dig2),Input(dig3);
		init=toNum(dig0,dig1,dig2,dig3);

		Input(dig0),Input(dig1),Input(dig2),Input(dig3);
		targ=toNum(dig0,dig1,dig2,dig3);

		int forb;
		Input(forb);

		FOR(prv,0,forb){
			Input(dig0),Input(dig1),Input(dig2),Input(dig3);
			tmp=toNum(dig0,dig1,dig2,dig3);
			comb[tmp]=-1;
		}

		if(init==targ){
			printf("0\n");
			continue;
		}

		queue<int>brdt;
		brdt.push(init);
		depth[init]=0;

		while(!brdt.empty()){
			int from=brdt.front(),dep=depth[from];
			brdt.pop();

			tmp=(from%10==0)?(from+9):(from-1);
			if(chkVis(tmp,brdt,dep))	break;
			tmp=(from%10==9)?(from-9):(from+1);
			if(chkVis(tmp,brdt,dep))	break;

			tmp=(from%100<=9)?(from+90):(from-10);
			if(chkVis(tmp,brdt,dep))	break;
			tmp=(from%100>=90)?(from-90):(from+10);
			if(chkVis(tmp,brdt,dep))	break;

			tmp=(from%1000<=99)?(from+900):(from-100);
			if(chkVis(tmp,brdt,dep))	break;
			tmp=(from%1000>=900)?(from-900):(from+100);
			if(chkVis(tmp,brdt,dep))	break;

			tmp=(from<=999)?(from+9000):(from-1000);
			if(chkVis(tmp,brdt,dep))	break;
			tmp=(from>=9000)?(from-9000):(from+1000);
			if(chkVis(tmp,brdt,dep))	break;

		}
		if(brdt.empty())
			printf("-1\n");
	}

	return 0;
}
