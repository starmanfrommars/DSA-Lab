#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct day {
  char *name;
  int date;
  char *desc;
 };
 
 void create(struct day calendar[7]) {
	for ( int i=0 ; i<7 ; i++ ) {
		calendar[i].name = (char*)malloc( 20*sizeof(char));
		calendar[i].desc = (char*)malloc( 20*sizeof(char));
	}
}

void read( struct day calendar[7] ) {
	for ( int i=0 ; i<7 ; i++ ) {
		printf("Enter the name of the day %d : ",i+1);
		scanf("%s",calendar[i].name);	
		printf("Enter the date of the day : ");
		scanf("%d",&calendar[i].date);
		printf("Enter the activity description of the day : ");
		scanf("%s",calendar[i].desc);
	}
}	

void display( struct day calendar[7] ) {
	for ( int i=0 ; i<7 ; i++ ) {
		printf("Day name = %s\n",calendar[i].name);
		printf("Date of the day = %d\n",calendar[i].date);
		printf("Activity of the day = %s\n",calendar[i].desc);
	}
}

void main() {
	struct day calendar[7];
	
	create(calendar);
	read(calendar);
	printf("Weekly Activity Details : \n");
	display(calendar);
	
	for ( int i=0 ; i<7 ; i++ ) {
		free(calendar[i].name);
		free(calendar[i].desc);
	}
}
