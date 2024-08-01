class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for( char ss : s){
            if(st.empty()){
                st.push(ss);
            }
            else{
                if( (st.top() == '(' && ss == ')') || (st.top() == '[' && ss == ']')  ||  (st.top() == '{' && ss == '}')){

                st.pop();
            }
                else{
                    st.push(ss);
                }
            }

        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};