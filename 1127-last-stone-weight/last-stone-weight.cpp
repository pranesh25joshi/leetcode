class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for( auto i : stones){
            q.push( i );
        }
        while( q.size() > 1){
            int i = q.top();
            q.pop();
            int j = q.top();
            q.pop();
            if( i == j){
            }
            else{
                q.push( i - j);
            }
        }
        if(q.empty()){
            return 0;
        }
        else{
            return q.top();
        }
    }
};