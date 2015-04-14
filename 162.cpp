/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

Note:
Your solution should be in logarithmic complexity.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int length = num.size();
        if(length==1){
            return 0;
        }
        if(length==0){
            return -1;
        }
        
        return findPeak(num, 0, length-1);
    }
    

private:
    int findPeak(const vector<int> &num, int left, int right){
        if(left==right){
            return left;
        }else{
            int mid = (left + right) / 2;
            if(mid==0){
                if(num[mid] > num[mid+1]){
                    return mid;
                }else{
                    return findPeak(num, mid+1, right);
                }
            }else{
                if(num[mid] > num[mid-1] && num[mid] > num[mid+1]){
                    return mid;
                }
                if(num[mid-1]<num[mid] && num[mid]<num[mid+1]){
                    return findPeak(num,mid+1, right);
                }else{
                    return findPeak(num,left, mid-1);
                }
            }
        }
    }
};

int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(5);
    a.push_back(9);
    // a.push_back(4);

    Solution s;
    int r = s.findPeakElement(a);
    cout << r << endl;
    return 0;
}