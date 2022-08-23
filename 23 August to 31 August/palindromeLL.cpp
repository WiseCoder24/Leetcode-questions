/*
234. Palindrome Linked List
Given the head of a singly linked list, return true if it is a palindrome.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleOfList(ListNode* head)
{
    ListNode *slow = head , *fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* reverseList(ListNode* head)
{
    ListNode *prev = NULL;
    while(head != NULL)
    {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
    bool isPalindrome(ListNode* head)
{
    if(head == NULL)
        return true;
    ListNode* middleNode = middleOfList(head);
    ListNode* startOfSecondHalf = reverseList(middleNode->next);
    ListNode *ptr1 = head , *ptr2 = startOfSecondHalf;
    while(ptr2 != NULL)
    {
        if(ptr1->val != ptr2->val)
            return false;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return true;
}

};