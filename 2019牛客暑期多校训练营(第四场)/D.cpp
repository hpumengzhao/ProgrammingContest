#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
    int T;
    cin >> T;
    while(T--){
        ll a;
        cin >> a;
        if(a%3 == 0){
            cout << 1 << ' ' << a << endl;
        } else {
            vector<ll> odd;
            vector<ll> even;
            for(ll i = 0; i <= 62; ++i){
                if(a&(1LL<<i)){
                    if(i%2LL == 0)    odd.push_back(i);
                    else    even.push_back(i);
                }
            }
            // cout << odd.size() << ' ' << even.size() << endl;
            if(odd.size() == 0 || even.size() == 0){
                ll l = 0, r = 0;
                if(odd.size() >= 3){
                    for(int i = 0; i <= 2; ++i){
                        r |= 1LL<<odd[i];
                    }
                    for(int i = odd.size()%3; i < odd.size(); ++i){
                        l |= 1LL<<odd[i];
                    }
                }
                if(even.size() >= 3){
                    for(int i = 0; i <= 2; ++i){
                        r |= 1LL<<even[i];
                    }
                    for(int i = even.size()%3; i < even.size(); ++i){
                        l |= 1LL<<even[i];
                    }
                }
                cout << 2 << ' ' << r << ' ' << l << endl;
                continue;
            }
            ll l = a, r = a;
            if(a%3LL == 2LL){
                l &= ~(1LL<<even[0]);
                r = 1LL<<odd[0] | 1LL<<even[0];
            } else {
                l &= ~(1LL<<odd[0]);
                r = 1LL<<odd[0] | 1LL<<even[0];
            }
            cout << 2 << ' ' << r << ' ' << l << endl;
        }
    }
    return 0;
}
