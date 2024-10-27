#include "resi.h"

Resi::Resi(string z, int p) : point(z,0,p){

}
bool Resi::adjPow(const vector<vector<point>>& sim, int x, int y){
int r = sim.size();
int c = sim[0].size();
for(int i = -1; i<=i; i++){
    for(int j = -1; j<=j; j++){
        int nX=x+i;
        int nY=y+j;
        if(nX>0&&nY<r && nY>=0&&nY<c){
            if(sim[nX][nY].getZone()=="-"){
                return true;
            }
        }
    }
}
return false;
}
int Resi::adjPop(const vector<vector<point>>& sim, int x, int y,int p){
int r = sim.size();
int c = sim[0].size();
int adjP=p;
for(int i = -1; i<=i; i++){
    for(int j = -1; j<=j; j++){
        int nX=x+i;
        int nY=y+j;
        if((i!=0||j!=0)&&nX>=0&&nY<r&&nY>=0 && nY<c){
           adjP+=sim[nX][nY].getPop();
            }
        }
    }
return adjP;
}

void Resi::updatePop(const vector<vector<point>>& sim, int x, int y){
    if(adjPow(sim,x,y)){
                int newPop = adjPop(sim, x, y, this->getPop());
                if(newPop>this->getPop()){
                    this->setPop(newPop);
                }
                }
                return;
}
