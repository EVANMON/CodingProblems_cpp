#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* merge(ListNode* l1, ListNode* l2){
    ListNode pre(0);
    ListNode* p = &pre;

    while(l1 && l2){
        if(l1->val <= l2->val){
            p->next = l1;
            l1 = l1->next;
        }
        else{
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    p->next = l1? l1 : l2;
    return pre.next;
}

    ListNode* quicksort(ListNode* head, int len){
    if(len == 0){
        return head;
    }
    if(len == 1){
        head->next = NULL;
        return head;
    }
    if(len == 2){
        ListNode* tmp = head->next;
        head->next = NULL;
        ListNode* p = merge(head, tmp);
        return p;
    }
    ListNode* p = head;
    ListNode* pre;
    for(int idx = 0; idx < len /2 ; idx++){
        pre = p;
        p = p->next;
    }
    pre->next = NULL;
    ListNode* sort1 = quicksort(head, len/2);
    ListNode* sort2 = quicksort(p, len - len/2);
    ListNode* rlt = merge(sort1, sort2);
    return rlt;
}

ListNode* sortList(ListNode* head) {
    int count=0;
    ListNode* p = head;
    while(p){
        count++;
        p = p->next;
    }
    ListNode* result = quicksort(head, count);
    return result;
}
    
    

int main() 
{
    std::string s;
    std::getline( std::cin, s );
    std::istringstream is( s );
    std::vector<int> v( ( std::istream_iterator<int>( is ) ), std::istream_iterator<int>() );

    ListNode* head = NULL;
    ListNode* cur;

    //for ( int x : v) std::cout << x << ' ';
    ListNode* node;
    for (int idx = 0; idx < v.size(); idx++){
        node = new ListNode(v[idx]);
        if(!head){
            head = node;
            cur = node;
            continue;
        }
        cur -> next = node;
        cur = node;
    }
    ListNode* result = sortList(head);
    cur = result;
    while(cur){
        cout<<cur->val<<' ';
        cur = cur->next;
    }

    return 0;
}