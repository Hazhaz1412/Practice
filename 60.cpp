#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int data;
    ListNode* nextNode;
};

ListNode* head = NULL;
ListNode* tail = NULL;
void pushFront(int val) {
    ListNode* newNode = new ListNode();
    newNode->data = val;
    if(head == NULL) {
        head = tail = newNode;
        newNode->nextNode = NULL;
    }
    else {
        newNode->nextNode = head;
        head = newNode;
    }
}

void pushBack(int val) {
    ListNode* newNode = new ListNode();
    newNode->data = val;
    newNode->nextNode = NULL;
    if(head == NULL) {
        head = tail = newNode;
        newNode->nextNode = NULL;
    }
    else {
        tail->nextNode = newNode;
        tail = newNode;
    }
}

void popFront() {
    if(head == NULL) return;
    ListNode* tmp = new ListNode();
    head = head->nextNode;
    delete tmp;
    if(head == NULL) {
        tail = NULL;
    }
}

void popBack() {
    if(head == NULL) return;
    if(head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }
    ListNode* cur = head;
    while(cur->nextNode != tail) {
        cur = cur->nextNode;
    }
    delete tail;
    tail = cur;
    tail->nextNode = NULL;
}

int main() {
    pushFront(10);
    pushFront(50);
    pushFront(52);
    pushBack(99);
    pushBack(101);
    pushBack(123);
    popBack();
    ListNode* cur = head;
    while(cur!=NULL) {
        cout << cur->data << ' ';
        cur = cur->nextNode;
    }
}