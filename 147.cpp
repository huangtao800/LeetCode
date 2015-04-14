#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode *pre = head;
        ListNode *current = head->next;
        ListNode *currentNext = NULL;
        ListNode *start = head;
        ListNode *startPre = NULL;
        while(current!=NULL){
            currentNext = current->next;
            while(start->val < current->val){
                startPre = start;
                start = start->next;
            }
            if(start == current){
                pre = current;
                current = current->next;
                continue;
            }
            if(start == head){
                pre->next = current->next;
                current->next = head;
                head = current;
            }else{
                pre->next = current->next;
                current->next = start;
                startPre->next = current;
            }
            
            current = currentNext;
        }
        return head;
    }
};

void printList(ListNode *a1){
    while(a1!=NULL){
        cout << a1->val <<" ";
        a1 = a1->next;
    }
    cout << endl;
}

int main(){
    ListNode a1(1);
    ListNode a2(2);
    ListNode a3(4);
    ListNode a4(0);

    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;

    Solution s;
    ListNode *r = s.insertionSortList(&a1);

    printList(r);
    return 0;
}