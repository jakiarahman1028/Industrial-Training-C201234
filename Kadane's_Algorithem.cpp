/*      bismillahir rahmanir rahim   
  		     @ monjurul0007
           
 UVa - 507 Jill Rides Again
 Kadane's Algorithem to find a range with maximum sum in a given 1D arrey.
 
 */


#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define F first
#define S second
#define mod 100000007

typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;

const int dx4[4] = {0,1,0,-1};
const int dy4[4] = {1,0,-1,0};
const int dx8[8] = {0,1,0,-1,1,-1,1,-1};
const int dy8[8] = {1,0,-1,0,1,-1,-1,1};

int main(){
    fasterInOut;
    
    int t;
    cin >> t;
    
    int cnt = 1;
    while(t--){
        int n;
        cin >> n;
        
        // Edge case: No segments to evaluate
        if (n <= 1) {
            cout << "Route " << cnt++ << " has no nice parts\n";
            continue;
        }
        
        int route[n+1], maxSum=1, currentSum=0, startIndex=1;
        int maxStartIndex=-1, maxEndIndex=-1;

        for(int i=0; i<n-1; i++){
            cin >> route[i];
            currentSum += route[i]; // Add current stop's niceness to the running sum
            
            if(currentSum < 0){ // If the sum becomes negative, reset the running sum
                currentSum = 0;
                startIndex = i+2; // Update the starting index for the next potential segment
            }
            
            // Update the maximum sum and segment indices if a better segment is found
            if(maxSum < currentSum || (maxSum == currentSum && maxEndIndex - maxStartIndex < i-startIndex+2)){
                maxSum = currentSum;
                maxStartIndex = startIndex;
                maxEndIndex = i+2;
            }
        }
        
        // If no positive-sum segment is found, output "no nice parts"
        if(maxStartIndex == -1)
            cout << "Route " << cnt++ << " has no nice parts\n";
        else
            cout << "The nicest part of route " << cnt++ << " is between stops " << maxStartIndex << " and " << maxEndIndex << "\n";
    }
    
    return 0;
}
