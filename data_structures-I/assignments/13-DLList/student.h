//*****************************************************************************************************
//
//      This header file defines a struct that represents a student.
//
//*****************************************************************************************************

#ifndef STUDENT_H
#define STUDENT_H

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
    friend ostream &operator<<(ostream &out, const Student &data);

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

ostream &operator<<(ostream &out, const Student &data) {
    out << setw(11) << left << data.id
        << setw(25) << data.name
        << setw(10) << data.major
        << data.gpa << endl;

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