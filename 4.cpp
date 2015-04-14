#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if(m==0){
            if(n%2==0){
                return (B[n/2] + B[n/2-1]) / 2.0;
            }else{
                return B[n/2];
            }
        }
        if(n==0){
            if(m%2==0){
                return (A[m/2] + A[m/2-1]) / 2.0;
            }else{
                return A[m/2];
            }
        }

        return findMedian(A,0,m-1,B,0,n-1);
    }
    
private:
    double findMedian(int A[], int aStart,int aEnd, int B[], int bStart, int bEnd){
        int aMid = (aStart + aEnd) / 2;
        int bMid = (bStart + bEnd) / 2;
        if(aStart==aEnd && bStart==bEnd){
            return (A[aStart] + B[bStart]) / 2.0;
        }
        if(aStart==aEnd){
            if(A[aMid]==B[bMid]){
                return A[aMid];
            }
            if(A[aMid] < B[bMid]){
                if((bEnd-bStart+1)%2!=0){
                    return (B[bMid] + max(A[aMid], B[bMid-1])) / 2.0;
                }else{
                    return B[bMid];
                }
            }else{
                if((bEnd-bStart+1)%2!=0){
                    return (B[bMid] + min(A[aMid], B[bMid+1])) / 2.0;
                }else{
                    return min(B[bMid+1], A[aMid]);
                }
            }
        }else if(bStart==bEnd){
            if(A[aMid]==B[bMid]){
                return A[aMid];
            }
            if(B[bMid]<A[aMid]){
                if((aEnd-aStart+1)%2!=0){
                    return (A[aMid]+max(B[bMid],A[aMid-1])) / 2.0;
                }else{
                    return A[aMid];
                }
            }else{
                if((aEnd-aStart+1)%2!=0){
                    return (A[aMid]+min(B[bMid],A[aMid+1])) / 2.0;
                }else{
                    return min(A[aMid+1],B[bMid]);
                }
            }
        }

        if(aStart==aEnd-1 && bStart==bEnd-1){
            int temp[]={A[aStart],A[aEnd],B[bStart],B[bEnd]};
            std::vector<int> v(temp,temp+4);
            sort(v.begin(),v.end());
            return (v[1]+v[2]) / 2.0;
        }
        if(aStart==aEnd-1){
            if((bEnd-bStart+1)%2!=0){
                if(A[aStart]<=B[bMid] && A[aEnd]<=B[bMid]){
                    return max(B[bMid-1],A[aEnd]);
                }else if(A[aStart]<=B[bMid] && A[aEnd] >= B[bMid]){
                    return B[bMid];
                }else{
                    return min(B[bMid+1],A[aStart]);
                }
            }else{
                if(A[aStart]<=B[bMid] && A[aEnd]<=B[bMid]){
                    return (B[bMid]+max(B[bMid-1],A[aEnd])) / 2.0;
                }else if(A[aStart]<=B[bMid] && A[aEnd] >= B[bMid]){
                    return (B[bMid] + min(B[bMid+1],A[aEnd])) / 2.0;
                }else{
                    return getMiniFour(B[bMid+1],B[bMid+2], A[aStart],A[aEnd]);
                }
            }
        }
        if(bStart==bEnd-1){
            if((aEnd-aStart+1)%2!=0){
                if(B[bStart]<=A[aMid] && B[bEnd]<=A[aMid]){
                    return max(A[aMid-1],B[bEnd]);
                }else if(B[bStart]<=A[aMid]  && B[bEnd]>=A[aMid]){
                    return A[aMid];
                }else{
                    return min(A[aMid+1],B[bStart]);
                }
            }else{
                if(B[bStart]<=A[aMid] && B[bEnd]<=A[aMid]){
                    return (A[aMid]+max(A[aMid-1],B[bEnd])) / 2.0;
                }else if(B[bStart]<=A[aMid]  && B[bEnd]>=A[aMid]){
                    return (A[aMid] + min(A[aMid+1],B[bEnd])) / 2.0;
                }else{
                    return getMiniFour(A[aMid+1],A[aMid+2],B[bStart],B[bEnd]);
                }
            }
        }
        
        int aLength = aEnd - aStart + 1;
        int bLength = bEnd - bStart + 1;
        int mini = min(aLength,bLength);
        if(mini%2==0){
            mini--;
        }
        
        if(A[aMid]>=B[bMid]){
            return findMedian(A,aStart,aEnd-mini/2,B,bStart+mini/2,bEnd);
        }else if(A[aMid]<B[bMid]){
            return findMedian(A,aStart+mini/2,aEnd,B,bStart,bEnd-mini/2);
        }
    }

    double getMiniFour(int a,int b, int c, int d){
        std::vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);
        sort(v.begin(),v.end());
        return (v[0]+v[1]) / 2.0;
    }
};

int main(){
    int A[]={1};
    int B[]={2,3};

    Solution s;
    double r = s.findMedianSortedArrays(A,1,B,2);
    cout << r <<endl;
    return 0;
}