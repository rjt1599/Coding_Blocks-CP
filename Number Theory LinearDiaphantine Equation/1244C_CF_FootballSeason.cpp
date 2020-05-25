#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#define ll long long
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))

ll GCD;

// ll X, Y;

void gcd(ll a, ll b)
{
    if(b==0)
    {
        GCD = a;
        return;
    }
    gcd(b, a % b);
}
ll inverse_modulo(ll a, ll m)
{   
    
    gcd(a, m);
    if(GCD != 1)
    {
        std::cout << "Does not exist";
    }
    ll ans = 1;
    ll p = m - 2;
    a = a % m;
    while(p > 0)
    {
        if(p & 1)
        {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        p = p >> 1;
    }
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    /*
    //Use fast i/o at starting of main() i.e.

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    */

    ll n, p, w, d;
    std::cin >> n >> p >> w >> d;

    gcd(w,d);
    ll g = GCD;

    p /= g;
    w /= g;
    d /= g;

    if(n * w < p)
    {
        std::cout << -1;
        return 0;
    }

    if(p % g != 0)
    {
        std::cout << -1 ;
        return 0;
    }
    ll p2, d_1;
    // if(w % g == 0)
    p2 = p % w;
    d_1 = inverse_modulo(d % w, w);
    ll y = p2 * d_1;

    if((p - y * d) % w != 0 )
    {
        std::cout << -1;
        return 0;
    }
    ll x;
    
    x  = (p - y * d) / w;

    if( x < 0)
    {
        std::cout << -1;
        return 0;
    }
    if(x + y > n)
    {
        std::cout << -1;
        return 0; 
    }

    std::cout << x << " " << y << " " << n - x - y;
    
    return 0;
}