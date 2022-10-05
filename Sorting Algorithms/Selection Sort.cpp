#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

void selection_sort(ll a[], ll n) {
    for(int i=0; i<n-1; i++) {
        int mn = i ;
        for(int j=i+1; j<n; j++) {
            if(a[j]<a[mn])
                mn = j ;
        }
        if(mn != i)
            swap(a[i], a[mn]) ;
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

    selection_sort(a, n) ;
}
