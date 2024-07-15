class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> v(n,1);
        while(k!=0){
            for(int i=1;i<n;i++){
                v[i] = (v[i]+v[i-1]) % 1000000007;
            }
            k--;
        }
        return v[n-1];
    }
};
