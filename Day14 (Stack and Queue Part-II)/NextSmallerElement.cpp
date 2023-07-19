vector<int> Solution::prevSmaller(vector<int> &A) {
    
    stack<pair<int, int>> s;
    int n = A.size();
    
    s.push({A[n-1], n-1});
    vector<int> ans(n);
    
    for(int i= n-2; i>=0; i--){
        while(!s.empty() && s.top().first > A[i]){
            ans[s.top().second] = A[i];
            s.pop();
        }
        
        s.push({A[i], i});
        
    }
    
    while(!s.empty()){
        ans[s.top().second] = -1;
        s.pop();
    }
    
    return ans;
}
