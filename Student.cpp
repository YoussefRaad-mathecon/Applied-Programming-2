#include "Student.hpp"

Student::Student() : name(""), tuition_fees(0.0), library_fines(0.0) {
    
}

Student::Student(std::string name, double fines, double fees) : name(name), tuition_fees(fees) {
    SetLibraryFines(fines);
}

void Student::SetLibraryFines(double amount) {
    if (amount >= 0) {
        library_fines = amount;
    } else {
        std::cerr << "Error: Library fines cannot be negative." << std::endl;
    }
}

double Student::GetLibraryFines() const {
    return library_fines;
}

double Student::MoneyOwed() const {
    return tuition_fees + library_fines;
}
