#include <iostream>
#include <vector>
#include <stack>
using namespace std;
  
int getMaxAreaHistogram(vector<int>& histogram) {
    int n = histogram.size();
    int maxArea = 0;

    // populating right boundary array having indexes of next smaller element for each index
    stack<int> stack_rb;
    vector<int> rightBoundary(n);

    // boundary case to be handled
    stack_rb.push(n - 1);
    rightBoundary[n - 1] = n;

    for (int i = n - 2; i >= 0; i--) {
        while (stack_rb.empty() == false && histogram[i] < histogram[stack_rb.top()]) {
            stack_rb.pop();
        }

        if (stack_rb.empty()) {
            rightBoundary[i] = n;
        } else {
            rightBoundary[i] = stack_rb.top();
        }

        stack_rb.push(i);
    }

    // populating left boundary array having indexes of next smaller element for each index
    stack<int> stack_lb;
    vector<int> leftBoundary(n);

    // boundary case to be handled
    stack_lb.push(0);
    leftBoundary[0] = -1;
    
    for (int i = 1; i < histogram.size(); i++) {
        while (stack_lb.empty() == false && histogram[i] < histogram[stack_lb.top()]) {
            stack_lb.pop();
        }

        if (stack_lb.empty()) {
            leftBoundary[i] = -1;
        } else {
            leftBoundary[i] = stack_lb.top();
        }

        stack_lb.push(i);
    }
    
    for (int i = 0; i < n; i++) {
        int width = (rightBoundary[i] - leftBoundary[i] - 1);
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