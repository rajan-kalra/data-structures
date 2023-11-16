#include <iostream>
#include <vector>
#include <stack>
using namespace std;
  
int getMaxAreaHistogram(vector<int>& histogram) {
    int n = histogram.size();
    int maxArea = 0;

    stack<int> stack_rb;

    /**
     * rightBoundary array shall contain the indexes
     * of next smaller element on the right for each index
     */
    vector<int> rightBoundary(n);

    // boundary case to be handled i.e for rightmost index, smaller element index is n-1
    rightBoundary[n - 1] = n-1;
    stack_rb.push(n - 1);

    for (int i = n - 2; i >= 0; i--) {
        if (histogram[stack_rb.top()] < histogram[i]) {
            rightBoundary[i] = stack_rb.top();
        } else {
            while (stack_rb.empty() == false && histogram[stack_rb.top()] >= histogram[i]) {
                stack_rb.pop();
            }
            if (stack_rb.empty() == true) {
                rightBoundary[i] = n-1;
            } else {    
                rightBoundary[i] = stack_rb.top();
            }
        }
        
        stack_rb.push(i);
    }

    stack<int> stack_lb;
    /**
     * leftBoundary array shall contain the indexes
     * of next smaller element on the left for each index
     */
    vector<int> leftBoundary(n);

    // boundary case to be handled i.e for leftmost index, smaller element index is 0
    leftBoundary[0] = 0;
    stack_lb.push(0);
    
    for (int i = 1; i < histogram.size(); i++) {
        if (histogram[stack_lb.top()] < histogram[i]) {
            leftBoundary[i] = stack_lb.top();
        } else {
            while (stack_lb.empty() == false && histogram[stack_lb.top()] >= histogram[i]) {
                stack_lb.pop();
            }

            if (stack_lb.empty() == true) {
                leftBoundary[i] = n-1;
            } else {    
                leftBoundary[i] = stack_lb.top();
            }
        }

        stack_lb.push(i);
    }

    for (int i = 0; i < n; i++) {
        int width = (rightBoundary[i] - leftBoundary[i] + 1);
        int area = histogram[i] * width;

        // here we find area for each index & calculate the maxArea
        maxArea = max(area, maxArea);
    }

    return maxArea;
}
  
// Driver code
int main()
{
    vector<int> histogram = { 6, 2, 5, 4, 5, 1, 6 };
    int n = sizeof(histogram) / sizeof(histogram[0]);
  
    // Function call
    cout << "Max area: " << getMaxAreaHistogram(histogram) << endl;
    return 0;
}
