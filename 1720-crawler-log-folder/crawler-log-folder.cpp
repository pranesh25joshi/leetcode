class Solution {
public:
    int minOperations(vector<string>& logs) {
        int steps = 0;
        for(string ops:logs){
            if(ops == "../" && steps != 0 ){
                steps--;
            }
            else if(ops == "./" || (ops == "../" && steps == 0 )){

            }
            else{
                steps++;
            }
        }
        return steps;
    }
};