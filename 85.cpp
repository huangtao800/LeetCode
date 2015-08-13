#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <climits>

using namespace std;


/**
** General idea: https://leetcode.com/discuss/20240/share-my-dp-solution
**/
class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        int result = 0;
        if(matrix.empty())	return result;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> left(n, 0);
        vector<int> right(n, n);
        vector<int> height(n,0);

        for(int i=0;i<m;i++){
        	int curLeft = 0, curRight = n;
        	for(int j=0;j<n;j++){
        		if(matrix[i][j] == '1'){
        			height[j]++;
        			left[j] = max(left[j], curLeft);
        		}else{
        			height[j] = 0;
        			left[j] = 0;
        			curLeft = j+1;
        		}
        	}

        	for(int j=n-1;j>=0;j--){
        		if(matrix[i][j] == '1'){
        			right[j] = min(right[j], curRight);
        		}else{
        			right[j] = n;
        			curRight = j;
        		}
        	}

        	for(int j=0;j<n;j++){
        		result = max(result, (right[j] - left[j]) * height[j]);
        	}
        }
        return result;
    }
};

int main(){
	char a[] = {'0','0','0','0','1'};
	char b[] = {'1','1','1','1','1'};

	vector<char> line1(a, a+5);
	vector<char> line2(b, b+5);
	vector<vector<char> > matrix;
	matrix.push_back(line1);
	matrix.push_back(line2);

	Solution s;
	int r = s.maximalRectangle(matrix);
	cout << r << endl;
}