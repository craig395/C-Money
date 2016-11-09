#include "Node.h"



Node::Node(unsigned int value)
{
	nextNode = nullptr;
	Node::value = value;
}

Node::Node(unsigned int value, Node * nextNode)
{
	Node::Node(value);
	Node::nextNode = nextNode;
}


Node::~Node()
{
	if (nextNode != nullptr)
	{
		delete nextNode;
	}
}

Node * Node::GetNextNode()
{
	return nextNode;
}

void Node::DeleteNextNode()
{
	delete nextNode;
	nextNode = nullptr;
}

void Node::SetNextNode(Node * nextNode)
{
	if (nextNode != nullptr) 
	{
		Node::nextNode == nextNode;
	}
}

unsigned int Node::Getvalue()
{
	return value;
}

void Node::setValue(unsigned int value)
{
	Node::value = value;
}
