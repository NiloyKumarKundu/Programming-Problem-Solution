#include <stdio.h>
#include <stdlib.h>

// #define NULL 0

struct ListNode {
    int data;
    struct ListNode* next;
};

typedef struct ListNode LN;

LN* head;

void init() {
    head = NULL;
}

void print_list() {
    LN* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

LN* search(int key) {
    LN* temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void insert_first(int item) {
    LN* new_node = (LN*)malloc(sizeof(LN));
    new_node->data = item;
    new_node->next = head;
    head = new_node;
}

void delete_first() {
    if(head == NULL)
        return;
    LN* temp = head;
    head = head->next;
    free(temp);
}

void insert_last(int item) {
    if(head == NULL) {
        insert_first(item);
        return;
    }
    LN* new_node = (LN*)malloc(sizeof(LN));
    new_node->data=item;
    new_node->next= NULL;
    LN* temp= head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=new_node;\
}

void delete_last() {
    LN* temp = head;
    if(head==NULL)
    {
        printf("Empty list \n");
        return;
    }
    if(head->next==NULL)
    {
        delete_first();
        return;
    }
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}

void insert_after(int olditem, int newitem) {

    LN* new_node = (LN*)malloc(sizeof(LN));
    new_node->data=newitem;

    LN* temp= search(olditem);

    if(temp==NULL)
    {
        printf("Item not found \n");
        return;
    }
    new_node->next=temp->next;
    temp->next=new_node;
	// write your code here
}

void delete_after(int olditem) {
    LN* temp = head;
    while(temp != NULL) {
        if(temp->data == olditem) {
			break;
		}
        temp = temp->next;
    }
    if(temp==NULL)
    {
        printf("Item not found \n");
        return;
    }
    LN* node = temp->next;
    if(temp->next==NULL)
    {
        printf("Item in Last node \n");
        return;
    }

    temp->next=temp->next->next;
    free(node);
}

void delete_item(int item) {
    LN* temp;
    temp=head;
    if(temp==NULL)
    {
        printf("Empty list \n");
        return;
    }
    if(temp->data == item)
    {
        delete_first();
        return;
    }

    if(search(item)==NULL)
    {
        printf("NOT FOUND \n");
        return;
    }


    while(temp->next != NULL) {
        if(temp->next->data == item) {
            LN* node = temp->next;
            temp->next = temp->next->next;
            free(node);
            return;
        }
        temp = temp->next;
    }
}

int main() {
    init();
    insert_first(2);
    insert_first(5);
    insert_first(7);
    insert_first(3);
    insert_first(13);
    insert_first(9);
    insert_first(11);
    print_list();
    delete_after(1);
    print_list();
    delete_after(11);
    print_list();
    delete_after(13);
    print_list();

    // delete_first();
    // print_list();
    // delete_first();
    // print_list();
    // delete_first();
    // print_list();
    // delete_first();
    // print_list();
    // delete_first();
    // print_list();
    // delete_first();
    // print_list();
    // delete_first();
    // print_list();




    return 0;
}

