#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include"person.hpp"
person::person(){}
person::person(std::string name,uint16_t age,std::string citizen_id):m_name(name),m_age(age),m_citizen_id(citizen_id){
  std::vector<char> v;
  v.push_back(citizen_id[6]);
  v.push_back(citizen_id[7]);
  v.push_back(citizen_id[8]);
  v.push_back(citizen_id[9]);
  std::string str(v.data(),v.size());
  int num=0;
  std::istringstream ss(str);
  ss>>num;
  if(num!=(2024-m_age)){
    std::cout<<"***************************************"<<std::endl;
    std::cout<<"fault!  age && citizen_id"<<std::endl; 
  }
  else{
    std::cout<<"***************************************"<<std::endl;
    print();
  }
}

void person::print(){
  std::cout<<"*****************************************"<<std::endl;
  std::cout<<"m_name:      "<<m_name<<std::endl;
  std::cout<<"m_age:       "<<m_age<<std::endl;
  std::cout<<"m_citizen_id:"<<m_citizen_id<<std::endl;
}


student::student(std::string name,uint16_t age,std::string citizen_id,uint64_t student_id,uint16_t grade):person(name,age,citizen_id),m_student_id(student_id),m_grade(grade){
  std::cout<<"**********student constructor*************"<<std::endl;
}
student::~student(){
  std::cout<<"**********student destructor**************"<<std::endl;
}
void student::print(){

  std::cout<<"m_student_id:"<<m_student_id<<std::endl;
  std::cout<<"m_grade:"<<m_grade<<std::endl;
}


teacher::teacher(std::string name,uint16_t age,std::string citizen_id,uint64_t t_id):person(name,age,citizen_id),m_t_id(t_id){
  std::cout<<"*********teacher constructor**************"<<std::endl;
}
teacher::~teacher(){
  std::cout<<"*********teacher destructor***************"<<std::endl;
  for(std::vector<student*>::iterator it=m_v.begin();it!=m_v.end();it++){
    delete *it;
  }
}  

void teacher::point(std::string name,uint16_t age,std::string citizen_id,uint64_t student_id,uint16_t grade){
  student*p=new student(name,age,citizen_id,student_id,grade);
  m_v.push_back(p);
}
 
std::vector<student*> teacher::get(){return m_v;}
