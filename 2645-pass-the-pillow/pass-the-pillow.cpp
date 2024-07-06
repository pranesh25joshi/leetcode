class Solution {
public:
    int passThePillow(int n, int time) {
        int p = time % (n-1);
            if((time / (n-1)) % 2 == 0 ){
                return p + 1;
            }
            else{
                return n - p;
            }

    }
};