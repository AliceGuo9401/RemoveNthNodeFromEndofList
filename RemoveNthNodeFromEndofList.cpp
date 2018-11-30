#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode * removeNthFromEnd (ListNode * head, int n) {
    //删除倒数第1个
    if (head->next == NULL && n == 1) //[1], 1 -> NULL
        return head = NULL;

    if (head->next != NULL && n == 1) { //[1, 2], 1 -> [1]
        ListNode *p1(head), *p2(head->next);
        while (p2->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = NULL;
        free(p2);
        return head;
    }

    ListNode *p1(head), *p2(head), *p3(head);
    for (int i = 0; i < n - 1; ++i)
        p3 = p3->next;
    
    //删除正数第1个
    if (p3->next == NULL) { //[1, 2, 3], 3 -> [2, 3]
        head = head->next;
        free(p1);
        return head;
    }
    
    p2 = p2->next;
    p3 = p3->next;
    while (p3->next != NULL) {
        p1 = p1->next;
        p2 = p2->next;
        p3 = p3->next;
    }
    p1->next = p2 -> next;  /**/
    free(p2);
    return head;
}

int main() {
    auto * list = new ListNode(1);
    auto * node1 = new ListNode(2);
    list->next = node1;
    auto * node2 = new ListNode(3);
    node1->next = node2;
    auto * node3 = new ListNode(4);
    node2->next = node3;
    auto * node4 = new ListNode(5);
    node3->next = node4;
    auto * node5 = new ListNode(6);
    node4->next = node5;
    auto * node6 = new ListNode(7);
    node5->next = node6;
    auto * node7 = new ListNode(8);
    node6->next = node7;
    auto * node8 = new ListNode(9);
    node7->next = node8;
    auto * node9 = new ListNode(10);
    node8->next = node9;
    int n(7);
    ListNode * newList = removeNthFromEnd(list, n);
    auto * p = newList;
    while (p != NULL) {
        cout << p->val << ' ';
        p = p->next;
    }
    return 0;
}
