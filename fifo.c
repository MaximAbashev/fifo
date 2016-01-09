#include <stdio.h>
#include <stdlib.h>

struct node {
		int num;
		struct node *next;
		struct node *prev;
	};

	void add(struct node** point, int value){
		struct node* tmp;
		struct node* tmp2; 
		if(*point == NULL) {
			tmp = (struct node*)malloc(sizeof(struct node));
			*point = tmp;
			tmp -> num = value;
			tmp -> next = NULL;
			tmp -> prev = NULL;
		}
		else {
			tmp = *point;
/*			while (tmp -> next != NULL) {
				tmp = tmp -> next;
			} */
			tmp2 = (struct node*)malloc(sizeof(struct node));
			tmp -> next = tmp2;
			tmp2 -> num = value;
			tmp2 -> prev = tmp;
			tmp2 -> next = NULL;
			*point = tmp2;
		}
	}

	void del(struct node* point){
		if(point == NULL) {
			return ;
		}
		if(point -> next != NULL) {
			del(point -> next);
		}
		free(point);
//		printf("test delete\n");
		point = NULL;	
		}

	void view(struct node* point) {
		while(point != NULL) {
			printf("%d", point -> num);
			printf("\n");
			point = point -> next;
		}
	}

int main (void) {

	struct node *start = NULL;
	struct node *end = NULL;
	struct node *next = NULL;
	struct node *prev = NULL;
	int num, i;
	int *array;

	printf("Please, enter number of tree elements!\n");
	scanf("%d", &num);
	array = (int*)malloc(num*sizeof(int));
	printf("Enter tree elements!\n");
	for(i=0; i<num; i++){
		scanf("%d", &array[i]);
	}
	for(i=0; i<num; i++){
		if(start == NULL) {
		add(&start, array[i]);
		end = start;
		}
		else {
			add(&end, array[i]);
		}
	}
	view(start);
	del(start);

	return 0;
}