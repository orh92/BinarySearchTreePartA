#include <iostream>
namespace ariel {

	class Node {
	public:
		int data;
		Node* left;
		Node* right;

		Node();
		~Node();
		//get new node function sign
		Node(int num);


	};//node


	class Tree {
	public:

		//fields of the tree
		Node* _root;
		//constuctor
		Tree();
		//destructor
		~Tree();
		//insert function sign(can throw exception)
		void insert(int num);
		void insert(Node* &node, int num);

		//print tree
		void print();
		void print(Node* node);

		//find the right children of the i
		int right(int i);
		int right(Node* node, int num);

		//find the left children of the i
		int left(int i);
		int left(Node* node, int num);

		//return the number of root
		int root();

		//return the parent of i
		int parent(int i);
		int parent(Node* node, int num);


		//boolean answer if the tree contains i
		bool contains(int i);

		bool contains(Node* node, int i);


		//return the number of elements in the tree
		int size();
		int size(Node* node);

		//remove element from the tree(can throw exception)
		void remove(int num);
		void remove(Node* &node, int num);

		//return node with the max/min val in the tree
		Node* FindMax(Node* nodeMaxVal);
		Node* FindMin(Node* nodeMinVal);

	};//end tree

}//end namespace
