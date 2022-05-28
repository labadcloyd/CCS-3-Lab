#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node *nodeptr;
typedef struct node {
	int 		x;
	nodeptr next;
} Node;
void addFirst(nodeptr *, int);
void addLast(nodeptr *, int);
void deleteNode(nodeptr *);
void displayList(nodeptr);
void displayOdd(nodeptr);

void main() {
	nodeptr head = NULL;
	int choice, num, inputChoice = 0, displayChoice = 0;

	while(choice != 4){
		system("cls");
		printf("MENU\n\n");
		printf("1. Add a node\n");
		printf("2. Display list\n");
		printf("3. Delete node\n");
		printf("4. Exit\n");
		printf("Choose an item: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				inputChoice = 0;
				while (inputChoice < 1 || inputChoice > 3) {
					printf("   ADD A NODE MENU\n\n");
					printf("   1. Add a node at the beginning\n");
					printf("   2. Add a node at the end\n");
					printf("   3. Exit\n");
					printf("   Choose an item: ");
					scanf("%d", &inputChoice);
					switch (inputChoice) {
						case 1:
							printf("      Enter number to add a node at the beginning: ");
							scanf("%d", &num);
							addFirst(&head, num);
							break;
						case 2:
							printf("      Enter number to add a node at the end: ");
							scanf("%d", &num);
							addLast(&head, num);
							break;
						case 3:
							choice = 0;
							break;
					}
				}
				break;
			case 2: 
				displayChoice = 0;
				while (displayChoice < 1 || displayChoice > 3) {
					printf("   DISPLAY LIST MENU\n\n");
					printf("   1. Display all nodes in the list\n");
					printf("   2. Display only nodes with odd numbers\n");
					printf("   3. Exit\n");
					printf("	 Choose an item: ");
					scanf("%d", &displayChoice);
					switch (displayChoice) {
						case 1:
							displayList(head);
							break;
						case 2:
							displayOdd(head);
							break;
						case 3:
							choice = 0;
							break;
					}
				};
				break;
			case 3:
				deleteNode(&head);
				break;
		}
	};
	printf("Press any key to continue\n");
	getch();
}

void addFirst(nodeptr *h, int num) {
    nodeptr ptr = (nodeptr)malloc(sizeof(Node));
    ptr->x = num;
    ptr->next = *h;

		*h = ptr;
    printf("--Node added--\n");
    
    printf("Press any key to continue\n");
		getch();
}

void addLast(nodeptr *h, int num) {
    nodeptr ptr = (nodeptr)malloc(sizeof(Node));
    ptr->x = num;
    ptr->next = NULL;

    if(*h == NULL) 
			*h = ptr;
    else {
			nodeptr p = *h;
			while(p->next != NULL)
				p = p->next;
				p->next = ptr;
    }
    printf("--Node added--\n");
    
    printf("Press any key to continue\n");
		getch();
}

void displayList(nodeptr h) {
	nodeptr p = h;
	if(p == NULL)
		printf("List is empty\n");
	else
		while(p != NULL) {
			printf("%d\n", p->x);
			p = p->next;
		}
    printf("Press any key to continue\n");
		getch();
}

void displayOdd(nodeptr h) {
	nodeptr p = h;
	if(p == NULL)
		printf("List is empty\n");
	else
		while(p != NULL) {
			if (p->x % 2 != 0) {
				printf("%d\n", p->x);
			}
			p = p->next;
		}
    printf("Press any key to continue\n");
		getch();
}

void deleteNode(nodeptr *h) {
	*h = NULL;
	printf("--All Nodes have been deleted--\n");
	
	printf("Press any key to continue\n");
	getch();
}