#include <stdio.h>
#include <stdlib.h>

int cnt = 0;

typedef struct B_Node {
	//노드 초기 설정
	int data;

	struct B_Node* left;
	struct B_Node* right;


} NODE;


NODE* plus_node(void) //노드 동적할당
{
	NODE* newNode = calloc(1, sizeof(NODE));

	newNode->data = 0;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
	
}

void setup(NODE* node, int data, NODE* leftchild, NODE* rightchild)
{
	node->data = data;
	node->left = leftchild;
	node->right = rightchild;

	
}

NODE* addNode(NODE* node, int data)
{
	cnt++;

	if (node == NULL)
	{
		node = plus_node();
		setup(node, data, NULL, NULL);
		

		
		//노드 생성 완료 

	}

	else if (data == node->data)
	{
		return node;
	}

	else if (data < node->data)
	{	
		
		node->left = addNode(node->left, data);
		//left 생성
	}

	else if (data > node->data)
	{
		//right 생성
		
		node->right = addNode(node->right, data);
	}

	

	return node;
}


int main() {


	int a, b, c, d, e, f;

	scanf_s("%d", &a);
	
	
	
	struct B_Node* start = (struct B_Node*)malloc(sizeof(struct B_Node));

	start->data = a;
	start->left = NULL;
	start->right = NULL;

	printf("%d\n\n", cnt);

	scanf_s("%d", &b);

	
	addNode(start, b);

	

	scanf_s("%d", &c);
	
	addNode(start, c);
	

	scanf_s("%d", &d);
	
	addNode(start, d);
	
	

	return 0;
}

