#include<stdio.h>
#include<string.h>

// Declaration of a struct named address
struct address {
    int houseno;
    char street[20];
    int stateno;
};

// Declaration of a nested struct named student
struct student {
    int NIM;
    char name[30];
    struct address adrs; // Nested struct
};

int main(){
	// Declaration of a variable of type struct student
	struct student stud;
	
	// Assigning values to the members of the struct
	strcpy(stud.name, "Zelda");
	stud.NIM = 255;
	stud.adrs.houseno = 78;
	strcpy(stud.adrs.street, "Hyrule");	
	stud.adrs.stateno = 3;
	
	// Printing the values of the members of the struct
	printf("Student detail is:\n");
	printf("Name	: %s\nNIM	: %d\n", stud.name, stud.NIM);
	printf("Address	: %s, House No. %d, State: %d\n", stud.adrs.street, stud.adrs.houseno, stud.adrs.stateno);	
}

