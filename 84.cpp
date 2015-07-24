#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <climits>

using namespace std;

/** General idea: http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> alreadyProcessedIndex;
        int result = 0;
        
        height.push_back(0);
        for(int i=0;i<height.size();i++){
            if(alreadyProcessedIndex.empty() || height[i] >= height[alreadyProcessedIndex.top()]){
            	alreadyProcessedIndex.push(i);
            }else{
            	while(!alreadyProcessedIndex.empty() && height[alreadyProcessedIndex.top()] > height[i]){
            		int lastIndex = alreadyProcessedIndex.top();
            		alreadyProcessedIndex.pop();
            		int h = height[lastIndex];
            		int leftIndex = alreadyProcessedIndex.empty()? -1 : alreadyProcessedIndex.top();
            		if(h * (i - leftIndex - 1) > result){
            			result = h * (i - leftIndex - 1);
            		}
            	}
            	alreadyProcessedIndex.push(i);
            }
        }
        return result;
    }
};

int main(){
	int h[] = {2,1,2};
	vector<int> height(h, h+3);
	Solution s;
	int r = s.largestRectangleArea(height);
	cout << r << endl;
}