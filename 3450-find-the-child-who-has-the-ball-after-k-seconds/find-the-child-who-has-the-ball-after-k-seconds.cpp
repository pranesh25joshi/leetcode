class Solution {
public:
    int numberOfChild(int n, int k) {
        int count = 0;
        int s = -1;
        for(int i = 1; i<=k; i++){
            if(count == n-1 || count == 0){
                s = -1*s;
            }
            count  = count + s;
        } 
        return count;
    }
};