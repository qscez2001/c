#include <stdio.h>
#include <string.h>

typedef struct node{
    char input;
    struct node* prev;
    struct node* next;
} Node;

Node* load(char ch, Node* node)
{
    if(node->next){
        Node *letter = malloc(sizeof(Node*));
        letter->input = ch;
        letter->next = node->next;
        letter->prev = node;
        node->next = letter;
        return letter;
    } else {
        Node *letter = malloc(sizeof(Node*));
        letter->input = ch;
        letter->next = NULL;
        letter->prev = node;
        node->next = letter;
        return letter;
    }

}

void fresh(Node* node)
{
    node->input = '\0';
    node->next = NULL;
    node->prev = NULL;
    return;
}


int main(void)
{
    //freopen("input.txt", "r", stdin);
    char ch;
    Node *output = malloc(sizeof(Node*));
    Node *cur_node = output;
    fresh(cur_node);
    while((ch = getchar()) != '\n'){
        switch(ch){
            case '>':
                if(cur_node->next) cur_node = cur_node->next;
                break;
            case '<':
                if(cur_node->prev) cur_node = cur_node->prev;
                break;
            case 'D':
                if(cur_node->next!=NULL){
                    cur_node = cur_node->next;
                    cur_node->prev->next = cur_node->next;
                    if(cur_node->next) cur_node->next->prev = cur_node->prev;
                    Node *tmp = cur_node;
                    cur_node = cur_node->prev;
                    free(tmp);
                }
                break;
            case EOF:
                break;
            default:
                cur_node = load(ch, cur_node);
            }
        if(ch == EOF) break;
    }
    while(output = output->next) putchar(output->input);
    putchar('\n');
    return 0;
}
