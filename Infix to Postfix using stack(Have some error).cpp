//INFIX:    K+L-M*N+(O^P)*W/U/V*T+Q
//POSTFIX:


#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
    map<char, ll> precedence ;
    precedence['^']=0 ;
    precedence['*'] = precedence['/'] = precedence['%'] = 1 ;
    precedence['+'] = precedence['-'] = 1 ;

    map<char, ll>associativity ;
    associativity['^'] = associativity['*'] = associativity['/']
    = associativity['%'] = associativity['+'] = associativity['-'] = 1 ;
    //1 means left to right, 0 means right to left

    string s ;
    cin >> s ;
    stack <char> st ;
    for(int i=0; i<s.size(); i++) {
        if(s[i]>='A' && s[i]<='Z')
            cout << s[i] ;
        else if(s[i]=='(')
            st.push(s[i]) ;
        else if(s[i]==')') {
            while(!st.empty() && st.top()!='(') {
                    cout << st.top() ;
                    st.pop() ;
            }
            st.pop() ;
        }
        else {
            if(st.size()==0)
                st.push(s[i]) ;
            else{
                while(st.size()) {
                    if(precedence[st.top()]<precedence[s[i]]) {
                        cout << st.top() ;
                        st.pop() ;
                        if(st.size()==0) {
                                st.push(s[i]) ;
                                break;
                            }
                    }
                    else if(precedence[st.top()]==precedence[s[i]])
                    {
                        if(associativity[st.top()]==1) {
                            cout << st.top() ;
                            st.pop() ;
                            if(st.size()==0) {
                                st.push(s[i]) ;
                                break;
                            }
                        }
                        else {
                            st.push(s[i]) ;
                            break;
                        }
                    }
                    else
                        st.push(s[i]) ;
                }
            }
        }
    }

    while(st.size()) {
        cout << st.top() ;
        st.pop() ;
    }

}
