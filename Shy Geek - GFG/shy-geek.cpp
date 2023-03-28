//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

class Shop
{
    vector<int> chocolates;
    int countOfCalls;
    public:
    Shop()
    {
        countOfCalls = 0;
    }
    void addChocolate(int x)
    {
        chocolates.push_back(x);
    }
    long long get(int i)
    {
        countOfCalls++;
        if(i<0 || i>=(int)chocolates.size() || countOfCalls>50)return -1;
        return chocolates[i];
    }
};


// } Driver Code Ends
//User function Template for Java

/*
Instructions - 

    1. 'shop' is object of class Shop.
    2. User 'shop.get(int i)' to enquire about the price
            of the i^th chocolate.
    3. Every chocolate in shop is arranged in increasing order
            i.e. shop.get(i) <= shop.get(i + 1) for all 0 <= i < n - 1
*/
class Solution{
    public:
    
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long* BinarySearch(int n, long k, Shop& shop) {
        long ans = 0;
        int low = 0, high = n - 1;
        long price = -1;
        int mid = -1;
        while (low <= high) {
            mid = (low + high) / 2;
            price = shop.get(mid);
            if (price == k) {
                long* result = new long[2];
                result[0] = price;
                result[1] = mid;
                return result;
            } else if (price < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        long* result = new long[2];
        result[0] = price;
        result[1] = mid;
        return result;
    }

    long long find(int n, long k) {
        if (k == 0) return 0;
        long ans = 0;
        long* binarysearch = BinarySearch(n, k, shop);
        int mid = (int)binarysearch[1];
        long price = binarysearch[0];
        if (price == k) return 1;
        if (price == -1) return 0;
        if (price > k && mid > 0) {
            long price2 = shop.get(mid - 1);
            ans += (k / price2);
            k = k % price2;
        } else if (price < k) {
            ans += (k / price);
            k = k % price;
        }
        return ans + find(mid, k);
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        long long k;
        cin >> k;
        
        Shop shop;
        for(int i = 0; i<n; i++)
        {
            int x;
            cin >> x;
            shop.addChocolate(x);
        }
        
        Solution obj(shop);
        long long res = obj.find(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends