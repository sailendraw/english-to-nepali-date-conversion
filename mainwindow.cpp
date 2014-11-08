#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QHash"
#include "QDebug"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);





}

MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow::is_leap_year(int year)
{
    int a =  year;
    if (a%100==0)
                {
                 if(a%400==0)
                 {
                    return true;
                 } else {
                    return false;
                 }

                } else {
                    if (a%4==0)
                    {
                        return true;
                    } else {
                        return false;
                    }
                }
}
int MainWindow::cnvToNepali(int mm, int dd, int yy)
{
   int  BS[91][13]={
       2000,30,32,31,32,31,30,30,30,29,30,29,31 ,
       2001,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2002,31,31,32,32,31,30,30,29,30,29,30,30 ,
       2003,31,32,31,32,31,30,30,30,29,29,30,31 ,
       2004,30,32,31,32,31,30,30,30,29,30,29,31 ,
       2005,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2006,31,31,32,32,31,30,30,29,30,29,30,30 ,
       2007,31,32,31,32,31,30,30,30,29,29,30,31 ,
       2008,31,31,31,32,31,31,29,30,30,29,29,31 ,
       2009,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2010,31,31,32,32,31,30,30,29,30,29,30,30 ,
       2011,31,32,31,32,31,30,30,30,29,29,30,31 ,
       2012,31,31,31,32,31,31,29,30,30,29,30,30 ,
       2013,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2014,31,31,32,32,31,30,30,29,30,29,30,30 ,
       2015,31,32,31,32,31,30,30,30,29,29,30,31 ,
       2016,31,31,31,32,31,31,29,30,30,29,30,30 ,
       2017,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2018,31,32,31,32,31,30,30,29,30,29,30,30 ,
       2019,31,32,31,32,31,30,30,30,29,30,29,31 ,
       2020,31,31,31,32,31,31,30,29,30,29,30,30 ,
       2021,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2022,31,32,31,32,31,30,30,30,29,29,30,30 ,
       2023,31,32,31,32,31,30,30,30,29,30,29,31 ,
       2024,31,31,31,32,31,31,30,29,30,29,30,30 ,
       2025,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2026,31,32,31,32,31,30,30,30,29,29,30,31 ,
       2027,30,32,31,32,31,30,30,30,29,30,29,31 ,
       2028,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2029,31,31,32,31,32,30,30,29,30,29,30,30 ,
       2030,31,32,31,32,31,30,30,30,29,29,30,31 ,
       2031,30,32,31,32,31,30,30,30,29,30,29,31 ,
       2032,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2033,31,31,32,32,31,30,30,29,30,29,30,30 ,
       2034,31,32,31,32,31,30,30,30,29,29,30,31 ,
       2035,30,32,31,32,31,31,29,30,30,29,29,31 ,
       2036,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2037,31,31,32,32,31,30,30,29,30,29,30,30 ,
       2038,31,32,31,32,31,30,30,30,29,29,30,31 ,
       2039,31,31,31,32,31,31,29,30,30,29,30,30 ,
       2040,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2041,31,31,32,32,31,30,30,29,30,29,30,30 ,
       2042,31,32,31,32,31,30,30,30,29,29,30,31 ,
       2043,31,31,31,32,31,31,29,30,30,29,30,30 ,
       2044,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2045,31,32,31,32,31,30,30,29,30,29,30,30 ,
       2046,31,32,31,32,31,30,30,30,29,29,30,31 ,
       2047,31,31,31,32,31,31,30,29,30,29,30,30 ,
       2048,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2049,31,32,31,32,31,30,30,30,29,29,30,30 ,
       2050,31,32,31,32,31,30,30,30,29,30,29,31 ,
       2051,31,31,31,32,31,31,30,29,30,29,30,30 ,
       2052,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2053,31,32,31,32,31,30,30,30,29,29,30,30 ,
       2054,31,32,31,32,31,30,30,30,29,30,29,31 ,
       2055,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2056,31,31,32,31,32,30,30,29,30,29,30,30 ,
       2057,31,32,31,32,31,30,30,30,29,29,30,31 ,
       2058,30,32,31,32,31,30,30,30,29,30,29,31 ,
       2059,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2060,31,31,32,32,31,30,30,29,30,29,30,30 ,
       2061,31,32,31,32,31,30,30,30,29,29,30,31 ,
       2062,30,32,31,32,31,31,29,30,29,30,29,31 ,
       2063,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2064,31,31,32,32,31,30,30,29,30,29,30,30 ,
       2065,31,32,31,32,31,30,30,30,29,29,30,31 ,
       2066,31,31,31,32,31,31,29,30,30,29,29,31 ,
       2067,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2068,31,31,32,32,31,30,30,29,30,29,30,30 ,
       2069,31,32,31,32,31,30,30,30,29,29,30,31 ,
       2070,31,31,31,32,31,31,29,30,30,29,30,30 ,
       2071,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2072,31,32,31,32,31,30,30,29,30,29,30,30 ,
       2073,31,32,31,32,31,30,30,30,29,29,30,31 ,
       2074,31,31,31,32,31,31,30,29,30,29,30,30 ,
       2075,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2076,31,32,31,32,31,30,30,30,29,29,30,30 ,
       2077,31,32,31,32,31,30,30,30,29,30,29,31 ,
       2078,31,31,31,32,31,31,30,29,30,29,30,30 ,
       2079,31,31,32,31,31,31,30,29,30,29,30,30 ,
       2080,31,32,31,32,31,30,30,30,29,29,30,30 ,
       2081, 31, 31, 32, 32, 31, 30, 30, 30, 29, 30, 30, 30 ,
       2082, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30 ,
       2083, 31, 31, 32, 31, 31, 30, 30, 30, 29, 30, 30, 30 ,
       2084, 31, 31, 32, 31, 31, 30, 30, 30, 29, 30, 30, 30 ,
       2085, 31, 32, 31, 32, 30, 31, 30, 30, 29, 30, 30, 30 ,
       2086, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30 ,
       2087, 31, 31, 32, 31, 31, 31, 30, 30, 29, 30, 30, 30 ,
       2088, 30, 31, 32, 32, 30, 31, 30, 30, 29, 30, 30, 30 ,
       2089, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30 ,
       2090, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30};


   int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int lmonth[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int yr;
    int mth;
    int dy;
    int def_eyy = 1944;									//spear head english date...
                int def_nyy = 2000; int def_nmm = 9; int def_ndd = 17-1;		//spear head nepali date...
                int total_eDays=0; int total_nDays=0; int a=0; int day=7-1;		//all the initializations...
                int m = 0; int y = 0; int i =0; int j = 0;
                int numDay=0;
                        //initial checks and all...
    if( yy<1944 ||  yy>2033){
        qDebug()<<"1,Supported only between 1944-2033";
       yr = 0;

    }
    if( mm<1 ||  mm >12){
       qDebug()<<"2,Error in month value 1-12, Are you looking for jupiter's calender?";
        mth= 0;
return 0;
    }
    if( dd<1 ||  dd >31){
       qDebug()<<"3:Error in day value";
        dy = 0;
        return 0;

    }
    // count total no. of days in-terms of year
                for(int i=0;  i<(yy-def_eyy);  i++)
                {	//total days for month calculation...(english)
                    if(is_leap_year(def_eyy+i)==1)
                        for(int j=0; j<12;  j++)
                         total_eDays += lmonth[j];
                    else
                        for(int j=0; j<12; j++)
                             total_eDays += month[j];
                }
                // count total no. of days in-terms of month
                            for(int i=0; i<(mm-1); i++){
                                if(is_leap_year(yy)==1)
                                    total_eDays += lmonth[i];
                                else
                                    total_eDays += month[i];
                            }

                            // count total no. of days in-terms of date
                                            total_eDays += dd;


                                             i = 0;j = def_nmm;
                                            total_nDays = def_ndd;
                                            m = def_nmm;
                                          y =def_nyy;
                                          while(total_eDays != 0) {
                                                              a = BS[i][j];
                                                              total_nDays++;						//count the days
                                                              day++;								//count the days interms of 7 days
                                                              if(total_nDays > a){
                                                                  m++;
                                                                  total_nDays=1;
                                                                  j++;
                                                              }
                                                              if(day > 7)
                                                                 day = 1;
                                                              if(m > 12){
                                                                  y++;
                                                                  m = 1;
                                                              }
                                                              if(j > 12){
                                                                  j = 1; i++;
                                                              }
                                                              total_eDays--;
                                                          }

                                                          numDay=day;
QString d;
QString barsha=QString::number(y);
QString nd=QString::number(total_nDays);
QString moth=get_nepali_month(m);
d.append(barsha);
d.append("-");
d.append(nd);
d.append("-");
d.append(moth);
ui->lineEdit->setText(d);

return 0;
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    qDebug()<<date;
}

void MainWindow::on_dateEdit_dateChanged(const QDate &date)
{
    int mm=date.month();
    int yy=date.year();
    int dd=date.day();
    cnvToNepali(mm,dd,yy);

}
QString MainWindow::get_nepali_month(int m){
    QString n_month = false;

    switch(m){
        case 1:
            n_month = "Baishak";
            break;

        case 2:
            n_month = "Jestha";
            break;

        case 3:
            n_month = "Ashad";
            break;

        case 4:
           n_month = "Shrawn";
            break;

        case 5:
            n_month = "Bhadra";
            break;

        case 6:
            n_month = "Ashwin";
            break;

        case 7:
            n_month = "kartik";
            break;

        case 8:
            n_month = "Mangshir";
            break;

        case 9:
            n_month = "Poush";
            break;

        case 10:
            n_month = "Magh";
            break;

        case 11:
            n_month = "Falgun";
            break;

        case 12:
            n_month = "Chaitra";
            break;
    }
    return  n_month;
}
QString MainWindow::get_day_of_week(int d)
{
    QString day;
    switch(d){
                case 1:
                    day = "Sunday";
                    break;

                case 2:
                    day = "Monday";
                    break;

                case 3:
                    day = "Tuesday";
                    break;

                case 4:
                    day = "Wednesday";
                    break;

                case 5:
                    day = "Thursday";
                    break;

                case 6:
                    day = "Friday";
                    break;

                case 7:
                    day = "Saturday";
                    break;
            }
            return day;
}
