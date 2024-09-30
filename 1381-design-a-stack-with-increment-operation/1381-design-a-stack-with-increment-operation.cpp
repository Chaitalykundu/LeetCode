class CustomStack {
private:
    vector<int> nums;
    int top;
public:
    CustomStack(int maxSize) {
        nums.resize(maxSize); top = -1;
    }
    
    void push(int x) {
        if(top+1 >= nums.size()) return;
        top++;
        nums[top] = x;
    }
    
    int pop() {
        if(top != -1){
            return nums[top--];
        }
        return -1;
    }
    
    void increment(int k, int val) {

        for(int i=0; i<min(k, top+1); i++){
            nums[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */