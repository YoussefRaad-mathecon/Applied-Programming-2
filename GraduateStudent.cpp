#include "GraduateStudent.hpp"

GraduateStudent::GraduateStudent() : Student(), fullTime(true) {}

GraduateStudent::GraduateStudent(std::string name, double fines, double fees, bool fullTime) 
    : Student(name, fines, fees), fullTime(fullTime) {}

double GraduateStudent::MoneyOwed() const {
    return GetLibraryFines();
}
