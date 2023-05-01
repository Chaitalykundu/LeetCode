class Solution {
public:
    double average(vector<int>& salary) {
        
        int n = salary.size();
        
        int min=salary[0], max=salary[0];
        double sum = 0;

        
        for(int i=0;i<n;i++)
        {
            if(min>salary[i])
                min = salary[i];
            if(max<salary[i])
                max = salary[i];
            sum+=salary[i];
        } 
        
        sum = sum - min - max;
                        
        return sum/(n-2);
    }
    
};