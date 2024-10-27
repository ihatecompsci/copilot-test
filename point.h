#ifndef READ_H
#define READ_H

#include <iostream>
#include <string>

using namespace std;

class point{
public:
    point();
    ~point();
    point(string zone);
    point(string zone, int pol, int pop);

    void setZone(string zone);
    void setPollution(int pol);
    void setPop(int pop);
    string getZone()const{return zone;}
    int getPollution()const{return pol;}
    int getPop()const{return pop;}
    void output()const;
private:
    string zone;
    int pop;
    int pol;
};
#endif // READ_H

