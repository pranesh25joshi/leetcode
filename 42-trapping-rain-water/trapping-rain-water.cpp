class Solution {
public:
    vector<int> getLeftMax(vector<int> & height, int n){
        vector<int> LeftminusRightMax(n);
        int h = height[0];
        for( int i =0; i<n ; i++){
            h = max(h, height[i] );
            LeftminusRightMax[i] = h;
        }
        h = height[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            h = max(h, height[i]);
            LeftminusRightMax[i] = min( h, LeftminusRightMax[i]);
        }
        return LeftminusRightMax;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax =  getLeftMax(height, n);

        int sum = 0;
        for( int i =0 ; i<n ; i++){
            sum += leftMax[i] - height[i];         
        }

        return sum;
    }
};