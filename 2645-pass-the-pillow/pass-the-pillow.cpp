class Solution {
public:
    int passThePillow(int n, int time) {
        if(n == time){
            return n - 1;
        }
        else if(n > time){
            return time + 1;
        }
        else{
            int p = time % (n-1);
            if((time / (n-1)) % 2 == 0 ){
                return p + 1;
            }
            else{
                return n - p;
            }
        }

    }
};