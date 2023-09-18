#include <stdio.h>
#include <stdlib.h>
/*definition of a node of Linked list*/
typedef struct node {
    int data;
    struct node *next;
} Node;

/*Head pointer : holds the first Node*/
Node *head = NULL;

void append(Node *p, int num) {
    /*creating a new node*/
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = num;
    new_node->next = NULL;
   
    /*if new node is the first node of LL*/
    if(p==NULL) { /*means head==NULL*/
        head = new_node;
        return;
    }
   
    /*if new node is being added to existing LL*/
    while(p->next!=NULL) {
        p=p->next;
    }
    p->next = new_node;
}

void display(Node *p) {
    while(p!=NULL) {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int countNodes(Node* p) {
    int count=0;
    while(p!=NULL) {
        count++;
        p=p->next;
    }
    return count;
}

void insertNode(Node* p, int num, int pos) {
    int n = countNodes(p); /*Total nodes in the LL*/
    if(pos<1 || pos>n+1) {
        printf("Invalid Position\n");
        return;
    }
    /*Create a new node*/
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = num;
    new_node->next = NULL;
    /*Adding new node to the first position*/
    if(pos==1) {
        new_node->next = head;
        head = new_node;
        return;
    }
    for(int i=1;i<pos-1;i++) {
        p=p->next; /*moving p to a node just previous to pos*/
    }
    new_node->next = p->next;
    p->next = new_node;
}

void deleteNode(Node *p, int pos) {
    int n=countNodes(p);
    if(pos<1 || pos>n) return;
   
    if(pos==1) {
        head = head->next;
        free(p);
        return;
    }
    Node *q = NULL;
    for(int i=1;i<pos;i++) {
        q=p;
        p=p->next;
    }
    q->next = p->next;
    free(p);
}
int search(Node*p ,int key){
	int found = 0;
	while(p!=NULL){
		if(p->data==key){
			found =1;
			break;
		}
		p=p->next;
		
	}
	return found;
}
int main()
{
    int arr[] = {10,20,30,40,50,60};
    int i;
    for(i=0;i<6;i++) {
        append(head, arr[i]);
    }
    display(head);
   
    insertNode(head, 100, 7);
   
    display(head);
   
    deleteNode(head, 3);
   
    display(head);
    printf("found: %d",search(head,50));
}

