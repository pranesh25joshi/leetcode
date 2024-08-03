class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> umap;
        unordered_map<int, int> amap;
        for( int num : target){
            umap[num]++;
        }
        for( int num : arr){
            amap[num]++;
        }
        for( int num : arr){
            if( umap[num] != amap[num]){
                return false;
            }
        }
        return true;

    }
};