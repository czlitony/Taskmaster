#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings/settingdialog.h"
#include <QMenuBar>

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

void MainWindow::on_settingButton_clicked()
{
    SettingDialog* settingDialog = new SettingDialog(this);
    settingDialog->setModal(true);
    settingDialog->show();
}
