#include "BinaryTree.h"

void BinaryTree::addMethod_(Node* node, const int& data)
{
	if (node->getData() > data)
	{
		if (node->getLeft() != nullptr)
		{
			addMethod_(node->getLeft(), data);
		}
		else
		{
			Node* newNode = new Node(data);
			node->setLeft(newNode);
		}
	}
	else if (node->getData() < data)
	{
		if (node->getRight() != nullptr)
		{
			addMethod_(node->getRight(), data);
		}
		else
		{
			Node* newNode = new Node(data);
			node->setRight(newNode);
		}
	}
	else
	{
		throw exception("Try to add data, that already contained");
	}
}

Node* BinaryTree::getStrictNode_(Node* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->isBothEmpty() || !node->isLeftEmpty() && !node->isRightEmpty())
	{
		return node;
	}
	if (node->isLeftEmpty())
	{
		return getStrictNode_(node->getRight());
	}
	return getStrictNode_(node->getLeft());
}


BinaryTree::BinaryTree() : head_(nullptr)
{
}

bool BinaryTree::isEmpty() const
{
	return head_ == nullptr;
}

void BinaryTree::add(const int& data)
{
	if (isEmpty())
	{
		head_ = new Node(data);
		return;
	}
	addMethod_(head_, data);
}

void BinaryTree::toStrict()
{
	if (head_->isBothNotEmpty())
	{
		strictMethod_(head_);
	}
	else
	{
		head_->setRight(nullptr);
		head_->setLeft(nullptr);
	}
}

void BinaryTree::print(const int& spaceBefore, const int& spaceBetween)
{
	printMethod_(head_, spaceBefore, spaceBetween);
}

void BinaryTree::strictMethod_(Node* previousNode)
{
	if (previousNode == nullptr || previousNode->isBothEmpty())
	{
		return;
	}

	Node* right = previousNode->getRight();
	Node* left = previousNode->getLeft();

	Node* response = getStrictNode_(right);
	if (response == right && previousNode->isLeftEmpty())
	{
		previousNode->setRight(nullptr);
	}
	else
	{
		if (response == nullptr)
		{
			previousNode->setRight(response);
		}
		else
		{
			if (response->isBothNotEmpty())
			{
				previousNode->setRight(response);
			}
		}
	}

	response = getStrictNode_(left);
	if (response == left && previousNode->isRightEmpty())
	{
		previousNode->setLeft(nullptr);
	}
	else
	{
		if (response == nullptr)
		{
			previousNode->setLeft(response);
		}
		else
		{
			if (response->isBothNotEmpty())
			{
				previousNode->setLeft(response);
			}
		}
	}
	strictMethod_(previousNode->getLeft());
	strictMethod_(previousNode->getRight());
}

void BinaryTree::printMethod_(Node* root, int spaceBefore, const int& spaceBetween)
{
	if (root == nullptr)
		return;

	spaceBefore += spaceBetween;

	printMethod_(root->getRight(), spaceBefore, spaceBetween);

	cout << endl;
	for (int i = spaceBetween; i < spaceBefore; i++)
		cout << " ";
	cout << root->getData() << "\n";

	printMethod_(root->getLeft(), spaceBefore, spaceBetween);
}
