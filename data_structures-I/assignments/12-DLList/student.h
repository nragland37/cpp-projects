//*****************************************************************************************************
//
//      This header file defines a struct that represents a student and uses operator overloading to
//      compare students by their ID numbers.
//
//*****************************************************************************************************

#ifndef STUDENT_H
#define STUDENT_H

//*****************************************************************************************************

#include <iomanip>

//*****************************************************************************************************

struct Student {
    int id;
    char name[50];
    char cityState[50];
    char phone[12];
    char gender;
    int year;
    int credits;
    float gpa;
    char major[6];

    Student();
    friend std::ostream &operator<<(std::ostream &out, const Student &data);

    bool operator<(const Student &rhs) const;
    bool operator<(int value) const;
    bool operator>(const Student &rhs) const;
    bool operator>(int value) const;
    bool operator==(const Student &rhs) const;
    bool operator==(int value) const;
    bool operator!=(const Student &rhs) const;
    bool operator!=(int value) const;
    bool operator<=(const Student &rhs) const;
    bool operator<=(int value) const;
    bool operator>=(const Student &rhs) const;
    bool operator>=(int value) const;
};

//*****************************************************************************************************

Student::Student() {
    id = 0;
}

//*****************************************************************************************************

std::ostream &operator<<(std::ostream &out, const Student &data) {
    out << std::setw(11) << std::left << data.id
        << std::setw(25) << data.name
        << std::setw(10) << data.major
        << data.gpa << std::endl;

    return out;
}

//*****************************************************************************************************

bool Student::operator<(const Student &rhs) const {
    return (this->id < rhs.id);
}

//*****************************************************************************************************

bool Student::operator<(int value) const {
    return (this->id < value);
}

//*****************************************************************************************************

bool Student::operator>(const Student &rhs) const {
    return (this->id > rhs.id);
}

//*****************************************************************************************************

bool Student::operator>(int value) const {
    return (this->id > value);
}

//*****************************************************************************************************

bool Student::operator==(const Student &rhs) const {
    return (this->id == rhs.id);
}

//*****************************************************************************************************

bool Student::operator==(int value) const {
    return (this->id == value);
}

//*****************************************************************************************************

bool Student::operator!=(const Student &rhs) const {
    return (this->id != rhs.id);
}

//*****************************************************************************************************

bool Student::operator!=(int value) const {
    return (this->id != value);
}

//*****************************************************************************************************

bool Student::operator<=(const Student &rhs) const {
    return (this->id <= rhs.id);
}

//*****************************************************************************************************

bool Student::operator<=(int value) const {
    return (this->id <= value);
}

//*****************************************************************************************************

bool Student::operator>=(const Student &rhs) const {
    return (this->id >= rhs.id);
}

//*****************************************************************************************************

bool Student::operator>=(int value) const {
    return (this->id >= value);
}

//*****************************************************************************************************

#endif