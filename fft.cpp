#include "fft.h"
#include <qmath.h>
#include <QDebug>

fft::fft(int t)
{
    int  i;

      T = t - 1;
      N = 1;
      for(i = 1; i <= T; i++)  N = N * 2;


      Xre = NULL;
      Xre = new double*[T+1];          // Строки для перестановок
      Xre[0] = NULL;  Xre[0] = new double[2 * N];  // Для результата
      for(i = 1; i < T+1; i++)  { Xre[i] = NULL;  Xre[i] = new double[N]; }

      Xim = NULL;
      Xim = new double*[T+1];          // Строки для перестановок
      Xim[0] = NULL;  Xim[0] = new double[2 * N];  // Для результата
      for(i = 1; i < T+1; i++)  { Xim[i] = NULL;  Xim[i] = new double[N]; }


      EVENre = NULL;  EVENre = new double[N];
      ODDre = NULL;   ODDre = new double[N];
      EVENim = NULL;  EVENim = new double[N];
      ODDim = NULL;   ODDim = new double[N];


      ind = NULL;
      ind = new long*[T+1];

      for(i = 0; i < T+1; i++)  { ind[i] = NULL;  ind[i] = new long[N]; }


      A = NULL;
      A = new double[2 * N];

      freq = NULL;
      freq = new double[2 * N];


      Wre = NULL;
      Wre = new double*[T+2];

      Wim = NULL;
      Wim = new double*[T+2];


      ReadyToBegin = false;
      No = 0;


      tm = NULL;
      tm = new double[N];
}

fft::~fft()
{
qDebug() << "деструктор fft";
}

void fft::Prepare()
{
int   i, j, p, parts, beg, end;
for(i = 0; i < N; i++)  ind[0][i] = i;

parts = 1;
for(i = 0; i < T; i++)
{
  for(p = 1; p <= parts; p++)
  {
    beg = (N / parts) * (p - 1);
    end = (N / parts) * p;
    for(j = beg; j < end; j++)
    {
      if(j < beg + ((end - beg) / 2))  ind[i+1][j] = ind[i][beg+((j-beg)*2)];
      else                             ind[i+1][j] = ind[i][beg+((j-beg-((end - beg) / 2))*2)+1];
    }
  }
  parts = parts * 2;
}

int     k, t, n;
long double  pi = 3.14159265358979323846264338327950288419716939937510;

for(t = 0; t <= T + 1; t++)
{
  n = 1;
  for(i = 0; i < t; i++)  n = n * 2;


  Wre[t] = NULL;  Wre[t] = new double[n];
  Wim[t] = NULL;  Wim[t] = new double[n];

  for(k = 0; k < n; k++)
  {
    Wre[t][k] = cosl(2*pi*k/n);

    Wim[t][k] = (-1) * sinl(2*pi*k/n);
  }
}

inversed = 0;

//Flt.Ini(fH, fT);
}

bool fft::PutVal(bool c)
{
int  i;
bool ret = false;


  Fault = false;


  if(!inversed)   Xre[T][No] = X0;
  else            { Xim[T][No] = X0;  tm[No] = tm0; }

  if(inversed)
    if(No == N - 1)  ReadyToBegin = true;
    else  No++;

  if(ReadyToBegin && inversed)
  {
    //dT = Flt.Go(tm[N - 1] - tm[0] + 2 * dt);
    dT = tm[N - 1] - tm[0] + 2 * dt; // "2 *" - т.к. время подается через раз
    if(dT <= 0)  Fault = true;
    if(Otsechka && dT > (N / CFreq))  Fault = true;   // "dT < N / fr" - отсекаем случаи, когда происходит скачек по времени

    if(c)   { Spectrum();  ret = true; }

    memmove(&tm[0], &tm[1], sizeof(tm[0]) * (N - 1));
    memmove(&Xre[T][0], &Xre[T][1], sizeof(Xre[T][0]) * (N - 1));
    memmove(&Xim[T][0], &Xim[T][1], sizeof(Xim[T][0]) * (N - 1));
  }

  inversed = 1 - inversed;


  return ret;
}

float fft::Spectrum()
{
int       i1, i2, j, p, parts, n, t;


t = T - 1;          // Встаем на предпоследний уровень с целью его формирования
parts = N / 2;      // Частей
n = 2;              // Штук в 1 части
while(1)
{
  for(p = 0; p < parts; p++)    // Цикл по частям разбиения
  {
    for(i1 = 0; i1 < n/2; i1++)
    {
      Xre[t][ind[t][(p*n)+i1]] = Xre[t+1][ind[t+1][(p*n)+i1]] + ((Wre[T-t][i1] * Xre[t+1][ind[t+1][((p*n)+(n/2))+i1]]) - (Wim[T-t][i1] * Xim[t+1][ind[t+1][((p*n)+(n/2))+i1]]));
      Xim[t][ind[t][(p*n)+i1]] = Xim[t+1][ind[t+1][(p*n)+i1]] + ((Wre[T-t][i1] * Xim[t+1][ind[t+1][((p*n)+(n/2))+i1]]) + (Wim[T-t][i1] * Xre[t+1][ind[t+1][((p*n)+(n/2))+i1]]));
    }
    for(i2 = n/2; i2 < n; i2++)
    {
      Xre[t][ind[t][(p*n)+i2]] = Xre[t+1][ind[t+1][((p*n)-(n/2))+i2]] - ((Wre[T-t][i2-(n/2)] * Xre[t+1][ind[t+1][(p*n)+i2]]) - (Wim[T-t][i2-(n/2)] * Xim[t+1][ind[t+1][(p*n)+i2]]));
      Xim[t][ind[t][(p*n)+i2]] = Xim[t+1][ind[t+1][((p*n)-(n/2))+i2]] - ((Wre[T-t][i2-(n/2)] * Xim[t+1][ind[t+1][(p*n)+i2]]) + (Wim[T-t][i2-(n/2)] * Xre[t+1][ind[t+1][(p*n)+i2]]));
    }
  }

  t--;
  if(t < 0) break;
  else
  {
    n = n * 2;
    parts = parts / 2;
  }
}


for(j = 0; j < N; j++)
{
  // Четные
  EVENre[j] = (Xre[0][j] + Xre[0][N-j]) / 2;
  EVENim[j] = (Xim[0][j] - Xim[0][N-j]) / 2;

  // Нечетные
  ODDre[j] = (Xim[0][j] + Xim[0][N-j]) / 2;
  ODDim[j] = (Xre[0][N-j] - Xre[0][j]) / 2;
}


for(j = 0; j < N; j++)
{
  // Первая половина спектра
  Xre[0][j] = EVENre[j] + (Wre[T + 1][j] * ODDre[j] - Wim[T + 1][j] * ODDim[j]);
  Xim[0][j] = EVENim[j] + (Wim[T + 1][j] * ODDre[j] + Wre[T + 1][j] * ODDim[j]);

  // Вторая половина спектра (не используется (зеркало))
  Xre[0][j + N] = EVENre[j] - (Wre[T + 1][j + N] * ODDre[j] - Wim[T + 1][j + N] * ODDim[j]);
  Xim[0][j + N] = EVENim[j] - (Wim[T + 1][j + N] * ODDre[j] + Wre[T + 1][j + N] * ODDim[j]);
}


//  Расчет амплитуд и частот
for(j = 0; j < N; j++)
{
  A[j] = (Xre[0][j] * Xre[0][j]) + (Xim[0][j] * Xim[0][j]);
  A[j] = sqrt(A[j]) / N;

  freq[j] = (double)j / dT;
  if(freq[j] > 199)
  dT=dT;
}


return 0;
}


