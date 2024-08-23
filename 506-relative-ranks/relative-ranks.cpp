class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int, vector<int>, greater<int> > q;
        map<int, string> mp;
        vector<string> ans;
        for( auto i : score){
            q.push( i );
        }
        while( q.size() > 3){
            int i = q.top();
            mp[i] = to_string(q.size());     
            q.pop();
        }
        if( q.size() == 3){
            int i = q.top();
            q.pop();
            mp[i] = "Bronze Medal"; 
        }
        if( q.size() == 2){
            int i = q.top();
            q.pop();
            mp[i] = "Silver Medal"; 
        }
        if( q.size() == 1){
            int i = q.top();
            q.pop();
            mp[i] = "Gold Medal"; 
        }
        for( auto i : score){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};