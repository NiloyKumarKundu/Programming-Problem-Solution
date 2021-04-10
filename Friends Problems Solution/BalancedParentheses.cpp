#include <stdio.h>
#include <stdlib.h>

#define NULL 0

struct ListNode {
	int data;
	struct ListNode *next;
};

typedef struct ListNode LN;

class SinglyLinkedList {
  public:
	// constructor
	SinglyLinkedList() {
		head = NULL;
	}

	LN *head;

	void print() {
		LN *temp = head;
		while (temp != NULL) {
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}

	void insert_first(int item) {
		LN *new_node = (LN *) malloc(sizeof(LN));
		new_node->data = item;
		new_node->next = head;
		head = new_node;
	}

	void remove_first() {
		if (head == NULL)
			return;
		LN *temp = head;
		head = head->next;
		free(temp);
	}
};

class Stack {
	SinglyLinkedList L;

  public:
	// constructor
	Stack() {
	}

	void push(int item) {
		L.insert_first(item);
	}

	void pop() {
		L.remove_first();
	}

	int peek() {
		if (L.head == NULL) {
			printf("Stack Underflow\n");
			return -1;
		}
		return L.head->data;
	}

	void print() {
		L.print();
	}
};

int main() {

	char str[100];
	gets(str);

	Stack s;

	int i = 0;
	int flag = 1;
	while (str[i] != '\0') {
		// write your code here
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			s.push(str[i]);
		} else {
			if (s.peek() == -1) {
				flag = 0;
				break;
			} else {
				if (s.peek() == '(' && str[i] != ')') {
					flag = 0;
					break;
				} else if (s.peek() == '{' && str[i] != '}') {
					flag = 0;
					break;
				} else if (s.peek() == '[' && str[i] != ']') {
                    flag = 0;
					break;
				} else {
					s.pop();
				}
			}
		}
		i++;
	}
    if (flag && s.peek() == -1) {
	    printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }

	return 0;
}
