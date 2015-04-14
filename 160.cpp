/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

*/

#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        int numA = 0, sumA = 0;
        int numB = 0, sumB = 0, newSumB=0;
        ListNode* current;
        for(current = headA;current!=NULL;current = current->next){
        	numA++;
        	sumA += current->val;
        }
        for(current = headB;current!=NULL;current = current->next){
        	numB++;
        	sumB += current->val;
        }

        for(current = headA;current!=NULL;current = current->next){
        	current->val = current->val + 1;
        }
        for(current = headB;current!=NULL;current = current->next){
        	current->val = current->val - 1;
        	newSumB+=current->val;
        }

        int repeatedNodes = numB - (sumB - newSumB);
        if(repeatedNodes == 0){
        	for(current=headA;current!=NULL;current = current->next){
        		current->val = current->val - 1;
        	}
        	for(current=headB;current!=NULL;current = current->next){
        		current->val = current->val + 1;
        	}
        	return NULL;
        }

        ListNode *result;
        int index = 1;
        for(current = headA;current!=NULL;current = current->next,index++){
        	if(index<=numA-repeatedNodes){
        		current->val = current->val - 1;
        	}else{
        		result = current;
        		break;
        	}
        }

        index = 1;
        for(current = headB;current!=NULL;current = current->next,index++){
        	if(index<=numB-repeatedNodes){
        		current->val = current->val + 1;
        	}else{
        		break;
        	}
        }

        return result;
    }

};

int main(){
	ListNode a1(1);
	ListNode a2(6);
	ListNode a3(7);
	a1.next = &a2;
	a2.next = &a3;
	ListNode *headA = &a1;

	ListNode c1(2);
	ListNode c2(6);
	ListNode c3(7);
	c1.next = &a2;
	// c2.next = &c3;

	
	ListNode *headB = &c1;

	Solution s;
	ListNode* r = s.getIntersectionNode(headA,headB);

	for(ListNode* current = headB;current!=NULL;current=current->next){
		cout << current->val << endl;
	}
	return 0;
}