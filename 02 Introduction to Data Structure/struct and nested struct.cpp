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
    struct address KTP_adrs; 		// Nested struct
    struct address domisili_adrs; 	// Nested struct
};

int main(){
	// Declaration of a variable of type struct student
	struct student stud;
	
	// Assigning values to the members of the struct
	strcpy(stud.name, "Zelda");
	stud.NIM = 255;
	
	// Assigning values to the members of the nested_struct	
	stud.KTP_adrs.houseno = 78;	
	strcpy(stud.KTP_adrs.street, "Hyrule");	
	stud.KTP_adrs.houseno = 3;

	stud.domisili_adrs.houseno = 108;	
	strcpy(stud.domisili_adrs.street, "Forest");	
	stud.domisili_adrs.houseno = 44;
	
	// Printing the values of the members of the struct
	printf("Student detail is:\n");
	printf("Name			 : %s\nNIM			 : %d\n", stud.name, stud.NIM);
	printf("KTP Address		 : %s, House No. %d, State: %d\n", stud.KTP_adrs.street, stud.KTP_adrs.houseno, stud.KTP_adrs.stateno);	
	printf("Domisili Address : %s, House No. %d, State: %d\n", stud.domisili_adrs.street, stud.domisili_adrs.houseno, stud.domisili_adrs.stateno);	
}

