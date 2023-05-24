#ifndef _COUNTRY_H
#define _COUNTRY_H 
#define STRLEN 100 //really should be around 60 ish 

struct countries {
	char country[STRLEN]; 
	double TRY; 
	char UPPSRY[STRLEN]; 
	char BUPPSRY[STRLEN]; 
	char POP[STRLEN]; 
	struct countries *next; 
};

void nodeCreator (struct countries **list, struct countries *holder); 
void fileReader(struct countries **list); 
struct countries* delimiter(char* input); 
void nodePrinter (struct countries *node);
void listPrinter (struct countries **list); 
void bestCountry(struct countries **list); 
#endif