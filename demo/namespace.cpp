#pragma once  //��ֹ�ļ������ذ���
#include <stdio.h>
#include <iostream>  //������
#include <string>  //�ַ���
#include "namespace.h"

using namespace std;
using namespace mynamespace;

void mynamespace::myfun(string str)
{
	cout << str << endl;
}
//���캯�� //���ó�Ա���ݳ�ʼ��ֵ
Student::Student() :name("student"), age(default_age)
{
	cout << "�޲λ��๹�캯����" + name << endl;
}
//���캯��
Student::Student(string name, int age)
{
	this->name = name;
	this->age = age;
	cout << "�вλ��๹�캯����" + name << endl;
}
//���캯��
Student::Student(int age)
{
	this->age = age;
	name = "student";
	cout << "�вλ��๹�캯����" + name << endl;
}
//���ƹ��캯��
Student::Student(const Student& another)
{
	name = another.name;
	age = another.age;
	cout << "���ิ�ƹ��캯����" + name << endl;
}
//��ֵ���캯��
Student& Student::operator=(const Student& another)
{
	//�Ը�ֵ���
	if (this == &another)
	{
		return *this;
	}
	//�ͷ�thisԭ�ڴ�
	//��ֵ���ڴ�
	name = another.name;
	age = another.age;
	cout << "���ำֵ���캯����" + name << endl;
	return *this;
}

//���������
Student Student::operator+(const Student& another) const
{
	Student student;
	student.setname(name + " and " + another.name + "'s group");
	student.setage((age + another.age) / 2);
	cout << "����ӷ����������" << endl;
	return student;
}
//���������
Student Student::operator+(const string& anothername) const
{
	Student parents(anothername);
	cout << "������ַ������������" << endl;
	return parents;   //���ܷ��ؾֲ���������á�  ���ض��󣬻Ὣ�ֲ�����ֵ�����ն��������پֲ����󡣲�����ָ���ڴ档�������ã����ֲ����ø�ֵ���������ã������پֲ�������������õ�����Ҳȫ�������ˡ�
}
void Student::setname(string name)   //�����ظ�ʹ��virtual
{
	this->name = name;   //this��Ϊ����Student
	cout << "�����������Ʋ���:" + name << endl;
}
string Student::getname() const
{
	cout << "�����ȡ���Ʋ���:" + name << endl;
	return (*this).name;  //this��ָ��  ����ȡָ��ֵ
	//return name;
}
void Student::setage(int age)
{
	cout << "���������������" << endl;
	this->age = age;
}
int Student::getage()
{
	cout << "���๲��̬������ȡ�������" << endl;
	return default_age;   //��̬����ֻ�ܲ�����̬����
}
//��������   ���Զ�ջָ���ں����˳�ʱ���ǻ��Զ��ͷ�ָ��Ķ��е��ڴ档���ԭ�ڴ��𻵣����ú�����
Student::~Student()
{
	cout << "������������:" + name << endl;
	//������д�ͷŶ����ڴ�ĺ���
}

//Ƕ���ຯ������
string Student::sex::getsex()
{
	return sexstr;
}
//Ƕ���ຯ������
void Student::sex::setsex(allsex sextype)
{
	if (sextype == boy)
		sexstr = "boy";
	else
		sexstr = "girl";
}


//����ģ���ⲿ�����Ա�����ķ���Ϊ��template<ģ���β��б�> ������������ ����<ģ���β���>::������(�����б�){������}��
template<class TT> TT classA<TT>::add(TT tt, TT pp){
	return tt + pp;
}

