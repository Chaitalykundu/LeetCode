class MyCalendarTwo {
public:
    vector<pair<int,int>> b, clash;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        // sort(b.begin(), b.end());
        
        for(int i = 0; i<clash.size(); i++){
            if(start>=clash[i].second||end<=clash[i].first) continue;
            else return false;
        }
        // cout<<"ok"<<endl;
        for(int i=0;i<b.size();i++){
            if(start>=b[i].second||end<=b[i].first) continue;
            else{
                int s = start<b[i].first?b[i].first:start;
                int e = end<b[i].second?end:b[i].second;
                clash.push_back(pair<int,int>(s,e));
            }
        }

        b.push_back(pair<int,int>(start,end));

        return true;
    }
};