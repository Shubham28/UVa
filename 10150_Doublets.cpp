#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)

using namespace std;

char dict[25145][18];
short track[25145];
int len;

void Input()
{
	char ch;
	bool prev=false;
	len=0;
	int pos=0;

	while(ch=getchar()){
		if(ch=='\n' && prev)
			break;
		else if(ch=='\n')
			len++,prev=true,pos=0;
		else {
			prev=false;
			dict[len][pos++]=ch;
		}
	}
	return;
}

int partition(int p,int r)
{
	int k=rand()%(r-p);

	char tmp[18];
	strcpy(tmp,dict[p]);
	strcpy(dict[p],dict[p+k]);
	strcpy(dict[p+k],tmp);

	int i=p;
	EFOR(j,p+1,r){
		if(strcmp(dict[j],dict[p])<0){
			strcpy(tmp,dict[j]);
			++i;
			strcpy(dict[j],dict[i]);
			strcpy(dict[i],tmp);
		}
	}
	strcpy(tmp,dict[i]);
	strcpy(dict[i],dict[p]);
	strcpy(dict[p],tmp);

	return i;
}

void quickSort(int p,int r)
{
	if(p<r){
		int q=partition(p,r);
		quickSort(p,q-1);
		quickSort(q+1,r);
	}
	return;
}

int binsrch(char word[])
{
	int lo=0,hi=len-1;
	while(lo<hi){
		int mid=lo+(hi-lo)/2;
		int cmp=strcmp(dict[mid],word);

		if(cmp==0)
			return mid;
		else if(cmp<0)
			lo=mid+1;
		else
			hi=mid-1;
	}
	if(strcmp(dict[lo],word)!=0)
		return -1;
	return lo;
}

void prntseq(int pos)
{
	if(track[pos]!=pos)
		prntseq(track[pos]);
	printf("%s\n",dict[pos]);

	return;
}
int main()
{
	Input();
	quickSort(0,len-1);

	char from[18],to[18];
	bool first=true;

	while(scanf("%s%s",from,to)!=EOF){
		if(!first)
			printf("\n");
		first=false;

		int pres=binsrch(from),fin=binsrch(to);
		if(strlen(from)!=strlen(to) || pres==-1 || fin==-1){
			printf("No solution.\n");
			continue;
		}

		bool found=false;
		queue<int>bfs;
		bfs.push(pres);

		memset(track,-1,sizeof(track));
		track[pres]=pres;

		while(!bfs.empty()){
			pres=bfs.front();
			bfs.pop();
			if(pres==fin){
				found=true;
				break;
			}

			char word[18];
			strcpy(word,dict[pres]);

			int tot=strlen(word);
			FOR(chng,0,tot){
				char tmp=word[chng];

				for(char let='a';let<='z';let++){
					if(let==tmp)
						continue;
					word[chng]=let;

					int chk=binsrch(word);
					if(chk!=-1 && track[chk]==-1){
						bfs.push(chk);
						track[chk]=pres;
					}
				}
				word[chng]=tmp;
			}
		}
		if(found)
			prntseq(fin);
		else
			printf("No solution.\n");
	}

	return 0;
}
