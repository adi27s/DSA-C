#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int val;
    struct node *adr;
};

typedef struct head_node {
    char str[100];
    struct node *node_t;
} head_t;

// Function prototypes
void assign_value(head_t *, int);
head_t* create_ll(void);
void print_ll(head_t *);
void add_at_the_beginning(head_t *);
void add_at_the_end(head_t *);

// Function definitions
head_t* create_ll(void) {
    head_t *head_ptr = (head_t *)malloc(sizeof(head_t));
    printf("Name the linked list: ");
    scanf("%99s", head_ptr->str);
    head_ptr->node_t = NULL;
    printf("New linked list initialized successfully!\n");
    assign_value(head_ptr, 0);
    return head_ptr;
}

void print_ll(head_t *head_node) {
    printf("Printing linked list %s\n", head_node->str);
    struct node *node_t = head_node->node_t;
    while (node_t != NULL) {
        printf("%d\n", node_t->val);
        node_t = node_t->adr;
    }
}

void assign_value(head_t *head_node, int start_index) {
    int num;
    struct node *node_t = head_node->node_t;
    if (head_node->node_t == NULL) {
        // Initialization of a new linked list
        printf("Enter numbers to add to the linked list (non-numeric input to stop):\n");
        while (scanf("%d", &num) == 1) {
            if (head_node->node_t == NULL) {
                head_node->node_t = (struct node *)malloc(sizeof(struct node));
                node_t = head_node->node_t;
            } else {
                node_t->adr = (struct node *)malloc(sizeof(struct node));
                node_t = node_t->adr;
            }
            node_t->val = num;
            node_t->adr = NULL;
            printf("Added: %d\n", node_t->val);
        }
        while (getchar() != '\n'); // Clear the input buffer incases like 99a88, where 99 is accepted but not 'a'
    } else {
        // Appending data to an existing linked list (at an index)
        int i=0;
        if (start_index == 0){
            add_at_the_beginning(head_node);
        }
        else{
            for(i=1;i<start_index;i++){
                node_t=node_t->adr;
                if(node_t->adr==NULL){
                    break;
                }
            }
            if(node_t->adr == NULL){
                add_at_the_end(head_node);
            }
            else{
                struct node *temp_node=(struct node *)malloc(sizeof(struct node));
                temp_node->adr=node_t->adr;
                printf("Enter the value\n");
                scanf("%d",&num);
                temp_node->val=num;
                node_t->adr=temp_node;   
            }
        }
    }
    print_ll(head_node);
}

void add_at_the_beginning(head_t *head_node){
    int num;
    struct node *node_t=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value\n");
    scanf("%d",&num);
    node_t->val=num;
    node_t->adr=head_node->node_t;
    head_node->node_t=node_t;
    printf("Successfully added at the beginning !\n");
}

void add_at_the_end(head_t *head_node){
    int num;
    struct node *node_t=(struct node*)malloc(sizeof(struct node));
    struct node *temp=head_node->node_t;
    while(temp->adr != NULL){
        temp=temp->adr;
    }
    printf("Enter the value\n");
    scanf("%d",&num);
    node_t->val=num;
    node_t->adr=NULL;
    temp->adr=node_t;
    printf("Successfully added at the end !\n");
}

// Main Code
int main() {
    head_t *head = NULL;
    int x,index;
    while(1){
        printf("Enter your choice:\n1. Create a new linked list\n2. Print linked list\n3. Add an element at the beginning of the linkedlist.\n4. Add an element at the end.\n5. Add an element at an index\n6. Delete the linkedlist\n");
        scanf("%d",&x);
        switch(x){
            case 1: head=create_ll();
            break;
            
            case 2: print_ll(head);
            break;
            
            case 3: add_at_the_beginning(head);
            break;
            
            case 4: add_at_the_end(head);
            break;
            
            case 5: printf("Enter the index\n");
            scanf("%d",&index);
            assign_value(head,index);
            break;
            
            case 6: {
                struct node *current = head->node_t;
                struct node *next;
                
                // Free all nodes in the linked list
                while (current != NULL) {
                    next = current->adr;
                    free(current);
                    current = next;
                }
                
                // Free the head node
                free(head);
                head = NULL;
                printf("Linked list and head address freed (Verify by choosing 2nd option)\n");
            }
        }
    }
    return 0;
}
