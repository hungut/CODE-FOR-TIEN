#include <iostream>
#include <math.h>
#include <string>
using namespace std;
typedef struct tagNode
{
    char Data;
	float Value;
    struct tagNode *pNext;
}Node;
Node *createNode(char x);
struct STACK
{
    Node *pTop;
    Node *pBot;
};
void createStack(STACK &s);
int IsEmpty(STACK& s);
void Push(STACK& s, Node* temp);
char Pop(STACK& s, char& trave);
float PopValue(STACK& s, float& trave);
int Priority(char a);
string DeleteBlank(string src);
void swap(string& str, int a, int b);
void printList(STACK& s);
void IntoPost(STACK& s, string str, char result[], int& j);
void DoMath(STACK& s, string str, int n);
Node* createStack(char x);
Node* createStackValue(float x);
int main()
{
    STACK s;
	Node* p;
	int i, j = 0;
	char result[50];
	string BieuThuc;
	createStack(s);
	flag:
	int mo_ngoac = 0, dong_ngoac = 0;
	cout << "nhap bieu thuc: ";
	getline(cin, BieuThuc);
	DeleteBlank(BieuThuc);
	for (i = 0; i < BieuThuc.length(); i++)
	{
		if (BieuThuc[i] == '(')
			mo_ngoac++;
		if (BieuThuc[i] == ')')
			dong_ngoac++;
		if (BieuThuc[i] != '+' && BieuThuc[i] != '-' && BieuThuc[i] != '*' && BieuThuc[i] != '/' && (BieuThuc[i] < 48 || BieuThuc[i] >57))
		{
			cout << "phat hien tu khoa khong hop le \nnhap lai ";
			goto flag;
		}
	}
	if (mo_ngoac != dong_ngoac)
	{
		cout << "nhap thieu ngoac" << endl;
		goto flag;
	}
	cout << BieuThuc << endl;
	IntoPost(s, BieuThuc, result, j);
	for (i = 0; i < j; i++)
		cout << result[i];
	cout << endl;
	DoMath(s, result, j);
    system("pause");
    return 0;
}

int Priority(char a){
	if (a == '+' || a == '-')
		return 1;
	if (a == '*' || a == '/')
		return 2;
	if (a == '^')
		return 3;
	return 0;
}
string DeleteBlank(string str){
    for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			for (int j = i ; j < str.length(); j++)
			{
				if (str[j] != ' ')
				{
					swap(str, i, j);
					break;
				}
			}
		}
	}
    return str;  
}
void swap(string& str, int a, int b)
{
	char temp;
	temp = str[a];
	str[a] = str[b];
	str[b] = temp;
}
Node *createNode(char x)
{
    Node *p;
    p = new Node;
    if (p == NULL) exit(1);
    p->Data = x;
    p->pNext = NULL;
    return p;
}
int IsEmpty(STACK& s)
{
	if (s.pTop == NULL)
		return 1;
	else
		return 0;
}
int IsFull(Node& p)
{
	if (p.pNext == NULL)
		return 1;
	else
		return 0;
}
Node* createStack(char x)
{
	Node* p;
	p = new Node;
	if (p == NULL) exit(1);
	p->Data = x;
	p->pNext = NULL;
	return p;
}
Node* createStackValue(float x)
{
	Node* p;
	p = new Node;
	if (p == NULL) exit(1);
	p->Value = x;
	p->pNext = NULL;
	return p;
}
void Push(STACK& s, Node* temp)
{
	if (s.pTop == NULL)
	{
		s.pTop = temp;
		s.pBot = temp;
	}
	else
	{
		temp->pNext = s.pTop;
		s.pTop = temp;
	}
}
char Pop(STACK& s, char& trave)
{
	Node* p;
	if (IsEmpty(s) != 1)
	{
		p = s.pTop;
		trave = p->Data;
		s.pTop = s.pTop->pNext;
		if (s.pTop == NULL)
			s.pBot = NULL;
		delete p;
		return trave;
	}
	return 0;
}
float PopValue(STACK& s, float& trave)
{
	Node* p;
	if (IsEmpty(s) != 1)
	{
		p = s.pTop;
		trave = p->Value;
		s.pTop = s.pTop->pNext;
		if (s.pTop == NULL)
			s.pBot = NULL;
		delete p;
		return trave;
	}
	return 0;
}
void createStack(STACK &s)
{
    s.pTop = NULL;
    s.pBot = NULL;
}
void printList(STACK& s)
{
	Node* p;
	p = s.pTop;
	while (p != NULL)
	{
		cout << p->Data;
		p = p->pNext;
	}
	cout << "\n";
}
void IntoPost(STACK& s, string str, char result[], int& j)
{
	Node* p;
	char temp;
	int i;
	for (i = 0; i < str.length(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
		{
			result[j] = ' ';
			j++;
			if (IsEmpty(s) == 1)
			{
				p = createStack(str[i]);
				Push(s, p);
			}
			else
			{
				if (s.pTop->Data == '(')
				{
					p = createStack(str[i]);
					Push(s, p);
				}
				else
				{
					if ((Priority(str[i]) <= Priority(s.pTop->Data)))
					{
						result[j] = Pop(s, temp);
						p = createStack(str[i]);
						Push(s, p);
						j++;
					}
					else
					{
						p = createStack(str[i]);
						Push(s, p);
					}
				}
			}
		}
		if (str[i] == '(')
		{
			p = createStack(str[i]);
			Push(s, p);
		}
		if (str[i] == ')')
		{
			while (s.pTop->Data != '(')
			{
				result[j] = Pop(s, temp);
				j++;
			}
			Pop(s, temp);
		}
		if (str[i] > 47 && str[i] < 58)
		{
			result[j] = str[i];
			j++;
		}
	}
	while (s.pTop != NULL)
	{
		result[j] = Pop(s, temp);
		j++;
	}
	printList(s);
}
void DoMath(STACK& s, string str, int n)
{
	Node* p;
	int i, j;
	float x, temp = 0;
	for (i = 0; i < n; i++)
	{
		if (str[i] > 47 && str[i] < 58)
		{
			temp = temp * 10 + (str[i] - '0');
			if (i + 1 == n)
			{
				p = createStackValue(temp);
				Push(s, p);
			}
		}
		else
		{
			if (str[i - 1] > 47 && str[i - 1] < 58)
			{
				p = createStackValue(temp);
				Push(s, p);
				temp = 0;
			}
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
		{
			switch (str[i])
			{
			case '+':
			{
				temp = PopValue(s, x) + PopValue(s, x);
				cout << temp << endl;
				p = createStackValue(temp);
				Push(s, p);
			}; break;
			case '-':
			{
				temp = - PopValue(s, x) + PopValue(s, x);
				cout << temp << endl;
				p = createStackValue(temp);
				Push(s, p);
			}; break;
			case '*':
			{
				temp = PopValue(s, x) * PopValue(s, x);
				cout << temp << endl;
				p = createStackValue(temp);
				Push(s, p);
			}; break;
			case '/':
			{
				temp = 1 / (PopValue(s, x) / PopValue(s, x));
				cout << temp << endl;
				p = createStackValue(temp);
				Push(s, p);
			}; break;
			case '^':
			{
				temp = PopValue(s, x);
				temp = pow(PopValue(s, x), temp);
				cout << temp << endl;
				p = createStackValue(temp);
				Push(s, p);
			}; break;
			}
			temp = 0;
		}
	}
	cout << "ket qua : " << PopValue(s, x) << endl;
}
