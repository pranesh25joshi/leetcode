class Solution {
public:
    int transform( string convert, int k){
        while( k > 0){
            int sum = 0;
            for( auto i : convert ){
                sum += i - '0';
            }
            convert = to_string(sum);
            k--;
        }
        return stoi(convert);
    }
    int getLucky(string s, int k) {
        string convert = ""; 
        for( auto i : s){
            int num = i - 'a' + 1;
            convert += to_string(num);
        }
        return transform( convert, k );

    }
};