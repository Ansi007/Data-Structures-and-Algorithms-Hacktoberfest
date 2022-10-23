# include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Student
{
friend class StudentList;
private:
	int id; //id of a student.
	string name; //name of a student.
	float cgpa; //cgpa of a student.
	Student* next; //address of the next available object.
public:
	Student(int id, string name, float cgpa, Student* next)
	{
		this->id = id;
		this->name = name;
		this->cgpa = cgpa;
		this->next = next;
	}//constructor
	void studentDetails() //displays the student informaton
	{
		cout << "ID :" << id << endl;
		cout << "Name :" << name << endl;
		cout << "CGPA :" << cgpa << endl;
		cout << "\n--------------------\n";
		
	}
};
class StudentList
{
private:
	Student* head; //start of the list
	Student* cursor; //current item of the list
public:
	StudentList() //constructor
	{
		head = NULL;
		cursor = NULL;

	}
	void insert(const Student& newStd)
	{
		Student* ptr = new Student(newStd.id, newStd.name, newStd.cgpa, NULL);
		//When no node is present
		if (head == NULL)
		{
			head = ptr;
			cursor = ptr;

		}
		

		else
		{
			Student* temp = head;
			while (temp != cursor)
			{
				temp = temp->next;

			}
			
			if (cursor->next == NULL)
			{
				cursor->next = ptr;
				ptr->next = NULL;
				cursor = ptr;
			}
			else {
				ptr->next = cursor->next;
				cursor->next = ptr;
				cursor = ptr;
			}

		}
	}




	bool isEmpty()
	{
		if (head == NULL)
			return true;
		return false;
	}
	void gotoBeginning()
	{
		cursor = head;
	}
	void gotoEnd()
	{
		Student* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		cursor = temp;
	}
	bool gotoNext()
	{
		if (cursor->next != NULL)
		{
			cursor = cursor->next;
			return true;
		}
		else
			return false;
	}
	bool gotoPrior()
	{
		if (cursor != head)
		{
			Student* temp = head;
			while (temp->next != cursor)
			{
				temp = temp->next;

			}
			cursor = temp;
			return true;
			
		}
		return false;

	}

	Student* getCursor()
	{
		return cursor;
	}

	void showStructure()
	{
		Student* temp = head;

		while (temp != NULL)
		{
			

			temp->studentDetails();
			temp = temp->next;
		}
	}

	void search(float cgpa)
	{
		Student* temp=head;
		while (temp != NULL)
		{
			if (temp->cgpa == cgpa)
			{
				temp->studentDetails();
				return;
			}
			temp = temp->next;
		}
		if(temp==NULL)
		cout << " NO Matching cgpa found" << endl;
	}


	void replace(const Student& newStd)
	{
		Student* ptr = new Student(newStd.id, newStd.name, newStd.cgpa, NULL);
		Student* temp = head;
		Student* prev = head;
		while (temp != NULL)
		{
			if (temp->id == newStd.id)
			{
				temp->id = newStd.id;
				temp->name = newStd.name;
				temp->cgpa = newStd.cgpa;
				return;

			}
			prev = temp;
			temp = temp->next;

		}

		if (prev)
		{
			prev->next = ptr;
			ptr->next = NULL;
		}

	}
	
	
	
	
	
	
	
	
	
	
	void remove(int id)
	{
		Student* temp = head;
		Student* pre = head;
		while (temp != NULL && temp->id != id)
		{
			pre = temp;
			temp = temp->next;

		}
		if (temp == cursor)       // if the node to be deleted has cursor and temp on the same position
		{
			if (temp == head)
			{
				head = head->next;				//delete AT start
				cursor = cursor->next;
				//temp = temp->next;
				delete temp;
													
			}
			else if (temp->next != NULL)		//delte any nod eat middle 
			{
				pre->next = temp->next;
				cursor = cursor->next;
				delete temp;

			}
			else if (temp->next == NULL)     //delete at last
			{
				cursor = head;
				pre->next = NULL;
				delete temp;

			}


		}
		else if (temp != cursor && temp != NULL)
		{
			if (temp == head)
			{
					head = head->next;				//delete AT start
					//temp = temp->next;
					delete temp;
			
			}

			else if (temp->next != NULL)
			{
				pre->next = temp->next;
				delete temp;
			}

			else if (temp->next == NULL)
			{
				pre->next = NULL;
				delete temp;
			}
		}

		else
		{
			cout << "ID not Matched:" << endl;
		}


	}







	~StudentList() //destructor
	{
		Student*temp=head;
		while(head!=NULL)
		{
			head=head->next;
			delete temp;
			temp=head;
		}
	}
	
};

int main()
{
	
	StudentList obj;
	ifstream file;
	file.open("input.txt");
	if (!file)
		return -1;
	int id;
	string st;
	float cgpa;
	while (true) {
		file >> id;
		file.ignore();
		getline(file, st);
		file >> cgpa;
		obj.insert(Student(id, st, cgpa, NULL));
		if (file.eof())
			break;
	}
	obj.showStructure();
	obj.insert(Student(2, "Aqib", 3.5, NULL));
	obj.insert(Student(4, "Ahmad", 3.6, NULL));
	obj.insert(Student(7, "Junaid", 3.4, NULL));
	obj.showStructure();
	obj.gotoBeginning();
	Student *s1 = obj.getCursor();
	s1->studentDetails();
	obj.gotoNext();
	obj.gotoPrior();
	s1 = obj.getCursor();
	s1->studentDetails();
	obj.search(3.6);
	obj.search(4.0);
	obj.replace(Student(1, "Shabbir", 3.3, NULL));
	obj.showStructure();
	obj.remove(9);
	
	cout<<"\n===============================================\n";
	
	obj.showStructure();

	return 0;
}
