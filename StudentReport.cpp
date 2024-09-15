#include <iostream>
#include <random>

using namespace std;

// 1. create student database + allow user input:
// 						name, class, roll number, attendance, marks/subject

string SUBJECTS[10] = {"Mathematics", "English", "Science", "History", "Geography", "Art", "Physical Education", "Biology", "Chemistry", "Physics"};
string names[100] = {"John Smith", "Jane Doe", "Emily Davis", "Michael Johnson", "Sarah Brown",
                        "David Wilson", "Laura Taylor", "James Anderson", "Emma Moore", "Daniel Harris",
                        "Olivia Martin", "Matthew Thompson", "Sophia Garcia", "Lucas Martinez", "Isabella Rodriguez",
                        "Ethan Lee", "Mia Gonzalez", "Alexander Perez", "Ava Wilson", "Liam Nguyen",
                        "Charlotte White", "Benjamin Hall", "Amelia Young", "Jacob King", "Harper Scott",
                        "William Adams", "Evelyn Nelson", "Jack Baker", "Ella Carter", "Henry Mitchell",
                        "Abigail Clark", "Samuel Lewis", "Chloe Robinson", "Isaac Walker", "Aria Young",
                        "Oliver Phillips", "Sofia Evans", "Mason Turner", "Lily Anderson", "Logan Hernandez",
                        "Zoe Lopez", "James Harris", "Grace Stewart", "Elijah Morris", "Hannah Murphy",
                        "Sebastian Collins", "Nora Reed", "Jack Murphy", "Mila Rivera", "Aiden Martinez",
                        "Ella Murphy", "Lucas Rogers", "Scarlett Cox", "Gabriel Hughes", "Avery Wood",
                        "Daniel Martinez", "Sophie Gray", "Wyatt Foster", "Luna Adams", "Julian Lee",
                        "Alice Baker", "Christian Ward", "Victoria Adams", "Landon Evans", "Madison Brooks",
                        "Henry Cooper", "Ella Allen", "Owen Ward", "Camila Clark", "James Scott",
                        "Layla Young", "David Green", "Penelope Hill", "Gavin Bell", "Aria Lewis",
                        "Jaxon Young", "Stella Nelson", "Micheal Hill", "Ellie Walker", "Jackson Adams"};


struct Student{
	string name;
	string class_id;
	int roll_number;
	double attendance;//0.8, 0.9, etc
	//string parent_name;
	string marks[8][2];
	Student * next;
};

//create students and create database for storage (linked list)

Student * createStudent(string name, string class_id, int roll_number, double attendance){
	Student * newStudent = new Student;
	newStudent->name = name;
	newStudent->class_id = class_id;
	newStudent->roll_number = roll_number;
	newStudent->attendance = attendance;
	newStudent->next = nullptr;
return newStudent;
}

Student * insertStudent(Student * student_top, string name, string class_id, int roll_number, double attendance){
	Student * newStudent = createStudent(name, class_id, roll_number, attendance);
	newStudent->next = student_top;
	return newStudent;
}

// 2. parents can view data saved by inputing roll# and name

void displayStudent(Student * student){
	cout << "\nName: " << student->name << "\nClass: " << student->class_id << "\nRoll number: " << student->roll_number << "\nAttendance: " << student->attendance << endl << endl;
}

void displayAllStudents(Student * top_student){
	while(top_student!=nullptr){
		displayStudent(top_student);
		top_student = top_student->next;
	}
}

double generateRandomDecimal(double min, double max) {
    double range = max - min;
    double random = (double)rand() / RAND_MAX;  // Random number between 0 and 1
    return min + (random * range);  // Scale and shift to the desired range
}

Student * createRandomData(){
	
	string name = "Joshua Sankar";
	string class_id = "Form1A";
	int roll_number = 110011;
	double attendance = 0.8;
	
	Student * student = createStudent(name, class_id, roll_number, attendance);
	string cid;
	string letters[5] = {"A", "B", "C", "D", "E"};
	int rollnum; 
	
	for(int i = 0; i<100; i++){
		cid="Form";
		cid += to_string(rand()%6+1) + letters[rand()%5];
		
		rollnum = rand() % 10000;
		attendance = generateRandomDecimal(0.0, 1.0);
		student = insertStudent(student, names[i], cid, rollnum, attendance);
		cid="";
	}
	return student;
}

//search for student
void prompt(Student * top_student){
	string stud_fullname;
	Student * curr = top_student;
	
	string name;
	string class_id;
	int rollnumber;
	double attendance;
	string option;
	bool found=false;
	
	while(true){
		cout << "Enter stop to stop" << endl;
		cout << "Please enter name of Student: eg: Joshua Sankar: ";
		cout << "Or enter 'add' to add new Student";
		getline(cin, stud_fullname);
		
		if(stud_fullname == "add"){
			while(true){
				cout << "Enter Student Name: ";
				getline(cin, name);
				cout << "Enter Class, eg 'Form 1,2,3 et.: ";
				cin >> class_id;
				cout << "Enter attendance: ";
				cin >> attendance;
				Student * newStudent = createStudent(name, class_id, rollnumber, attendance);
				cout << "\nStudent created: " << endl;
				displayStudent(newStudent);
				cout << "Would you like to create another student? Y/N";
				cin >> option;
				if(option=="N")
					return;
				else
					continue;
			}
		}
		
		while(curr!=nullptr){
			if(stud_fullname=="stop"){
				cout << "Program Stopped";
				exit(1);
			}
			else if(curr->name == stud_fullname){
				displayStudent(curr);
				found = true;
			}
			else if(curr==nullptr && found==false)
				cout << "\nStudent not found, Please Re-enter" << endl;
			curr = curr->next;
		}
		curr = top_student;
	}
	
}

int main(){
	
	Student * student = createRandomData();
	displayAllStudents(student);
	prompt(student);
	
return 0;
}