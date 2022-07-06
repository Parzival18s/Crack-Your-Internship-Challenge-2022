class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* ptr;
        ptr=node;
        ptr=ptr->next;
        node->val=ptr->val;
        node->next=ptr->next;
        return;
    }
};
//Node is pointer to the node that needs to be deleted, and it is guaranteed to not be a tail node.