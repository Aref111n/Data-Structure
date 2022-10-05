#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

void insertion_sort(ll a[], ll n) {
    for(int i=1; i<n; i++) {
        ll temp = a[i] ;
        ll j = i-1 ;
        while(j>=0 && a[j]>temp) {
            a[j+1] = a[j] ;
            j-- ;
        }
        a[j+1]=temp ;
    }

    for(int i=0; i<n; i++)
        cout << a[i] << " " ;
    cout << endl ;
}

int main()
{
    ll n ;
    cin >> n ;
    ll a[n+1] ;
    for(int i=0; i<n; i++)
        cin >> a[i] ;

    insertion_sort(a, n) ;
}
