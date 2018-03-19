#pragma once  //防止文件被多重包含
#include <stdio.h>
#include <iostream>  //数据流
#include <string>    //字符串
#include <exception>  //异常
#include <stdarg.h>  //变化参数
#ifndef PI   //如果没有定义PI则定义，否则跳过  避免重复包含
#define PI 3.1415926
#endif
using namespace std;  //常用空间函数
//自定义命名空间
namespace mynamespace
{
	//静态整型
	static long long timenow;
	//自定义函数
	void myfun(string str);

	//自定义类-学生类
	class Student
	{
	public:                                                             //公共成员，外部可以访问的成员
		Student();                                                      //无参构造函数   //默认构造函数（参数全有默认值+无参函数）可以无参调用
		Student(string name, int age = default_age);                       //有参构造函数   //函数名相同,方法重载,age含有默认参数,此参数可有可无
		Student(int age);                                               //有参构造函数 //函数名相同,方法重载,函数名相同，参数类型和数量不同的为重载，与返回值无关
		virtual ~Student();                                                //析构函数  //销毁对象时，自动调用该函数，该方法用来释放内存，最好设为虚函数，这样多态特性，能销毁派生类对象创建的内存
		Student(const Student& another);                                //复制构造函数
		Student& operator=(const Student& another);                     //重载赋值运算符，在函数内生成类对象的就要返回类，没有生成类对象的返回类引用
		//可以重载关系运算符 算数运算符  递增递减运算符  按位运算  二元逻辑运算符  插入<<运算符  提取>>运算符  下标运算符  函数调用运算符  解除引用运算符  内存分配和释放运算符
		Student operator+(const Student& another) const;                //加法运算符重载  Student的加法运算，const函数不改变类内成员，返回对象不返回引用是因为生成了一个新的对象，与原对象并列存在
		Student operator+(const string& anothername) const;             //加法运算符重载   避免重载时的隐式转化 +必须在Student的后面。对象名称既可以作为对象返回，又可以作为对象引用返回
		virtual void setname(string name);                              //virtual关键字，虚函数，支持派生类重写，最好所有函数都设置为虚函数，java就是这么做的
		string getname() const;                                         //不改变数据成员的函数声明为const
		void setage(int age);                                           //常规函数声明
		static int getage();                                            //static关键字，静态函数，静态方法不能重写，不存在继承  //静态方法属于定义它的类的名称，不属于特定的对象，调用时使用名字解析
		static string default_name;                                     //静态数据,存储在静态区
		static const int default_age = 18;                                //const关键字，常值数据，数据存储在文字常量区，const数据定义时需要赋值。
		//mutable标记的为可变变量   在const函数中可以改变值的变量
		enum allsex{ boy, girl };                                          //enum关键字，枚举类型，用于限定参数的取值范围，相等于define，或者const
		class sex{                                                      //定义内部类，性别
			public:
				string getsex();
				void setsex(allsex sextype);                                //使用枚举类型作为参数
			private:
				string sexstr;
		};
	protected:                                                          //派生类可以访问的成员
		string name;
	private:                                                            //只能在类内访问的成员
		int age;
	};


	//派生类-班长类
	class Monitor :public Student                                       //公有继承   public代表基类的最高访问权限  所有操作的权限自动降级为此权限  尽量使用public
	{
	public:
		Monitor(){                                                     //构造函数不能继承
			this->task = "帮助老师管理班级";                           //函数定义可以直接在声明中实现，也可以在对象cpp中实现，也可以不实现，在调用时实现
			name = "monitor";
			cout << "无参派生类构造函数" << endl;                           //cout<<           <<endl; 输出内容到dos窗口
		};
		virtual void setname(string name) override                     //override，重写虚方法  virtual、override可以不写，override写上以便与隐藏函数混淆
		{
			this->name = name;                                           //this作为对象Student
			cout << "派生类设置名称参数:" + name << endl;
		}
		using Student::getname;                                        //包含基类函数，使用using关键字显示的包含基类中定义的同名的所有版本的方法，包含后相当于在当前内中展开
		string getname(string surname)                                 //创建新成员函数，与基类形成重载  因为参数不同，若不使用using包含，则会隐藏基类函数
		{
			cout << "派生类获取名称参数:" + surname + name << endl;
			return surname + name;
		}
		void setage()                                                  //隐藏基类函数，与基类函数同名
		{
			age = 7;
			cout << "派生类设置年龄参数:" << age << endl;
		}
		int getage(){                                                  //创建对象成员函数，基类中的函数为静态函数，不属于对象，属于类
			cout << "派生类读取年龄参数:" << age << endl;
			return age;
		};
		string gettask(){ return task; };                                //创建对象成员函数
		void settask(string task, ...){                                 //...表示不定长的参数数目。创建对象成员函数
			va_list arg_ptr;                                           //定义参数列表
			va_start(arg_ptr, task);                                    //将参数列表起始位置绑定为第一个参数
			string aa = " ";
			// while (aa!="" && !aa==NULL)                              //无法对参数列表个数或结尾进行判断，必须自己传入特性参数来代表个数或结尾
			{
				aa = va_arg(arg_ptr, string);                           //迭代读取参数，并转化为相应的类型
			}
			va_end(arg_ptr);                                           //参数清理工作
			this->task = task;
		};
	private:
		int age;                                                       //基类中age为private，派生类无法访问，派生类重新定义
		string task;                                                   //添加派生类自有属性
	};





	//自定义类-老师类
	class Teacher
	{
	public:
		Teacher() :name("teacher"), course("语文"){                        //基类的默认构造函数，同时初始化数据成员name、course
			cout << "基类无参构造函数：" + name << endl;
		};
		Teacher(string name){ cout << "基类有参构造函数：" + name << endl; };   //基类的有参构造函数
		~Teacher(){ cout << "基类析构函数" << endl; };                        //析构函数
		friend class Student;                                          //友元，Student 类中所有的方法可以访问Teacher的private、protected、public数据成员和方法
		friend void Student::setname(string name);                     //只有设置友元的函数可以访问当前类的成员和方法，只有Student:;setname函数可以访问Teacher的成员方法
		virtual Student& getstudent() = 0;                               //=0代表为纯虚函数，没有定义方法，只是声明了方法，包含纯虚函数的类为抽象类，抽象类不能实例对象
		virtual void setstudent(Student& students) = 0;                 //&为引用，相当于变量别名
		virtual string getname() final{                                //final函数，禁止重写，用在派生类再次被继承后重写的情况下; 
			cout << "基类获取名称参数：" + name << endl; return name;
		};
		virtual void setname(string name = "teacher"){ this->name = name; };
	private:
		virtual string getcourse(){ return course; };                    //c++中，private函数也可以虚化重写，java中只能重写public和protect方法//继承时可以修改访问限制符
		string name;
	protected:
		string course;
	};



	//创建班主任类
	class Headmaster final :public Teacher          //final标记的类不能被继承
	{
	public:
		//using Teacher::Teacher;                                      //构造函数不能继承，只能显示调用
		Headmaster(){ cout << "派生类无参构造函数：headmaster" << endl; }; //派生类的构造函数  调用前会自动调用基类的默认构造函数
		Headmaster(string name) :Teacher(name){                         //派生类的构造函数,调用前会调用显示引用的基类构造函数
			cout << "派生类有参构造函数：" + name << endl;
		};
		~Headmaster(){ cout << "派生类析构函数" << endl; };                    //析构函数
		//使用时,默认参数取值根据指针类型  函数方法根据指向对象
		//virtual void setname(string name="headmaster") override;     //派生类的构造函数  没有using时  默认为重写了所有版本   有using时，表示重写了当前版本   派生类可以使用不同的默认参数
		virtual Student& getstudent() override{ return student; };       //记得添加override,因为基类改变,派生类没改变会报错,这样提醒修改派生类
		virtual void setstudent(Student& students) override{           //应该重写,重载方法的,所有版本。虚函数可以不重写，重写不重写都保持函数虚化特性
			this->student = student;
		};
		virtual string getcourse() override{ return course; };           //重写基类的private函数，并修改访问修饰符

	private:
		Student student;

	};

};


template<class TT = int>
class classA{                              //template<class T>为模板，类型T为不确定类型，classA为类模板,可以为不定类型设置默认值，但是在使用类定义示例时，仍然需要使用<>
public:
	TT add(TT tt, TT pp);                                           //使用模板函数
	template<class TT> TT plus(TT tt, TT pp){                       //在类模板内部定义函数
		return tt + pp;
	}
};