

struct Node{
    char *data;

    Node* next;
};

void findCircle(Node* list){


    Node *first = list;
    Node *second = list;

    while (first != nullptr && second != nullptr) {

        first = first->next;
        second = second->next->next;
        
        if(first == second){

            break;;
        }

    }




}


