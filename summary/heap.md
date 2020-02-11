# heap / 优先队列

1. 效率稳定好坏都是时间复杂度O(NlogN)
2. 额外空间复杂度O(1) 

顾名思义优先队列每次出队的元素都是最大的(大顶堆)
堆是以数组为底层, 根据二叉树和数组索引特殊(左子树index是父节点的2倍 base1 not 0)关系建立的一种数据结构\

特点 : 
0. 局部有序(子树没有父val大)
1. 完全二叉树:整个树是满的, 最底层从左到右没有空隙
2. push_heap 
    1. 新的数据放到数组最后(树底层的最后一个)
    2. 依次上浮
3. pop_heap
    1. root取出 最后一个节点放到root
    2. 下溯


## 实现

``` C++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        buildMaxHeap(nums);
        for (int i = 0; i < k - 1; i++) {
            swap(nums[0], nums[--heapSize]);
            maxHeapify(nums, 0);
        }
        return nums[0];
    }
private:
    int heapSize;
    
    int left(int i) {
        return (i << 1) + 1;
    }
    
    int right(int i) {
        return (i << 1) + 2;
    }
    
    void maxHeapify(vector<int>& nums, int i) {
        int largest = i, l = left(i), r = right(i);
        if (l < heapSize && nums[l] > nums[largest]) {
            largest = l;
        }
        if (r < heapSize && nums[r] > nums[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(nums[i], nums[largest]);
            maxHeapify(nums, largest);
        }
    }
    
    void buildMaxHeap(vector<int>& nums) {
        heapSize = nums.size();
        for (int i = (heapSize >> 1) - 1; i >= 0; i--) {
            maxHeapify(nums, i);
        }
    }
};
```

## 使用

取第k个大的数字
``` C++
// 小顶堆
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) { // 只维护前k个大的数字
                pq.pop();
            }
        }
        return pq.top();
    }
};

// 大顶堆 (default)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};
```