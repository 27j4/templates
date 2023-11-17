// Tenplate 1 -  Palindrome in a string 
bool palin(string s){
	if(s.size()<=1){
		return true;
	}
	int i = 0 , j = s.size()-1;
	while(i<j){
		if(s[i]!=s[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}


// Template 2 - Binary exponentiation
const int m = 1e9+7;
ll binpow(ll a , ll b){
	ll ans = 1;
	while(b){
		if(b&1){
			ans = (ans*a)%m;
			b--;
		}
		else{
			a = (a*a)%m;
			b = b/2;
		}
	}
	return ans;
}


// Template 3 - Factorisation
const int maxN = 10000000;
int arr[maxN+1]={0};
void factorization(){
    /*
    Note:
    ** Function getFactorization gives factorization in the form of map 
    ** O(Nloglog(N))
    */
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2;i <= maxN ;i++){
        if(!arr[i]){
            for(int j = i ;j <= maxN ;j+=i){
                if(!arr[j])
                    arr[j] = i;
            }
        }
    }
}
map<int,int> getFactorization(int x)
{
    // O(logn)
    factorization();
    map<int,int> ret;
    while (x != 1) {
        ret[arr[x]]++;
        x = x / arr[x];
    }
    return ret;
}


// Template 4 - Seive
const int maxN = 10000000;
bool arr[maxN+1]={0};
void seive(){
    // true means not a prime
    // false menas a prime
    /*
    Note -  This function stores all prime number in the range maxN in the form of true
            *** We have to call seive in the main function for use ***
    */
    arr[0] = true;
    arr[1] = true; 
    for(int i = 2;i*i <= maxN ;i++){
        if(!arr[i]){ // is a prime
            for(int j = i*i;j<= maxN;j+=i){
                arr[j] = true;
            }
        }
    }
}


// Template 5 - ETF[Euler Tuotient Function]
const int maxN = 1e7;
int phi[maxN+1];
void etf(){
	// Note -- call etf , take according size of array
	for(int i = 1 ; i <= maxN ;i++){
		phi[i] = i-1;
	}
	for(int i = 2;i<= maxN;i++){
		if(phi[i]==i-1){
			for(int j = i*2 ;j<= maxN ;j+=i){
				phi[j] = phi[j] - phi[j]/i;
			}
		}
	}
}

// Template 6 - GCD
int gcd(int a , int b){
	if(b==0){
		return a;
	}
	else{
		return gcd(b,a%b);
	}
}


// Template 7 - Matrix Multiplication
// Template 8 - MEX[Minimum Excluded]
// Template 9 - Prefix , Suffix Array
int prefix[n];
prefix[0] = arr[0];
for(int i =1;i < n;i++){
	prefix[i] = arr[i] + prefix[i-1]; // as in question
}

int suffix[n];
suffix[n-1] = arr[n-1];

// Temaplate 10 - To find how many powers of x present in n
int cnt_power(int n,int x){
	if(n==0){
		return 0;
	}
	else{
		int cnt = 0;
		while(!(n%x)){
			cnt++;
			n = n/x;
		}
		return cnt;
	}
}

// Template 11 - Matrix Expo Ques[Fibbonaci]
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb emplace_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define rloop(i,b,a) for(ll i=b;i>=a;i--)
#define test int t; cin>>t; while(t--)
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<":"; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*--------------------------------------------------------------------------------------------------------------*/
ll arr[3];
ll I[3][3] , T[3][3];
void mul(ll A[3][3] , ll B[3][3] , ll dim){
    ll res[dim+1][dim+1];
    for(ll i = 1 ; i <= dim ;i++){
        for(ll j = 1 ;j <= dim ;j++){
            res[i][j] = 0;
            for(ll k = 1 ; k <= dim ;k++){
                res[i][j]+=(A[i][k]*B[k][j])%mod;
            }
        }
    }
    for(int i = 1;i <= dim ;i++){
        for(int j = 1;j <= dim ;j++){
            A[i][j] = res[i][j];
        }
    }
}
ll getfib(ll n ){
    if(n==0){
        return arr[1];
    }
    if(n==1){
        return arr[2];
    }
    I[1][1] = 1 , I[2][2] = 1;
    I[1][2] = I[2][1] = 0;
    T[1][2] = T[2][1] = T[2][2] = 1;
    T[1][1] = 0;
    n = n-1;
    while(n){
        if(n&1){
            mul(I,T,2);
            n--;
        }
        else{
            mul(T,T,2);
            n = n / 2;
        }
    }
    return (arr[1]*I[1][2] + arr[2]*I[2][2])%mod;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t ;
    cin >> t;
    while(t--){
        cin >> arr[1] >> arr[2];
        ll n;
        cin >> n;
        cout << getfib(n) << "\n";
    }
}

/*---Anshul_Pandey---------------------------------------------------------------------------------------------*/

