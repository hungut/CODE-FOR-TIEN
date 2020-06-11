#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs;

struct node
{
  int data;
  node *next;
};

node *createLinkList(int n)
{
  node *head = NULL;
  node *tail = NULL;

  for (int i = 0; i < n; i++)
  {
    node *p = new node;
    int temp2;
    ifs >> temp2;
    p->data = temp2;
    p->next = NULL;
    if (head == NULL)
    {
      head = tail = p;
    }
    else
    {
      p->next = head;
      head = p;
    }
  }
  return head;
}

void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << endl;
    head = head->next;
  }
}

int main(int narg, char **argv)
{
  ifs.open(argv[1]);

  int n = 0;
  ifs >> n;
  if (n > 0)
  {
    node *head = createLinkList(n);
    print(head);
  }
  else
  {
    cout << "Invalid n" << endl;
  }

  ifs.close();
  return 0;
}
