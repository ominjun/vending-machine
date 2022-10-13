#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

#define CoffeeMoney 100
#define TeaMoney 150

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ChangeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);
    ui->pbCoffee->setEnabled(money >= CoffeeMoney);
    ui->pbTea->setEnabled(money >= TeaMoney);
}

void Widget::on_pb50_clicked()
{
    Widget::ChangeMoney(50);
}


void Widget::on_pb100_clicked()
{
    Widget::ChangeMoney(100);
}


void Widget::on_pb500_clicked()
{
    Widget::ChangeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    Widget::ChangeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    Widget::ChangeMoney(-150);
}
void Widget::AddMoneyInformation(QString * MoneyStr, int DivMoney)
{
    MoneyStr->append(QString::number(DivMoney));
    MoneyStr->append("= ");
    MoneyStr->append(QString::number(money/DivMoney));
    MoneyStr->append("\n");
    money %= DivMoney;
}

void Widget::on_pbReset_clicked()
{
    QMessageBox msg;
    QString remain;
    AddMoneyInformation(&remain,500);
    AddMoneyInformation(&remain,100);
    AddMoneyInformation(&remain,50);
    AddMoneyInformation(&remain,10);
    msg.information(this,"Reset",remain);
    Widget::ChangeMoney(-1 * money);
}
