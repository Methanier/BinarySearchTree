/*
	Charles Cozart
	Binary Search Tree
	CSC382
*/

#pragma once
#include<algorithm>
#include<string>
#include<iostream>
#include <iomanip>

//Namespace BinarySearchTree(BST) is under
namespace BST
{
	//Template for Generic programming of data types
	template <typename T>
	class BinarySearchTree
	{
	private:
		//Struct for data Nodes held in the BST
		struct Node
		{
			T data; //Node data of generic type
			Node *left; //Holds left child
			Node *right; //Holds right child

			Node(const T & inData, Node * leftNode, Node * rightNode) : data{ inData }, left{ leftNode }, right{ rightNode } {} //Constructor for const data types

			Node(T && inData, Node * leftNode, Node * rightNode) : data{ std::move{inData} }, left{ leftNode }, right{ rightNode } {} //constructor for non-const data types
			
		};


	public:

		//Default constructor
		BinarySearchTree()
		{
			_root = nullptr;
		}

		//Copy constructor of const BST's
		BinarySearchTree(const BinarySearchTree & inTree)
		{
			_root = Clone(inTree._root); //Calls Clone Function
		}

		//Copy constructor of non-const BST's
		BinarySearchTree(BinarySearchTree && inTree)
		{
			_root = Clone(inTree._root); //Calls Clone Function
		}

		//Destructor for BST
		~BinarySearchTree()
		{
			Clear(_root); //Calls clear function
		}

		//Public contains function
		bool Contains(const T & inData)
		{
			return Contains(inData, _root); //Calls and returns result of private Contains function
		}

		//Public Insert function for const data types
		void Insert(const T & inData)
		{
			Insert(inData, _root); //Calls private insert function
		}

		//Public Insert function for non-const data types
		void Insert(T && inData)
		{
			Insert(inData, _root); //Calls private insert function
		}

		//Public Delete function for const data types
		void Delete(const T & inData)
		{
			Delete(inData, _root); //Calls private Delete function
		}

		//Public Delete function for non-const data types
		void Delete(T && inData)
		{
			Delete(inData, _root); //Calls private Delete function
		}
		
		//Public Print function
		void Print()
		{
			Print(_root); //Calls private Print function
		}

		//Public GetRoot function returns private _root variable
		Node * GetRoot()
		{
			return _root;
		}

	private:

		Node * _root; //Private root variable, the main root of the BST

		//Private Insert function for const data types, has Node parameter for recusive calls
		void Insert(const T & inData, Node * & inNode)
		{
			//Checks if Node is empty
			if (inNode == nullptr)
			{
				inNode = new Node(inData, nullptr, nullptr); //Creates new node
			}
			//Checks if incoming data is less than the data in current node
			else if (inData < inNode->data)
			{
				Insert(inData, inNode->left); //Recusively calls Insert function on the left child of the current node
			}
			//Checks if incoming data is greater than the data in current node
			else if (inNode->data < inData)
			{
				Insert(inData, inNode->right); //Recursively calls Insert function on the right chile of the current node
			}
			else
			{
				//duplicat do nothing
			}
		}

		//Private Insert function for non-const data types, has Node parameter for recusive calls
		void Insert(T && inData, Node * inNode)
		{
			//Checks if Node is empty
			if (inNode == nullptr)
			{
				inNode = new Node(inData, nullptr, nullptr); //Creates new node
			}
			//Checks if incoming data is less than the data in current node
			else if (inData < inNode->data)
			{
				Insert(inData, inNode->left); //Recusively calls Insert function on the left child of the current node
			}
			//Checks if incoming data is greater than the data in current node
			else if (inNode->data < inData)
			{
				Insert(indata, inNode->right); //Recursively calls Insert function on the right chile of the current node
			}
			else
				//duplicat do nothing
		}

		//Private Clone function used in copy constructors
		Node * Clone(Node * inNode) {
			//Checks if the node is empty, if so returns null pointer
			if (inNode == nullptr)
				return nullptr;
			else
				return new Node{ inNode->data, Clone(inNode->left), Clone(inNode->right) }; //Creates a new Node using recursive calls to the Clone function for the left and right children of the Node.
		}

		//Private FindMaximum function, returns Node pointer to the maximum value of the pass Node
		Node * FindMaximum(Node * inNode) const
		{
			//If the current node is empty returns null pointer
			if (inNode == nullptr)
				return nullptr;
			//If the right child of the current node is empty, returns this node
			else if (inNode->right == nullptr)
				return inNode;
			else
			{
				return FindMaximum(inNode->right); //Recursively calls the FindMaximum function on this node's right child
			}
		}

		//Private FindMinimum function, returns Node pointer to the minimum value of the pass Node
		Node * FindMinimum(Node * inNode) const
		{
			//If the current Node is empty, returns null pointer.
			if (inNode == nullptr)
				return nullptr;
			//If the left child of the current node is empty, returns this node
			else if (inNode->left == nullptr)
				return inNode;
			else
				return FindMinimum(inNode->left); //Recursively calls the FindMinimum function on this Node's left child
		}

		//Private Contains Function
		bool Contains(const T & inData, Node * inNode) const
		{
			//If the current node is empty returns false
			if (inNode == nullptr)
				return false;
			//If the passed data is less than the data in the current node
			else if (inData < inNode->data)
			{
				return Contains(inData, inNode->left); //Recursively calls the Contains function on the current nodes left child;
			}
			//If the passed data is greater than the data in the current node
			else if (inData > inNode->data)
			{
				return Contains(inData, inNode->right); //Recursively calls the Contains function on the current nodes right child
			}
			//If the passed data is equal to the data in this node returns true
			else
			{
				return true;
			}
		}

		//Private Delete Function
		void Delete(const T & inData, Node * & inNode)
		{
			//If the current node is empty, returns out of the function
			if (inNode == nullptr)
				return;
			//If the passed data is less than the data in the current node
			if (inData < inNode->data)
			{
				Delete(inData, inNode->left); //Recursively calls the Delete function on the current Node's left child
			}
			//If the passed data is greater than the data in the current node
			else if (inData > inNode->data)
			{
				Delete(inData, inNode->right); //Recursively calls the Delete function on the current Node's right child
			}
			//If the current node has Two children
			else if(inNode->left != nullptr && inNode->right != nullptr)
			{
				inNode->data = FindMinimum(inNode->right)->data; //Sets the current nodes data to the smallest value found on the subtree of the right child
				Delete(inNode->data, inNode->right); //Recursively calls the delete function on the new data value and the right child of this node to remove the duplicate
			}
			//If the current node has one child
			else
			{
				Node *temp = inNode; //Creates temporary Node object equal to the node

				/*
					Ternary conditional statment. If the current node's left child is not empty, it sets the current node equal to the left child, otherwise it
					is set equal to the right child
				*/
				inNode = (inNode->left != nullptr) ? inNode->left : inNode->right;

				delete temp; //Deletes the temporary node object
			}
		}
		
		/*
			Private Print function
			Will print the tree with the root of the tree at the left side of the screen, right children will be displayed at the top, and left children at
			the bottom respective to their parents.

			Custom classes utilizing this tree will need to overload the ostsream opeartor <<
		*/
		void Print(Node * inNode, int indent = 0)
		{
			//If the current node is not empty
			if (inNode != nullptr)
			{
				//If the current node's right child is not empty
				if (inNode->right)
					Print(inNode->right, indent + 4); //Recursively calls the Print function on the current nodes right child adding a value to the indent parameter
				//If indent does not equal 0
				if (indent)
					std::cout << std::setw(indent) << ' '; //Sets the indent of the ostream
				//If the right child of the current node is not empty
				if (inNode->right)
				{
					std::cout << "  /\n" << std::setw(indent) << ' '; //sets the indent, prints spacing and the '/' character for linking the children
				}
				std::cout << inNode->data << "\n"; //Prints the current nodes data

				//If the current nodes left child is not empty
				if (inNode->left)
				{
					std::cout << std::setw(indent) << ' ' << " \\\n"; //Sets the ostream indent and prints the '\' character for child linking
					Print(inNode->left, indent + 4); //recursively calls the Print function on the left child of the current Node
				}
			}
		}

		//Private Clear function used in the destructor
		void Clear(Node *& inNode)
		{
			//If the current node is note empty
			if (inNode != nullptr)
			{
				Clear(inNode->left); //Recursively calls the Clear function on the current nodes left child
				Clear(inNode->right); //Recursively calls the Clear function on the current nodes right child
				delete inNode;
			}
			inNode = nullptr; //Sets the current node the null pointer
		}
	};
}
