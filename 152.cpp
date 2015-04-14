#include <iostream>

using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        return maxProductArray(A, 0, n-1);
    }
    
private:
    int maxProductArray(int A[], int left, int right){
        if(left == right) return A[left];
        
        int mid = (left + right) / 2;
        int leftMax = maxProductArray(A,left, mid);
        int rightMax = maxProductArray(A, mid+1, right);
        
        int leftSubMax = A[mid];
        int leftSubMin = A[mid];
        int leftProduct = A[mid];
        int rightSubMax = A[mid+1];
        int rightSubMin = A[mid+1];
        int rightProduct = A[mid+1];
        
        for(int i=mid;i>=left+1;i--){
            leftProduct = leftProduct * A[i-1];
            leftSubMax = max(leftSubMax, leftProduct);
            leftSubMin = min(leftSubMin, leftProduct);
        }
        
        for(int i=mid+1;i<=right-1;i++){
            rightProduct = rightProduct * A[i+1];
            rightSubMax = max(rightSubMax, rightProduct);
            rightSubMin = min(rightSubMin, rightProduct);
        }
        
        int leftRightMax = max(leftSubMax * rightSubMax, leftSubMin * rightSubMin);
        
        return max(leftRightMax,max(leftMax,rightMax));
        
    }
};

int main(){
    int A[] = {2,-5,-2,-4,3};

    Solution s;
    int r = s.maxProduct(A,5);
    cout << r <<endl;
}