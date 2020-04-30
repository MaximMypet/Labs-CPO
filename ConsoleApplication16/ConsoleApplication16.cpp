#include <iostream>
using namespace std;

struct TreeElement
{
	int value;
	TreeElement* right;
	TreeElement* left;

	TreeElement()
	{
		value = -1;
		right = NULL;
		left = NULL;
	}
};
struct spis {
	int value;
	spis* pointer;
	spis() {
		value = 0;
		pointer = NULL;
	}
};

void Input(TreeElement*& el, int v)
{
	if (el == NULL)
	{
		el = new TreeElement();
		el->value = v;
	}
	else if (el->value > v)
	{
		Input(el->left, v);
	}
	else if (el->value < v)
	{
		Input(el->right, v);
	}
}
void Output(TreeElement* el)
{
	if (el != NULL)
	{
		Output(el->left);
		cout << el->value << " ";
		Output(el->right);
	}
}
void Spisok(spis*& head, TreeElement* el, spis*& p)
{
    if (el != NULL)
    {
        Spisok(head, el->left, p);
        spis* p1 = new spis;
        p1->value = el->value;
        if (p == NULL)
        {
            head = p1;
            p = p1;
        }
        else
        {
            p->pointer = p1;
            p = p1;
        }
        Spisok(head, el->right, p);
    }
}

void Out(spis* l) {
    cout << "Spisok: ";
    while (l != NULL) {
        cout << l->value << " ";
        l = l->pointer;
    }
    cout << endl;
}
void Detach(TreeElement * root, TreeElement * el)
	{
		if (root == NULL || el == NULL)
		{
			return;
		}
		else if (root->left == el)
		{
			root->left = NULL;
		}
		else if (root->right == el)
		{
			root->right = NULL;
		}
		{
			Detach(root->left, el);
			Detach(root->right, el);
		}
	}
	
	TreeElement* Find(TreeElement* el, int v)
	{
		TreeElement* result = NULL;
		if (el == NULL) { result = NULL; }
		else if (el->value == v) { result = el; }
		else
		{
			result = Find(el->left, v);
			if (result == NULL) { result = Find(el->right, v); }
		}
		return result;
	}
	void Remove(TreeElement* el)
	{
		if (el != NULL) {
			Remove(el->left);
			Remove(el->right);
			delete el;
		};
	}
int main() {
	        spis* first = NULL;
	        spis* two = NULL;
			TreeElement* root = NULL;
			int x, y;
			cout << "Vvedite kol-vo elementov dereva:  ";
			cin >> y;
			cout << "Vvedite element dereva:  ";
			for (int i = 0; i < y; i++) {
				cin >> x;
				Input(root, x);
			}
			Output(root);
			cout << endl;
			Spisok(first, root, two);
			Out(first);

			int b;
			cout << "Vvedite element, kotorui xotite udalit':  ";
			cin >> b;
			TreeElement* e = Find(root, b);
			Detach(root,e);
			Remove(e);
			Output(root);
			cout << endl;
			TreeElement* e1 = Find(root, b);
			Detach(root, e1);
			Remove(e1);
			Output(root);
			cout << endl;
			system("pause");
		}
