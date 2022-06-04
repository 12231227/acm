#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;

char inputs[maxn],ch[maxn],ans[maxn];    //����ǰ�ַ���
char S[maxn * 2];     //������ַ���
int radius[maxn * 2]; //���İ뾶

int makestr(int len)
{ //�ַ�������
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        S[cnt++] = '#';
        S[cnt++] = inputs[i];
    }
    S[cnt++] = '#';
    return cnt;
}

void manacher(int len)
{
    for (int i = 0; i <= len; i++) radius[i] = 0;
    int R = -1; //���һ����ұ߽�
    int C = -1; //���һ����ұ߽�ĶԳ�����
    for (int i = 0; i < len; i++)
    {
        if (i <= R)
        {                                                  //��һ���ƶ�λ����R��
            radius[i] = min(radius[2 * C - i], R - i + 1); //�������R�����ڻ��Ĵ��Ļ��Ĵ��ڵ�Ԫ�رض�����
        }
        else
        {
            radius[i] = 1;
        }
        while (i + radius[i] < len && i - radius[i] > -1)
        { //���Ʊ߽�
            if (S[i - radius[i]] == S[i + radius[i]])
            { //��������չ
                radius[i]++;
            }
            else
            {
                break;
            }
        }
        if (i + radius[i] > R)
        { //����R,C
            R = i + radius[i] - 1;
            C = i;
        }
    }
    return;
}

int L[maxn];
int R[maxn];

void solve()
{
    int len = strlen(inputs);
    int manlen = makestr(len);
    manacher(manlen);
    int nowL = len - 1;
    for (int i = 0; i < len; i++)
    {
        R[i] = maxn + 10;
    }
    for (int i = 0; i < manlen; i++)
    {
        if (i % 2 == 0)
        {
            int mid = i / 2;
            int rr = radius[i] - 1;
            int LL = mid - (rr / 2);
            int RR = mid + (rr / 2) - 1;
            L[LL] = max(L[LL], RR);
            R[RR] = min(R[RR], LL);
        }
        else
        {
            int mid = i / 2;
            int rr = radius[i] - 2;
            int LL = mid - (rr / 2);
            int RR = mid + (rr / 2);
            L[LL] = max(L[LL], RR);
            R[RR] = min(R[RR], LL);
        }
    }
    for (int i = 1; i < len; i++)
    {
        L[i] = max(L[i - 1] - 1, L[i]);
    }
    for (int i = len - 2; i >= 0; i--)
    {
        R[i] = min(R[i + 1] + 1, R[i]);
    }
    /*for (int i = 0; i < len; i++)
    {
        printf("%d ", L[i]);
    }
    printf("\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", R[i]);
    }*/
}

int main()
{
	int t;
	scanf("%d" , &t);
	while (t--) {
		scanf("%s", ch);
		int n = strlen(ch);
		int o = n;
        int l,r;
        for (l = 0,r = n - 1;l < r;l++,r--) {
            if (ch[l] != ch[r]) break;
        }
        if (l >= r) {
            for (int i = 0; i < n; i++) printf("%c" , ch[i]);
            printf("\n");
        }
        else {
        	int m = 0;
	        for (int i = 0; i < l; i++) ans[m++] = ch[i];
	        n = 0;
	        for (int i = l;i <= r;i++) inputs[n++] = ch[i];
	        inputs[n] = '\0';
			for (int i = 0; i < n; i++) L[i] = 0 , R[i] = n - 1;
	    	solve();
	        if (L[0] > n - 1 - R[n - 1]) {
	            for (int i = 0; i <= L[0]; i++) ans[m++] = inputs[i];
	        }
	        else {
	            for (int i = R[n - 1]; i < n; i++) ans[m++] = inputs[i];
	        }
	    	for (int i = r + 1; i < o;i++) ans[m++] = ch[i];
	        for (int i = 0; i < m; i++) printf("%c" , ans[i]);
	    	printf("\n");
		}
	}
    return 0;
}

