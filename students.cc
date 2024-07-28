#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<memory>
#include"person.hpp"
int main(){
  //....................................................................................堆上实例化
  /*teacher *p1=new teacher("xx",13,"123456201135627826",3532498990);
  p1->point("zsm",23,"000000200155556147",20205041259,2024);
  (*p1).get()[0]->print();
  p1->print();
  delete p1;
  (*p1).get()[0]->print();
  p1->print();*/
  
//......................................................................................智能指针
  std::shared_ptr<teacher> ptr(new teacher("xx",13,"123456201135627826",3532498990));
  ptr->point("zsm",23,"000000200155556147",20205041259,2024);
  ptr->print();
  //(*ptr).get()[0]->print();
  //ptr->print();


  //....................................................................................栈上实例化
 /* teacher t1("xx",13,"123456201135627826",3532498990);
  t1.point("zsm",23,"000000200155556147",20205041259,2024);
  t1.get()[0]->print();*/


  /*....................................................................................读写
  teacher t1("xx",13,"123456201135627826",3532498990);
  std::ifstream in;
  in.open("st_information");
  std::string name,age,citizen_id,student_id,grade;
  in>>name>>age>>citizen_id>>student_id>>grade;
  std::string a;uint16_t b; std::string c;uint64_t d;uint32_t e;
  while(1)
  {
    in>>a>>b>>c>>d>>e;
    if(in.eof())
    {
      break;
    }
    t1.point(a,b,c,d,e);
  }
  t1.get()[1]->print();*/


  //.....................................................................................虚函数
  /*teacher t1("xx",13,"123456201135627826",3532498990);
  t1.point("zsm",23,"000000200155556147",20205041259,2024);
  person* p = &t1;
  p->print();
  p=t1.get()[0];
  p->print();*/
  return 0;
}
