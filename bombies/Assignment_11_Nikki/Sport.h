
#include <string>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

class Sport {
   private:
    string name;
    Date nextGame;
    int numTeams;
    string* teamNames;

   public:
    Sport(const string& n = "");
    string getName() const;
    void setName(const string& n);
    Date getDate() const;
    void setDate(const Date& d);
    int getNumTeams() const;
    void display() const;
    void populate();
    void addTeam(const string& n);
    ~Sport();
};

//**
inline void Sport::setName(const string& n) {
    name = n;
}

//**

inline void Sport::setDate(const Date& d) {
    nextGame = d;
}
//**

inline int Sport::getNumTeams() const {
    return numTeams;
}

inline string Sport::getName() const {
    return name;
}

//**

inline Date Sport::getDate() const {
    return Sport::nextGame;
}