#include "dispers_analysis.h"
#include "ui_dispers_analysis.h"
#include "fdistribution.h"
#include <qmath.h>
#include <QDebug>
#include <QMessageBox>

dispers_analysis::dispers_analysis(QString typeD, QList <QString> listWidget, QList<QList<double> > &Arr, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dispers_analysis)
{
    ui->setupUi(this);

    ui->lab_1->setText("Итоги ("+typeD+"):");
    ui->lab_warning->setStyleSheet("color: rgb(255, 0, 0)"); //текст предупреждения - красный
    typeA = typeD;
    arr = Arr;
    for (int i = 0; i < listWidget.count(); i++){
        ui->listGr->addItem(listWidget[i]);
        ui->listGr->item(i)->setTextAlignment(Qt::AlignCenter);
        if (arr[i].count()>0) ui->listGr->item(i)->setTextColor(QColor(67, 138, 0, 255)); //зеленый
        else ui->listGr->item(i)->setTextColor(QColor(255, 0, 0, 255)); //красный
    }

    model1 = new QStandardItemModel;
    //Заголовки столбцов
    QStringList headers1;
    headers1 << "Графики" << "Кол-во значений" << "Сумма" << "Среднее" << "Дисперсия";
    model1->setHorizontalHeaderLabels(headers1);
    // Ресайзим колонки по содержимому
    ui->tableResult->resizeColumnsToContents();
    ui->tableResult->horizontalHeader()->setStretchLastSection(true);
    ui->tableResult->setColumnWidth(0, 150);
    ui->tableResult->setModel(model1);
    Va = 0; Ve = 0;
    model2 = new QStandardItemModel;
    //Заголовки столбцов
    QStringList headers2;
    headers2 << "Источник вариации" << "SS" << "df" << "MS" << "F" << "F-критическое";
    model2->setHorizontalHeaderLabels(headers2);
    //ui->tableDispers->resizeColumnsToContents();
    ui->tableDispers->horizontalHeader()->setStretchLastSection(true); ui->tableDispers->setModel(model2);
    ui->tableDispers->setColumnWidth(0, 160);

}

dispers_analysis::~dispers_analysis()
{
    delete ui;
}

void dispers_analysis::on_listGr_clicked(const QModelIndex &)
{
    if (ui->listGr->selectedItems().count() > 1) ui->pushButton_Calculate->setEnabled(true);
    else ui->pushButton_Calculate->setEnabled(false);
}

void dispers_analysis::on_pushButton_close_clicked()
{
    this->close();
}

double dispers_analysis::sum(QList <double> &s)
{
    double res = 0;
    for(int i = 0; i < s.count(); i++) res += s[i];
    return res;
}

double dispers_analysis::avg(QList <double> &a)
{
    double res = sum(a)/a.count();
    return res;
}

double dispers_analysis::dispers(QList <double> &d)
{
    double res = 0, a = avg(d);
    for(int i = 0; i < d.count(); i++) res += qPow((d[i] - a), 2);
    res /= d.count()-1;
    return res;
}

double dispers_analysis::SSa(QList <double> ni) //между группами
{
    double res = 0, a = ui->tableResult->model()->rowCount();
    QList <double> sr;
    for (int i = 0; i < ui->listGr->count(); i++){
        if ((ui->listGr->item(i)->isSelected())  && (arr[i].count()>0)){
            sr.append(avg(arr[i])); //считаем среднее значение выделенного графика
        }
    }
    for (int j = 0; j < a; j++){ //от 0 до кол-ва выделенных графиков
        res += ni[j]*qPow((sr[j]-X), 2);
    }
    return res;
}

double dispers_analysis::SSe(QList <double> ni) //внутри групп
{
    double res = 0, a = ui->tableResult->model()->rowCount();
    QList <double> dis;
    for (int i = 0; i < ui->listGr->count(); i++){
        if ((ui->listGr->item(i)->isSelected())  && (arr[i].count()>0)){
            dis.append(dispers(arr[i])); //считаем дисперсию выделенного графика
        }
    }
    for (int j = 0; j < a; j++){//от 0 до кол-ва выделенных графиков
        res += (ni[j]-1)*dis[j];
    }
    return res;
}

void dispers_analysis::on_pushButton_Calculate_clicked()
{
    int k = 0, c = 0, rav = 0;
    bool f1 = true;
    double a = 1, n = 0, MSa = 1, MSe = 1, F = 1;
    X = 0; V = 0;
    QList <double> ni;
    model1->removeRows(0, ui->tableResult->model()->rowCount());
    model2->removeRows(0, model2->rowCount());
    ui->lab_opis->setText("");
    for (int i = 0; i < ui->listGr->count(); i++){
        if ((ui->listGr->item(i)->isSelected())  && (arr[i].count()>0)) {rav = arr[i].count(); break;} //запоминаем кол-во данных первого не пустого выбраного графика
    }
    for (int i = 0; i < ui->listGr->count(); i++){
        if ((ui->listGr->item(i)->isSelected()) && (arr[i].count()>0)) c+=1;
        if ((arr[i].count() != rav) && (arr[i].count()>0)) f1 = false; //если встретили не равное кол-во
    }
    if (c>1){ //если в списке графиков среди выделенных что-то есть больше 2, значит будем дальше считать
        if (!f1) ui->lab_warning->setText("Внимание! В выбранных графиках количество данных не равно между собой, из-за чего результат анализа может быть не точен!");
        else ui->lab_warning->setText("");
            for (int i = 0; i < ui->listGr->count(); i++){
                if ((ui->listGr->item(i)->isSelected()) && (arr[i].count()>0)){
                    model1->setItem(k, 0, new QStandardItem(ui->listGr->item(i)->text()));        //1 столбец - Графики
                    model1->setItem(k, 1, new QStandardItem(QString::number(arr[i].count())));    //2 столбец - Кол-во значений
                    model1->setItem(k, 2, new QStandardItem(QString::number(sum(arr[i]))));       //3 столбец - Сумма
                    model1->setItem(k, 3, new QStandardItem(QString::number(avg(arr[i]))));       //4 столбец - Среднее
                    model1->setItem(k, 4, new QStandardItem(QString::number(dispers(arr[i]))));   //5 столбец - Дисперсия
                    n+= arr[i].count();
                    ni.append(arr[i].count());
                    k+=1;
                }
            }
            a = ui->tableResult->model()->rowCount();
            ui->tableResult->setModel(model1);
            //число степеней свободы
            Va = a - 1; //число степеней свободы объяснённой дисперсии
            Ve = n - a; //число степеней свободы необъяснённой дисперсии
            //Вычислим суммы квадратов отклонений
            for (int i = 0; i < ui->listGr->count(); i++){
                if ((ui->listGr->item(i)->isSelected())  && (arr[i].count()>0)){
                    for (int j = 0; j < arr[i].count(); j++){
                        X += arr[i][j];
                    }
                }
            }
            X /= n;
            if ((a-1) != 0) MSa = SSa(ni)/(a-1); //объяснённая дисперсия (между групами)
            if (Ve != 0) MSe = SSe(ni)/Ve; //необъяснённая дисперсия (внутри групп)
            if (MSe != 0) F = MSa/MSe; //фактическое отношение Фишера
            model2->setItem(0, 0, new QStandardItem(QString("Между группами")));//Первый ряд
            model2->setItem(1, 0, new QStandardItem(QString("Внутри групп")));//Второй ряд
            model2->setItem(0, 1, new QStandardItem(QString::number(SSa(ni)))); //строка 1, столбец 2
            model2->setItem(1, 1, new QStandardItem(QString::number(SSe(ni))));
            model2->setItem(0, 2, new QStandardItem(QString::number(Va)));
            model2->setItem(1, 2, new QStandardItem(QString::number(Ve)));
            model2->setItem(0, 3, new QStandardItem(QString::number(MSa)));
            model2->setItem(1, 3, new QStandardItem(QString::number(MSe)));
            model2->setItem(0, 4, new QStandardItem(QString::number(F)));
            ui->tableDispers->setColumnWidth(0, 160);
            if ((Va !=0) && (Ve != 0)){
                fdistribution *fd = new fdistribution(ui->SpinAlpha->value(), Va, Ve);
                model2->setItem(0, 5, new QStandardItem(QString::number(fd->get_Fcritic())));
                if (F > fd->get_Fcritic()) ui->lab_opis->setText("Вывод:\nНулевая гипотеза отклоняется (F > F-критическое) "
                                        "с уровнем значимости альфа = " + QString::number(ui->SpinAlpha->value())+ ". "
                                        "Это означает, что фактор существенно влияет на изменение данных и данные зависимы от фактора "
                                                       "с вероятностью "+QString::number((1-ui->SpinAlpha->value())*100)+"%.");
                else ui->lab_opis->setText("Вывод:\nНулевая гипотеза не может быть отклонена (F < F-критическое) "
                                           "с уровнем значимости альфа = " + QString::number(ui->SpinAlpha->value())+ ". "
                                           "Это означает, что фактор не оказывает существенного влияния на данные "
                                           "с вероятностью "+QString::number((1-ui->SpinAlpha->value())*100)+"%.");
                delete fd;
            }
            ui->tableDispers->setModel(model2);
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Не во всех выбранных графиках расчитан анализируемый параметр!"));
}

void dispers_analysis::on_SpinAlpha_valueChanged(double arg1)
{
    if ((ui->pushButton_Calculate->isEnabled()) && (Va !=0) && (Ve != 0)){
        fdistribution *fd = new fdistribution(arg1, Va, Ve);
        model2->setItem(0, 5, new QStandardItem(QString::number(fd->get_Fcritic())));
        ui->tableDispers->setModel(model2);
        delete fd;
    }
}
