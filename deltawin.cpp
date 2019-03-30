#include "deltawin.h"
#include "ui_deltawin.h"
#include <qmath.h>

deltaWin::deltaWin(QList <double> &mass_minX, QList <double> &mass_maxX, QList <double> &mass_minY, QList <double> &mass_maxY, QList <double> &v1, QList <double> &v2, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deltaWin)
{
    ui->setupUi(this);
    deltaList(mass_minX, mass_maxX, mass_minY, mass_maxY, v1, v2);
}

void deltaWin::deltaList(QList <double> &mass_minX, QList <double> &mass_maxX, QList <double> &mass_minY, QList <double> &mass_maxY, QList <double> &v1, QList <double> &v2){
    if (mass_maxX[0] > mass_minX[0]){
        //если график в начале возрастает
        for(int i = 0; i < mass_maxX.count(); i ++){
            deltaT1.append(mass_maxX[i] - mass_minX[i]);
            ui->list1->addItem(QString::number(deltaT1[i]));
        }
        for(int i = 1; i < mass_minX.count(); i ++){
            deltaT2.append(mass_minX[i] - mass_maxX[i-1]);
            ui->list2->addItem(QString::number(deltaT2[i-1]));
        }
        int k1=0, k2=0;
        deltaR1.append(qFabs(mass_minY[0] - mass_maxY[0])); //это начало, дальше пойдет закономерность по циклу от 1 до n
        ui->listR1->addItem(QString::number(deltaR1[k1])); k1+=1;
        for(int i = 1; i < mass_minY.count(); i ++){
            for(int j = i-1; j <= i && j<mass_maxY.count(); j ++){
                if (i==j){
                    deltaR1.append(qFabs(mass_minY[i] - mass_maxY[j]));
                    ui->listR1->addItem(QString::number(deltaR1[k1++]));
                }else{
                    deltaR2.append(qFabs(mass_minY[i] - mass_maxY[j]));
                    ui->listR2->addItem(QString::number(deltaR2[k2++]));
                }
            }
        }
    }else{
        //если график в начале убывает
        for(int i = 1; i < mass_maxX.count(); i ++){
            deltaT2.append(mass_maxX[i] - mass_minX[i-1]);
            ui->list2->addItem(QString::number(deltaT2[i-1]));
        }
        for(int i = 0; i < mass_minX.count(); i ++){
            deltaT1.append(mass_minX[i] - mass_maxX[i]);
            ui->list1->addItem(QString::number(deltaT1[i]));
        }
        int h1=0, h2=0;
        for(int i = 0; i < mass_minY.count(); i++){
            for(int j = i; j <= i+1 && j<mass_maxY.count(); j ++){
                if (i==j){
                    deltaR2.append(qFabs(mass_minY[i] - mass_maxY[j]));
                    ui->listR2->addItem(QString::number(deltaR2[h1++]));

                }else{
                    deltaR1.append(qFabs(mass_minY[i] - mass_maxY[j]));
                    ui->listR1->addItem(QString::number(deltaR1[h2++]));
                }
            }
        }
    }
    for(int i = 0; i < v1.count(); i++)        ui->listV1->addItem(QString::number(v1[i]));
    for(int i = 0; i < v2.count(); i++)        ui->listV2->addItem(QString::number(v2[i]));

}

deltaWin::~deltaWin(){ delete ui; }
