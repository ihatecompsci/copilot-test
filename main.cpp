#include "point.h"
#include "resi.h"
#include "ind.h"
//#include "comm.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
void readCfg(string& regionName, int& rr, int& tl){
ifstream file;
string cfg;
cout<<"Input name of config file: ";
getline(cin,cfg);
file.open(cfg);

if(!file.is_open()){
        cerr<<"Could not open configuration file.";
        return;
    }
string cfgl;
while(getline(file,cfgl)){
        if(cfgl.find("Region Layout")!= string::npos)
        {
            regionName=(cfgl.substr(cfgl.find(':')+1));
        }
        else if(cfgl.find("Time Limit:")!= string::npos)
        {
            rr=stoi(cfgl.substr(cfgl.find(':')+1));
        }
        else if (cfgl.find("Refresh Rate:")!= string::npos)
        {
            tl=stoi(cfgl.substr(cfgl.find(':')+1));
        }
        }
        file.close();
    }
void readReg(string reg, vector<vector<point>>& sim){

ifstream file;
string l;
string z;
file.open(reg);
if(!file.is_open()){
        cerr<<"Could not open region file.";
        return;
    }
point p;
while(getline(file,l))
    {
        stringstream regL(l);
        vector<point> temp;
        for(string::size_type i = 0; i<(l.length()/2)+1;i++)
        {
            getline(regL,z,',');
            p.setZone(z);
            temp.push_back(p);
            z="";
        }
        sim.push_back(temp);
        l="";
    }
    file.close();
}
void printSim(vector<vector<point>>& sim){
for(vector<vector<point>>::size_type i=0;i<sim.size();i++)
    {
        for(vector<point>::size_type j=0;j<sim[i].size();j++){
            sim[i][j].output();
            cout<<" ";

        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
string reg="";
int tl=20;
int rr;
int ts=0;
int refresh=0;

vector<vector<point>> sim;

readCfg(reg,tl,rr);
readReg(reg,sim);
cout<<"Time Limit:"<<tl<<endl;
cout<<"Refresh Rate:"<<rr<<endl;
while(ts<tl){
cout<<"Time Step # : "<<ts+1<<endl;
cout<<endl;
printSim(sim);
refresh++;

if(refresh>=rr){
need to write updateSim for cell manipulation
    updateSim(sim);
    refresh=0;
}
ts++;
}
return 0;
}
