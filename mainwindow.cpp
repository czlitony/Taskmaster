#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings/settingdialog.h"
#include "taskmaster.h"
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_taskMaster(new TaskMaster)
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

void MainWindow::on_switchButton_clicked(bool checked)
{
    if (checked)
    {
        m_taskMaster->start();
    }
    else
    {
        m_taskMaster->stop();
    }
}
