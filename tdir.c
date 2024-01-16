#include <stdio.h>
#include <string.h>
#include <malloc.h>
	
enum menu
{
	MENU_ADD = 1,
	MENU_DELETE = 2,
	MENU_SEARCH = 3,
	MENU_ALL = 4,
	MENU_EXIT = 5
};

int main(void){

	struct abonent {									
		char name[10];
		char second_name[10];
		char tel[10];
	};
		
	struct abonent *list = NULL;
	int capacity = 0;
	int menu;
	
	while (1){
		printf("\n1) Add abonent\n2) Delete abonent\n3) Search abonent\n4) Output all\n5) Exit\nSelect option: ");
		scanf("%d", &menu);
		
		switch(menu){
		case MENU_ADD:
			capacity++;
			list = realloc(list, capacity * sizeof(struct abonent));
			
			printf("\nName: ");
			scanf("%s", list[capacity-1].name);
			printf("Surname: ");
			scanf("%s", list[capacity-1].second_name);
			printf("Number: ");
			scanf("%s", list[capacity-1].tel);
			break;
		case MENU_DELETE:
			if (capacity == 0){
				break;
			}
			else{
				int delete_position;
				char copy_name[10];
				char copy_surname[10];
				char copy_number[10];

				printf("\nDelete position: ");
				scanf("%d", &delete_position);
					
				strcpy(copy_name, list[capacity-1].name);
				strcpy(copy_surname, list[capacity-1].second_name);
				strcpy(copy_number, list[capacity-1].tel);
			
				strcpy(list[delete_position].name, list[capacity-1].name);
				strcpy(list[delete_position].second_name, list[capacity-1].second_name);
				strcpy(list[delete_position].tel, list[capacity-1].tel);
			
				strcpy(list[delete_position].name, copy_name);
				strcpy(list[delete_position].second_name, copy_surname);
				strcpy(list[delete_position].tel, copy_number);
			
				capacity--;
				list = realloc(list, capacity * sizeof(struct abonent));
				break;
			}											
		case MENU_SEARCH:
			char name[10];
			
			printf("\nName: ");
			scanf("%s", name);
			for (int i = 0; i < capacity; i++){
				if (strcmp(name, list[i].name) == 0){
					printf("\n%d) Name: %s\nSurname: %s\nNumber: %s\n", i, list[i].name, list[i].second_name, list[i].tel);
				}
				else{
				}
			}							
			break;
		case MENU_ALL:	
			for (int i = 0; i < capacity; i++){
				printf("\n%d) Name: %s\n Surname: %s\n Number: %s\n", i, list[i].name, list[i].second_name, list[i].tel);
			}								
			break;
		case MENU_EXIT:			
			free(list);						
			return 0;
		}
	}
}		
