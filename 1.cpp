#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> sortedNumbers = numbers;
        sort(sortedNumbers.begin(),sortedNumbers.end());
        vector<int> result;
        int a, b;
        int left = 0, right = sortedNumbers.size()-1;
        
        while(left<right){
            int sum = sortedNumbers[left] + sortedNumbers[right];
            if(sum==target){
                a = sortedNumbers[left];
                b = sortedNumbers[right];
                break;
            }
            if(sum<target){
                left++;
            }else{
                right--;
            }
        }
        
        for(int i=0;i<numbers.size();i++){
            if(numbers[i]==a || numbers[i]==b){
                result.push_back(i+1);
                
                if(result.size()==2){
                    return result;
                }
            }
        }
        return result;
    }
};

int main(){
    return 0;
}