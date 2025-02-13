#include<stdio.h>
#include<string.h>

// Structure is basically a user-defined data type that can store 
// related information (even of different data types) together, 
// while an array can store only entities of same data types.

struct reviews{
	char reviewerName[100];
	double totalPlay;
	char review[1000];
	int rating;
};

struct games{
	char title[100];
	char developerName[100];
	int totalReviews;
	double price;

	// nested struct
	// each game can have maksimum of 200 reviews
	struct reviews review[200];
};

void printGameDetail(struct games game[], int index, int indexReview){
	printf("Game Name: %s\n", game[index].title);
	printf("Game Developer: %s\n", game[index].developerName);
	printf("Total Reviews: %d\n", game[index].totalReviews);
	printf("Price: $%.2lf\n", game[index].price);
	
	printf("Reviewer Name: %s\n", game[index].review[indexReview].reviewerName);
}

int main(){
	// ADT 			--> games
	// ADT Object 	--> game

	// the library can have 5 games
	struct games game[5];
	
	// assign value to the ADT object
	strcpy(game[0].title, "Balatro");
	strcpy(game[0].developerName, "LocalThunk");
	game[0].totalReviews = 8245;
	game[0].price = 9.99;

	// input review
	strcpy(game[0].review[0].reviewerName, "mister jackpots");
	game[0].review[0].totalPlay = 684.5;
	strcpy(game[0].review[0].review, "a long review");
	game[0].review[0].rating = 1; 					// 1 means recommended
		
	// assign value to the ADT object
	strcpy(game[1].title, "DAVE THE DIVER");
	strcpy(game[1].developerName, "MINTROCKET");
	game[1].totalReviews = 1241;
	game[1].price = 5.99;
	
	// print value
	printGameDetail(game, 0, 0); puts("");
	printGameDetail(game, 1, 0); puts("");
	
	
}
