class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int> map;
        for(char i : sentence){
            map[i]++;
        }
        int i = 97;
        while(i<=122){
            if(map[(char)i] == 0){
                return false;
            }
            i++;
        }
        return true;
    }
};