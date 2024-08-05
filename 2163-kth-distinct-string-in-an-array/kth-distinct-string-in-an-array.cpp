class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> umap;
        for( string w : arr){
            umap[w]++;
        }
        for (string w : arr) {
            if (umap[w] == 1) {
                k--;
                if (k == 0) {
                    return w;
                }
            }
        }
        return "";
    }
};