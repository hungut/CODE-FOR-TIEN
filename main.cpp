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
      tail->next = p;
      tail = p;
    }
  }
  return head;
}

node *insertNode(node *head, node *newNode, int position)
{
  //node *Head = NULL;
  if (position <= 0)
    return head;
  else
  {
    if (position != 1)
    {
      int k = 1;
      node *p = head;
      while (p != NULL & k != position - 1)
      {
        p = p->next;
        ++k;
      }

      if (k == position - 1)
      {
        newNode->next = p->next;
        p->next = newNode;
      }
      else
      {
        while (p->next != NULL)
        {
          p = p->next;
        }
        p->next = newNode;
      }
    }
    if (position == 1)
    {
      //node *p = head;
      newNode->next = head;
      head = newNode;
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

    node *newNode = new node();
    ifs >> newNode->data;
    int position = 0;
    ifs >> position;
    head = insertNode(head, newNode, position);

    print(head);
  }
  else
  {
    cout << "Invalid n" << endl;
  }

  ifs.close();
  return 0;
}
