class KthLargest {
  priority_queue<int> minHeap;
  int k;

public:
  KthLargest(int k, vector<int> &nums) {
    this->k = k;
    for (int num : nums) {
      add(num);
    }
  }

  int add(int val) {
    if (minHeap.size() < k || val > -minHeap.top()) {
      minHeap.push(-val);
      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }
    return -minHeap.top();
  }
};