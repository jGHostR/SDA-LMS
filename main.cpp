//SDA PROJECT
//GROUP 9
//SALMAN AHMAD 20L-2197
//IBRAR ALI 20L-2125
#include<iostream>
#include <fstream>
#include<string>
using namespace std;

class User
{
	string name;
	string userName;
	string password;
public:
	User()
	{
		name = ' ';
		userName = ' ';
		password = ' ';
	}
	void set_User(string n, string u, string pass)
	{
		name = n;
		userName = u;
		password = pass;
	}
	string getName()
	{
		return name;
	}
	void printUser()
	{
		cout << name << " " << userName << " " << password;
	}
};

class CLO
{
	int cloID;
	string clo_D;
public:
	fstream clo;
	CLO()
	{
		cloID = 0;
		clo_D = ' ';
	}
	int getCLO()
	{
		return cloID;
	}
	void addCLO(int courseID, int id, string c)
	{
		/*int i;
		string d;
		int coID;
		clo.open("CLO.txt");
		while (!clo.eof())
		{
			clo >> i;
			clo >> d;
			if (id == i)
			{
				cout << "CLO ID already exists";
				return;
			}*/
			/*else
			{
				cloID = i;
				clo_D = d;
				fin3 << endl << coID << " " << i;
			}*/
			/*}*/
			/*if (clo.eof())
			{
				cloID = id;
				clo_D = c;
				clo  << id << " " << c;
			}*/
		clo.open("CLO.txt", ios::app);
		clo << endl << courseID << " " << id << " " << c;
	}
	void delCLO(int coid, int clid)
	{
		int coID, cloID;
		string d;
		ifstream fin1;
		ofstream fout1;
		fout1.open("temp.txt", ios::out | ios::app);
		fin1.open("CLO.txt");


		while (!fin1.eof())
		{
			fin1 >> coID;
			fin1 >> cloID;
			fin1 >> d;
			if (coID == coid && cloID != clid)
			{
				fout1 << coID << " " << cloID << " " << d;
				fout1 << endl;
			}
		}
		fin1.close();
		fout1.close();

		remove("CLO.txt");
		rename("temp.txt", "CLO.txt");
	}
	void CLOUpdate(string d)
	{
		this->clo_D = d;
		int coID, clid;
		string details;
		ifstream fin;
		ofstream fout;
		fout.open("temp.txt", ios::out | ios::app);

		fin.open("Courses.txt");

		while (!fin.eof())
		{
			fin >> coID;
			fin >> clid;
			fin >> details;
			if (clid)
			{
				fout << coID << " " << clid << " " << details;
				fout << endl;
			}
			if (details == d)
			{
				
				
				/*if (val_num == 1)
				{
					fin >> c_id;
					fin >> c_Title;
					c_Title = update;
					fin >> cred_h;
					fin >> pre_req;
					fin >> prog;

					fout << c_id << " " << c_Title << " " << cred_h << " " << pre_req << "  " << prog;
					fout << endl;
				}
				else if (val_num == 2)
				{
					fin >> c_id;
					fin >> c_Title;
					fin >> cred_h;
					fin >> pre_req;
					pre_req = update;
					fin >> prog;

					fout << c_id << " " << c_Title << " " << cred_h << " " << pre_req << "  " << prog;
					fout << endl;

				}
				else if (val_num == 3)
				{
					fin >> c_id;
					fin >> c_Title;
					fin >> cred_h;
					fin >> pre_req;
					fin >> prog;
					prog = update;

					fout << c_id << " " << c_Title << " " << cred_h << " " << pre_req << "  " << prog;
					fout << endl;
				}
				if (val_num == 4)
				{
					fin >> c_id;
					fin >> c_Title;
					fin >> cred_h;
					cred_h = cre_upd;
					fin >> pre_req;
					fin >> prog;

					fout << c_id << " " << c_Title << " " << cred_h << " " << pre_req << "  " << prog;
					fout << endl;
				}

			}*/
		}
		fin.close();
		fout.close();

		remove("Courses.txt");
		rename("temp.txt", "Courses.txt");
	}
	}
};

class Course
{
	CLO* cloptr;
	int cid;
	string title;
	int creditHours;
	string preReq;
	string Program;
	int cloCount;
public:
	fstream fin2;
	fstream read;
	fstream check;
	fstream read2;
	fstream read3;
	Course()
	{
		cid = 0;
		title = ' ';
		creditHours = 0;
		preReq = ' ';
		Program = ' ';
		cloCount = 0;
		cloptr = new CLO[5];
		/*int coid, clid;
		string d;
		int counter = 0;
		read2.open("CoursesCLO.txt");
		while (!read2.eof())
		{
			read2 >> coid;
			read2 >> clid;
			read2 >> d;
			cloptr[counter].addCLO(coid,clid, d);
			counter++;
		}*/
	}
	Course(int c, string ti, int cred, string pre, string prog)
	{
		cid = c;
		title = ti;
		creditHours = cred;
		preReq = pre;
		Program = prog;
		cloCount = 0;
		cloptr = new CLO[5];
		/*int coid, clid;
		string d;
		int counter = 0;
		read3.open("CLO.txt");
		while (!read3.eof())
		{
			read3 >> coid;
			read3 >> clid;
			read3 >> d;
			if(coid ==  this->cid)
			cloptr[clid].addCLO(coid, clid, d);
		}*/
	}
	int getCourseID()
	{
		return cid;
	}
	bool isCid(int cid)
	{
		int id, cred;
		string ti, pre, prog;
		check.open("Courses.txt");
		while (check.eof())
		{
			check >> id;
			check >> ti;
			check >> cred;
			check >> pre;
			check >> prog;
			if (cid == id)
			{
				check.close();
				return true;
			}
		}
		check.close();
		return false;
	}
	void addCourse()
	{
		fin2.open("Courses.txt", ios::app);
		fin2 << endl << cid << " " << title << " " << creditHours << " " << preReq << " " << Program;
		fin2.close();
	}
	void ReadCourses()
	{
		int id, cred;
		string ti, pre, prog;
		read.open("Courses.txt");
		read >> id;
		read >> ti;
		read >> cred;
		read >> pre;
		read >> prog;
		setCourse(id, ti, cred, pre, prog);
		read.close();
	}
	void setCourse(int c, string ti, int cred, string pre, string prog)
	{
		cid = c;
		title = ti;
		creditHours = cred;
		preReq = pre;
		Program = prog;
		cloptr = new CLO[5];
	}
	CLO* getCLOptr()
	{
		return cloptr;
	}
	void addCLO(int coid, int id, string c)
	{
		cloptr[id - 1].addCLO(coid, id, c);
	}

	void deleteCourse(int co)
	{
		string c_Title, pre_req, prog;
		int c_id, cred_h;
		ifstream fin6;
		ofstream fout6;
		fout6.open("temp.txt", ios::out);

		fin6.open("Courses.txt");

		while (!fin6.eof())
		{
			fin6 >> c_id;
			fin6 >> c_Title;
			fin6 >> cred_h;
			fin6 >> pre_req;
			fin6 >> prog;
			if (c_id != co)
			{
				fout6 << c_id << " " << c_Title << " " << cred_h << " " << pre_req << "  " << prog;
				fout6 << endl;
			}
		}
		fin6.close();
		fout6.close();

		remove("Courses.txt");
		rename("temp.txt", "Courses.txt");
	}
	void CoursedelCLO(int coID, int cloid)
	{
		cloptr[0].delCLO(coID, cloid);
	}
	void update_Course(int course_id, int val_num, string update, int cre_upd)
	{
		string c_Title, pre_req, prog;
		int c_id, cred_h;
		ifstream fin;
		ofstream fout;
		fout.open("temp.txt", ios::out | ios::app);

		fin.open("Courses.txt");

		while (!fin.eof())
		{
			fin >> c_id;
			fin >> c_Title;
			fin >> cred_h;
			fin >> pre_req;
			fin >> prog;
			if (c_id != course_id)
			{
				fout << c_id << " " << c_Title << " " << cred_h << " " << pre_req << "  " << prog;
				fout << endl;
			}
			if (c_id == course_id)
			{
				if (val_num == 1)
				{
					fin >> c_id;
					fin >> c_Title;
					c_Title = update;
					fin >> cred_h;
					fin >> pre_req;
					fin >> prog;

					fout << c_id << " " << c_Title << " " << cred_h << " " << pre_req << "  " << prog;
					fout << endl;
				}
				else if (val_num == 2)
				{
					fin >> c_id;
					fin >> c_Title;
					fin >> cred_h;
					fin >> pre_req;
					pre_req = update;
					fin >> prog;

					fout << c_id << " " << c_Title << " " << cred_h << " " << pre_req << "  " << prog;
					fout << endl;

				}
				else if (val_num == 3)
				{
					fin >> c_id;
					fin >> c_Title;
					fin >> cred_h;
					fin >> pre_req;
					fin >> prog;
					prog = update;

					fout << c_id << " " << c_Title << " " << cred_h << " " << pre_req << "  " << prog;
					fout << endl;
				}
				if (val_num == 4)
				{
					fin >> c_id;
					fin >> c_Title;
					fin >> cred_h;
					cred_h = cre_upd;
					fin >> pre_req;
					fin >> prog;

					fout << c_id << " " << c_Title << " " << cred_h << " " << pre_req << "  " << prog;
					fout << endl;
				}

			}
		}
		fin.close();
		fout.close();

		remove("Courses.txt");
		rename("temp.txt", "Courses.txt");
	}
	void cUpdateCLO(string d)
	{
		CLO c2;
		c2.CLOUpdate(d);
	}
};

class AcademicOfficer : public User
{
	int aoID;
	string name;
	Course* cptr;
public:
	fstream fin;
	fstream CFile;
	fstream CFile2;
	fstream ao;
	fstream del;
	fstream chk;
	fstream chk2;
	AcademicOfficer()
	{
		User AO;
		cptr = new Course[10];
		ao.open("Courses.txt");
		int i, cre;
		string t, pr, pro;
		int counter = 0;
		while (!ao.eof())
		{
			ao >> i;
			ao >> t;
			ao >> cre;
			ao >> pr;
			ao >> pro;
			cptr[counter].setCourse(i, t, cre, pr, pro);
			counter++;
		}
		ao.close();
	}
	AcademicOfficer(string n, string u, string pass)
	{
		fin.open("AcademicOfficer2.txt");
		set_User(n, u, pass);
		fin << n << " " << u << " " << pass;
		cptr = new Course[10];
		fin.close();
	}
	bool readFromFile(string u, string pass)
	{
		bool isFound = false;
		string line;
		string user, p;
		fin.open("AcademicOfficer2.txt");
		while (!fin.eof())
		{
			/*getline(fin, line);
			if (line.find(u))
			{
				if (line.find(pass))
				{
					isFound = true;
				}
			}*/
			fin >> user;
			fin >> p;
			if (u == user)
			{
				if (p == pass)
					isFound = true;
			}
		}
		fin.close();
		return isFound;
	}
	void print_AO()
	{
		printUser();
	}
	void AOaddCourse(int id, string ti, int cred, string pre, string prog)
	{
		int i, cre;
		string t, pr, pro;
		CFile.open("Courses.txt");
		while (!CFile.eof())
		{
			CFile >> i;
			CFile >> t;
			CFile >> cre;
			CFile >> pr;
			CFile >> pro;

			if (id == i)
			{
				cout << "This Course already exists. Please enter a New ID" << endl;
			}
			else if (id != i && CFile.eof())
			{
				int co = 0;
				while (cptr[co].getCourseID() != 0) {
					co++;
				}
				cptr[co].setCourse(id, ti, cred, pre, prog);
				cptr[co].addCourse();
				return;
			}
		}

		CFile.close();
	}
	void AoaddCLO(int courseID, int id, string c)
	{
		cptr[courseID - 1].addCLO(courseID, id, c);
	}
	void deleteCLO(int cid, int cl)
	{
		for (int i = 0; i < 10; i++)
		{
			if (cptr[i].getCourseID() == cid)
			{
				cptr[i].CoursedelCLO(cid,cl);
				return;
			}
			
		}
	}
	void AOdeleteCourse(int cid)
	{
		for (int i = 0; i < 10; i++)
		{
			if (cid == cptr[i].getCourseID())
			{
				cptr[i].deleteCourse(cid);
			}
		}
	}
	bool check(int coID)
	{
		int cid, crd;
		string ti, pre, pro;
		chk.open("Courses.txt");
		while (!chk.eof())
		{
			chk >> cid;
			chk >> ti;
			chk >> crd;
			chk >> pre;
			chk >> pro;
			if (cid == coID)
			{
				chk.close();
				return true;
			}
		}
		chk.close();
		return false;
	}
	bool checkCLO(int cid, int cloid)
	{
		int coID, clID;
		string d;
		chk2.open("CLO.txt");
		while (!chk2.eof())
		{
			chk2 >> coID;
			chk2 >> clID;
			chk2 >> d;
			if (coID == cid && clID == cloid)
			{
				chk2.close();
				return false;
			}
		}
		chk2.close();
		return true;
	}
	bool checkCLO2(int coid, int cloid)
	{
		int coID, clID;
		string d;
		chk2.open("CLO.txt");
		while (!chk2.eof())
		{
			chk2 >> coID;
			chk2 >> clID;
			chk2 >> d;
			if (coID == coid && clID == cloid)
			{
				chk2.close();
				return true;
			}
		}
		chk2.close();
		return false;
	}
	void AOupdateCourse(int cid, int val_num, string update, int cred_upd)
	{
		Course c2;
		c2.update_Course(cid, val_num, update, cred_upd);

	}
	void updateCLO(string d)
	{
		Course c3;
		c3.cUpdateCLO(d);
	}
};

class Evaluation
{
	int eval_type, m, noq, clo_cov;
	string tname;
	CLO* clo;
public:
	fstream fout;
	ifstream fin;
	Evaluation()
	{
		eval_type = 0;
	}
	void addquizz(string tname, string qid, int noq, int m, int clo_cov)
	{
		fout.open("quiz.txt", fstream::app);
		fout << qid << " " << clo_cov << " " << noq << " " << m << " " << tname;
		fout << endl;

	}
	void addassignment(string tname, string ass_id, int noq, int m, int clo_cov)
	{
		fout.open("assignments.txt", fstream::app);
		fout << ass_id << " " << clo_cov << " " << noq << " " << m << " " << tname;
		fout << endl;
	}
	void addexam(string tname, string exam_id, int noq, int m, int clo_cov)
	{
		fout.open("exams.txt", fstream::app);
		fout << exam_id << " " << clo_cov << " " << noq << "  " << m << " " << tname;
		fout << endl;
	}
	bool checkintegrity(int eval_type, string eval_type_id)
	{
		fstream fin;
		string e_id, q_id, a_id;
		if (eval_type == 1)
		{
			fin.open("quiz.txt");
			while (!fin.eof())
			{
				fin >> q_id;
				if (q_id == eval_type_id)
				{
					return false;
				}
			}
		}
		else if (eval_type == 2)
		{
			fin.open("assignments.txt");
			while (!fin.eof())
			{
				fin >> a_id;
				if (a_id == eval_type_id)
				{
					return false;
				}
			}
		}
		else if (eval_type == 3)
		{
			fin.open("exams.txt");
			while (!fin.eof())
			{
				fin >> e_id;
				if (e_id == eval_type_id)
				{
					return false;
				}
			}
		}
		return true;
	}
	void teachers_evaluation(string tname, int  eval_type, string eval_type_id, int clo_cov)
	{
		fout.open("Teacher.txt", fstream::app);
		fout << clo_cov << " " << tname << "  ";
		if (eval_type == 1)
		{
			if ((checkintegrity(eval_type, eval_type_id) == true))
			{
				fout << "Quiz" << "  " << eval_type_id << endl;
			}
		}
		else if (eval_type == 2)
		{

			if ((checkintegrity(eval_type, eval_type_id) == true))
			{
				fout << "Assignment" << "  " << eval_type_id << endl;
			}
		}
		else if (eval_type == 3)
		{

			if ((checkintegrity(eval_type, eval_type_id) == true))
			{
				fout << "Exam" << "  " << eval_type_id << endl;
			}
		}

	}
	void delete_teacher_evaluations(string eval_type_id)
	{
		string tname, id, eval_type_name;
		int clo_Cov;
		fout.open("temp.txt", ios::out | ios::app);
		fin.open("Teacher.txt");
		while (!fin.eof())
		{
			fin >> clo_Cov;
			fin >> tname;
			fin >> eval_type_name;
			fin >> id;
			if (eval_type_id != id)
			{

				fout << clo_Cov << " " << tname << " " << eval_type_name << " " << id;
				fout << endl;
			}
		}
		fin.close();
		fout.close();

		remove("Teacher.txt");
		rename("temp.txt", "Teacher.txt");


	}
	

	void delete_evaluation(int eval_type, string eval_type_id)
	{
		string tname, q_id;
		int  m, noq, clo_cov;
		ifstream fin;
		ofstream fout;
		fout.open("temp.txt", ios::out | ios::app);
		if (eval_type == 1)
		{
			fin.open("quiz.txt");
		}
		if (eval_type == 2)
		{
			fin.open("assignments.txt");
		}
		if (eval_type == 3)
		{
			fin.open("exams.txt");
		}
		while (!fin.eof())
		{
			fin >> q_id;
			fin >> clo_cov;
			fin >> noq;
			fin >> m;
			fin >> tname;
			if (eval_type_id != q_id)
			{

				fout << q_id << " " << clo_cov << " " << noq << "  " << m << " " << tname;
				fout << endl;
			}
		}
		fin.close();
		fout.close();
		if (eval_type == 1)
		{
			remove("quiz.txt");
			rename("temp.txt", "quiz.txt");
		}
		if (eval_type == 2)
		{
			remove("assignments.txt");
			rename("temp.txt", "assignments.txt");
		}
		if (eval_type == 3)
		{
			remove("exams.txt");
			rename("temp.txt", "exams.txt");
		}

	}
	void update_evaluation(int eval_type, string eval_type_id, int val_num, int update, string upd_t)
	{
		string q_id, tname;
		int m, noq, clo_cov;
		ifstream fin;
		ofstream fout;
		fout.open("temp.txt", ios::out | ios::app);
		if (eval_type == 1)
		{
			fin.open("quiz.txt");
		}
		else if (eval_type == 2)
		{
			fin.open("assignments.txt");
		}
		else if (eval_type == 3)
		{
			fin.open("exams.txt");
		}
		while (!fin.eof())
		{
			fin >> q_id;
			if (eval_type_id != q_id)
			{
				fin >> clo_cov;
				fin >> noq;
				fin >> m;
				fin >> tname;

				fout << q_id << " " << clo_cov << " " << noq << "  " << m << " " << tname << endl;
				//fout << endl;
			}
			else if (eval_type_id == q_id)
			{
				if (val_num == 1)
				{
					fin >> clo_cov;
					clo_cov = update;
					fin >> noq;
					fin >> m;
					fin >> tname;

					fout << q_id << " " << clo_cov << " " << noq << "  " << m << " " << tname << endl;
					// fout << endl;

				}
				else if (val_num == 2)
				{
					fin >> clo_cov;
					fin >> noq;
					noq = update;
					fin >> m;
					fin >> tname;

					fout << q_id << " " << clo_cov << " " << noq << "  " << m << " " << tname << endl;
					//fout << endl;

				}
				else if (val_num == 3)
				{
					fin >> clo_cov;
					fin >> noq;
					fin >> m;
					m = update;
					fin >> tname;

					fout << q_id << " " << clo_cov << " " << noq << "  " << m << " " << tname << endl;
					//fout << endl;
				}
				if (val_num == 4)
				{
					fin >> clo_cov;
					fin >> noq;
					fin >> m;
					fin >> tname;
					tname = upd_t;

					fout << q_id << " " << clo_cov << " " << noq << "  " << m << " " << tname << endl;
					// fout << endl;
				}

			}

		}
		fin.close();
		fout.close();
		if (eval_type == 1)
		{
			remove("quiz.txt");
			rename("temp.txt", "quiz.txt");
		}
		else if (eval_type == 2)
		{
			remove("assignments.txt");
			rename("temp.txt", "assignments.txt");
		}
		else if (eval_type == 3)
		{
			remove("exams.txt");
			rename("temp.txt", "exams.txt");
		}

	}
};

class Teacher : public User
{
	int Tid;
	Course* c;
	CLO* clo;
	Evaluation E1;
public:
	ifstream fin;
	Teacher()
	{
		User t;
		Tid = 0;
	}
	Teacher(string n, string u, string pass)
	{
		set_User(n, u, pass);
	}
	bool readFromFile(string u, string pass)
	{
		bool isFound = false;
		string line;
		string user, p;
		fin.open("Login.txt");
		while (!fin.eof())
		{
			fin >> user;
			fin >> p;
			if (u == user)
			{
				if (p == pass)
					return true;
			}
		}
		return false;
	}

	bool CheckAllCLOHasTested(Course* c)
	{

	}

};

int main()
{
	int input, input2, input3, input4, tmarks, no_of_questions, clo_covered, cred, cid;
	string username, pass, teacher_name, ti, pre, prog, cloDetail;
	bool isFound, found, isfound2;
	isFound = false;
	found = false;
	isfound2 = false;
	cout << "------------------Welcome to OBE System--------------" << endl;
	cout << "Press 1 for Academic Officer" << endl;
	cout << "Press 2 for Teacher" << endl;
	cin >> input;
	if (input == 1)
	{
		AcademicOfficer a1;
		while (!found)
		{
			cout << "Enter Username: ";
			cin >> username;
			cout << "Enter Password: ";
			cin >> pass;
			isFound = a1.readFromFile(username, pass);
			if (isFound)
			{
				cout << "ACADEMIC OFFICER LOGGED IN SUCCESSFULLY" << endl;
				found = true;
			}
		}
		cout << "Press 1 to add Course" << endl;
		cout << "Press 2 to Add CLO" << endl;
		cout << "Press 3 to delete Course" << endl;
		cout << "Press 4 to delete CLO" << endl;
		cout << "Press 5 to update Course" << endl;
		cout << "Press 6 to update CLO" << endl;
		cin >> input2;
		if (input2 == 1)
		{
			cout << "Enter course id: ";
			cin >> cid;
			cout << "Enter Title: ";
			cin >> ti;
			cout << "Enter credit hours: ";
			cin >> cred;
			cout << "Enter Pre-requisite ";
			cin >> pre;
			cout << "Enter the Program that this course falls under: ";
			cin >> prog;
			a1.AOaddCourse(cid, ti, cred, pre, prog);
		}
		else if (input2 == 2)
		{

			cout << "Enter the Course ID for which you want to add CLO for: ";
			cin >> input3;
			if (a1.check(input3))
			{
				cout << "Enter new CLO id: ";
				cin >> input4;
				if (a1.checkCLO(input3, input4)) {

					cout << "Enter the description of the CLO: ";
					cin >> cloDetail;
					a1.AoaddCLO(input3, input4, cloDetail);
				}
				else
					cout << "This CLO already exists for this Course ID";
			}
			else {
				cout << "The course ID does not exist";
			}
		}
		else if (input2 == 3)
		{
			cout << "Enter course id to delete course: ";
			cin >> cid;
			if (a1.check(cid))
			{
				a1.AOdeleteCourse(cid);
			}
			else
				cout << "This course does not exist";
		}
		else if (input2 == 4)
		{
			int coid, clid;
			cout << "Enter the Course ID from which you want to delete a CLO: ";
			cin >> coid;
			if (a1.check(coid))
			{
				cout << "Enter the CLO ID yo want to delete: ";
				cin >> clid;
				if (a1.checkCLO2(coid, clid))
				{
					a1.deleteCLO(coid, clid);
				}
				else
					cout << "This CLO ID does not exist for this Course";
			
			}
			else
				cout << "There is no course with this ID";
		}
		else if (input2 == 5)
		{
			int course_upd_num = 0, credit_hours = 0;
			string updated;
			cout << "Enter course if to update course record: ";
			cin >> cid;
			if (a1.check(cid))
			{
				cout << "Enter 1 to update course title: " << endl;
				cout << "Enter 2 to update course pre Requisite: " << endl;
				cout << "Enter 3 to update course degree progra,: " << endl;
				cout << "Enter 4 to update course credit Hours: " << endl;	
				cin >> course_upd_num;
				if (course_upd_num == 4)
				{
					cout << "Enter updated credit hours value: ";
					cin >> credit_hours;

				}
				else
				{
					cout << "Enter updated value: ";
					cin >> updated;
				}
				a1.AOupdateCourse(cid, course_upd_num, updated, credit_hours);
			}
			else
				cout << "This course ID does not exist";
		}
		else if (input2 == 6)
		{
			int coinput, clinput, update_info, clinput2;
			string updated_details;
			cout << "Enter the Course ID for which you want to update CLO for: ";
			cin >> coinput;
			if (a1.check(coinput))
			{
				cout << "Enter the CLO that you want updated:";
					cin >> clinput;
				if (a1.checkCLO2(coinput, clinput))
				{
					cout << "Enter 1 if you want to update CLO ID"<<endl;
					cout << "Enter 2 if you want to update the details";
					cin >> update_info;
					if (update_info == 1)
					{
						cout << "Enter cloID: ";
						cin >> clinput2;

					}

				}
				else
					cout<<"This CLO does not exist for the entered Course ID";
			}
			else
				cout << "This Course ID does not exist";
		}

	}
	else if (input == 2)
	{
		Teacher t1;
		while (!found)
		{
			cout << "Enter Username: ";
			cin >> username;
			cout << "Enter Password: ";
			cin >> pass;
			isFound = t1.readFromFile(username, pass);
			if (isFound)
			{
				cout << "Teacher LOGGED IN SUCCESSFULLY" << endl;
				found = true;
			}
		}

		int eval_type, choice;
		cout << "Press 1 to add an Evaluation" << endl;
		cout << "Press 2 to delete an Evaluation " << endl;
		cout << "press 3 to update an evaluation" << endl;
		cin >> choice;
		string qid, ass_id, exam_id, teacher_name;
		Evaluation e;
		if (choice == 1)
		{
			cout << "Press 1 to add quizz Evaluation" << endl;
			cout << "Press 2 to add Assignment Evaluation" << endl;
			cout << "Press 3 to add Exam Evaluation" << endl << endl;
			cout << "Enter Evaluation type" << endl;
			cin >> eval_type;
			if (eval_type == 1)
			{
				do
				{
					cout << "Enter quiz id(format:  (q01)" << endl;
					cin >> qid;
					if (e.checkintegrity(eval_type, qid) == false)
						cout << "Quiz id already exist!!" << endl;
				} while (e.checkintegrity(eval_type, qid) == false);
				cout << "Enter Teacher's  name" << endl;
				cin >> teacher_name;
				cout << "Enter total marks" << endl;
				cin >> tmarks;
				cout << "Enter No of Questions" << endl;
				cin >> no_of_questions;
				cout << "Enter Clo Covered" << endl;
				cin >> clo_covered;
				e.addquizz(teacher_name, qid, no_of_questions, tmarks, clo_covered);
				e.teachers_evaluation(teacher_name, eval_type, qid, clo_covered);
				
			}
			if (eval_type == 2)
			{
				do
				{
					cout << "Enter assignment id(format: (a01)" << endl;
					cin >> ass_id;
					if (e.checkintegrity(eval_type, ass_id) == false)
						cout << "Assignment id already exist!!" << endl;
				} while (e.checkintegrity(eval_type, ass_id) == false);
				cout << "Enter Teacher's  name" << endl;
				cin >> teacher_name;
				cout << "Enter total marks" << endl;
				cin >> tmarks;
				cout << "Enter No of Questions" << endl;
				cin >> no_of_questions;
				cout << "Enter Clo Covered" << endl;
				cin >> clo_covered;
				e.addassignment(teacher_name, ass_id, no_of_questions, tmarks, clo_covered);
				e.teachers_evaluation(teacher_name, eval_type, ass_id, clo_covered);
				//t1.teachers_evaluation(eval_id,teacher_name, eval_type, ass_id);

			}
			if (eval_type == 3)
			{
				do
				{
					cout << "Enter exam id(format: (e01)" << endl;
					cin >> exam_id;
					if (e.checkintegrity(eval_type, exam_id) == false)
						cout << "Exam id already exist!!" << endl;
				} while (e.checkintegrity(eval_type, exam_id) == false);
				cout << "Enter Teacher's  name" << endl;
				cin >> teacher_name;
				cout << "Enter total marks" << endl;
				cin >> tmarks;
				cout << "Enter No of Questions" << endl;
				cin >> no_of_questions;
				cout << "Enter Clo Covered" << endl;
				cin >> clo_covered;
				e.addexam(teacher_name, exam_id, no_of_questions, tmarks, clo_covered);
				e.teachers_evaluation(teacher_name, eval_type, exam_id, clo_covered);
				//t1.teachers_evaluation(eval_id, teacher_name, eval_type, exam_id);

			}

		}
		else if (choice == 2)
		{
			int del;
			cout << "Enter 1 to delete quiz" << endl;
			cout << "Enter 2 to delete Assignment" << endl;
			cout << "Enter 3 to delete Exam" << endl;
			cin >> del;
			if (del == 1)
			{
				cout << "Enter quiz id to delete record: " << endl;
				cin >> qid;
				if (e.checkintegrity(del, qid) == true)
				{
					cout << "Quiz does not exist!!" << endl;
				}
				else
					e.delete_evaluation(del, qid);
				e.delete_teacher_evaluations(qid);
			}
			if (del == 2)
			{
				cout << "Enter assignment id to delete record: " << endl;
				cin >> ass_id;
				if (e.checkintegrity(del, ass_id) == true)
				{
					cout << "Assignment does not exist!!" << endl;
				}
				else
					e.delete_evaluation(del, ass_id);
				e.delete_teacher_evaluations(ass_id);
			}
			if (del == 3)
			{
				cout << "Enter Exam id to delete record: " << endl;
				cin >> exam_id;
				if (e.checkintegrity(del, exam_id) == true)
				{
					cout << "Exam does not exist!!" << endl;
				}
				else
					e.delete_evaluation(del, exam_id);
				//e.delete_teacher_evaluations(exam_id);
			}
		}
		else if (choice == 3)
		{
			int upd = 0, update = 0, upd_val = 0;
			string upd_teacher;
			cout << "Enter 1 to update quiz" << endl;
			cout << "Enter 2 to update Assignment" << endl;
			cout << "Enter 3 to update Exam" << endl;
			cin >> upd;
			if (upd == 1)
			{
				cout << "Enter id of the quiz you want ot update record: " << endl;
				cin >> qid;
				if (e.checkintegrity(upd, qid) == true)
				{
					cout << "Quiz does not exist!!" << endl;
				}
				else
				{
					cout << "Enter 1 to update CLO" << endl;
					cout << "Enter 2 to update No of question" << endl;
					cout << "Enter 3 to update Marks" << endl;
					cout << "Enter 4 to update Teacher's Name" << endl;
					cin >> update;
					if (update == 4)
					{
						cout << "Enter updated_teacher's Name: ";
						cin >> upd_teacher;
					}
					else
					{
						cout << "Enter updated value: ";
						cin >> upd_val;
					}
				}
				e.update_evaluation(upd, qid, update, upd_val, upd_teacher);
			}
			else if (upd == 2)
			{
				cout << "Enter id of the Assignment you want ot update record: " << endl;
				cin >> ass_id;
				if (e.checkintegrity(upd, ass_id) == true)
				{
					cout << "Assignment does not exist!!" << endl;
				}
				else
				{
					cout << "Enter 1 to update CLO" << endl;
					cout << "Enter 2 to update No of question" << endl;
					cout << "Enter 3 to update Marks" << endl;
					cout << "Enter 4 to update Teacher's Name" << endl;
					cin >> update;
					if (update == 4)
					{
						cout << "Enter updated teacher's Name: ";
						cin >> upd_teacher;
					}
					else
					{
						cout << "Enter updated value: ";
						cin >> upd_val;
					}
				}
				e.update_evaluation(upd, ass_id, update, upd_val, upd_teacher);
			}
			else if (upd == 3)
			{
				cout << "Enter id of the Exam you want ot update record: " << endl;
				cin >> exam_id;
				if (e.checkintegrity(upd, exam_id) == true)
				{
					cout << "exam does not exist!!" << endl;
				}
				else
				{
					cout << "Enter 1 to update CLO" << endl;
					cout << "Enter 2 to update No of question" << endl;
					cout << "Enter 3 to update Marks" << endl;
					cout << "Enter 4 to update Teacher's Name:" << endl;
					cin >> update;
					if (update == 4)
					{
						cout << "Enter updated teacher Name: ";
						cin >> upd_teacher;
					}
					else
					{
						cout << "Enter updated value: ";
						cin >> upd_val;
					}
					e.update_evaluation(upd, qid, update, upd_val, upd_teacher);
				}
			}
		}
	}
	
	return 0;
}