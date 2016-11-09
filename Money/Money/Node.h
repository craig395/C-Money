#pragma once
class Node//TODO: make a template type
{
private:
	Node* nextNode;
	unsigned int value;
public:
	Node(unsigned int value);
	Node(unsigned int value, Node* nextNode);
	~Node();
	Node* GetNextNode();
	void DeleteNextNode();
	void SetNextNode(Node* nextNode);
	unsigned int Getvalue();
	void setValue(unsigned int value);
};

