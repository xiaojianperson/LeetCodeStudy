#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // maxHeapify 是一个辅助函数，用于对堆进行下沉操作，以维护最大堆的性质
    void maxHeapify(vector<int>& a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i; // 初始化左右子节点的索引和最大值索引为当前节点
        // 如果左子节点存在且大于当前最大值，则更新最大值索引为左子节点
        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        }
        // 如果右子节点存在且大于当前最大值，则更新最大值索引为右子节点
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        // 如果最大值索引不是当前节点，说明子节点比父节点大，需要交换并继续下沉操作
        if (largest != i) {
            swap(a[i], a[largest]); // 交换当前节点和最大子节点的值
            maxHeapify(a, largest, heapSize); // 对交换后的子树继续进行下沉操作
        }
    }

    // buildMaxHeap 是一个辅助函数，用于构建最大堆
    void buildMaxHeap(vector<int>& a, int heapSize) {
        // 从最后一个非叶子节点开始，向上进行下沉操作，直到根节点
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        }
    }

    // findKthLargest 函数用于找出数组中第 k 个最大的元素
    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size(); // 获取原始数组的大小
        buildMaxHeap(nums, heapSize); // 首先构建最大堆
        // 从数组的最后一个元素开始，逐个移除最大元素，直到找到第 k 个最大元素
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]); // 将堆顶元素（当前最大元素）与当前索引的元素交换
            --heapSize; // 减少堆的大小
            maxHeapify(nums, 0, heapSize); // 对新的堆顶元素进行下沉操作，维护最大堆的性质
        }
        // 返回堆顶元素，即第 k 个最大的元素
        return nums[0];
    }
};