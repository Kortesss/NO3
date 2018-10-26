#include "delta.h"
#include "ui_delta.h"
#include <qmath.h>

delta::delta(QList <double> mass_minX, QList <double> mass_maxX, QList <double> mass_minY, QList <double> mass_maxY, QWidget *parent):
    QWidget(parent),
    ui(new Ui::delta)
{
    ui->setupUi(this);
    deltaList(mass_minX, mass_maxX, mass_minY, mass_maxY);
}

void delta::deltaList(QList <double> mass_minX, QList <double> mass_maxX, QList <double> mass_minY, QList <double> mass_maxY){
    if (mass_maxX[0] > mass_minX[0]){//если график в начале возрастает
        for(int i = 0; i < mass_maxX.count(); i ++){
            this->deltaT1.append(mass_maxX[i] - mass_minX[i]);
            ui->list1->addItem(QString::number(this->deltaT1[i]));
        }
        for(int i = 1; i < mass_minX.count(); i ++){
            this->deltaT2.append(mass_minX[i] - mass_maxX[i-1]);
            ui->list2->addItem(QString::number(this->deltaT2[i-1]));
        }
        int k = 0;
        this->deltaR.append(qFabs(mass_minY[0] - mass_maxY[0])); //это начала, дальше пойдет закономерность по циклу от 1 до n
        for(int i = 1; i < mass_minY.count(); i ++){
            for(int j = i-1; j <= i; j ++){
                this->deltaR.append(qFabs(mass_minY[i] - mass_maxY[j]));
                ui->list3->addItem(QString::number(this->deltaR[k]));
                k+=1;
            }
        }
    }else{//если график в начале убывает
        for(int i = 1; i < mass_maxX.count(); i ++){
            this->deltaT1.append(mass_maxX[i] - mass_minX[i-1]);
            ui->list1->addItem(QString::number(this->deltaT1[i-1]));
        }
        for(int i = 0; i < mass_minX.count(); i ++){
            this->deltaT2.append(mass_minX[i] - mass_maxX[i-1]);
            ui->list2->addItem(QString::number(this->deltaT2[i]));
        }
        int h = 0;
        for(int i = 0; i < mass_minY.count(); i ++){
            for(int j = i; j <= i+1; j ++){
                this->deltaR.append(qFabs(mass_minY[i] - mass_maxY[j]));
                ui->list3->addItem(QString::number(this->deltaR[h]));
                h+=1;
            }
        }
    }

}

delta::~delta()
{
    delete ui;
}
