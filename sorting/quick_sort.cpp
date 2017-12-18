#include <bits/stdc++.h>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef vector<pair<lli,lli> > vplli;

inline bool isPrime(lli n){
    if (n <= 1)  {
        return false;
    }
    if (n <= 3)  {
        return true;
    }

    if (n%2 == 0 || n%3 == 0) {
        return false;
    }
    
    for (int i=5; i*i<=n; i=i+6){
        if (n%i == 0 || n%(i+2) == 0){
            return false;
        }
    }

    return true;
}

inline bool isEven(lli x){
    if(x&1) return false;
    else return true;
}

inline int binSearch(int arr[],int val,int b){
    int low=0,high=b-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]>val){
            high=mid-1;
        }
        else if(arr[mid]<val){
            low=mid+1;
        }
        else{
            return 1;
        }
    }
    return 0;
}
ll partition(ll *arr,ll l,ll h){
    ll i = l-1;
    ll pivot = arr[h];

    for (int j=l;j<h;j++){
        if (arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}


void quicksort(ll *arr,ll l,ll h){
    if (l>=h)
        return;
    ll p = partition(arr,l,h);
    quicksort(arr,l,p-1);
    quicksort(arr,p+1,h);
}

int main(){
    ll n;
    cin>>n;
    ll arr[n];

    for (int i=0;i<n;i++)
        cin>>arr[i];

    quicksort(arr,0,n-1);
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
