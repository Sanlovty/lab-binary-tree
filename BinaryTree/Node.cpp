#include "Node.h"

Node::Node() : data_(int()), left_(nullptr), right_(nullptr)
{
}

Node::Node(const int& data) : data_(data), left_(nullptr), right_(nullptr)
{
}

Node::Node(const int& data, Node* left, Node* right): data_(data), left_(left), right_(right)
{
}

Node::Node(const int& data, Node& left, Node& right): data_(data), left_(&left), right_(&right)
{
}

bool Node::isLeftEmpty() const
{
	return left_ == nullptr;
}

bool Node::isRightEmpty() const
{
	return right_ == nullptr;
}

bool Node::isBothEmpty() const
{
	return left_ == nullptr && right_ == nullptr;
}

bool Node::isBothNotEmpty() const
{
	return left_ != nullptr && right_ != nullptr;
}

int Node::getData() const
{
	return data_;
}

Node* Node::getLeft() const
{
	return left_;
}

Node* Node::getRight() const
{
	return right_;
}

void Node::setData(const int& data)
{
	data_ = data;
}

void Node::setLeft(Node* left)
{
	left_ = left;
}

void Node::setLeft(Node& left)
{
	left_ = &left;
}

void Node::setRight(Node* right)
{
	right_ = right;
}

void Node::setRight(Node& right)
{
	right_ = &right;
}
