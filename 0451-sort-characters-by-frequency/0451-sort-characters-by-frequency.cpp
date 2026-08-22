class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        vector<pair<char,int>>v;
        for(auto it: mp){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),[](pair<char,int>a,pair<char,int>b){
            return a.second>b.second;
        });
        string ans="";
        for (int i=0;i<v.size();i++){
            char ch=v[i].first;
            int freq=v[i].second;
            for(int j=0;j<freq;j++){
                ans+=ch;
            }
        }
        return ans;
    }
};