#include "Student.h"
Student::Student(string name, string id, string speciality, Score score) : m_Name(name), m_Id(id), m_Speciality(speciality), m_Score(score)
{
}

string Student::get_Name()
{
	return m_Name;
}

string Student::get_Id()
{
	return m_Id;
}

string Student::get_Speciality()
{
	return m_Speciality;
}

double Student::get_Score()
{
	return m_Score.get_sum_Score();
}

int Student::get_Rank()
{
	return m_Rank;
}

string Student::get_Comment()
{
	return m_Comment;
}

void Student::set_Rank(int rank)
{
	m_Rank = rank;
}

void Student::set_Comment()//90及以上为优，80以上为中，70以上为良，60以上为及格，
{
	//cout << "综合评价成绩为：" << (int)m_Score.get_sum_Score() << endl;
	switch ((int)m_Score.get_sum_Score()/10) {
	case 10:
	case 9:
		m_Comment = "优";
		break;
	case 8:
		m_Comment = "良";
		break;
	case 7:
		m_Comment = "中";
		break;
	case 6:
		m_Comment = "及格";
		break;
	default:
		m_Comment = "不及格";
		break;
	}
	
}

void Student::set_Name(string name)
{
	m_Name = name;
}

void Student::set_Id(string id)
{
	m_Id = id;
}

void Student::set_Sepciality(string speciality)
{
	m_Speciality = speciality;
}

void Student::set_Score(double score)
{
	m_Score.set_sum_Score(score);
}

ostream& operator<<(ostream& out, Student& st)
{
	if (st.m_Id != "\0") {
		out << st.m_Speciality << "    " << st.m_Id << '\t' << st.m_Name << '\t' << st.m_Score.sum_Score << '\t' << '\t' << st.m_Rank << '\t' << st.m_Comment << endl;
	}
	return out;
}

istream& operator>>(istream& in, Student& st)
{
	in >> st.m_Speciality >> st.m_Id >> st.m_Name >> st.m_Score.sum_Score;
	//in.read((char*)&st.m_Score.sum_Score, sizeof(float));
	in.get();
	in >> st.m_Rank >> st.m_Comment;
	in.get();
	return in;
}
