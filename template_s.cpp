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

