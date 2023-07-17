//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(Item a, Item b){
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        
        return r1 > r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        sort(arr, arr+n, comp);
        int curWeight = 0;
        double finalValue = 0;
        
        for(int i=0; i<n; i++){
            if(curWeight + arr[i].weight <= W){
                curWeight += arr[i].weight;
                finalValue += arr[i].value;
            }
            
            else{
                int remain = W - curWeight;
                finalValue += (arr[i].value / (double)arr[i].weight) * (double)remain;
                break;
            }
        }
        return finalValue;
    }
        
};