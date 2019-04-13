
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;
// This function is used to create the linked list according to the input.

void Create_List(Node** head, int data) {
    if (*head == NULL) {
        // correct
        *head = malloc(sizeof(Node));
        (*(*head)).data = data;
    }
    else {
        //printf("DEBUG: function.h :: %d\n", (*(*head)).data);
        Node *prev;
        Node *current = *head;

        while (current != NULL) {
            prev = current;
            //printf("DEBUG: function.h :: %d\n", (*current).data);
            current = current->next;
        }
       
        prev->next = malloc(sizeof(Node));
        prev->next->data = data; 
    }
}

int Length(Node* head)
{
    int len = 0;
    Node* y = head;
    while (y != NULL) {
        len++;
        y = y->next;
    }
    return len;  
}

// This function is used to create a linked list by adding two linked lists together.
Node* Add_List(Node* head_a, Node* head_b){
  Node *a = head_a;
  Node *b = head_b;
  Node *head = malloc(sizeof(Node));
  int len_a = Length(a);
  int len_b = Length(b);
  // printf("%d %d\n", len_a, len_b);
  if (len_a > len_b) {
    // case: longer list + shorter list
    // loop shorter length
    Node* current = head;
    for(int i=1; i<=len_a; i++){
      if(a->next != 0){
        current->next = malloc(sizeof(Node));
      }
        current->data = a->data;
        current = current->next;
        a = a->next;
    }
    current = head;
    for(int i=1; i<=len_b; i++){
      current->data += b->data;
      current = current->next;
      b = b->next;
    }
    return head;
  }
  else {
    Node* current = head;
    for(int i=1; i<=len_b; i++){
      if(b->next != 0){
        current->next = malloc(sizeof(Node));
      }
        current->data = b->data;
        current = current->next;
        b = b->next;
    }
    current = head;
    for(int i=1; i<=len_a; i++){
      current->data += a->data;
      current = current->next;
      a = a->next;
    }
    return head;
  }

}
// This function is used to print out the key value in the linked list.
void Print_List(Node* head){
  Node* current = head;
  while (current->next != NULL){
      printf("%d->", current->data);
      current = current->next;
  }
  printf("%d\n", current->data);
}
// This function is used to free the memory space.
void Free_List(Node* head){
  free(head);
}
