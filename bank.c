#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[50];
    int acc_no;
    float balance;
    struct node *next;
};
typedef struct node *Node;

Node bank;

void take_input(char *name, int *acc_no, float *balance)
{
    printf("Enter customer name, Account No., and Balance (separated by spaces):\n");
    scanf("%s %d %f", name, acc_no, balance);
}

Node insert_end(Node bank)
{
    char name[50];
    int acc_no;
    float balance;

    while (1)
    {
        take_input(name, &acc_no, &balance);

        if (acc_no == -999)
        {
            break;
        }

        Node p = (Node)malloc(sizeof(Node));
        strcpy(p->name, name);
        p->acc_no = acc_no;
        p->balance = balance;

        if (bank == NULL)
        {
            p->next = NULL;
            bank = p;
        }
        else
        {
            p->next = bank;
            bank = p;
        }
    }

    return bank;
}
Node insert_right(Node bank)
{
    char name[50];
    int acc_no;
    float balance;

    take_input(name, &acc_no, &balance);

    printf("Enter the account number after which a node has to be added: ");
    int after_acc_no;
    scanf("%d", &after_acc_no);

    // Create a new node
    Node new_node = (Node)malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    new_node->acc_no = acc_no;
    new_node->balance = balance;

    // Find the node after which the new node should be inserted
    Node temp = bank;
    while (temp != NULL && temp->acc_no != after_acc_no) {
        temp = temp->next;
    }

    // If a node with the given account number is found, insert the new node
    if (temp != NULL) {
        new_node->next = temp->next;
        temp->next = new_node;
    } else {
        printf("No node with the given account number was found.\n");
    }

    return bank;
}

Node interest(Node bank)
{
    if(bank == NULL)
    return NULL;
    Node temp = bank;

  while(temp != NULL)
  {
    if(temp->balance > 50000.00)
    temp->balance+= temp->balance*0.1;

    temp = temp->next;
  }

  return bank;



}

void display(Node bank)
{
    if (bank == NULL)
        printf("Empty Linked List ....\n");

    else
    {
        Node temp = bank;

        while (temp != NULL)
        {
            printf("%s->%d->%0.2fRs---> \n", temp->name, temp->acc_no, temp->balance);
            temp = temp->next;
        }
    }
}

int main()
{
    bank = NULL;

    bank = insert_end(bank);

    display(bank);
    bank = insert_right(bank);
    printf("Updated Linked List\n");
    display(bank);

    bank = interest(bank);
    printf("Updated Bank Balances...\n");
    display(bank);
    return 0;
}
