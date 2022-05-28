#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node *nodeptr;
typedef struct node
{
    int x;
    nodeptr next;
}Node;

void createNode(nodeptr *h, int num);
void display(nodeptr h);
//int menu();

void main()
{
    nodeptr head = NULL;
    int choice, x;

    do{
        system("cls");
            printf("MENU\n\n");
            printf("1. create node\n");
            printf("2. display list\n");
            printf("3. Exit\n");
            printf("Choose an item: ");
            scanf("%d", &choice);
            switch(choice){
                case 1: printf("Enter number to add to list: ");
                        scanf("%d", &x);
                        createNode(&head, x);
                        break;
                case 2: display(head);
            }

    }while(choice != 3);
    getch();

}

void createNode(nodeptr *h, int num) // add to end
{
    nodeptr ptr = (nodeptr)malloc(sizeof(Node));
    ptr->x = num;
    ptr->next = NULL;

    if(*h == NULL) //if list is empty
        *h = ptr;
    else // list is not empty, look for last node
    {
        nodeptr p = *h;
        while(p->next != NULL)
            p = p->next; // update
        p->next = ptr;
    }
    printf("Node added\n");
    getch();
}

void display(nodeptr h)
{
    nodeptr p = h;
    if(p == NULL)
        printf("List is empty");
    else
        while(p != NULL)
        {
            printf("%d\n", p->x);
            p = p->next; // update
        }
        getch();
}