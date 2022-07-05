#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include "Student.h"
#include <fstream>
#include <typeinfo>
#include <string>
using namespace std;
class Department {
private:
	deque<Student> ds;
	string m_Speciality;
public:
	//构造函数
	Department(){}
	Department(string speciality);
	//方法定义
	void Sort();//对当前所有学生根据sum_score排序
	void output_tofile();//将学生信息写入文件
	void input_fromfile();//将已有学生信息从文件读入
	//主函数中的功能模块实现
	void Add();//提供添加学生信息功能
	void Check();//提供查询当前专业系统内学生信息功能
	void Delete();//提供删除当前专业内某学号学生信息的功能
	void Change();//修改学生信息的功能
	void Clear();//将已输入的学生信息清空
	//析构函数
	~Department() {
		ds.shrink_to_fit();
	}
};