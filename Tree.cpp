# include <iostream>
# include <cstdlib>
# include <stdexcept>
# include "Tree.hpp"
# include <exception>      // std::exception

using namespace std;
using   ariel::Node;
using  ariel::Tree;



//constructors for Node
ariel::Node::Node() : Node(0) {}
ariel::Node::Node(int num) : data(num), left(nullptr), right(nullptr) {} 

ariel::Node::~Node() {
	if (left != nullptr) { delete left; left=nullptr;}
	if (right != nullptr) { delete right; right=nullptr; }
}

//tree constructor for root null and size of the tree 0
ariel::Tree::Tree() {
	_root = nullptr;
}

ariel::Tree::~Tree() {
	if (_root != nullptr) { delete _root; _root=nullptr; }
}

//insert function
void ariel::Tree::insert(int num){
if(contains(num)){throw std::invalid_argument("this number already on the Tree, error to insert him agian");}
	else if(_root != NULL){
		insert(_root,num);
	}else{
		_root = new Node(num);
		
	}
}


//insert helper function
void ariel::Tree::insert( Node* &leaf,int num){

	if(num < leaf->data){
		if(leaf->left != nullptr){
			insert(leaf->left,num);
		}else{
			leaf->left = new Node(num);
			
		}
	}else if(num > leaf->data){
		if(leaf->right != nullptr){
			insert( leaf->right,num);
		}else{
			leaf->right = new Node(num);
			
		}
	}

}



//print the tree
void ariel::Tree::print() {//Inorder print
	if (_root == nullptr) { throw std::invalid_argument("error: you trying to print empty tree"); }
	else { return print(this->_root); }
}//end print

void ariel::Tree::print(Node* TreePrint) {
	if (TreePrint == nullptr)
		return;

	/* first recur on left child */
	print(TreePrint->left);

	/* then print the data of node */
	cout << TreePrint->data << " ";

	/* now recur on right child */
	print(TreePrint->right);
}//end print helper




//find the maximum value Node
Node* ariel::Tree::FindMax(Node* nodeMaxVal)
{
	if (nodeMaxVal == nullptr) {
		return nullptr;
	}
	while (nodeMaxVal->right != nullptr)
	{
		nodeMaxVal = nodeMaxVal->right;
	}
	return nodeMaxVal;
}//end FindMax value node

Node* ariel::Tree::FindMin(Node* nodeMinVal) {
	if (nodeMinVal == nullptr) {
		return nullptr;
	}
	while (nodeMinVal->left != nullptr)
	{
		nodeMinVal = nodeMinVal->left;
	}
	return nodeMinVal;
}//end find min value node


//remove function
void ariel::Tree::remove(int num){
if(!contains(num)){throw std::invalid_argument("this element is not in the Tree Cannot remove him");}
else {
return remove(this->_root,num);
}
}//end remove



// Function to delete node from a BST. Note that root is passed by
// reference to the function
void ariel::Tree::remove(Node* &node, int num)
{
	// base case: key not found in tree
	if (node == nullptr)
		return;

	// if given key is less than the root node, recurse for left subtree
	if (num < node->data)
		remove(node->left, num);

	// if given key is more than the root node, recurse for right subtree
	else if (num > node->data)
		remove(node->right, num);

	// key found
	else
	{
		// Case 1: node to be deleted has no children (it is a leaf node)
		if (node->left == nullptr && node->right == nullptr)
		{
			// deallocate the memory and update root to null
			delete node;
			node = nullptr;
		}

		// Case 2: node to be deleted has two children
		else if (node->left && node->right)
		{
			// find its in-order predecessor node
			Node *predecessor = FindMax(node->left);

			// Copy the value of predecessor to current node
			node->data = predecessor->data;

			// recursively delete the predecessor. Note that the
			// predecessor will have at-most one child (left child)
			remove(node->left, predecessor->data);
		}

		// Case 3: node to be deleted has only one child
		else
		{
			// find child node
			Node* child = (node->left)? node->left: node->right;
			Node* curr = node;

			node = child;

			// deallocate the memory
			delete curr;
			curr=nullptr;
		}
	}
}


int ariel::Tree::size() {
	//if root null so no have numbers inside so return 0
	if (_root == nullptr) { return 0; }
	//else: root not null so call to size helper with the pointer to root
	else { return size(this->_root); }
}//end size

//return the size of the tree(how maney numbers in it)
int ariel::Tree::size(Node* temp) {
	if (temp == nullptr) { return 0; }
	else { return(1 + size(temp->left) + size(temp->right)); }

}//end size helper




//check if the tree contains specific number
bool ariel::Tree::contains(int num) {
	return contains(this->_root, num);
}//end contains

bool ariel::Tree::contains(Node* node, int num) {
	if (node == nullptr) {
		return false;
	}
	Node* temp = node;
	while (temp != nullptr) {
		if (temp->data == num) {
			return true;
		}
		else if (temp->data > num) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	return false;
}//end contains


//return the value of the root
int ariel::Tree::root() {
	if (_root != nullptr) { return _root->data; }
	else { throw std::invalid_argument("root function error: root=NULL"); }
	return 0;
}//end root




//return the left children of num
int ariel::Tree::left(int num) {
	if (!contains(num)) { throw std::invalid_argument("num not exist so cant find his left children"); }
	else { return(left(_root, num)); }
}//end left

//left helper
int ariel::Tree::left(Node* leftOfNum, int num) {
	//if root is NULL throw exception
	if (leftOfNum == nullptr) {
		throw std::invalid_argument("root is NULL,no have left children.");
	}

	//check if num is exist
	if (!contains(num)) { throw std::invalid_argument("the number that we try to find his left children not exist in the tree"); }

	//if found the number check the children
	if (leftOfNum->data == num) {
		//if left is null throw exception

		if (leftOfNum->left == nullptr) {
			throw std::invalid_argument("root no have left children.");
		}

		//if left children not NULL return his value
		if (leftOfNum->left != nullptr) {
			return leftOfNum->left->data;
		}
	}

	//use left_helper
	//search in left sub tree
	if (leftOfNum->data > num) {
		return left(leftOfNum->left, num);
	}
	//search in right sub tree
	else {
		return left(leftOfNum->right, num);
	}

}//end left helper




//return the right children of num
int ariel::Tree::right(int num) {
if (!contains(num)) { throw std::invalid_argument("num not exist so cant find his right children"); }
	else { return(right(_root, num)); }
}//end right


//right helper
int ariel::Tree::right(Node* rightOfNUm, int num) {
if(rightOfNUm==nullptr){ throw std::invalid_argument("somehow right helper func root is null"); }
else{

//@data==num@ check the left and right
if((rightOfNUm->data)==num){
 if(rightOfNUm->right==nullptr){throw std::invalid_argument("the right children are nullptr");}
else{return rightOfNUm->right->data;}
}
//@data!=num@
else{
if((rightOfNUm->data)<num){return right(rightOfNUm->right,num);}
else{return right(rightOfNUm->left,num);}
}


}
}//end right helper


//find the parent of num
int ariel::Tree::parent(int num) {
	if (!contains(num)) { throw std::invalid_argument("num not exist so cant find his parent children"); }
	else {
		return(parent(_root, num));
	}
}//end parent


int ariel::Tree::parent(Node* parentOfNum, int num) {

	//if no number in the tree throw error

	if (parentOfNum == nullptr) {
		throw std::invalid_argument("root is null so he have no parent.");
	}


	//if the root is the number so he no have parent throw error

	if (parentOfNum->data == num) {
		throw std::invalid_argument("root is the number and he have no parent.");
	}

	//if left children is null and the number is lower than the root data
	if ((parentOfNum->left == nullptr) && (parentOfNum->data > num)) { throw std::invalid_argument("root is the number and he have no parent."); }


	//if the right children is null and the root data is bigger than num
	if ((parentOfNum->right == nullptr) && (parentOfNum->data < num)) { throw std::invalid_argument("root is the number and he have no parent."); }


	//need to search on the left and right sub trees

	//right sub tree
	if (parentOfNum->data < num) {
		if (parentOfNum->right->data == num) { return parentOfNum->data; }
		else { return parent(parentOfNum->right, num); }
	}
	//left sub tree
	else {
		if (parentOfNum->left->data == num) { return parentOfNum->data; }
		else { return parent(parentOfNum->left, num); }
	}
}//end parent_helper
