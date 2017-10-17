#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->oneButton->setFlat(true);
      ui->twoButton->setFlat(true);
        ui->threeButton->setFlat(true);
          ui->fourButton->setFlat(true);
            ui->fiveButton->setFlat(true);
              ui->sixButton->setFlat(true);
              ui->sevenButton->setFlat(true);
                ui->eightButton->setFlat(true);
                  ui->nineButton->setFlat(true);
                    ui->zeroButton->setFlat(true);
                      ui->pointButton->setFlat(true);
                        ui->leftButton->setFlat(true);
                          ui->rightButton->setFlat(true);
                          ui->addButton->setFlat(true);
                          ui->subtractButton->setFlat(true);
                          ui->multiplyButton->setFlat(true);
                          ui->divideButton->setFlat(true);
                          ui->equalButton->setFlat(true);
        QObject::connect(ui->copySelectedItem,SIGNAL(triggered(bool)),ui->valueLineEdit,SLOT(copy()));
        QObject::connect(ui->undoItem,SIGNAL(triggered(bool)),ui->valueLineEdit,SLOT(undo()));
        QObject::connect(ui->redoItem,SIGNAL(triggered(bool)),ui->valueLineEdit,SLOT(redo()));
        QObject::connect(ui->selectedAllItem,SIGNAL(triggered(bool)),ui->valueLineEdit,SLOT(selectAll()));
        QObject:connect(ui->pasteItem,SIGNAL(triggered(bool)),ui->valueLineEdit,SLOT(paste()));
        this->setWindowTitle("Calculator");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_oneButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    lineEditValue.append('1');
    ui->valueLineEdit->setText(lineEditValue);

}

void MainWindow::on_twoButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    lineEditValue.append('2');
    ui->valueLineEdit->setText(lineEditValue);
}

void MainWindow::on_threeButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    lineEditValue.append('3');
    ui->valueLineEdit->setText(lineEditValue);
}

void MainWindow::on_fourButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    lineEditValue.append('4');
    ui->valueLineEdit->setText(lineEditValue);
}

void MainWindow::on_fiveButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    lineEditValue.append('5');
    ui->valueLineEdit->setText(lineEditValue);
}

void MainWindow::on_sixButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    lineEditValue.append('6');
    ui->valueLineEdit->setText(lineEditValue);
}

void MainWindow::on_sevenButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    lineEditValue.append('7');
    ui->valueLineEdit->setText(lineEditValue);
}

void MainWindow::on_eightButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    lineEditValue.append('8');
    ui->valueLineEdit->setText(lineEditValue);
}

void MainWindow::on_nineButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    lineEditValue.append('9');
    ui->valueLineEdit->setText(lineEditValue);
}

void MainWindow::on_zeroButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    lineEditValue.append('0');
    ui->valueLineEdit->setText(lineEditValue);
}

void MainWindow::on_pointButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    lineEditValue.append('.');
    ui->valueLineEdit->setText(lineEditValue);
}

void MainWindow::on_leftButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    lineEditValue.append('(');
    ui->valueLineEdit->setText(lineEditValue);
}

void MainWindow::on_rightButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    lineEditValue.append(')');
    ui->valueLineEdit->setText(lineEditValue);
}

void MainWindow::on_addButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    lineEditValue.append('+');
    ui->valueLineEdit->setText(lineEditValue);
}

void MainWindow::on_subtractButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    lineEditValue.append('-');
    ui->valueLineEdit->setText(lineEditValue);
}

void MainWindow::on_multiplyButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    lineEditValue.append('*');
    ui->valueLineEdit->setText(lineEditValue);
}

void MainWindow::on_divideButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    lineEditValue.append('/');
    ui->valueLineEdit->setText(lineEditValue);
}

void MainWindow::on_equalButton_clicked()
{
    lineEditValue=ui->valueLineEdit->text();
    Line line=Function::getBackE(lineEditValue);
    if(line.isEmply())
    {
        QMessageBox::information(this,"error","please check your expression!");
        return;
    }
    double result=Function::getResultByLine(line);
    ui->valueLineEdit->setText(QString::number(result));

}
