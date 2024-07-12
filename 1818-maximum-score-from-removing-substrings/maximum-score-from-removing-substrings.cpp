class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int gain = 0;
        string stack;
        char firstChar = 'a', secondChar = 'b';
        
        if (x < y) {
            swap(x, y);
            swap(firstChar, secondChar);
        }
        
        for (char ch : s) {
            if (!stack.empty() && stack.back() == firstChar && ch == secondChar) {
                gain += x;
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }
        
        string remaining;
        swap(remaining, stack);
        
        for (char ch : remaining) {
            if (!stack.empty() && stack.back() == secondChar && ch == firstChar) {
                gain += y;
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }
        
        return gain;
    }
};
