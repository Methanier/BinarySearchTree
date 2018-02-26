#pragma once
#include<algorithm>

namespace BST
{
	template <typename T>
	class BinarySearchTree
	{
	private:
		struct Node
		{
			T data;
			Node *left;
			Node *right;

			Node(const T data & inData, Node * leftNode, Node * rightNode) : data{ inData }, left{ leftNode }, right{ rightNode } {}

			Node(T data && inData, Node * leftNode, Node * rightNode) : data{ std::move{inData} }, left{ leftNode }, right{ rightNode } {}
		};

	public:
		BinarySearchTree()
		{
			root = nullptr;
		}
		BinarySearchTree(const BinarySearchTree & inTree)
		{
			root = inTree->root;
			Node * temp = inTree->root;
			while (temp->left != nullptr)
			{
				temp = temp->left;
				Insert(temp->data);
			}

			temp = inTree->root;
			while (temp->right != nullptr)
			{
				temp = temp->right;
				Insert(temp->data);
			}
		}
		BinarySearchTree(BinarySearchTree && inTree)
		{
			root = inTree->root;
			Node * temp = inTree->root;
			while (temp->left != nullptr)
			{
				temp = temp->left;
				Insert(temp->data);
			}

			temp = inTree->root;
			while (temp->right != nullptr)
			{
				temp = temp->right;
				Insert(temp->data);
			}
		}
		~BinarySearchTree();

		const T & FindMaximum() const;
		const T & FindMinimum() const;

		void Insert(const T & inData)
		{
			Insert(inData, root);
		}
		void Insert(T && inData)
		{
			Insert(inData, root);
		}

		void Delete(const T & inData);

	private:

		Node * root;

		Insert(const T & inData, Node * inNode)
		{
			if (inNode == nullptr)
			{
				inNode = new Node(inData, nullptr, nullptr);
			}
			else if (inData < inNode->data)
			{
				Insert(inData, inNode->left);
			}
			else if (inNode->data < inData)
			{
				Insert(indata, inNode->right)
			}
			else
				//duplicat do nothing
		}
		Insert(T && inData, Node * inNode)
		{
			if (inNode == nullptr)
			{
				inNode = new Node(inData, nullptr, nullptr);
			}
			else if (inData < inNode->data)
			{
				Insert(inData, inNode->left);
			}
			else if (inNode->data < inData)
			{
				Insert(indata, inNode->right)
			}
			else
				//duplicat do nothing
		}
		Node * FindMaximum() const;
		Node * FindMinimum() const;
	};
}
