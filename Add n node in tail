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
