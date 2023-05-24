#include "country.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h> 

/* Double Pointer Usage Explanation
 * In main you are passing the address to the first node (ie head) on the linked list
 * because you are passing the address and not the pointer to the node itself, this address 
 * can be changed without affecting the address in main 
 * if the address was affected, then you'd lose the head starting point of your list 
*/

void nodeCreator (struct countries **list, struct countries *holder){
	struct countries *newNode  = holder;  
	if (*list == NULL){
		newNode->next = NULL;
		*list = newNode; 
	}
	else {
		while ((*list)->next != NULL){
			list = &((*list)->next); 
		}
		(*list)->next = newNode;
	}
}

void fileReader (struct countries **list){
	FILE *fp; 
	char buffer[STRLEN]; 
	fp = fopen ("csvData.csv", "r");
	fgets (buffer, STRLEN, fp); //trash first line 
	while (fgets(buffer, STRLEN, fp) != NULL){
		nodeCreator (list, delimiter (buffer)); 
	}
	fclose(fp); 
}

struct countries* delimiter(char* input){
	int cnt = 0; 
	char temp[STRLEN];  
	double conv; 
	strcpy (temp, "\0");
	struct countries *holder = (struct countries*) malloc (sizeof (struct countries));  

	for (int i = 0; i < STRLEN; i++){
		if ((input[i] == ',') || (input[i] == '\0')){
			if (cnt == 0){
				strcpy(holder->country, temp); 
			}
			else if (cnt == 1){
				conv = strtod (temp, NULL);
				//strcpy (holder->TRY,temp); 
				holder->TRY = conv; 
			}
			else if (cnt == 2){
				strcpy (holder->UPPSRY,temp); 
			}
			else if (cnt == 3){
				strcpy (holder->BUPPSRY,temp); 
			}
			else if (cnt == 4){
				strcpy (holder->POP,temp); 
			}
			cnt++; 
			i++;
			strcpy (temp, "\0"); 
		}
		if (cnt == 0){
			strncat (temp, &input[i], 1); 
		}
		else if (cnt == 1){
			strncat (temp, &input[i], 1); 
		}
		else if (cnt == 2){
			strncat (temp, &input[i], 1); 
		}
		else if (cnt == 3){
			strncat (temp, &input[i], 1); 
		}
		else if (cnt == 4){ 
			strncat (temp, &input[i], 1); 
		}
		else if (cnt > 4){
			return holder; 
		}
	} 
	return holder; //should never actually get here because every line ends with null terminator and contains 5 values 
}

void nodePrinter (struct countries *node){
	printf ("\n**************************\n");
	printf ("Country: %s ", node->country); 
	printf ("Education Percentage: %f\n", node->TRY);
	printf ("**************************\n");
	//printf ("Val3: %s\n", node->UPPSRY); 
	//printf ("Val4: %s\n", node->BUPPSRY); 
	//printf ("Val5: %s\n", node->POP); IDK WHAT THESE LAST 3 STATS EVEN MEAN SO I'M LEAVING THEM OUT 
}

void listPrinter (struct countries **list) {
	while (*list != NULL){
		nodePrinter (*list); 
		list = &((*list)->next);
	}
}

void bestCountry (struct countries **list){
	double highest = 0; 
	char bestCountry[STRLEN]; 
	strcpy (bestCountry, "\0"); 
	double lowest = 1; 
	char lowestCountry[STRLEN]; 
	strcpy (lowestCountry, "\0"); 
	while (*list != NULL){
		if ((*list)->TRY > highest){
			highest = (*list)->TRY; 
			strcpy (bestCountry, (*list)->country); 
		}
		else if ((*list)->TRY < lowest){
			lowest = (*list)->TRY; 
			strcpy (lowestCountry, (*list)->country); 
		}
		list = &((*list)->next); 
	}
	printf ("Most educated country is %s with %.2f%% of educated people\n", bestCountry, (highest * 100)); 
	printf ("Least educated country is %s with %.2f%% of educated people\n", lowestCountry, (lowest * 100));
}