#pragma once                  //��ֹ�ļ������ذ���
#include <stdio.h>
#include <stdlib.h>
#include <chrono>             //������ʽ   vs2012����
#include <iostream>           //������
#include <memory>             //�ڴ����
#include <fstream>            //�ļ���
#include <string>             //�ַ���
#include <regex>              //������ʽ
#include <exception>          //�쳣
#include <stdexcept>          //�쳣����
#include <iterator>           //������
#include <array>              //�ɻ�ȡ��С�Ĺ̶�����
#include <vector>             //���ݽṹ  �����ֲ��Ķ�̬����
#include <list>               //�������ֲ���˫������
#include <deque>              //˫ͷ����
#include <queue>              //�����ȳ�����
#include <stack>              //��������
#include <set>                //���򼯺�
#include <map>                //��ϣ��
#include <algorithm>          //STL�㷨
#include <numeric>            //��ֵ�����㷨
#include <math.h>             //��ֵ�����㷨
#include <functional>         //����ָ�룬������ָ����Ϊ�Զ��庯������   ʵ�����ûص�����
#include <thread>             //���߳̿�   vs2012����
#include <atomic>             //ԭ������  �̰߳�ȫ  vs2012����
#include <mutex>              //����������  vs2012����
#include <time.h>             //ʱ������
#include "namespace.h"        //�Զ���ռ�  ""����������Ŀ¼  �ٱ���ȫ��  <>����ϵͳĿ¼     ����h�ļ�  �൱��h�ļ�ֱ��չ��

using namespace std;                                                    //���ÿռ亯��
using namespace mynamespace;                                            //�Զ��������ռ�   Ҫ���ⲻͬ�ռ��µ�ͬ������������ͻ

struct People                                                           //�Զ���ṹ��
{
	string name;
	int age;
}People1;                                                               //People�����ͣ�People1�Ǳ���

typedef int* intptr;                                                    //���ͱ���  typedefΪ�������������ṩһ���µ�����  using�����ƹ���

const string studentname = "student";                                   //��������  �κβ������ƿռ䡢���������е����ƶ�����Ϊȫ������
string stringtemp = "";                                                   //ȫ�ֱ���
const int getstudentnumber(){ return 33; }                                //�������ʽ

typedef void(*funtype)(string);                                        //���庯��ָ������  ����string  ����void    �ȼ��� using funtype = void (*)(string);��Ϊ�˳���Ƶ�ʸߵĴ��룬����Ķ������Ժ���д������
//function<void(string)> function_pointer = printstring;                //����ָ��
//void (*function_pointer)(string str)= printstring;                    //����ָ��
void printstring(string str);                                           //��������
void process(const vector<string>& vec, function<void(string)> fun);     //��������
inline void sprintf1(string str){                                       //��������������ʱ�ڴ��봦չ����Ϊ��ʹ��Ƶ�ʸߣ��Ҵ�����С�ĺ���������Ķ������ͺ͵��ÿ����
	cout << str << endl;
}
void printstring(string str)                                            //�Զ��庯������ӡ����ַ�����
{
	cout << str << endl;
}
void process(const vector<string>& vec, function<void(string)> fun)      //�Զ��庯�������ú���fun������������Ա��
{
	for (auto& item : vec)
		fun(item);
}
template<class T> 
void print(T a)                                       //ģ�庯��������ģ��ͨʽ
{
	cout << a << endl;
}
string Student::default_name = studentname;                             //���ھ�̬���������贴�����󣬳�ʼ������ں�����ȫ������
int main()
{
	myfun("��������ߣ�����");                                          //�����Զ���ռ��ں�����//�����ַ��������������
	cout << "============������������============" << endl;                   //cout<<    <<endl��ӡ���
	timenow = time(NULL);                                               //�ռ侲̬������ֱ��ʹ�ã��˾䷵�ص�ֻ��һ��ʱ���

	cout << "��ǰʱ���" << timenow << "\n";                                   //ʱ�����ʾָ��ʱ�������׼ʱ��ԭ��֮�������

	int* const temp = new int(0);                                       //const��������������(������*ָ��)���˴���ʾָ�򲻱䣬��������int(const int*  var)����ʾָ������ݲ���
	int& studentnumber = *temp;                                         //��������,���ò�ռ�ڴ�,����������,ֻ�Ǳ���

	cout << "Ĭ��ѧ������Ϊ" + studentname + "\n";                           //cout��֧��ת���ַ���֧�ִ�ӡ������������
	cout << "Ĭ�ϰ༶����Ϊ" << (studentnumber = getstudentnumber()) << endl; //��ӡ������������������ó������ʽ��endl�ǻ���ˢ��

	string str1 = to_string(std::min(studentnumber, 22));                //��������ת��Ϊ�ַ�����min��max��vs��windows.h����Ϊ�˺꣬���¿��������������û��ʹ��:
	string str2 = str1 + "34";                                            //�ַ���ʹ��+�ϲ����ַ�������ֱ�ӳ�ʼ��Ϊ���������ַ�����ӡ��������string str2 = "11"+"34";    
	studentnumber = (stoi(str2)) / 10;                                   //�ַ���ת��Ϊָ�����Ƶ��������ͣ�stoi��stof��stod
	cout << "���ϰ����Σ��༶������" << studentnumber;
	cout.flush();                                                       //��ʾˢ����������д�����̨��������
	//float classtime = 45_min+50_s;                                    //�����Զ�����������c++11�����
	classA<int> initstr;                                                //����ģ���� <>���滻����Ҫ�����ͣ�                
	auto  int1 = initstr.plus(3, 2);                                       //�Զ��������ͣ���ȥ��const�޶��������� 
	decltype(int1) int2 = 0x11;                                           //���ͽ��ã�0xΪ16���Ʊ�ʾ
	int int3 = int1^int2;                                                 //���밴λ���   ��101��10001  ��λ���Ϊ10100
	cout << "�������к�����Լ" << int3 << endl;                               //��ӡ���

	classA<> initstr1;                                                  //ʹ��Ĭ�����Ͳ���

	//ջstack���溯����һ��������һ����ջ���໥��Ӱ�죬�Զ��ͷţ�һ�����棬�Ƚ�������ڴ��޶�  �ڴ���������
	//��heap�������ռ�  �ֶ��ͷţ���������洢������ṹ���ڴ���������ڴ棬�ڴ�����������
	//ȫ���������ֳ����������������   �ַ�ָ���ʼ�����ַ����ڳ�����ָ����ջ��
	cout << "============���ָ��������============" << endl;
	Student* student = nullptr;                                           //ָ�붨���ʼ��Ϊ��
	student = new Student;                                              //����ָ���ڴ�   ָ�����ջ��  �����ڶ���
	//student->age = 3;                                                 //˽�г�Ա  �޷�����
	//(*student).name = "С��";                                           //������Ա   �޷�����
	student->setname("С��");
	delete student;                                                     //�ͷ�ָ���ڴ�
	student = nullptr;                                                  //ָ���ÿ�   ��ֹҰָ��
	Student* students = nullptr;                                          //��ָ�붨�壬��ʼ��Ϊ��
	students = new Student[3];                                          //���������ڴ�
	delete[] students;                                                  //�ͷ������ڴ�

	string namestr;
	int age;
	print("����ѧ�����������䣺");                                        //����ģ�庯��
	cin >> namestr >> age;                                                  //��ȡ�Ӵ�����������ݣ��ֱ����namestr������age������
	auto vlambda = [namestr](int age){                                  //lambda���ʽ�����������溯����չ��  []��Ϊ�������  ()��Ϊ��������û�в���ʱ���Բ���()
		cout << "����ѧ���ṹ�壺���ƣ�" + namestr << "�����䣺" << age << endl;
	};
	vlambda(age);                                                       //չ��vlambda����




	cout << "============ѧ��,�������============" << endl;
	Student student1("����");                                         //�ڶ�ջ�д�������
	student1.setname("С��");                                         //�������ں�������ջ��ʹ�ö���
	Student* student2 = new Student("����", 7);                            //ʹ��new ���ٵ��ڴ��ڶ��ϣ�ָ����ջ�ϣ���Ҫ�����ͷ��ڶ��ϵĶ���
	student2->setname("С��");                                            //�ڶ���ʹ�ö���
	Student student3(student1);                                         //���ø��ƹ��캯����������һ������
	Student& student4 = student3;                                       //��������,���ò���������,ֻ�Ǳ���
	student4 = *student2;                                               //��ֵ���캯��
	student4.setname("С��");
	Student student5 = student1 + student4;                               //���ؼӷ������
	student5 = student3 + "С��";                                           //���ؼӷ������
	cout << "ѧ���б�" + student1.getname()
		<< +"��" + student2->getname()
		<< "��" + student3.getname()
		<< "��" + student4.getname()
		<< "��" + student5.getname() << endl;
	delete student2;                                                    //�ͷ��ڴ棬���������������ֻ��ͨ��new�������ڴ�Ĳ���Ҫ�ͷţ�������Զ��ͷ�
	student2 = nullptr;                                                 //ָ���ÿգ�����Ұָ��
	auto student6 = unique_ptr<Student>();                              //ʹ������ָ�룬ָ������ʱ���Զ�����ָ���ڴ棬��try catch�в��õ��ĳ����ָ���ڴ�й©





	cout << "============�೤���������============" << endl;
	Monitor monitor;                                                    //���������࣬���ȵ��û��๹�캯�����ٵ��������๹�캯��
	Student student11 = monitor;                                        //������ת��Ϊ���࣬�����ضϣ�������õ��ǻ���Ĺ��캯��
	//ָ�����������Ļ���ָ�룬���Ե�����������д���麯���������еķ��麯���������Ĭ�ϲ�����������δ����д���麯��(��������̳�Ĭ����)
	Student& student12 = monitor;                                       //����ָ�����������������תΪ���࣬�������ضϡ����ö���ʱ��Ҫ��ʼ�������ò��ɸı�
	student12.setname("С��");                                            //������������д���麯��
	student12.getname();                                                //���û��ຯ��
	student12.getage();                                                 //��̬���������ж�����
	Student::getage();                                                  //��̬��������ͨ���������Ƶ���
	monitor.getname("��");                                               //�������������������
	monitor.getname();                                                  //��������������Ļ��ຯ����������û������
	monitor.setage();                                                   //���������า�ǵĺ���
	monitor.getage();                                                   //





	cout << "============��ʦ���Ͳ���============" << endl;
	Teacher* teacher = nullptr;                                         //�����಻��ʵ�������󣬵��ǿ��Խ���ָ��                                                   
	teacher = new Headmaster();                                         //��������������ʵ��������   ��Ϊ������д�����д��麯����ʹ�������Ϊ�ǳ�����
	teacher->getname();                                                 //ָ����Ե��û���ķ�������Ϊ��������  ����ʵ�ַ����ǲ�һ��   ��Ϊ��ͬ������д�뷽����ͬ
	delete teacher;                                                     //����ָ��
	Headmaster Headmaster1("���Һ�������");





	cout << "============������============" << endl;

	ifstream infile("input.txt", std::ios::in);                                     //�����ļ���ifstream  ����ļ���  ofstream   fstream˫���ļ���ͬʱ��д�ļ�
	ofstream outfile("output.txt", ios_base::trunc);                     //appд֮ǰ�ƶ����ļ�β��ate�򿪺��ƶ����ļ�β��binary������ģʽ�������
	//in��ͷ��ʼ��   out��ͷ��ʼд   trunc��ɾ����������
	if (outfile && infile)
	{
		try                                                             //try{}catch(){}  ��������ĳ�δ���
		{
			infile.tie(&outfile);                                       //����������������󶨣����������Զ�ˢ��������������������Ҳ���԰󶨣�ʵ��ͬ��
			string readstr;
			infile >> readstr;                                            //����������  ������ͬʱ���������
			outfile << readstr;                                           //��һ��д���ַ���
			ios_base::streampos curpos = outfile.tellp();               //��ȡ���λ�ã������tellp��������tellg
			if (10 == curpos)                                             //����Ⱥ����߻������ᱨ��
			{
				//�����seekp��������seekg //iso_base::end���Ľ�β��iso_base::beg���Ŀ�ʼ��iso_base::cur���ĵ�ǰλ��
				outfile.seekp(-2, ios_base::end);                        //-2��ʾָ����λ��ǰ��2��λ��
				outfile << 0;
				outfile.close();
			}

			char line[1024] = { 0 };                                        //���ж�ȡ�ļ�
			while (infile.getline(line, sizeof(line)))
			{
			}
		}
		catch (const exception err)                                     //�׳��쳣����һ����ѭ�쳣�б�javaֻ���׳��쳣�б��е��쳣
		{                                                               //c++�е������쳣����exception������  �����׳�exception û�������
			cout << "�쳣����:" << err.what() << endl;                        //�����쳣�඼��.what()���쳣��������
		}
		catch (...)                                                     //ƥ�������쳣          
		{                                                               //try catch ���쳣�಻��Ҫ�ַ������ù��캯�� throw��Ҫ�ַ��������쳣��Ĺ��캯��
			throw invalid_argument("�޷����ļ�");                     //�׳�invalid_argumenty�쳣  ��exception�������쳣�඼��Ҫ�ַ������ù��캯��
		}
	}
	else
		cout << "�ļ�������" << endl;





	cout << "============STL�������㷨����============" << endl;            //STL  4��16������
	//˳������  vector��deque��list��forward_list��array
	//��������map��multimap��set��multiset
	//��������������ϣ�� unordered_map�� unordered_multimap��unordered_set��unordered_multiset
	//����������  queue��priority_queue��stack
	//������һ�����ݽṹ�����ݼ���������������Ԫ�ص��ڴ����Ԫ�ص�����iterator:����Ԫ�صķ��ʣ�ָ��Ԫ�ص�ָ�룩���㷨����������
	array<string, 3> allstr0 = { "name1", "name2", "name3" };                //�ɻ�ȡ��С�Ĺ̶�����
	vector<string> allstr1 = vector<string>(10);                                              //�����ֲ��Ķ�̬����
	list<string> allstr2;                                               //�������ֲ���˫������
	deque<string> allstr3;                                              //�����ֲ���˫ͷ����
	queue<string> allstr4;                                              //�����ȳ��Ķ���
	stack<string> allstr5;                                              //��������ջ
	set<string>  allstr6;                                               //�����Ԫ��Ψһ�ļ���
	multiset<string> allstr7;                                           //�����Ԫ�ز�Ψһ�ļ���
	map<string, int>   map_student;                                      //multimap֧���ظ���ֵ
	map_student.insert(pair<string, int>("С��", 12));                  //map�Ĳ���

	string allnamestr[] = { "С��", "С��", "С��", "С��", "С��" };
	vector<string> allstudent(allnamestr, allnamestr + 5);                //����ת��Ϊ����
	//allstudent.assign(5,"studentname");                               //��̬�����ڴ�
	vector<string> allteacher(2);                                       //�����ַ�������;
	allteacher[0] = "����ʦ";
	allteacher[1] = "����ʦ";
	if (allstudent != allteacher)                                         //����==��!=����������
	{
		allstudent.push_back("С��");                                 //β�����Ԫ��
		allstudent.pop_back();                                          //β��ɾ��Ԫ��
		auto iter = begin(allstudent);                                  //��ȡ�ײ�
		allstudent.insert(iter, "С��");                                   //��ָ��λ�ò���Ԫ��
		iter++;                                                         //�൱��ָ��++
		*iter = "С��";
		allstudent.erase(iter);                                         //��ָ��λ��ɾ��Ԫ��  ɾ����iter���ܼ���ʹ����
		for (vector<string>::iterator iter1 = begin(allstudent); iter1 != end(allstudent); ++iter1)
		{
			cout << *iter1 << endl;
		}
		for (const auto& iter2 : allteacher)                              //���������ã����������rbegin(vectorstr1)��insert_iterator�����������move_iterator�ƶ�������
		{
			cout << iter2 << endl;
		}
	}
	process(allstudent, [](string str){cout << str << endl; });               //ʹ��lambda���ñ����Ļص�����
	process(allteacher, printstring);                                    //�Զ��庯����Ϊ��������

	int sum = 0;
	vector<int> vectorint1(10, 1);
	auto it = find_if_not(begin(vectorint1), end(vectorint1), [](int i){return i<8; });    //�����㷨
	for_each(begin(vectorint1), end(vectorint1), [&sum](int i){sum += i; });                 //�����㷨��ÿ��Ԫ��ִ�лص�����
	partition(begin(vectorint1), end(vectorint1), [](int i){return i % 2; });                //�����㷨  һ��Ŀ�굽����Ŀ��  ͨ������ֵ true��false��������//lambda���ʽ������true������ǰ��   ����false�����ں���
	std::sort(begin(vectorint1), end(vectorint1));                                           //�����㷨��ֻ������˳������




	cout << "============�ַ�����������===========" << endl;
	string strtemp = "luanpengluanpeng";
	string str11(strtemp, 2, 3);                                                          //���캯����ԭ�ַ�������ʼλ�ã���ȡ���ȡ��Ӻ���ǰ���ο���ʡ�ԡ�string str2(num,c);����num��c�ַ����ַ���
	string str = "luanpengluanpeng";
	str.swap(strtemp);  //�����ַ�����ֵ��
	//append��push_back��β������ַ�����
	//insert��ָ��λ�ò����ַ�����
	//erase(��ָ��λ��ɾ�������ַ�����
	//replace�滻�ַ�����size��length���س��ȣ�
	//substr���ַ�����
	//find�����ص�string::size_type ���͵�ֵ��string::npos��ʾ�ַ���ĩβ�󣬲�ѯ����λ��
	regex myregex("ua[l-q]");                                                           //������ʽģʽ   //������ʽ   ^$\.*+?()[]{}|Ϊ�����ַ�
	regex_match(str, myregex);                                                           //��֤Դ�ַ����Ƿ����ָ��ģʽ�����ַ���
	smatch mysmatch;                                                                    //�����  �ַ�������
	if (regex_search(str, mysmatch, myregex))                                              //���ҷ��Ϲ�����ַ���,Ĭ��ֻ��ѯ��һ������������   ���ش��ڻ򲻴���bool
	{
		for (auto x = mysmatch.begin(); x != mysmatch.end(); x++)
			cout << x->str() << endl;
	}
	//$1��ʾƥ������ַ�����һ��ģ������  $&��ʾƥ������������ַ���  $��ʾƥ�������ǰ���ַ���   $`��ʾƥ������ĶϺ���ַ���
	const string format("name=$1");                                                        //�滻��ʽ  �滻��name=ƥ�������ģ���ַ���  
	string result = regex_replace(str, myregex, format);                                    //�ַ����滻
	cout << result << endl;




	thread t1(printstring, "����һ�����߳�");                                           //�������߳�  �����ж������
	//t1.join;                                                                          //˳��ִ���߳�
	t1.detach();                                                                        //�����̷߳�֧


	//���ʹ�ý�ΪƵ���Ķ����죬����ʹ�ö����   һ�ι��캯����ÿ��ȥ��ȡ����
	//�ڴ泣������
	//�ڴ�й©���ͷŲ�����ƥ�䣬����ͷţ��ͷ�δ����ģ��ͷŶ�ջ�ڴ�
	//������Ч�ڴ棬�������ͷ��ڴ棬�ڴ�Խ�磬ָ��δ��ʼ��
	system("pause");

}




//�Զ����������������û��������������ı仯   ��_��ͷ   ����
//��׼�� i  il   if��������Ϊ��������complex<double>  complex<long double>   complex<float>
//float operator"" _min(float minute)
//{
//  return minute/60;
//}
//float operator"" _s(float second)
//{
//  return second/60/60;
//}


//ֻ��c++11�������Ժ�
//ͨ�����ر߽�����
//double sum2(){
//  return 0;
//}
////�䳤ģ��
//template<typename T1,typename...T2> double sum2(T1 p,T2...args)
//{
//  double ret = p+sum2(args);
//  return ret;
//}