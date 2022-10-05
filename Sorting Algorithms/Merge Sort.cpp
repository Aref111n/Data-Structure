#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll a[1001] ;

void Merge(ll l, ll m, ll r) {
    ll i = l ;
    ll j = m+1 ;
    ll k = l ;
    ll b[r-l+6] ;

    while(i<=m && j<=r) {
        if(a[i]<=a[j])
            b[k++] = a[i++] ;
        else
            b[k++] = a[j++] ;
    }

    while(i<=m)
        b[k++] = a[i++] ;
    while(j<=r)
        b[k++] = a[j++] ;

    //cout << l << " " << r << endl ;
    for(int k=l; k<=r; k++) {
        a[k] = b[k] ;
        //cout << a[k] << " " ;
    }
    //cout << endl ;
}

void merge_sort(ll l, ll r) {
    if(l>=r)
        return ;

    ll m = (l+r)/2 ;
    merge_sort(l, m) ;
    merge_sort(m+1, r) ;
    Merge(l, m, r) ;
}

int main()
{
    ll n ;
    cin >> n ;

    for(int i=0; i<n; i++)
        cin >> a[i] ;

    merge_sort(0, n-1) ;

    for(int i=0; i<n; i++)
        cout << a[i] << " " ;
}
