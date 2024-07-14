class Solution {
public:
    string reverseParentheses(string s) {
        int count = 0;
        string p = "";
        // int ptr = 0;
        stack<int> sk;
        sk.push(0);
        for(int i=0; i< s.length(); i++){
            
            if(s[i] != '(' && s[i] != ')'){
                p.push_back(s[i]);
                count++;
            }
            else if(s[i] == '('){
                sk.push(count);
            }
            else{
                reverse(p.begin()+sk.top(), p.end());
                sk.pop();
            }
        }
        return p;
    }
};