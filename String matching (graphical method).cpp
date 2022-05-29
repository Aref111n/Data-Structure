#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll tab[100][27] ;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("outp.txt", "w", stdout);
#endif
    string s, p ;
    cin >> s >> p ;

    char ch = p[0] ;
    ll cp = 0 ;

    for(int i=0; i<p.size(); i++) {
        tab[i][int(p[i]-'a')] = i+1 ;
        if(ch!=p[i] && cp==0) {
            tab[i][int(ch - 'a')] = i ; 
        }
    }

    ll k = 0 ;
    for(int i=0; i<s.size(); i++) {
        k = tab[k][int(s[i]-'a')] ;
        if(k==p.size()) {
          cout << "Match Found at index " << i-p.size()+1 << endl ;
          return 0 ;
        }
    }

    cout << "Not Found" << endl ;
    return 0 ;
}
