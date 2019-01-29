#ifndef FFT_H
#define FFT_H

#include <QMainWindow>
//#include <flt.h>

class fft
{
public:
    fft(int t);
    ~fft();

    void Prepare();
    bool PutVal(bool c);
    float Spectrum();               // Возвращает погрешность зеркального эффекта
    long       N;                                    // Размер блока данных
    long       T;                                    // N = 2 ^ T
    long       No;
    double     CFreq;
    int        inversed;                             // Признак инверсной подачи данных

    double     X0, tm0;
    double     **Xre, **Xim;
    double     *tm, dt;                              // Время, приращение времени
    long       **ind;                                // Индексы для перестановок
    double     **Wre, **Wim;                         // Поворачивающие множители
    double     *A, *freq;                            // Амплитуды, частоты
    double     dT;
    bool       ReadyToBegin, Fault, Otsechka;

    double     *EVENre, *ODDre, *EVENim, *ODDim;     // Буфера для отображений Фурье четных и нечетных наборов


    //Filter     Flt;
    //double     fH, fT;                               // Параметры фильтра

private:


};

#endif // FFT_H
