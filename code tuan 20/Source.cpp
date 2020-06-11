#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;

typedef struct student
{
	int id;
	string name;
	int day;
	int month;
	int year;
	//
	string From;
	struct student *next;
} Student;
/*
Input: name of input file
Output: name
Objecvtive: read input file and create student list 
which contains information corresponding.
*/

Student *readInput(const char *sFilename)
{
	string line;
	bool t = false;
	ifstream myfile(sFilename);
	Student *stu = NULL, *tmp = NULL;

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (t && (line.length() > 0))
			{
				//cout << line << endl;
				stu = new Student();
				stringstream degree(line.substr(0, line.find("\t")));
				degree >> stu->id;
				stu->name = line.substr(line.find("\t") + 1);
				//cout << stu->id << "-" << stu->name << endl;
				stu->next = tmp;
				tmp = stu;
			}
			if (line.find("Student") != std::string::npos)
				t = true;
		}
		myfile.close();
	}

	else
		cout << "Unable to open file";
	return stu;
}

void printStudentList(Student *list)
{
	Student *stu = list;
	while (stu != NULL)
	{
		cout << stu->id << " - " << stu->name << endl;
		stu = stu->next;
	}
}

void testID(Student *list)
{
	for (Student *p = list; p != NULL; p = p->next)
		for (Student *q = p->next; q != NULL; q = q->next)
		{
			bool flag = false;
			if (p->id == q->id || p->name == q->name && p->day == q->day && p->month == q->month && p->year == q->year)
			{
				cout << q->id << " - " << q->name << endl;
				flag = true;
			}
			if (flag)
				cout << p->id << " - " << p->name << endl;
		}
}

void rearrangeStudent(Student *list)
{
	Student *p, *q;
	string tmp;
	if ((!list) || !list->next)
		return;
	p = list;
	q = list->next;
	while (q)
	{
		tmp = p->name;
		p->name = q->name;
		q->name = tmp;

		p = q->next;
		q = p ? p->next : 0;
	}
}
void Search(Student *list, string Name)
{
	Student *p, *q;
	string tmp;
	if ((!list) || !list->next)
		return;
	p = list;
	q = list->next;
	while (q == NULL)
	{
		if (q->name == Name)
		{
			cout << p->id << " " << p->name << endl;
			cout << p->next->id << " " << p->next->name << endl;
			break;
		}
		p = p->next;
		q = q->next;
	}
}
void deleteNode(Student *list, string name)
{
	for (Student *p = list; p != NULL; p = p->next)
		if (p->next->name == name)
		{
			p->next = p->next->next;
			return;
		}
}

Student *addNode(Student *list, int id, string name)
{
	int k = 1;
	Student *p = list;
	Student *q;
	q = new Student;
	q->id = id;
	q->name = name;
	while (p != NULL && k != id)
	{
		p = p->next;
		++k;
	}
	if (k != id)
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = q;
	}
	else
	{
		q->next = p->next;
		p->next = q;
	}
	return list;
}

void deleteNode(Student *list, int id)
{
	for (Student *p = list; p != NULL; p = p->next)
		if (p->next->id == id)
		{
			p->next = p->next->next;
			return;
		}
}

void demo()
{
	Student *stuList = readInput("demo7Input1.txt");

	/*printStudentList(stuList); // print list student
	rearrangeStudent(stuList);
	cout << "--------------" << endl;
	printStudentList(stuList); // print list
	cout << "--------------" << endl;
	testID(stuList);
	cout << "--------------" << endl;

	deleteNode(stuList, "Cao Thanh Binh");
	printStudentList(stuList);

	deleteNode(stuList, 12);
	cout << "--------------" << endl;
	printStudentList(stuList);*/
	Search(stuList, " Cao Thanh Binh");
}
int main()
{
	demo();
	cout << "End of program" << endl;
	system("pause");
	return 0;
}