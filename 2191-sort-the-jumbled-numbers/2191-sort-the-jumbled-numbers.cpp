class Solution {
  long  int fv(int num,vector<int>& mapping)
    {
       if(num<10)
       return mapping[num];
       string s = to_string(num);
       string op = "0";
       for(int i =0;i<s.size();i++)
       {
          string a= "";
          a += s[i];
         long int k = stoi(a);
         long int val = mapping[k];
          op =op+to_string(val);
       }
       return(stoi(op));
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
      map<long int, int>m1;
      unordered_map<int,long int>m2;
      for(int i =0;i<nums.size();i++)
      {
        if(m2[nums[i]])
        {
          long int value = m2[nums[i]];
           if(m1[value])
            value++;
            m1[value] = nums[i];
            continue;
         }
       long  int value = fv(nums[i],mapping);
         if(m1[value])
         {
            while(m1[value]>0)
            value++;
            m1[value] = nums[i];
         }
         else
        m1[value] = nums[i];
        m2[nums[i]] = value;
      }
      int count =0;
      for(auto it = m1.begin();it!=m1.end();it++)
      {
         int k = it->second;
         nums[count] = k;
         count++;
      }
      return(nums);
    }
};