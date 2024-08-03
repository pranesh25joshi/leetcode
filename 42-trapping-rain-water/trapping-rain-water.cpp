class Solution {
public:
    vector<int> getLeftMax(vector<int> & height, int n){
        vector<int> LeftMax(n);
        int h = height[0];
        for( int i =0; i<n ; i++){
            h = max(h, height[i] );
            LeftMax[i] = h;
        }
        return LeftMax;
    }
    vector<int> getRightMax(vector<int>& height, int n) {
        vector<int> RightMax(n);
        int h = height[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            h = max(h, height[i]);
            RightMax[i] = h;
        }
        return RightMax;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax =  getLeftMax(height, n);
        vector<int> rightMax = getRightMax(height, n);

        int sum = 0;
        for( int i =0 ; i<n ; i++){
            sum += min(leftMax[i], rightMax[i]) - height[i];
            
        }

        return sum;
    }
};