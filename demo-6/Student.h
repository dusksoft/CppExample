﻿#ifndef _STUDENT_H_
#define _STUDENT_H_


class Student {
public:
	// 构造函数允许重载
	explicit Student();	// 关键词explicit 禁止构造函数隐式类型转换
	Student(int id);
	
	~Student();	// 虚构函数不能重载
	
	void output();
	
	// 给类成员进行赋值
	int getId();
	void setId(int id);
	int getScore();
	void setScore(int score);
private:
	// 类成员函数必须私有化
	int m_id;
	int m_score;
};

#endif