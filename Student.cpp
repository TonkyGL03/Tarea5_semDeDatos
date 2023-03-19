#include "Student.h"

using namespace std;

Student::Student() {}

Student::Student(const Student& s) : code(s.code), name(s.name), birthDate(s.birthDate), career(s.career), startDate(s.startDate), grade(s.grade){ }

Student& Student::operator=(const Student& s){
    code = s.code;
    name = s.name;
    birthDate = s.birthDate;
    career = s.career;
    startDate = s.startDate;
    grade = s.grade;

    return *this;
}

string Student::getCode() const {
    return code;
}

Name Student::getName() const {
    return name;
}

Date Student::getBirthDate() const{
    return birthDate;
}

string Student::getCareer() const{
    return career;
}

Date Student::getStartDate() const{
    return startDate;
}

float Student::getGrade() const{
    return grade;
}

string Student::toString() const{
    string result;

    result = code;
    result+= "|";
    result+=name.toString();
    result+= "|";
    result+=birthDate.toString();
    result+= "|";
    result+=career;
    result+= "|";
    result+=startDate.toString();
    result+= "|";
    result+= to_string(grade);

    return result;
}

void Student::setCode(const string& c){
    code = c;
}

void Student::setName(const Name& n){
    name = n;
}

void Student::setBirthDate(const Date& d){
    birthDate = d;
}

void Student::setCareer(const string& c){
    career = c;
}

void Student::setStartDate(const Date& d){
    startDate = d;
}

void Student::setGrade(const float& g){
    grade = g;
}

bool Student::operator == (const Student& s) const{
    return code == s.code;
}

bool Student::operator != (const Student& s) const{
    return code != s.code;
}

bool Student::operator < (const Student& s) const{
    return code < s.code;
}

bool Student::operator <= (const Student& s) const{
    return code <= s.code;
}

bool Student::operator >= (const Student& s) const{
    return code >= s.code;
}

ostream& operator << (ostream& os, Student& s){
    char myGrade[7];
    sprintf(myGrade, "%0.2f", s.grade);

    os << s.code << endl;
    os << s.name << endl;
    os << s.birthDate << endl;
    os << s.career << endl;
    os << s.startDate << endl;
    os << myGrade;

    return os;
}

istream& operator >> (istream& is, Student& s){
    string myStr;

    getline(is, s.code);
    is >> s.name;
    is >> s.birthDate;
    getline(is, s.career);
    is >> s.startDate;
    getline(is, myStr);
    s.grade = atof(myStr.c_str());

    return is;
}
