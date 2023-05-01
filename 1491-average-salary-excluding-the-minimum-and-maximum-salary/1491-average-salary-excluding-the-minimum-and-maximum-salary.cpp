class Solution {
public:
    double average(vector<int>& salary) {
        
        int n = salary.size();
        
        int min=salary[0], max=salary[0];
        
        for(int i=0;i<n;i++)
        {
            if(min>salary[i])
                min = salary[i];
            if(max<salary[i])
                max = salary[i];
        } 
        
        double sum = 0;
        for(int i=0;i<n;i++){
            if(salary[i]==min || salary[i]==max)
                continue;
            sum+=salary[i];
            
        }
                        
        double avg = sum/(n-2);
        return avg;
    }
    
};