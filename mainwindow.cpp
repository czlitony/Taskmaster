#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings/settingdialog.h"
#include "tasks/taskmanager.h"
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_taskManager = new TaskManager;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_taskManager;
}

void MainWindow::on_settingButton_clicked()
{
    SettingDialog* settingDialog = new SettingDialog(this);
    settingDialog->setModal(true);
    settingDialog->show();
}

void MainWindow::on_switchButton_clicked()
{
    m_taskManager->start();
}
