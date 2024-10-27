#include "point.h"
point::point(){
zone="";
pol=0;
pop=0;
}
point::~point(){

}
point::point(string zone){
this->zone=zone;
pol=0;
pop=0;
}
point::point(string zone, int pol, int pop){
this->zone=zone;
this->pol=pol;
this->pop=pop;
}
void point::setZone(string zone){
this->zone=zone;
}
void point::setPollution(int pol){
this->pol=pol;
}
void point::setPop(int pop){
this->pop=pop;
}
void point::output()const{
if(pop==0)
    {
        cout<<zone;
    }
else if(pop>0)
    {
        cout<<pop;
    }
}
