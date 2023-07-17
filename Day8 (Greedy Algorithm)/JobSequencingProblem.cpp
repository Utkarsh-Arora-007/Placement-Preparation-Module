/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    static bool comparison(Job &a, Job &b){
        return (a.profit > b.profit);
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        sort(arr, arr+n, comparison);
        
        int max_dead = arr[0].dead;
        
        for(int i=1; i<n; i++){
            max_dead = max(max_dead, arr[i].dead);
        }
        
        vector<int> slot(max_dead +1, -1);
        
        int no_jobs = 0, to_profit = 0;
        
        for(int i=0; i<n;i++){
            
            for(int j =arr[i].dead; j>0; j--){
             if(slot[j] == -1){
                no_jobs++;
                to_profit = to_profit + arr[i].profit;
                slot[j] = arr[i].id;
                break;
              }
            }
        
        }
    
    vector<int> ans;
    ans.push_back(no_jobs);
    ans.push_back(to_profit);
    
    return ans;
        
        
    } 
    
};