#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    MainWindow m;
    m.show();
}
