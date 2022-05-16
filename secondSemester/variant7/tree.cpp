#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

struct Tree {
	int info;
	Tree* left;
	Tree* right;
	Tree* parent;
};

void add(Tree*& branch,Tree* parent, int info);

void transplant(Tree*& branch, Tree* replaceableBranch, Tree* branchSubstitute);
void treeDelete(Tree*& branch, Tree* deletedItem);

// мне лень !!!!
void balancedTree();
void DeleteNodeFromBinary(Tree* node, int value);
Tree* Leftmost(Tree* node);
Tree* Rightmost(Tree* node);

void inorderTreeWalk(Tree* branch);
void preorderTreeWalk(Tree* branch);
void postorderTreeWalk(Tree* branch);

Tree* treeMinimum(Tree* branch);
Tree* treeMaximum(Tree* branch);

void seachElement(Tree* branch, int value);
Tree* treeSearch(Tree* branch, int value);
int findHeight(Tree* branch);

int main() {
	srand(time(0));

				
	Tree* branch = NULL;
	int count;
	cout << "How many items do you want to add: ";
	cin >> count;

	for (int i = 0; i < count; i++) {
		int info = rand() % 60;
		add(branch, NULL, info);
	}

	while (true) {
		int choice;
		cout << " \n 1 - individual task;\n 2 - add branch;\n 3 - search element;\n"
			<< " 4 - view element;\n 5 - exit;\n 6 - individual task;\n 7 - delete element \n"
			<< "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				system("cls");
				break;

			case 2:
				system("cls");
				
				int value;
				cout << "What number do you want to add: ";
				cin >> value;
				add(branch, NULL, value);
				break;

			case 3:
				system("cls");
				
				int key;
				cout << "What number do you want to find: ";
				cin >> key;
				seachElement(branch, key);

				break;

			case 4:
				system("cls");
				
				cout << " Your Tree: ";
				inorderTreeWalk(branch);
				cout << endl;

				break;

			case 5:
				system("cls");
				cout << "Good bye!!";
				return 0;

			case 6:
				cout << "Height of your tree is " << findHeight(branch);
				break;
				 
			case 7:
				system("cls");
				
				cout << " Your Tree: ";
				inorderTreeWalk(branch);

				int item;
				cout << "\nWhat value we delete: ";
				cin >> item;
				
				Tree* deletedItem = treeSearch(branch, item);
				
				if (!deletedItem) {
					cout << "Enter corect value!!!";
					break;
				}

				DeleteNodeFromBinary(branch, item);
				break;
		}
	}

}

void add(Tree*& branch,Tree* parent, int info) {
	if (branch == NULL) {
		branch = new Tree;
		branch->info = info;
		branch->left = NULL;
		branch->right = NULL;
		branch->parent = parent;
		return;
	}
	else {
		if (info >= branch->info) {
			add(branch->right, branch, info);
		}
		else {
			add(branch->left, branch, info);
		}
	}
}
/*
void add(Tree*& branch, Tree* value) {
	Tree* y = NULL;
	Tree* x = branch;
	while (x != NULL) {
		y = x;
		if (value->info < x->info) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	value->parent = y;
	if (y == NULL) {
		branch = value;
	}
	else if (value->info < y->info) {
		y->left = value;
	}
	else {
		y->right = value;
	}

}
*/
// возвращает информацию есть ли у нас этот элемент
void seachElement(Tree* branch, int value) {
	if (branch->info == value) {
		cout << "We have that element " << value;
		return;
	}
	else if (branch->info < value) {
		seachElement(branch->right, value);
	}
	else if (branch->info > value) {
		seachElement(branch->left, value);
	}
	else {
		cout << "Tree doesn't have a " << value;
		return;
	}
}

// возвращает указатель на элемент который мы ищем
Tree* treeSearch(Tree* branch, int value) {
	if (branch == NULL || value == branch->info) {
		return branch;
	}
	if (value < branch->info) {
		return treeSearch(branch->left, value);
	}
	else {
		return treeSearch(branch->right, value);
	}
}


// центрированный обход дерева, стоит по умолчанию
void inorderTreeWalk(Tree* branch){
	if (branch != NULL) {
		inorderTreeWalk(branch->left);
		cout << branch->info << " ";
		inorderTreeWalk(branch->right);
	}
}


// обход в прямом порядке
void preorderTreeWalk(Tree* branch) {
	if (branch != NULL) {
		cout << branch->info << " ";
		preorderTreeWalk(branch->left);
		preorderTreeWalk(branch->right);
	}
}

// обход в обратном порядке
void postorderTreeWalk(Tree* branch) {
	if (branch != NULL) {
		cout << branch->info << " ";
		postorderTreeWalk(branch->right);
		postorderTreeWalk(branch->left);

	}
}

Tree* treeMinimum(Tree* branch) {
	while (branch->left != NULL) {
		branch = branch->left;
	}
	return branch;
}

Tree* treeMaximum(Tree* branch) {
	while (branch->right != NULL) {
		branch = branch->right;
	}
	return branch;
}

// функция которая меняет местами деревья
void transplant(Tree*& branch, Tree* replaceableBranch, Tree* branchSubstitute) {
	
	if (replaceableBranch->parent == NULL) {
		branch = branchSubstitute;
	}
	else if (branchSubstitute == replaceableBranch->parent->left) {
		replaceableBranch->parent->left = branchSubstitute;
	}
	else {
		replaceableBranch->parent->right = branchSubstitute;
	}
	if (branchSubstitute != NULL) {
		replaceableBranch->parent == branchSubstitute->parent;
	}
}


void treeDelete(Tree*& branch, Tree* deletedItem) {
	if (deletedItem->left == NULL) {
		transplant(branch, deletedItem, deletedItem->right);
	}
	else if (deletedItem->right == NULL) {
		transplant(branch, deletedItem, deletedItem->left);
	}
	else {
		Tree* minimumValue = treeMinimum(deletedItem->right);
		if (minimumValue->parent != deletedItem) {
			transplant(branch, minimumValue, minimumValue->right);
			minimumValue->right = deletedItem->right;
			minimumValue->right->parent = minimumValue;
		}
		transplant(branch, deletedItem, minimumValue);
		minimumValue->left = deletedItem->left;
		minimumValue->left->parent = minimumValue;
	}
}

// из интернета
void DeleteNodeFromBinary(Tree* node, int value)
{
	if (node == NULL)
		return;

	if (value < node->info)
		return DeleteNodeFromBinary(node->left, value);
	else if (value > node->info)
		return DeleteNodeFromBinary(node->right, value);
	else {
		if (node->left == NULL && node->right == NULL) {
			if (node->parent->left == node)
				node->parent->left = NULL;
			else
				node->parent->right = NULL;
			delete node;
		}
		else {
			Tree* newnode = NULL;
			if (node->left != NULL) {
				newnode = Rightmost(node->left);
			}
			else
				newnode = Leftmost(node->right);

			if (node->parent->left == node)
				node->parent->left = newnode;
			else
				node->parent->right = newnode;

			newnode->parent = node->parent;
			newnode->right = node->right;
			newnode->left = node->left;

			delete node;
		}
	}
}
Tree* Leftmost(Tree* node) {
	if (node == NULL)
		return NULL;
	if (node->left != NULL) {
		return Leftmost(node->left);
	}
	return node;
}
Tree* Rightmost(Tree* node) {
	if (node == NULL)
		return NULL;
	if (node->right != NULL) {
		return Rightmost(node->right);
	}
	return node;
}

//
void makeBalanceTree(Tree** branch, int n, int k, int* a) {
	if (n == k) {
		*branch = NULL;
		return;
	}
	else {
		int m = (n + k) / 2;
		*branch = new Tree;
		(*branch)->info = a[m];
		makeBalanceTree(&(*branch)->left, n, m, a);
		makeBalanceTree(&(*branch)->right, m + 1, k, a);
	}

}
 

// уберёшь потом d
int findHeight(Tree* branch){
	if (branch == NULL) {
		return 0;
	}
	else {
		int leftSide;
		int rightSide;

		leftSide = findHeight(branch->left);
		rightSide = findHeight(branch->right);
		
		if (leftSide > rightSide) {
			return leftSide + 1;
		}
		else {
			return rightSide + 1;
		}
	}
}