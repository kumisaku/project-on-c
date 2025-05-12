#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CHAR_SIZE 64

typedef struct node{
	char lagu[CHAR_SIZE];
	struct node*next;
	struct node*previous;
}node;

//common head and rear
node*head = NULL;
node*rear = NULL;

//alternate

node*deletedHead = NULL;
node*deletedRear = NULL;

//keep a track of how much node
int count = 0;

//keep a track of how much node that has been deleted from option
int CountDelete = 0;
int maxDel = 5;

node*createNode(char song[]){
	node*newNode = (node*)malloc(sizeof(node));
	strcpy(newNode->lagu, song);
	newNode->next = NULL;
	newNode->previous = NULL;
	
	return newNode;
}

void insertNode(char song[], int choice){
	node*newNode = createNode(song);
	
	if(choice == 0){
		head = newNode;
		rear = newNode;
	}else if(choice == 1){
		newNode->next = head;
		head->previous = newNode;
		head = newNode;
	}else if(choice == count+1){
		newNode->previous = rear;
		rear->next = newNode;
		rear = newNode;
	}else{
		node*temp = head;
		for(int i = 0; i < choice-2;i++){
			temp = temp->next;
		}
		
		newNode->next = temp->next;
		temp->next->previous = newNode;
		newNode->previous = temp;
		temp->next = newNode;
		temp = newNode;
	}
	
	count += 1;
}

void deleteNode(int selected){
	if(head == NULL || selected == 0){
		printf("There is no goddamn song~~\n");
		return;
	}
	
	node*temp = NULL;
	if(selected == 1 && count == 1){
		temp = head;
		head = NULL;
		rear = NULL;
		temp->next = NULL;
		temp->previous = NULL;
	}
	else if(selected == 1){
		temp = head;
		head = head->next;
		head->previous = NULL;
		temp->next = NULL;
		temp->previous = NULL;
	}else if(selected == count){
		temp = rear;
		rear = rear->previous;
		rear->next = NULL;
		temp->next = NULL;
		temp->previous = NULL;
	}else{
		temp = head;
		for(int i = 0; i < selected-1;i++){
			temp = temp->next;
		}
		
		if(temp->next != NULL){
			temp->previous->next = temp->next;
		}else if(temp->previous != NULL){
			temp->next->previous = temp->previous;
		}
		
		temp->next = NULL;
		temp->previous = NULL;
	}
	
	
	if(CountDelete < maxDel && CountDelete != -1){
		if(deletedHead == NULL){
			deletedHead  = temp;
			deletedRear = temp;
		}else{
			temp->next = deletedHead;
			deletedHead->previous = temp;
			deletedHead = temp;
		}

	}else{
		//adding the head
		temp->next = deletedHead;
		deletedHead->previous = temp;
		deletedHead = temp;
		
		node*temp2 = rear;
		deletedRear = deletedRear->previous;
		deletedRear->next = NULL;
		free(temp2);
		
	}
	CountDelete++;
	count -= 1;
}

void displaySong(){
	if(head == NULL){
		printf("There is no available song!\n");
		return;
	}
	node*temp = head;
	int countTemp = 1;
	
	printf("\nAvailable Song\n");
	while(temp != NULL){
		printf("%d. %s\n", (countTemp)++, temp->lagu);
		temp = temp->next;
	}
}

void DeleteSong(){
	if(count == 0){
		printf("There is no song to delete!\n");
		return;
	}
	else if(count == 1){
		int answ;
		displaySong();
		printf("Do you want to delete this song?\n");
		printf("1. Yes\n");
		printf("2. Nu uh\n");
		scanf("%d", &answ);
		switch(answ){
			case 1:
				printf("Aight Buddy!\n");
				deleteNode(1);
				printf("Delete Success!\n");
				break;
			default:
				return;
		}
	}
	else{
		printf("Available Song!\n");
		displaySong();
		printf("\nWhich Song do you want to delete?\n");
		
		int number;
		do{
			printf("Select the Number (1 - %d): ", count);
			scanf("%d", &number);	
		}while(number < 1 || number > count);
		
		deleteNode(number);
	}

}

void addSong(){
	char song[CHAR_SIZE];
	
	printf("Insert Song Name: ");
	scanf(" %[^\n]", song);
	
	if(count == 0){
		printf("You haven't put any song!\n");
		printf("Song is inserted in the first spot!\n");
		insertNode(song, 0);
	}
	else
	{
		printf("Where do you want to put it?\n");
		printf("Available Spot: 1 - %d\n", count+1);
		
		int answer;
		do{
			printf("\nSelect ur Spot! (1-%d): ", count+1);
			scanf("%d", &answer);
			
			if(answer > count+1){
				printf("Invalid, please select the available spot!!!!\n");
			}
			
		}while(answer > count+1);
		insertNode(song, answer);	
	}
}

void sortNodeDsc(){
	node*i,*j;
	
	for(i = head; i != NULL ; i = i->next){
		int swap = 0;
		for(j = head; j->next != NULL; j = j->next){
			if(strcmp(j->lagu, j->next->lagu) < 0){
				char songTemp[CHAR_SIZE];
				strcpy(songTemp, j->lagu);
				strcpy(j->lagu, j->next->lagu);
				strcpy(j->next->lagu, songTemp);
				swap = 1;
			}
		}
		if(swap == 0){
			break;
		}
	}
}

void sortNodeAsc(){
	node*i,*j;
	
	for(i = head; i != NULL ; i = i->next){
		int swap = 0;
		for(j = head; j->next != NULL; j = j->next){
			if(strcmp(j->lagu, j->next->lagu) > 0){
				char songTemp[CHAR_SIZE];
				strcpy(songTemp, j->lagu);
				strcpy(j->lagu, j->next->lagu);
				strcpy(j->next->lagu, songTemp);
				swap = 1;
			}
		}
		if(swap == 0){
			break;
		}
	}
}

void sortSong(){
	int answer;
	
	if(count == 0){
		printf("There is no node to be sorted!\n");
		return;
	}else if(count == 1){
		printf("Why do you even one to sort one song???\n");
		printf("SNAP BACK TO REALITY!!!\n");
		return;
	}
	
	do{
		printf("Which way do you want to sort it?\n");
		printf("1. Ascending\n");
		printf("2. Descending\n");
		printf("3. Cancel\n");
		printf("Select Menu (1-3): ");
		scanf("%d", &answer);
	}while(answer < 1 || answer > 3);
	
	switch(answer){
		case 1:
			sortNodeAsc();
			break;
		case 2:
			sortNodeDsc();
			break;
		default:
			printf("Aight Buddy!\n");
			return;
	}

}

void displayDeletedSong(){
	printf("Here is the list of the previous song (max 5) :\n");
	int count = 1;
	node*prtTemp = deletedHead;
	while(prtTemp != NULL){
		printf("%d. %s\n", count++, prtTemp->lagu);
		prtTemp = prtTemp->next;
	}
}

void RecoverNode(int choice){
	
	node*temp2 = deletedHead;
	
	char buffer[CHAR_SIZE];
	if(choice == 1 && CountDelete == 1){
		strcpy(buffer, temp2->lagu);
		temp2->next = NULL;
		temp2->previous = NULL;
		free(temp2);
	}
	else if(choice == 1){
		strcpy(buffer, temp2->lagu);
		deletedHead = deletedHead->next;
		deletedHead->previous = NULL;
		temp2->next = NULL;
		temp2->previous = NULL;
		free(temp2);
	}
	else if(choice == maxDel){
		strcpy(buffer, temp2->lagu);
		deletedRear = deletedRear->previous;
		deletedRear->next = NULL;
		temp2->next = NULL;
		temp2->previous = NULL;
		free(temp2);
	}
	else{
		
		for(int i = 0 ; i < choice-1;i++){
			temp2 = temp2->next;
		}
		
		char buffer[CHAR_SIZE];
		strcpy(buffer, temp2->lagu);
		
		if(temp2->next != NULL){
			temp2->previous->next = temp2->next;
		}
		
		if(temp2->previous != NULL){
			temp2->next->previous = temp2->previous;
		}
		
		temp2->next = NULL;
		temp2->previous = NULL;
		
		free(temp2);		
	}
	
	CountDelete -= 1;
	
	int choce;
	
	do{
		printf("Where do you want to put the song? Available Spot(1 - %d)\n", count+1);
		displaySong();
		printf("\nSelect Option (1 - %d): ", count+1);
		scanf("%d", &choce);
	}while(choce < 1 || choce > count+1);
	
	insertNode(buffer, choce);

}

void RecoverSong(){
	
	displayDeletedSong();
	
	if(CountDelete == 1){
		int answ;
		do{
			printf("There is only one song...\n");
			printf("Do you want to recover this frrr??");
			printf("1. Yes\n");
			printf("2. No\n");		
		}while(answ < 1 || answ > 2);
		
		switch(answ){
			case 1:
				RecoverNode(1);
				break;
			default:
				return;
		}
	}
	else{
		int answDel;
	
		do{
			printf("Which song do you want to recover?\n");
			printf("Select song (1 - %d): ", CountDelete);
			scanf("%d", &answDel);
		}while(answDel < 1 || answDel > CountDelete);
		
		RecoverNode(answDel);
	}
}

void ViewHistorySong(){
	
	if(deletedHead == NULL){
		printf("You have not deleted any song!!\n");
		return;
	}
	
	displayDeletedSong();
	
	int answer;
	
	do{
		printf("Do you want to recover one of your song?\n");
		printf("1. Yes\n");
		printf("2. No\n");
		printf("Select Option(1-2): ");
		
		scanf("%d", &answer);
		
		if(answer < 1 || answer > 2)printf("Please select the valid menu bro~~\n");
		
	}while(answer < 1 || answer > 2);
	
	switch(answer){
		case 1:
			RecoverSong();
			break;
		default:
			return;	
	}
}

void menu(){
	int countMenu = 0;
	do{
		int answer;
		printf("\n===--Spotify Playlist--===\n");
		printf("1. Add Song\n");
		printf("2. Display Song\n");
		printf("3. Delete Song\n");
		printf("4. View Deleted Song\n");
		printf("5. Sort Song\n");
		printf("6. Exit\n");
		
		
		printf("Select Menu (1-5): ");
		scanf("%d", &answer);
		
		switch(answer){
			case 1:
				addSong();
				break;
			case 2:
				displaySong();
				break;
			case 3:
				DeleteSong();
				break;
			case 4:
				ViewHistorySong();
				break;
			case 5:
				sortSong();
				break;
			case 6:
				printf("\nCYAAAA\n");
				exit(1);
			default:
				printf("Invalid choice! Try Again my HOMIEEE~~~\n");
		}
		countMenu++;
		
		if(countMenu == 4){
			system("cls");
			countMenu = 0;
		}
	}while(1);
}

int main(){
	menu();
	return 0;
}
