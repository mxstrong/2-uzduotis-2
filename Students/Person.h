#pragma once
#include <string>

class Person 
{
protected:
  std::string name, surname;
public:
  virtual std::string getName() = 0;
  virtual std::string getSurname() = 0;
  virtual void setName(std::string name) = 0;
  virtual void setSurname(std::string surname) = 0;
  virtual void setFullName(std::string name, std::string surname) = 0;
};