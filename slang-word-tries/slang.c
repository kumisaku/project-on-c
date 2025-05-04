#include <stdio.h> //including the standard output
#include <stdlib.h> //including the library for memory
#include <string.h> //including the library for string modification
#include <stdbool.h> //including the library for the bool variable

#define NUM_CHAR 256 //setting up the amount of array for the trienode chidlren

//this is the structure for the trienode including the children,description and the terminal
typedef struct trienode {
    struct trienode *children[NUM_CHAR];
    char description[NUM_CHAR];
    bool terminal;
} trienode;

//this is the function to set the struct with the data requested
trienode *createNode() {
    trienode *newNode = (trienode *)malloc(sizeof(trienode)); //setting up the newnode to allocate the memory for the newnode
    memset(newNode->children, 0, sizeof(newNode->children)); //setting up the memory size for the children declaration
    newNode->terminal = false; //setting up the default terminal to false
    newNode->description[0] = '\0'; //setting up the description to begin with nothing without words
    return newNode; //returning the node
}

//function to insert trie node
bool insertNode(trienode **root, const char *text, const char *description) {
    if (*root == NULL) {
        *root = createNode(); //this is the if statement to create newnode for the root if there is no root yet in the trie
    }

    trienode *temp = *root; //declaring a temporary pointer that points to the root
    
    //this is a for loop to copy the letter with the iteration of an index in text
    for (int i = 0; text[i] != '\0'; i++) {
        unsigned char index = (unsigned char)text[i]; //creating a variable index to store the remaining index in the loop
        if (!temp->children[index]) {
            temp->children[index] = createNode(); //an if statement for creating a newnode if there is no node
        }
        temp = temp->children[index]; //this is for the iteration to the next node
    }
	
	//an if else statement for a word that has been added to the trie
    if (temp->terminal) {
        printf("You have already added this word!\n"); 
        return false; //returning false if the word is already exist with the sign of the terminal on the letter index
    } else {
        temp->terminal = true; //setting up the letter of the last word  to be true
        strncpy(temp->description, description, NUM_CHAR - 1); //copying the description from the inputted description
        temp->description[NUM_CHAR - 1] = '\0'; // this will save up memory for the last index
        printf("Successfully added new slang word.\n"); //output
        return true; //returning true if the word is not exist and successfully added to the trie
    }
}

//a function for the recursion print of the trie
void printTrie_rec(trienode *node, char *prefix, int *count, int length) {
	//an if statement for the displaying the founded word 
    if (node->terminal) {
        prefix[length] = '\0'; //setting the last index to \0
        printf("%d. %s\n", (*count)++, prefix); //print the word
    }
	//iteration function to find the bool terminal that have true value
	for (int i = 'A'; i <= 'Z'; i++) {
	    if (node->children[i]) {
	        prefix[length] = i;
	        printTrie_rec(node->children[i], prefix, count, length + 1);
	    }
	}
	for (int i = 'a'; i <= 'z'; i++) {
	    if (node->children[i]) {
	        prefix[length] = i;
	        printTrie_rec(node->children[i], prefix, count, length + 1);
	    }
	}
	// the loop will order with lexicographical graph
}

//a function to display the trie
void printTrie(trienode *root) {
	//an if statement for no root
    if (!root) {
        printf("There are no slang words in the dictionary yet.\n"); //displaying
        return; //return if there is no root yet
    }

    int count = 1; //declaring the count variable
    char buffer[101]; //declaring the buffer for the word
    printTrie_rec(root, buffer, &count, 0); //calling the recursion print function
}

//this is the pressing enter function
void waitEnter() {
    printf("\nPress enter to continue...\n"); //print word
    while (getchar() != '\n'); //waiting until the user input enter
}

//a function to search for the node
trienode *searchNode(trienode *root, const char *word) {
    if (!root) return NULL; //returning a null if there is not root

    trienode *temp = root; //declaring temp variable
    
    //an iteration to store index from the word
    for (int i = 0; word[i] != '\0'; i++) {
        unsigned char index = (unsigned char)word[i]; //store the index word to the index variable
        if (!temp->children[index]) {
            return NULL; //if there is no index that we search it will return NULL
        }
        temp = temp->children[index]; //iterate to the next index children
    }
    return temp->terminal ? temp : NULL; //return temp if the word is found but NULL if the word is not found
}

//a function to searchslang words
void searchSlang(trienode *root, char *slangWord) {
    trienode *result = searchNode(root, slangWord); //call the function and store the result in a result pointer
    if (result) { //if condition if there is a result
        printf("\nSlang word  : %s\n", slangWord);
        printf("Description : %s\n", result->description);
    } else { //a condition if there is no result
        printf("\nNo slang word \"%s\" found in the dictionary.\n", slangWord);
    }
}


// a function to collect word for the prefix print
void collectword(trienode *node, char *buffer, int len, int *count) {
	
	//if function for printing word
    if (node->terminal) {
        buffer[len] = '\0'; //emptying the last index of the word
        printf("%d. %s\n", (*count)++, buffer); //printing the word
    }
    
    //iteration for the word recursion
    for (int i = 0; i < NUM_CHAR; i++) {
    	//iteration while recursion trough the children index (if statement if the index is available)
        if (node->children[i]) {
            buffer[len] = i; // making the last word
            collectword(node->children[i], buffer, len + 1, count); //recursion for the collected word
        }
    }
}

//a function for searching the prefix
void searchprefix(trienode *root) {
    char prefix[54]; //prefix word declaration
    printf("Input a prefix to search: ");
    scanf(" %53s", prefix);

    trienode *prefixNode = searchNode(root, prefix); //storing the searchnode function into pointer
    
    //if else statement for the founded pointer
    if (!prefixNode) {
        printf("\nNo words found starting with \"%s\".\n", prefix);
    } else {
        printf("\nWords starting with \"%s\":\n", prefix);
        char buffer[100];
        strncpy(buffer, prefix, sizeof(buffer) - 1); //copying the prefix word to the buffer
        buffer[sizeof(buffer) - 1] = '\0';
        int count = 1;
        collectword(prefixNode, buffer, strlen(prefix), &count); //recursion that store the argument of the count, buffer, and other stuff
    }
}

//function to free memory of trie
void freeTrie(trienode *root) {
    if (!root) return; //return if there is no root
    
    //iterate function for freeing each node
    for (int i = 0; i < NUM_CHAR; i++) {
        if (root->children[i]) {
            freeTrie(root->children[i]);
        }
    }
    
    free(root); //free the memory of the node
}

//main function for the menu
int main() {
    int answer;
    trienode *root = NULL; //declaring the root as NULL
    
    //menu loop until exit
    do {
        printf("Welcome to the Slang Academy!\n");
        printf("1. Add a new slang word\n");
        printf("2. Search for a slang word\n");
        printf("3. View all words with a prefix\n");
        printf("4. View all slang words\n");
        printf("5. Exit\n");
        printf("\nSelect an option (1-5): ");
        
        //if statement for invalid input (string)
        if (scanf("%d", &answer) != 1){
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        getchar();
		
		//menu for number 1
        if (answer == 1) {
            char slangSearch[54], description[101];
            int valid, i;
            //loop until the condition is met
		    do {
		        valid = 1; //check if valid
		
		        printf("Input a new slang word [Must be more than 1 characters and contains no space]: ");
		        scanf(" %[^\n]", slangSearch); //ask user input
		        
		        //condition for checking valid input
		        if (strlen(slangSearch) < 2) {
		            valid = 0;
		        } else {
		        	//checking for the spaces
		            for (i = 0; slangSearch[i] != '\0'; i++) {
		                if (slangSearch[i] == ' ') {
		                    valid = 0;
		                    break;
		                }
		            }
		        }
		    } while (!valid);

            getchar();
            
            //condition to loop if the slang word description is invalid
            do {
                printf("Input a new slang word description [Must be more than 2 words]: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0';
            } while (strchr(description, ' ') == NULL || strchr(strchr(description, ' ') + 1, ' ') == NULL);

            insertNode(&root, slangSearch, description); //calling the function for the insert
            waitEnter(); //calling the function to wait for the user 'enter' input
            
            //menu 2
        } else if (answer == 2) {
            char slangSearch[54];
            int valid, i;
            //condition check for the word
		    do {
		        valid = 1; //check if valid
		
		        printf("Input a slang word to be searched [Must be more than 1 characters and contains no space]: ");
		        scanf(" %[^\n]", slangSearch); //ask user input
		        
		        //condition for checking valid input
		        if (strlen(slangSearch) < 2) {
		            valid = 0;
		        } else {
		        	//checking for the spaces
		            for (i = 0; slangSearch[i] != '\0'; i++) {
		                if (slangSearch[i] == ' ') {
		                    valid = 0;
		                    break;
		                }
		            }
		        }
		    } while (!valid);

            searchSlang(root, slangSearch); //calling the search function
            waitEnter(); //calling the function to wait for the user 'enter' input
            
            //menu 3
        } else if (answer == 3) {
            searchprefix(root); //calling the function for prefix search
            waitEnter(); //calling the function to wait for the user 'enter' input
            
            //menu 4
        } else if (answer == 4) {
            printf("List of all slang words in the dictionary:\n");
            printTrie(root); //displaying all of the word in the trie
            waitEnter(); //calling the function to wait for the user 'enter' input
            
            //menu 5
        } else if (answer == 5) {
            printf("Thank you... Have a nice day :)\n");
            freeTrie(root); //free trie memory
        } else {
            printf("Invalid option. Please choose a number between 1 and 5.\n");
        }
    } while (answer != 5);

    return 0;
}
