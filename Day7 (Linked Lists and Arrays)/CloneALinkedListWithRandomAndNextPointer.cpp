class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node *it = head;

        while(it){
            Node *clone = new Node(it->val);
            clone->next = it->next;
            it->next = clone;
            it = it->next->next;

        }

        it = head;
        while(it){
            Node *clone = it->next;

            if(it->random){
                clone->random = it->random->next;
            }

            else{
                clone->random = NULL;
            }
            it = it->next->next;
        }

        it = head;

        Node *clone = it->next;
        while(it){
            Node *newnode = it->next;
            it->next = it->next->next;
            if(newnode->next){
                newnode->next = newnode->next->next;
            }

            it = it->next;
        }

        return clone;
    }
};