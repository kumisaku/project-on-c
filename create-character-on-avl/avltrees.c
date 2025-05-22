#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAME_MAX 64

typedef struct profile{
    char name[NAME_MAX];
    int id;
}profile;

typedef struct node{
    profile data;
    int height;
    struct node*left;
    struct node*right;
}node;

node*createNode(profile data){
    node*newNode = (node*)malloc(sizeof(node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    newNode->data = data;

    return newNode;
}

int max(int a, int b){
    return a > b? a : b;
}

int height(node*n){
    if(n == NULL){
        return 0;
    }
    return n->height;
}

int getBalance(node*n){
    if(n == NULL){
        return 0;
    }
    return height(n->left) - height(n->right);
}

node*leftRotate(node*x){
    node*y = x->right;
    node*t2 = y->left;

    y->left = x;
    x->right = t2;

    //update node height
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return y;
}

node*rightRotate(node*y){
    node*x = y->left;
    node*t2 = x->right;

    x->right = y;
    y->left = t2;

    //update node height
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

node*insertNode(node*root,profile data){
    if(root == NULL){
        return createNode(data);
    }
    else if(data.id < root->data.id)root->left = insertNode(root->left, data);
    else if(data.id > root->data.id)root->right = insertNode(root->right, data);
    else return root;

    //get height of the node
    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root); //getting the node balance

    if(balance > 1 && data.id < root->left->data.id){
       return rightRotate(root); 
    }
    if(balance > 1 && data.id > root->left->data.id){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && data.id > root->right->data.id){
        return leftRotate(root);
    }
    if(balance < -1 && data.id < root->right->data.id){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

profile createChara(){
    profile data;
    char name[NAME_MAX];
    int id;

    printf("Enter Character Name[MAX 64]: ");
    scanf("%s", name);
    printf("Enter Custom Id: ");
    scanf("%d", &id);

    strcpy(data.name, name);
    data.id = id;

    return data;
}

node*getMinValues(node*root){
    node*current = root;

    while(current->left != NULL){
        current = current->left;
    }

    return current;
}

node*deleteNode(node*root, int id){
    if(root == NULL)return root;
    else if(id < root->data.id)root->left = deleteNode(root->left, id);
    else if(id > root->data.id)root->right = deleteNode(root->right, id);
    else
    {
        //no child & 1 child
        if(root->left == NULL || root->right == NULL){
            node*temp = root->left ? root->left : root->right;

            //no child
            if(temp == NULL){
                temp = root;
                root = NULL;
            }
            
            // 1 child
            else{
                *root = *temp;
            }


            free(temp);
        }
        // two child
        else{
            node*temp = getMinValues(root->right);
            root->data.id = temp->data.id;
            root->right = deleteNode(root->right, temp->data.id);
        }
    }

    // AVL Operations
    if(root == NULL){
        return root;
    }

    //get node height
    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);

    //rotate operations
    if(balance < -1 && getBalance(root->right) <= 0){
        return leftRotate(root);
    }
    if(balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    if(balance > 1 && getBalance(root->left) >= 0){
        return rightRotate(root);
    }
    if(balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return leftRotate(root);
    }

    return root;
}

void deleteChar(node**root){
    int id;
    printf("Enter id: ");
    scanf("%d", &id);

    *root = deleteNode(*root, id);
}

void prefix(node*root){
    if(root != NULL){
        printf("==========================\n");
        printf("Name: %s\nId: #%d\n", root->data.name, root->data.id);
        printf("==========================\n");
        prefix(root->left);
        prefix(root->right);
    }
}

int main(){

    node*root = NULL; //initialize root

    int options;

    // menu bar
    
    while(1){
        printf("1. Create characters\n");
        printf("2. Display created characters[prefix]\n");
        printf("3. Delete characters\n");
        printf("4. Exit\n");
        printf("Select: ");
        scanf("%d", &options);

        switch(options){
            case 1:
                profile data = createChara();
                root = insertNode(root,data);
                break;
            case 2:
                prefix(root);
                break;
            case 3:
                deleteChar(&root);
                break;
            case 4:
                return 0;
                break;
            default:
                return 1;
        }
    }
    return 0;
}