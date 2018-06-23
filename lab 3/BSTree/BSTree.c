#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "C:\Users\Zak\Documents\Atom Projects\block3\lab 3\BSTree\BSTree.h"


/* Statiska hjalpfunktioner anvands av andra funktioner i tradet och ska inte ligga i interfacet (anvandaren behover inte kanna till dessa) */

static int lesserNode (BSTree tree)   //Function that returns the smallest node in a binary search tree
{
	if(tree->left!=NULL) //If-statemnent is false if we are at the smallest node
		return lesserNode(tree->left);    //Recursion is used to get to the smallest node
	return tree->data;
}

/* Skapar en tradnod med det givna datat genom att allokera minne for noden. Glom inte att initiera pekarna*/
static struct treeNode* createNode(int data)
{
	BSTree newnode=NULL;    //Creates a pointer and allocates a new node to it
	newnode=malloc(sizeof(struct treeNode));

	if(newnode==NULL)
	{
		printf("MEMORY FAIL\n");
		return NULL;
	}

	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

/*Addera sorterad data till array från vänster till höger*/
void dataToArray(const BSTree tree,int* array,int *index)
{
	if(tree!=NULL)
	{
	  dataToArray(tree->left,array,index);//treversera träd från vänster till höger på sådan sätt får det sorterad vänster till höger
	  array[*index] = tree->data;
	  (*index)++;

	  dataToArray(tree->right,array,index);
	}
}

/* Returnerar en dynamiskt allokerad array som innehaller tradets data sorterat */
static int* writeSortedToArray(const BSTree tree)
{
	int* arr;
	int index=0;// Initierar index på 0
	arr = malloc(sizeof(int)*numberOfNodes(tree));//Alloker dynamiskt minne till arr
	if(arr==NULL)
	{
		printf("ERROR: MEMORY FAIL!");
		return NULL;
	}
	dataToArray(tree,arr,&index);//Skickar in tbinär träd till hjälpfunktionen.

	return arr;
}

/* Bygger upp ett sorterat, balanserat trad fran en sorterad array */
static void buildTreeSortedFromArray(BSTree* tree, const int arr[], int size)
{
	int index = (size/2);//Dela arrayens storlek i index
	if(find(*tree, arr[index])==0)//funktionen är sann tills upptäcks att data redan har lagts till trädet
	{
		insertSorted(tree, arr[index]);
		buildTreeSortedFromArray(tree, arr+index, size-index);// bygger höger del
		buildTreeSortedFromArray(tree, arr,index);//bygger vänster del
	}
}

/* Implementation av tradet, funktionerna i interfacet */
/* Skapar ett tomt trad - denna funktion ar fardig */
BSTree emptyTree(void)
{
	return NULL;
}

/* Returnerar 1 ifall tradet ar tomt, 0 annars */
int isEmpty(const BSTree tree)
{
	if(tree==NULL)
		return 1;
	else
  	return 0;
}

/* Satter in 'data' sorterat i *tree
 Post-condition: data finns i tradet*/
void insertSorted(BSTree* tree, int data)
{
	if(*tree == NULL)//if first node
	{
	struct treeNode* newNode = createNode(data);
	*tree = newNode;
	}
	else
	{
		if((*tree)->data>data) //if newode data is smaller
		{
			if((*tree)->left == NULL)
				(*tree)->left = createNode(data);
			else
				insertSorted(&(*tree)->left, data);
		}
		else if ((*tree)->data<data) //if newnode data is bigger
		{
			if((*tree)->right == NULL)
				(*tree)->right = createNode(data);
			else
				insertSorted(&(*tree)->right, data);
		}
	}
	assert(find(*tree, data)==1); //check if data was correctly added
}

/* Utskriftsfunktioner
   Vid anrop: anvand stdio som andra argument for att skriva ut pŒ skarmen
   Det racker att ni implementerar LR ordningarna*/
void printPreorder(const BSTree tree, FILE *textfile) //prints the tree L2R
{
	if(tree!=NULL)
	{
		fprintf(textfile, "|%d|", tree->data);
		printPreorder(tree->left, textfile);
		printPreorder(tree->right, textfile);
	}
}

void printInorder(const BSTree tree, FILE *textfile)
{
	if(tree!=NULL)
	{
	  printInorder(tree->left, textfile);
	  fprintf(textfile, "|%d|", tree->data);
	  printInorder(tree->right, textfile);
	}
}

void printPostorder(const BSTree tree, FILE *textfile)  //Postorder prints the nodes by depth, last is root
{
	if(tree!=NULL)
	{
		printPostorder(tree->left, textfile);
		printPostorder(tree->right, textfile);
		fprintf(textfile, "|%d|", tree->data);
	}
}

/* Returnerar 1 om 'data' finns i tree, 0 annars */
int find(const BSTree tree, int data)
{
	if(tree==NULL)  //true if tree is empty or data was not found
		return 0;
	if(tree->data==data)
		return 1; //return 1 if we found data
	if(data<tree->data)
		return find(tree->left, data);//search to the left if data we are looking for is smaller than current node
	else
		return find(tree->right, data);// search to the right if data we are looking for is bigger than current node
	}

/* Tar bort 'data' fran tradet om det finns */
void removeElement(BSTree* tree, int data)
{
	if(*tree==NULL)
		printf("Data not found");
	else
	{
	/* This if statement is true if the node has two children
	and contains the searched data.*/
	if(data==(*tree)->data && (*tree)->right!=NULL && (*tree)->left!=NULL)
	{
		(*tree)->data=lesserNode((*tree)->right);//we set the node we want to remove to the smallest value in the right part of tree
		// to make it the new root of that tree

	removeElement(&((*tree)->right), (*tree)->data);
	}
	else if(data==(*tree)->data)
	{
		BSTree nodeToRemove;
		nodeToRemove=(*tree); //nodeToRemove points to the node we wish to remove
		if(nodeToRemove->right==NULL)
		*tree=nodeToRemove->left;   //if there is not a child to the right.

		else
		*tree=nodeToRemove->right;
		free(nodeToRemove);
	}
	else if(data>(*tree)->data)//if data is greater
		removeElement(&((*tree)->right), data); //search to right if bigger

	else
		removeElement(&((*tree)->left), data);  //search to left if smaller
	}
}

/* Returnerar hur manga noder som totalt finns i tradet */
int numberOfNodes(const BSTree tree)
{
if(tree==NULL)  //true if no more nodes to count or tree is empty
	return 0;
return 1 + numberOfNodes(tree->left) + numberOfNodes(tree->right);
}

/* Returnerar hur djupt tradet ar */
int depth(const BSTree tree)
{
	if(tree==NULL)  //tree is empty
		return 0;
	if(depth(tree->left)>depth(tree->right))//which is deepest
		return 1 + depth(tree->left);
	else{
		return 1 + depth(tree->right);
	}
}

/* Returnerar minimidjupet for tradet
   Se math.h for anvandbara funktioner*/
int minDepth(const BSTree tree)
{
	if(tree!=NULL)
		return (log10(numberOfNodes(tree))/log10(2))+1; //with the help of a formula calculate minimum depth (d>=log2(n+1))

	return 0;
}
//EXAMINATION
int countLeaf(BSTree tree)
{
	if (tree)
	{
		if (tree->right == NULL && tree->left == NULL)
		{
			return 1;
		}
		else
		{
			return countLeaf(tree->right) + countLeaf(tree->left);
		}
	}
	else
	{
		return 0;
	}
}

/* Balansera tradet sa att depth(tree) == minDepth(tree) */
void balanceTree(BSTree* tree)
{
	if((*tree)!= NULL)
	{
		int tempNodes=numberOfNodes(*tree); //saves number of node
		int *arr=writeSortedToArray(*tree); //sort with writeSortedToArray
		freeTree(tree);
		buildTreeSortedFromArray(tree, arr, tempNodes);//build the tree

		arr=NULL;
		assert(tempNodes==numberOfNodes(*tree));
		assert(depth(*tree)==minDepth(*tree));
 }
}
/* Tom tradet och frigor minnet for de olika noderna */
void freeTree(BSTree* tree)
{
	if((*tree)!= NULL)
	{
		freeTree(&((*tree)->left));
		freeTree(&((*tree)->right));
		free(*tree);
		*tree =NULL;
	}
	assert(isEmpty(*tree)); //make sure its empty
}
