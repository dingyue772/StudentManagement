#pragma once
#include <iostream>
#include <string>
#include "Score.h"
using namespace std;

class Student
{
private:
	string m_Name;
	string m_Id;
	string m_Speciality;
	Score m_Score;
	int m_Rank;
	string m_Comment;
public:
	
	//属性方法
	Student() {}
	Student(string name, string id, string speciality, Score score);
	//get类方法
	string get_Name();
	string get_Id();
	string get_Speciality();
	double get_Score();
	void display_scores();
	int get_Rank();
	string get_Comment();
	//运算符重载
	friend ostream& operator<< (ostream& out, Student& st);
	friend istream& operator>> (istream& in, Student& st);
	//set类方法
	void set_Rank(int rank);
	void set_Comment();
	void set_Name(string name);
	void set_Id(string id);
	void set_Sepciality(string speciality);
	void set_Score(double score);
};