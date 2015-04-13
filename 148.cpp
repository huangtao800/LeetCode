#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        int length = 0;
        ListNode *current = head;
        while(current!=NULL){
        	length++;
        	current = current->next;
        }
        return sortListWithLength(head, length);
    }

private:
	ListNode *sortListWithLength(ListNode *head, int length){
		if(length==1){
			return head;
		}
		int mid = length / 2;
		ListNode *rightHead = head;
		for(int i=0;i<mid;i++){
			if(i==mid-1){
				ListNode* tmp = rightHead;
				rightHead = rightHead->next;
				tmp->next = NULL;
			}else{
				rightHead = rightHead->next;
			}
		}
		ListNode *leftHead = sortListWithLength(head, mid);
		rightHead = sortListWithLength(rightHead,length-mid);

		return mergeList(leftHead,rightHead);
	}

	ListNode* mergeList(ListNode *leftHead, ListNode* rightHead){
		if(leftHead->val < rightHead->val){
			return insertList(leftHead,rightHead);
		}else{
			return insertList(rightHead,leftHead);
		}
	}

	ListNode *insertList(ListNode *des, ListNode *src){
		ListNode *current = des;
		ListNode *srcNext;
		ListNode *currentNext;
		while(src!=NULL){
			while(current->next!=NULL){
				if(current->val < src->val && current->next->val < src->val){
					current = current->next;
				}else{
					break;
				}
			}
			if(current->next == NULL){
				current->next = src;
				break;
			}
			currentNext = current->next;
			srcNext = src->next;
			current->next = src;
			src->next = currentNext;
			src = srcNext;
		}
		return des;
	}
};

void printList(ListNode* head){
	while(head!=NULL){
		cout << head->val <<" ";
		head = head->next;
	}
	cout << endl;
}

int main(){
	ListNode a1(5);
	ListNode a2(4);
	ListNode a3(3);
	ListNode a4(-2);
	ListNode a5(1);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;

	Solution s;
	ListNode *r = s.sortList(&a1);
	printList(r);
	return 0;
}