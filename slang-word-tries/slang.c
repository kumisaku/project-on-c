#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUM_CHAR 256 //setting up the amount of array for the trienode chidlren

//this is the structure for the trienode including the children,description and the terminal
typedef struct trienode {
    struct trienode *children[NUM_CHAR];
    char description[NUM_CHAR];
    bool terminal;
} trienode;

//this is the function to set the struct with the data requested
trienode *createNode() {
    trienode *newNode = (trienode *)malloc(sizeof(trienode));
    memset(newNode->children, 0, sizeof(newNode->children));
    newNode->terminal = false;
    newNode->description[0] = '\0';
    return newNode;
}

//function to insert trie node
bool insertNode(trienode **root, const char *text, const char *description) {
    if (*root == NULL) {
        *root = createNode();
    }

    trienode *temp = *root;
    
    //this is a for loop to copy the letter with the iteration of an index in text
    for (int i = 0; text[i] != '\0'; i++) {
        unsigned char index = (unsigned char)text[i];
        if (!temp->children[index]) {
            temp->children[index] = createNode();
        }
        temp = temp->children[index];
    }
	
	//an if else statement for a word that has been added to the trie
    if (temp->terminal) {
        printf("You have already added this word!\n"); 
        return false;
    } else {
        temp->terminal = true;
        strncpy(temp->description, description, NUM_CHAR - 1);
        temp->description[NUM_CHAR - 1] = '\0';
        printf("Successfully added new slang word.\n");
        return true;
    }
}

//a function for the recursion print of the trie
void printTrie_rec(trienode *node, char *prefix, int *count, int length) { 
    if (node->terminal) {
        prefix[length] = '\0';
        printf("%d. %s\n", (*count)++, prefix);
    }

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

}

//a function to display the trie
void printTrie(trienode *root) {

    if (!root) {
        printf("There are no slang words in the dictionary yet.\n");
        return;
    }

    int count = 1;
    char buffer[101];
    printTrie_rec(root, buffer, &count, 0);
}

//this is the pressing enter function
void waitEnter() {
    printf("\nPress enter to continue...\n");
    while (getchar() != '\n');
}

//a function to search for the node
trienode *searchNode(trienode *root, const char *word) {
    if (!root) return NULL;

    trienode *temp = root;
    
    //an iteration to store index from the word
    for (int i = 0; word[i] != '\0'; i++) {
        unsigned char index = (unsigned char)word[i];
        if (!temp->children[index]) {
            return NULL;
        }
        temp = temp->children[index];
    }
    return temp->terminal ? temp : NULL;
}

//a function to searchslang words
void searchSlang(trienode *root, char *slangWord) {
    trienode *result = searchNode(root, slangWord);
    if (result) {
        printf("\nSlang word  : %s\n", slangWord);
        printf("Description : %s\n", result->description);
    } else {
        printf("\nNo slang word \"%s\" found in the dictionary.\n", slangWord);
    }
}


// a function to collect word for the prefix print
void collectword(trienode *node, char *buffer, int len, int *count) {
	

    if (node->terminal) {
        buffer[len] = '\0';
        printf("%d. %s\n", (*count)++, buffer);
    }
    
    //iteration for the word recursion
    for (int i = 0; i < NUM_CHAR; i++) {

        if (node->children[i]) {
            buffer[len] = i;
            collectword(node->children[i], buffer, len + 1, count);
        }
    }
}

//a function for searching the prefix
void searchprefix(trienode *root) {
    char prefix[54];
    printf("Input a prefix to search: ");
    scanf(" %53s", prefix);

    trienode *prefixNode = searchNode(root, prefix);
    
    //if else statement for the founded pointer
    if (!prefixNode) {
        printf("\nNo words found starting with \"%s\".\n", prefix);
    } else {
        printf("\nWords starting with \"%s\":\n", prefix);
        char buffer[100];
        strncpy(buffer, prefix, sizeof(buffer) - 1); 
        buffer[sizeof(buffer) - 1] = '\0';
        int count = 1;
        collectword(prefixNode, buffer, strlen(prefix), &count);
    }
}

//function to free memory of trie
void freeTrie(trienode *root) {
    if (!root) return;
    
    //iterate function for freeing each node
    for (int i = 0; i < NUM_CHAR; i++) {
        if (root->children[i]) {
            freeTrie(root->children[i]);
        }
    }
    
    free(root);
}

//main function for the menu
int main() {
    int answer;
    trienode *root = NULL;
    
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
		        valid = 1;
		
		        printf("Input a new slang word [Must be more than 1 characters and contains no space]: ");
		        scanf(" %[^\n]", slangSearch);
		        
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

            insertNode(&root, slangSearch, description);
            waitEnter(); 
            
            //menu 2
        } else if (answer == 2) {
            char slangSearch[54];
            int valid, i;

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

            searchSlang(root, slangSearch);
            waitEnter();
            
            //menu 3
        } else if (answer == 3) {
            searchprefix(root);
            waitEnter();
            
            //menu 4
        } else if (answer == 4) {
            printf("List of all slang words in the dictionary:\n");
            printTrie(root);
            waitEnter();
            
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
