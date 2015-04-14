#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* r){
    while(r!=NULL){
        cout << r->val << " ";
        r = r->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int progress = 0;
        ListNode *tmpL1 = l1;
        ListNode *tmpL2 = l2;

        ListNode *start = NULL;
        while(tmpL1!=NULL && tmpL2!=NULL){
            tmpL1 = tmpL1->next;
            tmpL2 = tmpL2->next;
        }
        if(tmpL2==NULL){
            ListNode *tmp = l1;
            l1 = l2;
            l2 = tmp;
        }

        tmpL1 = l1;
        tmpL2 = l2;
        while(tmpL1!=NULL){
            start = tmpL2;
            start->val = tmpL1->val + tmpL2->val + progress;
            if(start->val>=10){
                start->val = start->val - 10;
                progress = 1;
            }else{
                progress = 0;
            }

            tmpL1 = tmpL1->next;
            tmpL2 = tmpL2->next;
        }

        while(tmpL2!=NULL){
            start = tmpL2;
            start->val = tmpL2->val + progress;
            if(start->val >= 10){
                start->val = start->val - 10;
                progress = 1;
            }else{
                progress = 0;
            }
            tmpL2 = tmpL2->next;
        }
        if(progress){
            ListNode *tmp = new ListNode(progress);
            start->next = tmp;
        }
        return l2;
    }
};


int main(){
    ListNode a1(5);
    // ListNode a2(4);
    // ListNode a3(5);
    // a1.next = &a2;
    // a2.next = &a3;

    ListNode b1(5);
    // ListNode b2(6);
    // ListNode b3(4);
    // b1.next = &b2;
    // b2.next = &b3;

    Solution s;
    ListNode *result = s.addTwoNumbers(&a1,&b1);
    printList(result);
    // delete result;
    return 0;
}