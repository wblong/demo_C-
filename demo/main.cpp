#pragma once                  //防止文件被多重包含
#include <stdio.h>
#include <stdlib.h>
#include <chrono>             //正则表达式   vs2012后有
#include <iostream>           //数据流
#include <memory>             //内存操作
#include <fstream>            //文件流
#include <string>             //字符串
#include <regex>              //正则表达式
#include <exception>          //异常
#include <stdexcept>          //异常类型
#include <iterator>           //迭代器
#include <array>              //可获取大小的固定数组
#include <vector>             //数据结构  连续分布的动态数组
#include <list>               //不连续分布的双向链表
#include <deque>              //双头队列
#include <queue>              //先入先出队列
#include <stack>              //先入后出堆
#include <set>                //有序集合
#include <map>                //哈希表
#include <algorithm>          //STL算法
#include <numeric>            //数值计算算法
#include <math.h>             //数值计算算法
#include <functional>         //函数指针，将函数指针作为自定义函数参数   实现设置回调函数
#include <thread>             //多线程库   vs2012后有
#include <atomic>             //原子类型  线程安全  vs2012后有
#include <mutex>              //互斥体类型  vs2012后有
#include <time.h>             //时间类型
#include "namespace.h"        //自定义空间  ""先搜索本地目录  再遍历全部  <>遍历系统目录     引用h文件  相当于h文件直接展开

using namespace std;                                                    //重用空间函数
using namespace mynamespace;                                            //自定义命名空间   要避免不同空间下的同名变量函数冲突

struct People                                                           //自定义结构体
{
	string name;
	int age;
}People1;                                                               //People是类型，People1是变量

typedef int* intptr;                                                    //类型别名  typedef为已有类型声明提供一个新的名称  using有类似功能

const string studentname = "student";                                   //常量变量  任何不在名称空间、函数、类中的名称都被认为全局作用
string stringtemp = "";                                                   //全局变量
const int getstudentnumber(){ return 33; }                                //常量表达式

typedef void(*funtype)(string);                                        //定义函数指针类型  输入string  返回void    等价于 using funtype = void (*)(string);。为了出现频率高的代码，避免改动繁琐性和书写繁琐性
//function<void(string)> function_pointer = printstring;                //函数指针
//void (*function_pointer)(string str)= printstring;                    //函数指针
void printstring(string str);                                           //函数声明
void process(const vector<string>& vec, function<void(string)> fun);     //函数声明
inline void sprintf1(string str){                                       //内联函数，编译时在代码处展开，为读使用频率高，且代码量小的函数。避免改动繁琐型和调用快捷性
	cout << str << endl;
}
void printstring(string str)                                            //自定义函数（打印输出字符串）
{
	cout << str << endl;
}
void process(const vector<string>& vec, function<void(string)> fun)      //自定义函数（调用函数fun，调用向量成员）
{
	for (auto& item : vec)
		fun(item);
}
template<class T> 
void print(T a)                                       //模板函数，函数模板通式
{
	cout << a << endl;
}
string Student::default_name = studentname;                             //类内静态变量，无需创建对象，初始化需放在函数外全局区域
int main()
{
	myfun("代码调试者：栾鹏");                                          //调用自定义空间内函数，//两个字符串常量不能相加
	cout << "============基本类型数据============" << endl;                   //cout<<    <<endl打印输出
	timenow = time(NULL);                                               //空间静态变量，直接使用，此句返回的只是一个时间戳

	cout << "当前时间戳" << timenow << "\n";                                   //时间戳表示指定时间点距离标准时间原点之间的秒数

	int* const temp = new int(0);                                       //const作用于左侧的类型(作用于*指针)，此处表示指向不变，若作用于int(const int*  var)，表示指向的数据不变
	int& studentnumber = *temp;                                         //设置引用,引用不占内存,不创建对象,只是别名

	cout << "默认学生名称为" + studentname + "\n";                           //cout中支持转移字符，支持打印各种类型数据
	cout << "默认班级人数为" << (studentnumber = getstudentnumber()) << endl; //打印输出，常量变量、调用常量表达式，endl是换行刷新

	string str1 = to_string(std::min(studentnumber, 22));                //其他类型转化为字符串。min和max被vs中windows.h定义为了宏，导致库里面的正常函数没法使用:
	string str2 = str1 + "34";                                            //字符串使用+合并，字符串不能直接初始化为两个常量字符串相加。如果不能string str2 = "11"+"34";    
	studentnumber = (stoi(str2)) / 10;                                   //字符串转化为指定进制的其他类型，stoi，stof，stod
	cout << "算上班主任，班级人数：" << studentnumber;
	cout.flush();                                                       //显示刷新数据流，写入控制台，不换行
	//float classtime = 45_min+50_s;                                    //调用自定义字面量，c++11后才有
	classA<int> initstr;                                                //定义模板类 <>内替换成需要的类型，                
	auto  int1 = initstr.plus(3, 2);                                       //自动变量类型，会去除const限定符和引用 
	decltype(int1) int2 = 0x11;                                           //类型借用，0x为16进制表示
	int int3 = int1^int2;                                                 //补码按位异或   即101与10001  按位异或为10100
	cout << "；其中男孩个数约" << int3 << endl;                               //打印输出

	classA<> initstr1;                                                  //使用默认类型参数

	//栈stack跟随函数，一个函数，一个堆栈，相互不影响，自动释放，一级缓存，先进后出，内存限定  内存向下增长
	//堆heap，公共空间  手动释放，二级缓存存储，链表结构，内存根据物理内存，内存向上增长。
	//全局区、文字常量区、程序代码区   字符指针初始化的字符串在常量，指针在栈上
	cout << "============类的指针与数组============" << endl;
	Student* student = nullptr;                                           //指针定义初始化为空
	student = new Student;                                              //开辟指针内存   指针存在栈中  对象在堆中
	//student->age = 3;                                                 //私有成员  无法访问
	//(*student).name = "小明";                                           //保护成员   无法访问
	student->setname("小明");
	delete student;                                                     //释放指针内存
	student = nullptr;                                                  //指针置空   防止野指针
	Student* students = nullptr;                                          //类指针定义，初始化为空
	students = new Student[3];                                          //开辟数组内存
	delete[] students;                                                  //释放数组内存

	string namestr;
	int age;
	print("输入学生姓名和年龄：");                                        //调用模板函数
	cin >> namestr >> age;                                                  //获取从窗口输入的数据，分别放在namestr变量和age变量中
	auto vlambda = [namestr](int age){                                  //lambda表达式，函数名代替函数体展开  []内为捕获变量  ()内为参数，在没有参数时可以不加()
		cout << "创建学生结构体：名称：" + namestr << "；年龄：" << age << endl;
	};
	vlambda(age);                                                       //展开vlambda函数




	cout << "============学生,基类操作============" << endl;
	Student student1("晓刚");                                         //在堆栈中创建对象
	student1.setname("小刚");                                         //调用类内函数，在栈上使用对象
	Student* student2 = new Student("晓红", 7);                            //使用new 开辟的内存在堆上，指针在栈上，需要代码释放在堆上的对象
	student2->setname("小红");                                            //在堆上使用对象
	Student student3(student1);                                         //调用复制构造函数，即复制一个对象，
	Student& student4 = student3;                                       //设置引用,引用不创建对象,只是别名
	student4 = *student2;                                               //赋值构造函数
	student4.setname("小刘");
	Student student5 = student1 + student4;                               //重载加法运算符
	student5 = student3 + "小韩";                                           //重载加法运算符
	cout << "学生列表：" + student1.getname()
		<< +"、" + student2->getname()
		<< "、" + student3.getname()
		<< "、" + student4.getname()
		<< "、" + student5.getname() << endl;
	delete student2;                                                    //释放内存，会调用析构函数。只有通过new开辟了内存的才需要释放，否则会自动释放
	student2 = nullptr;                                                 //指针置空，避免野指针
	auto student6 = unique_ptr<Student>();                              //使用智能指针，指针销毁时会自动销毁指向内存，在try catch中不用担心出错而指针内存泄漏





	cout << "============班长派生类操作============" << endl;
	Monitor monitor;                                                    //生成派生类，会先调用基类构造函数，再调用派生类构造函数
	Student student11 = monitor;                                        //派生类转化为基类，产生截断，这里调用的是基类的构造函数
	//指向派生类对象的基类指针，可以调用派生类重写的虚函数、基类中的非虚函数、基类的默认参数、基类中未被重写的虚函数(被派生类继承默认了)
	Student& student12 = monitor;                                       //引用指向派生类对象，派生类转为基类，不产生截断。引用定义时需要初始化，引用不可改变
	student12.setname("小明");                                            //调用派生类重写的虚函数
	student12.getname();                                                //调用基类函数
	student12.getage();                                                 //静态函数，所有对象共享
	Student::getage();                                                  //静态函数，可通过类型名称调用
	monitor.getname("王");                                               //调用派生类的新增函数
	monitor.getname();                                                  //调用派生类包含的基类函数，不包含没法调用
	monitor.setage();                                                   //调用派生类覆盖的函数
	monitor.getage();                                                   //





	cout << "============老师类型操作============" << endl;
	Teacher* teacher = nullptr;                                         //抽象类不能实例化对象，但是可以建立指针                                                   
	teacher = new Headmaster();                                         //抽象类的子类可以实例化对象   因为子类重写了所有纯虚函数，使得子类成为非抽象类
	teacher->getname();                                                 //指针可以调用基类的方法，因为存在声明  但是实现方法是不一定   因为不同派生类写入方法不同
	delete teacher;                                                     //基类指针
	Headmaster Headmaster1("刘家航班主任");





	cout << "============流操作============" << endl;

	ifstream infile("input.txt", std::ios::in);                                     //输入文件流ifstream  输出文件流  ofstream   fstream双向文件流同时读写文件
	ofstream outfile("output.txt", ios_base::trunc);                     //app写之前移动到文件尾，ate打开后移动到文件尾，binary二进制模式输入输出
	//in从头开始读   out从头开始写   trunc打开删除已有数据
	if (outfile && infile)
	{
		try                                                             //try{}catch(){}  尝试运行某段代码
		{
			infile.tie(&outfile);                                       //将输入流与输出流绑定，输入流会自动刷新至输出流，两个输出流也可以绑定，实现同步
			string readstr;
			infile >> readstr;                                            //读入数据流  数据流同时进入输出流
			outfile << readstr;                                           //再一次写入字符串
			ios_base::streampos curpos = outfile.tellp();               //获取标记位置，输出流tellp，输入流tellg
			if (10 == curpos)                                             //这里等号两边缓过来会报错
			{
				//输出流seekp，输入流seekg //iso_base::end流的结尾，iso_base::beg流的开始，iso_base::cur流的当前位置
				outfile.seekp(-2, ios_base::end);                        //-2表示指定流位置前面2个位置
				outfile << 0;
				outfile.close();
			}

			char line[1024] = { 0 };                                        //按行读取文件
			while (infile.getline(line, sizeof(line)))
			{
			}
		}
		catch (const exception err)                                     //抛出异常并不一定遵循异常列表，java只能抛出异常列表中的异常
		{                                                               //c++中的所有异常都是exception的派生  所以抛出exception 没有针对性
			cout << "异常描述:" << err.what() << endl;                        //所有异常类都有.what()，异常描述函数
		}
		catch (...)                                                     //匹配所有异常          
		{                                                               //try catch 中异常类不需要字符串设置构造函数 throw需要字符串设置异常类的构造函数
			throw invalid_argument("无法打开文件");                     //抛出invalid_argumenty异常  除exception的所有异常类都需要字符串设置构造函数
		}
	}
	else
		cout << "文件不存在" << endl;





	cout << "============STL容器和算法操作============" << endl;            //STL  4类16大容器
	//顺序容器  vector、deque、list、forward_list、array
	//关联容器map、multimap、set、multiset
	//无序关联容器或哈希表 unordered_map、 unordered_multimap、unordered_set、unordered_multiset
	//容器适配器  queue、priority_queue、stack
	//容器：一定数据结构的数据集；分配器：数据元素的内存管理；元素迭代器iterator:容器元素的访问（指向元素的指针）；算法：数据运算
	array<string, 3> allstr0 = { "name1", "name2", "name3" };                //可获取大小的固定数组
	vector<string> allstr1 = vector<string>(10);                                              //连续分布的动态数组
	list<string> allstr2;                                               //不连续分布的双向链表
	deque<string> allstr3;                                              //连续分布的双头队列
	queue<string> allstr4;                                              //先入先出的队列
	stack<string> allstr5;                                              //先入后出的栈
	set<string>  allstr6;                                               //有序的元素唯一的集合
	multiset<string> allstr7;                                           //有序的元素不唯一的集合
	map<string, int>   map_student;                                      //multimap支持重复键值
	map_student.insert(pair<string, int>("小明", 12));                  //map的插入

	string allnamestr[] = { "小明", "小王", "小刚", "小红", "小刘" };
	vector<string> allstudent(allnamestr, allnamestr + 5);                //数组转化为向量
	//allstudent.assign(5,"studentname");                               //动态分配内存
	vector<string> allteacher(2);                                       //定义字符串向量;
	allteacher[0] = "王老师";
	allteacher[1] = "张老师";
	if (allstudent != allteacher)                                         //向量==或!=进行了重载
	{
		allstudent.push_back("小张");                                 //尾部添加元素
		allstudent.pop_back();                                          //尾部删除元素
		auto iter = begin(allstudent);                                  //获取首部
		allstudent.insert(iter, "小李");                                   //在指定位置插入元素
		iter++;                                                         //相当于指针++
		*iter = "小陈";
		allstudent.erase(iter);                                         //在指定位置删除元素  删除后iter不能继续使用了
		for (vector<string>::iterator iter1 = begin(allstudent); iter1 != end(allstudent); ++iter1)
		{
			cout << *iter1 << endl;
		}
		for (const auto& iter2 : allteacher)                              //迭代器引用，反向迭代器rbegin(vectorstr1)，insert_iterator插入迭代器，move_iterator移动迭代器
		{
			cout << iter2 << endl;
		}
	}
	process(allstudent, [](string str){cout << str << endl; });               //使用lambda设置遍历的回调函数
	process(allteacher, printstring);                                    //自定义函数作为参数传递

	int sum = 0;
	vector<int> vectorint1(10, 1);
	auto it = find_if_not(begin(vectorint1), end(vectorint1), [](int i){return i<8; });    //搜索算法
	for_each(begin(vectorint1), end(vectorint1), [&sum](int i){sum += i; });                 //操作算法，每个元素执行回调函数
	partition(begin(vectorint1), end(vectorint1), [](int i){return i % 2; });                //分区算法  一个目标到两个目标  通过返回值 true、false决定区间//lambda表达式，返回true的排在前面   返回false的排在后面
	std::sort(begin(vectorint1), end(vectorint1));                                           //排序算法，只能用于顺序容器




	cout << "============字符串和正则法则===========" << endl;
	string strtemp = "luanpengluanpeng";
	string str11(strtemp, 2, 3);                                                          //构造函数，原字符串，起始位置，截取长度。从后向前依次可以省略。string str2(num,c);生成num个c字符的字符串
	string str = "luanpengluanpeng";
	str.swap(strtemp);  //交换字符串的值，
	//append和push_back在尾部添加字符串，
	//insert在指定位置插入字符串，
	//erase(在指定位置删除长度字符串，
	//replace替换字符串，size和length返回长度，
	//substr子字符串，
	//find，返回的string::size_type 类型的值，string::npos表示字符串末尾后，查询结束位置
	regex myregex("ua[l-q]");                                                           //正则表达式模式   //正则表达式   ^$\.*+?()[]{}|为特殊字符
	regex_match(str, myregex);                                                           //验证源字符串是否存在指定模式的子字符串
	smatch mysmatch;                                                                    //结果集  字符串数组
	if (regex_search(str, mysmatch, myregex))                                              //查找符合规则的字符串,默认只查询第一个符合条件的   返回存在或不存在bool
	{
		for (auto x = mysmatch.begin(); x != mysmatch.end(); x++)
			cout << x->str() << endl;
	}
	//$1表示匹配出的字符串第一段模糊区间  $&表示匹配出来的所有字符串  $表示匹配出来段前的字符串   $`表示匹配出来的断后的字符串
	const string format("name=$1");                                                        //替换格式  替换成name=匹配出来的模糊字符串  
	string result = regex_replace(str, myregex, format);                                    //字符串替换
	cout << result << endl;




	thread t1(printstring, "这是一个新线程");                                           //创建多线程  可以有多个参数
	//t1.join;                                                                          //顺序执行线程
	t1.detach();                                                                        //创建线程分支


	//如果使用较为频繁的对象构造，可以使用对象池   一次构造函数，每次去读取即可
	//内存常见错误
	//内存泄漏，释放操作不匹配，多次释放，释放未分配的，释放堆栈内存
	//访问无效内存，访问已释放内存，内存越界，指针未初始化
	system("pause");

}




//自定义字面量可以让用户定义符号所引起的变化   以_开头   定义
//标准中 i  il   if被字面量为创建复数complex<double>  complex<long double>   complex<float>
//float operator"" _min(float minute)
//{
//  return minute/60;
//}
//float operator"" _s(float second)
//{
//  return second/60/60;
//}


//只在c++11编译器以后
//通过重载边界条件
//double sum2(){
//  return 0;
//}
////变长模板
//template<typename T1,typename...T2> double sum2(T1 p,T2...args)
//{
//  double ret = p+sum2(args);
//  return ret;
//}