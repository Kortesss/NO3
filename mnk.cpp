#include "mnk.h"
#include <qmath.h>
#include <QMessageBox>

double sumXY(QList <double> x, QList <double> y)
{
    double res = 0;
    for(int i = 0; i < x.count(); i++){ res += x[i]*y[i]; }
    return res;
}

double sum(QList <double> k)
{
    double res = 0;
    for(int i = 0; i < k.count(); i++){ res += k[i]; }
    return res;
}

double sumXsqr(QList <double> k)
{
    double res = 0;
    for(int i = 0; i < k.count(); i++){ res += qPow(k[i], 2); }
    return res;
}

mnk::mnk(QList <double> x, QList <double> y, int n)
{
    //Найходим a и b.  n-количество точек
    a = (n*sumXY(x,y) - sum(x)*sum(y))/(n*sumXsqr(x) - qPow(sum(x), 2));
    b = (sum(y) - a*sum(x))/n;
    //Оценка погрешности МНК
    for(int i = 0; i < x.count(); i++){
        sigma1 += qPow(y[i]-(a*x[i]+b), 2);
        sigma2 += qPow(y[i]-(qPow(x[i]+1, 0.33333333333)+1), 2);
    }
    //Так как формула сигма1<сигма2, то прямая y лучше приближает исходные данные
    if (sigma1<sigma2){
        QMessageBox::information(NULL,"Результат",
                              "σ1 = "+QString::number(sigma1)+"; σ2 = "+QString::number(sigma2)+
                              "\nТ.к σ1<σ2, то линия тренда лучше приближает исходные данные");
    }
    xAVG = sum(x)/x.count();  yAVG = sum(y)/y.count();  xyAVG = sumXY(x,y)/x.count();
    //Дисперсия
    Dx = sumXsqr(x)/x.count() - qPow(xAVG, 2);
    Dy = sumXsqr(y)/y.count() - qPow(yAVG, 2);
    //Среднеквадратическое отклонение
    sigX = qSqrt(Dx);
    sigY = qSqrt(Dy);
    //Коэффициент корреляции
    Kcor = (xyAVG-xAVG*yAVG)/(sigX*sigY);
    //Коэффициент детерминации
    Kdet = Kcor * Kcor;
}

double mnk::get_yy(double x)
{  //y=ax+b
    double yy = 0;
    yy = a*x+b;
    return yy;
}

double mnk::get_Kdet()
{
    return Kdet;
}

double mnk::get_a()
{
    return a;
}

double mnk::get_b()
{
    return b;
}
