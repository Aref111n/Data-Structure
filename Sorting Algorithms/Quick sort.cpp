#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll a[1001] ;

ll Partition(ll l, ll r) {
    ll p = a[l] ;
    ll i = l ;
    ll j = r ;

    while(i<j) {
        while(a[i]<=p)
            i++ ;
        while(a[j]>p)
            j-- ;
        if(i<j)
            swap(a[i], a[j]) ;
    }

    swap(a[l], a[j]) ;
    return j ;
}

void quick_sort(ll l, ll r) {
    if(l>=r)
        return ;

    ll pos = Partition(l, r) ;
    quick_sort(l, pos-1) ;
    quick_sort(pos+1, r) ;
}

int main()
{
    ll n ;
    cin >> n ;

    for(int i=0; i<n; i++)
        cin >> a[i] ;

    quick_sort(0, n-1) ;

    for(int i=0; i<n; i++)
        cout << a[i] << " " ;
}
