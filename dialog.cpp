#include "dialog.h"
#include "ui_dialog.h"
//########################################################################################################
#include "QDebug"
using namespace std;
#include <iostream>
#include <fstream>
#include <QFileDialog>
#include <QTextStream>
#include <QProcess>
/// переменные:
std::vector<unsigned long long> list_of_synapses ;
std::vector<unsigned long long> list_of_neurons[201] ;
long long variable_error;
QString    Nazvaniye_fayla_s_neyronami_i_signalom="";
bool Odin_Uchitelia;
bool Odin_Programmi;
//########################################################################################################
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
//########################################################################################################
qDebug() << "Funktsiya_resheniya_2_avto";
//########################################################################################################   
for (int bmp_name=8;bmp_name<117; bmp_name++)
{
Nazvaniye_fayla_s_neyronami_i_signalom="/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/peyzaji_2/"+
QString::number(bmp_name)+"/neurons_and_signal.txt";
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// //NOTE: считывание в вектор нейронов и сигналов из файла
    std::ifstream is( 
       Nazvaniye_fayla_s_neyronami_i_signalom.toStdString().c_str()
        );
    std::istream_iterator<unsigned long long> start(is), end;
    std::vector<unsigned long long> list_of_neurons(start, end);
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// считываем синапсы из файла в вектор
    std::ifstream is2(

    "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt"
    );
    std::istream_iterator<unsigned long long> start2(is2), end2;
    std::vector<unsigned long long> list_of_synapses(start2, end2);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   считаем ошибку
    variable_error     =   1073741824-list_of_neurons[200] ;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//   std::cout << "variable_error = "<< variable_error<< std::endl;
//   std::cout << "list_of_neurons[200] = "<< list_of_neurons[200]<< std::endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   показываем что определила программа
    if 
        ( variable_error <=0)

    {
        ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это 1.");
        Odin_Programmi=true;
        // записываем имя файла в файл
//########################################################################################################

    QFile file("/home/viktor/my_projects_qt_2/Funktsiya_resheniya_2_avto/oshibochnie_bmp.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text))
      {
        qDebug() << "Failed to open file";
          }
    QTextStream out(&file);

        out << Nazvaniye_fayla_s_neyronami_i_signalom << endl;
   
    file.close();
//########################################################################################################     
        
    }
                           else {
        ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это не 1.");
          Odin_Programmi=false;
    }
//########################################################################################################



} // for



}

Dialog::~Dialog()
{
    delete ui;
}

