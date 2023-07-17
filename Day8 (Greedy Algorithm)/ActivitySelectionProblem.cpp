class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
         vector<pair<int, int>> meet;
        for(int i=0; i<n; i++){
            meet.push_back({end[i], start[i]});
        }   
        sort(meet.begin(), meet.end());
        int v = -1;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(meet[i].second > v){
                ans++;
                v = meet[i].first;
            }
        }
        return ans;
    }
};