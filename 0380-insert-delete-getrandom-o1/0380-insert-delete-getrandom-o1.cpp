class RandomizedSet {
    unordered_set<int>s;
public:
    RandomizedSet() {
       
    }
    
    bool insert(int val) {
        if(s.find(val)!=s.end())return 0;
        else {
          
           s.insert(val);
            return 1;
        }
    }
    
    bool remove(int val) {
        if(s.find(val)==s.end())return 0;
        else {
           
            s.erase(val);
            return 1;
        }
    }
    
    int getRandom() {
        return *next(s.begin(),rand()%s.size()); //hehe kaisa laga mera mazak
    }
};