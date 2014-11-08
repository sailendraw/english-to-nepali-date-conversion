#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
struct DateStruct{
        int yy;
        int mm;
        int dd;
        int day;
        char wmonth[20];
        char wday[20];
};

struct DateStruct2{
        int yy;
        int mm;
        int dd;
        int day;
};
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    int is_leap_year(int);
      int cnvToNepali(int, int , int);
        DateStruct cnvToEnglish(int, int, int);
        int what();
        int err(int errno, char * desc);
    ~MainWindow();

private slots:
        void on_calendarWidget_clicked(const QDate &date);

        void on_dateEdit_dateChanged(const QDate &date);
        QString get_nepali_month(int);
        QString get_day_of_week(int);

private:


    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
