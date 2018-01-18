#define MAX 20

int count=0;

struct node
{
	char data;
	bool isEndOfString;
	node *left, *eq, *right;
};

node* newnode(char data)
{
	node* temp = new node;
	temp->data = data;
	temp->isEndOfString = false;
	temp->left = temp->eq = temp->right = NULL;
	return temp;
}

void insert(node** root, char *word)
{
	if (!(*root))
		*root = newnode(*word);

	if ((*word) < (*root)->data)
		insert(&( (*root)->left ), word);
	else if ((*word) > (*root)->data)
		insert(&( (*root)->right ), word);
	else
	{
		if (*(word+1))
		insert(&( (*root)->eq ), word+1);
        else
		(*root)->isEndOfString = true;
	}
}

int search(node *root, char *word)
{
	if (!root)
		return 0;

	if (*word < (root)->data)
		return search(root->left, word);

	else if (*word > (root)->data)
		return search(root->right, word);

	else
	{
		if (*(word+1) == '\0')
			return root->isEndOfString;
		return search(root->eq, word+1);
	}
}

