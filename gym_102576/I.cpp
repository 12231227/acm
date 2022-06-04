#include <bits/stdc++.h>
using namespace std;

struct Wint:deque<int>
{
    Wint(int n=0)
    {
        push_back(n);
        check();
    }
    Wint& check()
    {
        while(!empty()&&!back())pop_back();
        if(empty())return *this;
        for(int i=1;i<(int)size();++i)
        {
            (*this)[i]+=(*this)[i-1]/10;
            (*this)[i-1]%=10;
        }
        while(back()>=10)
        {
            push_back(back()/10);
            (*this)[size()-2]%=10;
        }
        return *this;
    }
};
istream& operator>>(istream &is,Wint &n)
{
    string s;
    is>>s;
    n.clear();
    for(int i=s.size()-1;i>=0;--i)n.push_back(s[i]-'0');
    return is;
}
ostream& operator<<(ostream &os,const Wint &n)
{
    if(n.empty())os<<0;
    for(int i=n.size()-1;i>=0;--i)os<<n[i];
    return os;
}
bool operator!=(const Wint &a,const Wint &b)
{
    if(a.size()!=b.size())return 1;
    for(int i=a.size()-1; i>=0; --i)
        if(a[i]!=b[i]) return 1;
    return 0;
}
bool operator==(const Wint &a,const Wint &b)
{
    return !(a!=b);
}
bool operator<(const Wint &a,const Wint &b)
{
    if(a.size()!=b.size())return a.size()<b.size();
    for(int i=a.size()-1; i>=0; --i)
        if(a[i]!=b[i])return a[i]<b[i];
    return 0;
}
bool operator>(const Wint &a,const Wint &b)
{
    return b<a;
}
bool operator<=(const Wint &a,const Wint &b)
{
    return !(a>b);
}
bool operator>=(const Wint &a,const Wint &b)
{
    return !(a<b);
}
Wint& operator+=(Wint &a,const Wint &b)
{
    if((int)a.size()<(int)b.size())a.resize((int)b.size());
    for(int i=0; i!=(int)b.size(); ++i)a[i]+=b[i];
    return a.check();
}
Wint operator+(Wint a,const Wint &b)
{
    return a+=b;
}
Wint& operator-=(Wint &a,Wint b)
{
    if(a<b)swap(a,b);
    for(int i=0; i!=b.size(); a[i]-=b[i],++i)
        if(a[i]<b[i])
        {
            int j=i+1;
            while(!a[j])++j;
            while(j>i)
            {
                --a[j];
                a[--j]+=10;
            }
        }
    return a.check();
}
Wint operator-(Wint a,const Wint &b)
{
    return a-=b;
}
Wint operator*(const Wint &a,const Wint &b)
{
    Wint n;
    n.assign(a.size()+b.size()-1,0);
    for(int i=0; i!=a.size(); ++i)
        for(int j=0; j!=b.size(); ++j)
            n[i+j]+=a[i]*b[j];
    return n.check();
}
Wint& operator*=(Wint &a,const Wint &b)
{
    return a=a*b;
}
Wint divmod(Wint &a,const Wint &b)
{
    Wint ans;
    for(int t=a.size()-b.size(); a>=b; --t)
    {
        Wint d;
        d.assign(t+1,0);
        d.back()=1;
        Wint c=b*d;
        while(a>=c)
        {
            a-=c;
            ans+=d;
        }
    }
    return ans;
}
Wint operator/(Wint a,const Wint &b)
{
    return divmod(a,b);
}
Wint& operator/=(Wint &a,const Wint &b)
{
    return a=a/b;
}
Wint& operator%=(Wint &a,const Wint &b)
{
    divmod(a,b);
    return a;
}
Wint operator%(Wint a,const Wint &b)
{
    return a%=b;
}
Wint pow(const Wint &n,const Wint &k)
{
    if(k.empty())return 1;
    if(k==2)return n*n;
    if(k.back()%2)return n*pow(n,k-1);
    return pow(pow(n,k/2),2);
};

vector <Wint> ans;

int main(){
//	freopen("111.in","r",stdin);
//	freopen("out.txt","w",stdout); 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	for (cin >> t; t; t--) {
		Wint n;
		cin >> n;
		ans.clear();
		while ((int)n.size() > 2) {
			int p = (int)n.size() - ((int)n.size() + 1) / 2;
			Wint tmp = n;
			for (int i = 1; i <= p; i++)  tmp.pop_front();
			bool flag = true;
			for (int i = p; i < (int)n.size() - 1; i++)
				if (n[i] != 0) { flag = false; break; }
			if (tmp[tmp.size() - 1] != 1 || !flag) {
				tmp -= 1;
				Wint m;
				for (int i = (int)tmp.size() - 1; i >= (int)tmp.size() - p; i--)
					m.push_back(tmp[i]);
				for (int i = 1; i <= p; i++) tmp.push_front(0);
				tmp += m;
				ans.push_back(tmp);
				n -= tmp;
			}
			else {
				for (int i = 0; i < (int)n.size() - 1; i++)
					if (n[i] != 0) { flag = false; break; }
				for (int i = 1; i <= p; i++) //tmp *= 10;
					tmp.push_front(0);
				if (!flag) tmp += 1; else tmp -= 1;
				ans.push_back(tmp);
				n -= tmp;
			}
		}
		if ((int)n.size() == 1) ans.push_back(n);
		else if ((int)n.size() == 2){
			if (n[1] < n[0]) {
				Wint m; m.push_back(n[1]); m.push_back(n[1]);
				n -= m;
				ans.push_back(m); ans.push_back(n);
			}
			else if (n[1] == n[0]) {
				Wint m; m.push_back(n[1]); m.push_back(n[1]);
				ans.push_back(m);
			}
			else if (n[1] > 1) {
				Wint m; m.push_back(n[1] - 1); m.push_back(n[1] - 1);
				n -= m;
				if (n.size() == 1){
					ans.push_back(m); ans.push_back(n);
				}
				else {
					ans.push_back(m);
					Wint tt;
					tt = 5;
					ans.push_back(tt); ans.push_back(tt);
				}
			}
			else {
				Wint m; m.push_back(9);
				n -= m;
				ans.push_back(m); ans.push_back(n);
			}
		}
		cout << (int)ans.size() << endl;
		for (auto u : ans) cout << u << endl;
	}
} 

