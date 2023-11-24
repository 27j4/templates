

/*-----------------------------Number Theory --------------------------------*/

// 1. To finding GCD
ll gcd(ll a , ll b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}



// 2. Binary exponentiation
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



// 3. Factorisation
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



// 4. Seive - [ To store all the prime numbers]
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



// 5. ETF
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



// 6. Question of matrix exponentiation [Recurrence relation]
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

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



// 7. For calculating binomial coefficient
int fac[1000001];
const int m = 1000000007;
int power(int b , int p){
    // condition of odd p
    int result =1;
    while(p){
        if(p&1){
            result = (result * 1LL*b)%m;
            p--;
        }
        // condition of even p
        else{
            p = p/2;
            b = (b*1LL*b)%m;
        }
    }
    return result;
}
 
int c(int a, int b){
    if (a<b){
        return -1;
    }
    else{
        ll res = fac[a];
        res = (res*1LL*power(fac[b],m-2))%m; // BE
        res = (res*1LL*power(fac[a-b],m-2))%m; // BE
        return res;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // to find aCb
 
   // 1. precomputing a!% m
    fac[0]=1;
    fac[1]=1;
    for(int i = 2; i<= 1000000;i++){
        fac[i] = (fac[i-1]*1LL*i)%m; // 1LL -> for not having integer overflow
    }
 
    int t;
    cin >> t;
    while(t--){
        int a , b;
        cin >> a >> b;
        cout << c(a,b) << '\n';
    }
}

/* INVERSION COUNT USING MERGE SORT */

// C++ program for Merge Sort
#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
        int const right ,vector<int> &vec)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
        *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
        && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            vec[indexOfSubArrayOne] += indexOfSubArrayTwo;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            // vec[indexOfMergedArray] += indexOfSubArrayTwo;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        vec[indexOfSubArrayOne] += indexOfSubArrayTwo;
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end ,vector<int> &vec)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid,vec);
    mergeSort(array, mid + 1, end,vec);
    merge(array, begin, mid, end,vec);
}

// Driver code
int main()
{
    int arr[] = {1,5,4,5,6};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    vector<int> vec(arr_size,0);
    mergeSort(arr, 0, arr_size - 1,vec);
    for(int i = 0 ;i < arr_size ;i++){
        cout << vec[i] << " ";
    }
    cout << "\n";
    return 0;
}





/*-------------------------------Subarray_Problems-------------------------------*/


// 1. Kadanes Algorithm
ll maxSubArraySum(ll a[], ll start , ll end)
{
    ll max_so_far = LLONG_MIN, max_ending_here = 0;
 
    for (ll i = start; i <= end; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}


