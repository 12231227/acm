#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int t;
	int nums[50],nump[50],numt[50];
	scanf("%d",&t);
	while (t--){
		char s[111],t[111],p[111];
		scanf("%s %s %s",&s,&t,&p);
		memset(nump,0,sizeof(nump));
		memset(nums,0,sizeof(nums));
		memset(numt,0,sizeof(numt));
		for (int i = 0 ;i < strlen(p); i++)
		 nump[p[i] - 'a' + 1]++;
		for (int i = 0 ;i < strlen(s); i++)
		 nums[s[i] - 'a' + 1]++;
		for (int i = 0 ;i < strlen(t); i++)
		 numt[t[i] - 'a' + 1]++;
		bool flag = true;
		int i = 0; int j = 0;
		while (i < strlen(s) && j < strlen(t)){
			if (s[i] == t[j]) { i++; j++; }
			else j++;
		}
		if (i != strlen(s)) flag = false;
		for (int i = 1; i <= 26; i++)
		 if (nums[i] + nump[i] < numt[i]) { flag = false; break; }
		if (flag) printf("YES\n"); else printf("NO\n");
	}
} 
