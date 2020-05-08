#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Benchmark.h"
#include "Student.h"
#include "PrintResults.h"

TEST_CASE("It generates correct amount of students")
{
  std::vector<Student> students;
  REQUIRE(students.size() == 0);
  generateData(students, 1);
  REQUIRE(students.size() == 1);
  students.clear();
  REQUIRE(students.size() == 0);
  generateData(students, 0);
  REQUIRE(students.size() == 0);
  generateData(students, 10);
  REQUIRE(students.size() == 10);
}

TEST_CASE("It calculates final using average correctly")
{
  std::vector<int> results{ 10, 9, 8 };
  Student student("Name", "Surname", results, 9);
  REQUIRE(student.getFinal() == 9);
  student.addHomeworkResult(10);
  REQUIRE(student.getFinal() > 9);
}

TEST_CASE("It calculates final using median correctly")
{
  std::vector<int> results{ 10, 9, 8 };
  Student student("Name", "Surname", results, 9);
  student.setMedianOrAverage("mediana");
  REQUIRE(student.getFinal() == 9);
  student.addHomeworkResult(10);
  REQUIRE(student.getFinal() > 9);
}

TEST_CASE("It determines which student is first alphabetically correctly")
{
  std::vector<Student> students;
  Student student1("a", "a");
  Student student2("a", "b");
  Student student3("b", "a");
  Student student4("c", "c");
  REQUIRE(isFirst(student1, student4));
  REQUIRE(isFirst(student1, student3));
  REQUIRE(isFirst(student1, student2));
  REQUIRE(isFirst(student2, student3));
  REQUIRE(isFirst(student3, student4));
}

TEST_CASE("It divides students correctly")
{
  std::vector<Student> students, badStudents;
  std::vector<int> results1 { 1, 2, 3 };
  students.push_back(Student("a", "a", results1, 4));
  std::vector<int> results2 { 7, 8, 9 };
  students.push_back(Student("b", "b", results2, 10));
  std::vector<int> results3 { 1, 1, 1 };
  students.push_back(Student("c", "c", results3, 10));
  divideStudents(students, badStudents);
  REQUIRE(students.size() == 2);
  REQUIRE(badStudents.size() == 1);
  REQUIRE(students[0].getName() == "b");
  REQUIRE(students[1].getName() == "c");
  REQUIRE(badStudents[0].getName() == "a");
}