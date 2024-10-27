#ifndef RESI_H
#define RESI_H

#include "point.h"
#include <vector>
#include <iostream>
using namespace std;

class Resi : public point{
public:
    Resi();
    Resi(string z, int p=0);
    void updatePop(const vector<vector<point>>& sim,int x, int y );
    static bool adjPow(const vector<vector<point>>& sim,int x, int y );
    static int adjPop(const vector<vector<point>>& sim,int x, int y , int p);
private:
    void apply(const vector<vector<point>>& sim,int x, int y);

};



#endif // RESI_H
