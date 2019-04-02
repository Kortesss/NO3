#include "extrem_simple.h"

extrem_simple::extrem_simple(QList<double> &mass_minX, QList<double> &mass_maxX, QList<double> &mass_minY, QList<double> &mass_maxY, QList<double> &mass_y_Gr, QList<double> &mass_x_Gr, int x1, int x2, double limit, double miny)
{
    mass_minX.clear(); mass_maxX.clear();
    mass_minY.clear(); mass_maxY.clear();//чтобы память не засорять
    bool up; //переменная отвечающая за возрастание
    if (mass_y_Gr[x1+1] > mass_y_Gr[x1]){
        up = true;//смотрим, возрастает ли график
        mass_minX.append(mass_x_Gr[x1]);
        mass_minY.append(mass_y_Gr[x1]);
    }
    for(int i = x1+1; i <= x2; i ++){
        if (up){ //если возрастает
            if (mass_y_Gr[i] < mass_y_Gr[i-1]){ //ждем когда она перестанет возрастать
                if((mass_y_Gr[i-1] - mass_y_Gr[i]) > ((miny*limit)/10)){
                    mass_maxX.append(mass_x_Gr[i-1]);
                    mass_maxY.append(mass_y_Gr[i-1]);
                    up = false;
                }
            }
        }else{
            if (mass_y_Gr[i] > mass_y_Gr[i-1]){ //ждем когда она перестанет убывать
                if((mass_y_Gr[i] - mass_y_Gr[i-1])>limit){
                    mass_minX.append(mass_x_Gr[i-1]);
                    mass_minY.append(mass_y_Gr[i-1]);
                    up = true;
                }
            }
        }
    }
    if (mass_y_Gr[x2] > mass_y_Gr[x2-1]){
        mass_maxX.append(mass_x_Gr[x2]);
        mass_maxY.append(mass_y_Gr[x2]);
    }else{
        mass_minX.append(mass_x_Gr[x2]);
        mass_minY.append(mass_y_Gr[x2]);
    }
}

