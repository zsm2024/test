#include<iostream>
#include<string>
#include<vector>
class person{
public:
  person();
  person(std::string name,uint16_t age,std::string citizen_id);
  virtual void print();
private:
  std::string m_name;
  int m_age;
  std::string m_citizen_id;
};

class student:public person{
public:
  student(std::string name,uint16_t age,std::string citizen_id,uint64_t student_id,uint16_t grade);
  ~student();
  void print() override;
private:
  uint64_t m_student_id;
  uint16_t m_grade;
};


class teacher:public person{
public:
  teacher(std::string name,uint16_t age,std::string citizen_id,uint64_t t_id);
  void point(std::string name,uint16_t age,std::string citizen_id,uint64_t student_id,uint16_t grade);
  ~teacher();
  std::vector<student*> const get();
  void print() override;
private:
  std::vector<student*> m_v;
  uint64_t m_t_id;
};
