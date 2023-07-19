class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        sort(str.begin(),str.end());
        int i=0,j=0;
        int n=str.size();
        string s="";
        while(i<str[0].size() && j<str[n-1].size()){
            if(str[0][i]!=str[n-1][j]) break;
            s+=str[0][i];
            i++;j++;
        }
        return s;
    }
};