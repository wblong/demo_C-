#pragma once  //防止文件被多重包含
#include <stdio.h>
#include <iostream>  //数据流
#include <string>  //字符串
#include "namespace.h"

using namespace std;
using namespace mynamespace;

void mynamespace::myfun(string str)
{
	cout << str << endl;
}
//构造函数 //设置成员数据初始化值
Student::Student() :name("student"), age(default_age)
{
	cout << "无参基类构造函数：" + name << endl;
}
//构造函数
Student::Student(string name, int age)
{
	this->name = name;
	this->age = age;
	cout << "有参基类构造函数：" + name << endl;
}
//构造函数
Student::Student(int age)
{
	this->age = age;
	name = "student";
	cout << "有参基类构造函数：" + name << endl;
}
//复制构造函数
Student::Student(const Student& another)
{
	name = another.name;
	age = another.age;
	cout << "基类复制构造函数：" + name << endl;
}
//赋值构造函数
Student& Student::operator=(const Student& another)
{
	//自赋值检测
	if (this == &another)
	{
		return *this;
	}
	//释放this原内存
	//赋值新内存
	name = another.name;
	age = another.age;
	cout << "基类赋值构造函数：" + name << endl;
	return *this;
}

//运算符重载
Student Student::operator+(const Student& another) const
{
	Student student;
	student.setname(name + " and " + another.name + "'s group");
	student.setage((age + another.age) / 2);
	cout << "基类加法运算符重载" << endl;
	return student;
}
//运算符重载
Student Student::operator+(const string& anothername) const
{
	Student parents(anothername);
	cout << "基类加字符串运算符重载" << endl;
	return parents;   //不能返回局部对象的引用。  返回对象，会将局部对象赋值给接收对象，再销毁局部对象。不销毁指针内存。返回引用，将局部引用赋值给接收引用，再销毁局部对象，则接收引用的内容也全部销毁了。
}
void Student::setname(string name)   //无需重复使用virtual
{
	this->name = name;   //this作为对象Student
	cout << "基类设置名称参数:" + name << endl;
}
string Student::getname() const
{
	cout << "基类读取名称参数:" + name << endl;
	return (*this).name;  //this是指针  可以取指向值
	//return name;
}
void Student::setage(int age)
{
	cout << "基类设置年龄参数" << endl;
	this->age = age;
}
int Student::getage()
{
	cout << "基类共享静态函数读取年龄参数" << endl;
	return default_age;   //静态函数只能操作静态数据
}
//析构函数   所以堆栈指针在函数退出时总是会自动释放指向的堆中的内存。造成原内存损坏（调用函数）
Student::~Student()
{
	cout << "基类析构函数:" + name << endl;
	//这里填写释放对象内存的函数
}

//嵌套类函数定义
string Student::sex::getsex()
{
	return sexstr;
}
//嵌套类函数定义
void Student::sex::setsex(allsex sextype)
{
	if (sextype == boy)
		sexstr = "boy";
	else
		sexstr = "girl";
}


//在类模板外部定义成员函数的方法为：template<模板形参列表> 函数返回类型 类名<模板形参名>::函数名(参数列表){函数体}，
template<class TT> TT classA<TT>::add(TT tt, TT pp){
	return tt + pp;
}

