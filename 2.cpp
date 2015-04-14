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
        ListNode *result = NULL;
        ListNode *head = NULL;
        ListNode *tmpL1 = l1;
        ListNode *tmpL2 = l2;

        int longList = 0;
        while(tmpL1!=NULL || tmpL2!=NULL){

            if(tmpL1!=NULL && tmpL2 !=NULL){
                if(head!=NULL) cout << "head before: "<< head->val << endl;
                ListNode tmp(tmpL1->val + tmpL2->val);                
                if(head!=NULL) cout << "head after: "<< head->val << endl;
                if(result==NULL){
                    result = &tmp;
                    head = result;
                }else{
                    result->next = &tmp;
                    result = result->next;
                    
                }
                tmpL1 = tmpL1->next;
                tmpL2 = tmpL2->next;;
            }else if(tmpL1==NULL){
                longList = 2;
                ListNode tmp(tmpL2->val);
                result->next = &tmp;
                result = result->next;
                tmpL2 = tmpL2->next;
            }else{
                longList = 1;
                ListNode tmp(tmpL1->val);
                result->next = &tmp;
                result = result->next;
                tmpL1 = tmpL1->next;
            }
        }

        // printList(head);
        tmpL1 = l1;
        tmpL2 = l2;
        if(longList == 0 || longList == 1){
            while(head!=NULL){
                tmpL1->val = head->val;
                tmpL1 = tmpL1->next;
                head = head->next;
            }
            return l1;
        }else{
            while(head!=NULL){
                tmpL2->val = head->val;
                tmpL2 = tmpL2->next;
                head = head->next;
            }         
            return l2;
        }
    }
};


int main(){
    ListNode a1(2);
    ListNode a2(4);
    ListNode a3(3);
    a1.next = &a2;
    a2.next = &a3;

    ListNode b1(5);
    ListNode b2(6);
    ListNode b3(4);
    b1.next = &b2;
    b2.next = &b3;

    Solution s;
    ListNode *result = s.addTwoNumbers(&a1,&b1);
    return 0;
}