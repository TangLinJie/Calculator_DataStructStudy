#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"function.h"
#include<QIcon>
#include<QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString lineEditValue;
private slots:

    void on_oneButton_clicked();
    void on_twoButton_clicked();
    void on_threeButton_clicked();
    void on_fourButton_clicked();
    void on_fiveButton_clicked();
    void on_sixButton_clicked();
    void on_sevenButton_clicked();
    void on_eightButton_clicked();
    void on_nineButton_clicked();
    void on_zeroButton_clicked();
    void on_pointButton_clicked();
    void on_leftButton_clicked();
    void on_rightButton_clicked();
    void on_addButton_clicked();
    void on_subtractButton_clicked();
    void on_multiplyButton_clicked();
    void on_divideButton_clicked();
    void on_equalButton_clicked();
};

#endif // MAINWINDOW_H
