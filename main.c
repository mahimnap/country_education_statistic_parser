#include "country.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h> 

int main (int argc, char **argv){

	if (argc != 2) {
		fprintf (stderr, "Usage: %s plus the following: \n0 for just creating the table \n1 for printing entire table, \n2 for printing most/least educated countries, or \n3 for printing everything\n", argv[0]); 
		exit (1); 
		return 0; 
	}

	if (argv[1][0] == '0'){
		struct countries *myTable; 
		myTable = NULL; 
		fileReader (&myTable); 	
		return 0; 
	}
	else if (argv[1][0] == '1'){
		struct countries *myTable; 
		myTable = NULL; 
		fileReader (&myTable); 
		listPrinter (&myTable); 
		return 0; 
	}
	else if (argv[1][0] == '2'){
		struct countries *myTable; 
		myTable = NULL; 
		fileReader (&myTable); 
		bestCountry (&myTable);	
		return 0; 	
	}
	else if (argv[1][0] == '3'){
		struct countries *myTable; 
		myTable = NULL; 
		fileReader (&myTable); 
		listPrinter (&myTable); 
		bestCountry (&myTable);	
		return 0; 	
	}
	else {
		fprintf (stderr, "Usage: %s plus the following: \n0 for just creating the table \n1 for printing entire table, \n2 for printing most/least educated countries, or \n3 for printing everything\n", argv[0]); 
		exit (1); 
		return 0; 	
	}
}