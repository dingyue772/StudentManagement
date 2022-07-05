#include "Department.h"

//排序用的谓词
class MyCompare {
public:
	bool operator()(Student& s1, Student& s2)
	{
		if (s1.get_Score() != s2.get_Score())
			return s1.get_Score() > s2.get_Score();
		else
			return s1.get_Id() < s2.get_Id();
	}
};
Department::Department(string speciality):m_Speciality(speciality)
{
}
//排序函数
void Department::Sort()
{

	sort(ds.begin(), ds.end(), MyCompare());
	int i = 1;
	for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++) {
		it->set_Rank(i);
		it->set_Comment();
		i++;
	}

}

void Department::output_tofile()
{
	ofstream outfile;
	outfile.open("student.txt", ios::out);
	if (!outfile.is_open())
	{
		cout << "student.txt打开失败" << endl;
		return;
	}
	int flag = 0;
	for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++) {
		if (it->get_Id() != "\0")
			flag = 1;
	}
	if (flag) {
		outfile << "专业\t" << "\t" << "学号\t" << "姓名\t" << "综合评价分数\t" << "排名\t" << "评价" << endl;
		for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++) {
			if (it->get_Id() != "\0")
				outfile << *it;
		}
		outfile.close();
	}
	
}

void Department::input_fromfile()
{
	ifstream infile;
	infile.open("student.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "student.txt打开失败" << endl;
		return;
	}
	int flag = 1;
	while (!infile.eof())
	{
		if (flag) {
			string butter;
			getline(infile, butter);
			flag = 0;
		}
		Student stu;
		infile >> stu;
		if(stu.get_Id() != "\0")
		ds.push_back(stu);
		//cout << stu;
	}
	infile.close();
}

void Department::Add()
{
	string id;
	string name;
	double s1, s2, s3, s4;
	string speciality = m_Speciality;
	cout << "学号：";
	cin >> id;
	while (id.size() != 10)
	{
		cout << "学号应为10位,请重新输入";
		cin >> id;
	}
	for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
		if (it->get_Id() == id ) {
			cout << "学号输入错误，请重新输入";
			cin >> id;
			it = ds.begin();
		}
	cout << "姓名：";
	cin >> name;
	cout << "学分绩：";
	cin >> s1;
	while (s1 < 0 || s1 > 100) {
		cout << "请输入正确的学分绩";
		cin >> s1;
	}
	cout << "日常行为分：";
	cin >> s2;
	while (s2 < 0 || s2 > 100) {
		cout << "请输入正确的日常行为分";
		cin >> s2;
	}
	cout << "个性发展分：";
	cin >> s3;
	while (s3 < 0 || s3 > 2) {
		cout << "请输入正确的个性发展分（上限为2分）";
		cin >> s1;
	}
	cout << "班级互评分：";
	cin >> s4;
	while (s4 <= 0 || s4 > 100) {
		cout << "请输入正确的班级互评分";
		cin >> s4;
	}
	Score score(s1, s2, s3, s4);
	Student stu(name, id, speciality, score);
	ds.push_back(stu);
	//cout << "当前容器中有" << ds.size() << "个学生的信息" << endl;
}

void Department::Check()
{
	cout << "*************************" << endl;
	cout << "***    " << "1. 学号查询" << "    ***" << endl;
	cout << "***    " << "2. 姓名查询" << "    ***" << endl;
	cout << "***    " << "3. 排名查询" << "    ***" << endl;
	cout << "***    " << "4. 评价查询" << "    ***" << endl;
	cout << "***    " << "5. 全部查询" << "    ***" << endl;
	cout << "*************************" << endl;
	cout << "请输入你想要的查询方式" << endl;
	int flag;
	cin >> flag;
	system("cls");
	switch (flag) {
	case 1:
	{
		string id;
		cout << "请输入你想要查询的学号" << endl;
		cin >> id;
		system("cls");
		for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
			if (it->get_Id() == id) {
				cout << *it << endl;
				break;
			}
		break;
	}
	case 2:
	{
		string name;
		cout << "请输入你想要查询的姓名" << endl;
		cin >> name;
		system("cls");
		for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
			if (it->get_Name() == name) {
				cout << *it << endl;
				break;
			}
		break;
	}
	case 3:
	{
		int rank;
		cout << "请输入你想要查询的排名" << endl;
		cin >> rank;
		system("cls");
		for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
			if (it->get_Rank() == rank) {
				cout << *it << endl;
				break;
			}
		break;
	}
	case 4:
	{
		string comment;
		cout << "请输入你想要查询的评价" << endl;
		cin >> comment;
		system("cls");
		for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
			if (it->get_Comment() == comment) {
				cout << *it << endl;
			}
		break;
	}
	case 5:
	{
		for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
				cout << *it << endl;
		break;
	}
	default:
	{
		cout << "请输入对应数字选择以上查询方式" << endl;
		break;
	}
	}
}

void Department::Delete()
{
	cout << "请输入你想要删除的学生的学号" << endl;
	string id;
	cin >> id;
	for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
	{
		it->set_Id("\0");
	}
}

void Department::Change()
{
	cout << "请输入你要修改的学生的学号" << endl;
	string id;
	cin >> id;
	for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
	{
		cout << "1";
		if (id == it->get_Id())
		{
			cout << "请输入该学生修改之后的信息" << endl;
			string id;
			string name;
			double s1, s2, s3, s4;
			string speciality = m_Speciality;
			cout << "学号：";
			cin >> id;
			while (id.size() != 10)
			{
				cout << "学号应为10位,请重新输入";
				cin >> id;
			}
			for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
				if (it->get_Id() == id) {
					cout << "学号输入错误，请重新输入";
					cin >> id;
					it = ds.begin();
				}
			cout << "姓名：";
			cin >> name;
			cout << "学分绩：";
			cin >> s1;
			while (s1 < 0 || s1 > 100) {
				cout << "请输入正确的学分绩";
				cin >> s1;
			}
			cout << "日常行为分：";
			cin >> s2;
			while (s2 < 0 || s2 > 100) {
				cout << "请输入正确的日常行为分";
				cin >> s2;
			}
			cout << "个性发展分：";
			cin >> s3;
			while (s3 < 0 || s3 > 2) {
				cout << "请输入正确的个性发展分（上限为2分）";
				cin >> s1;
			}
			cout << "班级互评分：";
			cin >> s4;
			while (s4 <= 0 || s4 > 100) {
				cout << "请输入正确的班级互评分";
				cin >> s4;
			}
			Score score(s1, s2, s3, s4);
			Student stu(name, id, speciality, score);
			*it = stu;
		}
		cout << "修改完成" << endl;
		return;
	}
	cout << "查无此人" << endl;
}

void Department::Clear()
{
	for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
		it->set_Id("\0");
	cout << "学生信息已清空" << endl;
	system("pause");
}


