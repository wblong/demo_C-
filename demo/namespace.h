#pragma once  //��ֹ�ļ������ذ���
#include <stdio.h>
#include <iostream>  //������
#include <string>    //�ַ���
#include <exception>  //�쳣
#include <stdarg.h>  //�仯����
#ifndef PI   //���û�ж���PI���壬��������  �����ظ�����
#define PI 3.1415926
#endif
using namespace std;  //���ÿռ亯��
//�Զ��������ռ�
namespace mynamespace
{
	//��̬����
	static long long timenow;
	//�Զ��庯��
	void myfun(string str);

	//�Զ�����-ѧ����
	class Student
	{
	public:                                                             //������Ա���ⲿ���Է��ʵĳ�Ա
		Student();                                                      //�޲ι��캯��   //Ĭ�Ϲ��캯��������ȫ��Ĭ��ֵ+�޲κ����������޲ε���
		Student(string name, int age = default_age);                       //�вι��캯��   //��������ͬ,��������,age����Ĭ�ϲ���,�˲������п���
		Student(int age);                                               //�вι��캯�� //��������ͬ,��������,��������ͬ���������ͺ�������ͬ��Ϊ���أ��뷵��ֵ�޹�
		virtual ~Student();                                                //��������  //���ٶ���ʱ���Զ����øú������÷��������ͷ��ڴ棬�����Ϊ�麯����������̬���ԣ���������������󴴽����ڴ�
		Student(const Student& another);                                //���ƹ��캯��
		Student& operator=(const Student& another);                     //���ظ�ֵ��������ں��������������ľ�Ҫ�����࣬û�����������ķ���������
		//�������ع�ϵ����� ���������  �����ݼ������  ��λ����  ��Ԫ�߼������  ����<<�����  ��ȡ>>�����  �±������  �������������  ������������  �ڴ������ͷ������
		Student operator+(const Student& another) const;                //�ӷ����������  Student�ļӷ����㣬const�������ı����ڳ�Ա�����ض��󲻷�����������Ϊ������һ���µĶ�����ԭ�����д���
		Student operator+(const string& anothername) const;             //�ӷ����������   ��������ʱ����ʽת�� +������Student�ĺ��档�������Ƽȿ�����Ϊ���󷵻أ��ֿ�����Ϊ�������÷���
		virtual void setname(string name);                              //virtual�ؼ��֣��麯����֧����������д��������к���������Ϊ�麯����java������ô����
		string getname() const;                                         //���ı����ݳ�Ա�ĺ�������Ϊconst
		void setage(int age);                                           //���溯������
		static int getage();                                            //static�ؼ��֣���̬��������̬����������д�������ڼ̳�  //��̬�������ڶ�������������ƣ��������ض��Ķ��󣬵���ʱʹ�����ֽ���
		static string default_name;                                     //��̬����,�洢�ھ�̬��
		static const int default_age = 18;                                //const�ؼ��֣���ֵ���ݣ����ݴ洢�����ֳ�������const���ݶ���ʱ��Ҫ��ֵ��
		//mutable��ǵ�Ϊ�ɱ����   ��const�����п��Ըı�ֵ�ı���
		enum allsex{ boy, girl };                                          //enum�ؼ��֣�ö�����ͣ������޶�������ȡֵ��Χ�������define������const
		class sex{                                                      //�����ڲ��࣬�Ա�
			public:
				string getsex();
				void setsex(allsex sextype);                                //ʹ��ö��������Ϊ����
			private:
				string sexstr;
		};
	protected:                                                          //��������Է��ʵĳ�Ա
		string name;
	private:                                                            //ֻ�������ڷ��ʵĳ�Ա
		int age;
	};


	//������-�೤��
	class Monitor :public Student                                       //���м̳�   public����������߷���Ȩ��  ���в�����Ȩ���Զ�����Ϊ��Ȩ��  ����ʹ��public
	{
	public:
		Monitor(){                                                     //���캯�����ܼ̳�
			this->task = "������ʦ����༶";                           //�����������ֱ����������ʵ�֣�Ҳ�����ڶ���cpp��ʵ�֣�Ҳ���Բ�ʵ�֣��ڵ���ʱʵ��
			name = "monitor";
			cout << "�޲������๹�캯��" << endl;                           //cout<<           <<endl; ������ݵ�dos����
		};
		virtual void setname(string name) override                     //override����д�鷽��  virtual��override���Բ�д��overrideд���Ա������غ�������
		{
			this->name = name;                                           //this��Ϊ����Student
			cout << "�������������Ʋ���:" + name << endl;
		}
		using Student::getname;                                        //�������ຯ����ʹ��using�ؼ�����ʾ�İ��������ж����ͬ�������а汾�ķ������������൱���ڵ�ǰ����չ��
		string getname(string surname)                                 //�����³�Ա������������γ�����  ��Ϊ������ͬ������ʹ��using������������ػ��ຯ��
		{
			cout << "�������ȡ���Ʋ���:" + surname + name << endl;
			return surname + name;
		}
		void setage()                                                  //���ػ��ຯ��������ຯ��ͬ��
		{
			age = 7;
			cout << "�����������������:" << age << endl;
		}
		int getage(){                                                  //���������Ա�����������еĺ���Ϊ��̬�����������ڶ���������
			cout << "�������ȡ�������:" << age << endl;
			return age;
		};
		string gettask(){ return task; };                                //���������Ա����
		void settask(string task, ...){                                 //...��ʾ�������Ĳ�����Ŀ�����������Ա����
			va_list arg_ptr;                                           //��������б�
			va_start(arg_ptr, task);                                    //�������б���ʼλ�ð�Ϊ��һ������
			string aa = " ";
			// while (aa!="" && !aa==NULL)                              //�޷��Բ����б�������β�����жϣ������Լ��������Բ���������������β
			{
				aa = va_arg(arg_ptr, string);                           //������ȡ��������ת��Ϊ��Ӧ������
			}
			va_end(arg_ptr);                                           //����������
			this->task = task;
		};
	private:
		int age;                                                       //������ageΪprivate���������޷����ʣ����������¶���
		string task;                                                   //�����������������
	};





	//�Զ�����-��ʦ��
	class Teacher
	{
	public:
		Teacher() :name("teacher"), course("����"){                        //�����Ĭ�Ϲ��캯����ͬʱ��ʼ�����ݳ�Աname��course
			cout << "�����޲ι��캯����" + name << endl;
		};
		Teacher(string name){ cout << "�����вι��캯����" + name << endl; };   //������вι��캯��
		~Teacher(){ cout << "������������" << endl; };                        //��������
		friend class Student;                                          //��Ԫ��Student �������еķ������Է���Teacher��private��protected��public���ݳ�Ա�ͷ���
		friend void Student::setname(string name);                     //ֻ��������Ԫ�ĺ������Է��ʵ�ǰ��ĳ�Ա�ͷ�����ֻ��Student:;setname�������Է���Teacher�ĳ�Ա����
		virtual Student& getstudent() = 0;                               //=0����Ϊ���麯����û�ж��巽����ֻ�������˷������������麯������Ϊ�����࣬�����಻��ʵ������
		virtual void setstudent(Student& students) = 0;                 //&Ϊ���ã��൱�ڱ�������
		virtual string getname() final{                                //final��������ֹ��д�������������ٴα��̳к���д�������; 
			cout << "�����ȡ���Ʋ�����" + name << endl; return name;
		};
		virtual void setname(string name = "teacher"){ this->name = name; };
	private:
		virtual string getcourse(){ return course; };                    //c++�У�private����Ҳ�����黯��д��java��ֻ����дpublic��protect����//�̳�ʱ�����޸ķ������Ʒ�
		string name;
	protected:
		string course;
	};



	//������������
	class Headmaster final :public Teacher          //final��ǵ��಻�ܱ��̳�
	{
	public:
		//using Teacher::Teacher;                                      //���캯�����ܼ̳У�ֻ����ʾ����
		Headmaster(){ cout << "�������޲ι��캯����headmaster" << endl; }; //������Ĺ��캯��  ����ǰ���Զ����û����Ĭ�Ϲ��캯��
		Headmaster(string name) :Teacher(name){                         //������Ĺ��캯��,����ǰ�������ʾ���õĻ��๹�캯��
			cout << "�������вι��캯����" + name << endl;
		};
		~Headmaster(){ cout << "��������������" << endl; };                    //��������
		//ʹ��ʱ,Ĭ�ϲ���ȡֵ����ָ������  ������������ָ�����
		//virtual void setname(string name="headmaster") override;     //������Ĺ��캯��  û��usingʱ  Ĭ��Ϊ��д�����а汾   ��usingʱ����ʾ��д�˵�ǰ�汾   ���������ʹ�ò�ͬ��Ĭ�ϲ���
		virtual Student& getstudent() override{ return student; };       //�ǵ����override,��Ϊ����ı�,������û�ı�ᱨ��,���������޸�������
		virtual void setstudent(Student& students) override{           //Ӧ����д,���ط�����,���а汾���麯�����Բ���д����д����д�����ֺ����黯����
			this->student = student;
		};
		virtual string getcourse() override{ return course; };           //��д�����private���������޸ķ������η�

	private:
		Student student;

	};

};


template<class TT = int>
class classA{                              //template<class T>Ϊģ�壬����TΪ��ȷ�����ͣ�classAΪ��ģ��,����Ϊ������������Ĭ��ֵ��������ʹ���ඨ��ʾ��ʱ����Ȼ��Ҫʹ��<>
public:
	TT add(TT tt, TT pp);                                           //ʹ��ģ�庯��
	template<class TT> TT plus(TT tt, TT pp){                       //����ģ���ڲ����庯��
		return tt + pp;
	}
};