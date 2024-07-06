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
            if((time / (n-1)) % 2 == 0 ){
                return (time % (n-1)) + 1;
            }
            else{
                return n - (time % (n-1));
            }
        }

    }
};