// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


// The largest rectangle is shown in the shaded area, which has area = 10 unit.

// For example,
// Given height = [2,1,5,6,2,3],
// return 10.

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        stack<int> myStack;
        int maxArea = 0;
        for(int i = 0; i < height.size(); ++i) {
            if(myStack.empty() || height[i] >= height[myStack.top()]) {
                myStack.push(i);
            } else {
                while(!myStack.empty() && height[i] < height[myStack.top()]) {
                    int h = height[myStack.top()];
                    myStack.pop();
                    int w = myStack.empty() ? i : i-myStack.top()-1;
                    maxArea = max(maxArea, w*h);
                }
                myStack.push(i);
            }
        }
        return maxArea;
    }
};
