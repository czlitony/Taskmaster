#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings/settingdialog.h"
#include "tasks/retrievalresult.h"
#include "tasks/unfinishedtask.h"
#include "tasks/quicktask.h"
#include "tasks/filetask.h"
#include "taskmaster.h"
#include <QMenuBar>
#include <QMessageBox>
#include <QStandardItemModel>
#include <functional>
#include <future>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_settingDialog(new SettingDialog(this)),
    m_taskMaster(new TaskMaster)
{
    ui->setupUi(this);

    m_settingDialog->setModal(true);

    connect(m_taskMaster, SIGNAL(fireOnTasksRetrieved(TaskRetrievalResult, const QList<UnfinishedTask>&, const QList<QuickTask>&, const QList<FileTask>&)),
            this, SLOT(onTasksRetrieved(TaskRetrievalResult, const QList<UnfinishedTask>&, const QList<QuickTask>&, const QList<FileTask>&)), Qt::DirectConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_settingButton_clicked()
{
    m_settingDialog->show();
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

void MainWindow::showSessionExpiryDialog()
{
    QMessageBox msgBox;
    msgBox.setText("Session Expired!");
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.exec();
}

void MainWindow::updateUnfinishedTasksTable(const QList<UnfinishedTask> &unfinishedTask)
{
    QStandardItemModel *model = new QStandardItemModel();
    QStringList list;
    list << "Id" << "Language" << "Word Number" << "Status" << "Time Left" << "Deadline" << "Pay" << "Bonus";
    model->setHorizontalHeaderLabels(list);

    int row = 0;
    foreach (UnfinishedTask item, unfinishedTask) {
        int col = 0;
        model->setItem(row, col++, new QStandardItem(item.getOrderDetail().getNumber()));
        model->setItem(row, col++, new QStandardItem(item.getLanguage()));
        model->setItem(row, col++, new QStandardItem(QString::number(item.getWordNumber())));
        model->setItem(row, col++, new QStandardItem(item.getStatus()));
        model->setItem(row, col++, new QStandardItem(item.getTimeLeft()));
        model->setItem(row, col++, new QStandardItem(item.getDeadline()));
        model->setItem(row, col++, new QStandardItem(item.getPay()));
        model->setItem(row, col++, new QStandardItem(item.getBonus()));

        ++row;
    }


    ui->unfinishedTaskTable->setModel(model);
}

void MainWindow::updateQuickTasksTable(const QList<QuickTask> &quickTask)
{
    QStandardItemModel *model = new QStandardItemModel();
    QStringList list;
    list << "Id" << "Language" << "Word Number" << "Abstract" << "Finish Time" << "Pay" << "Bonus";
    model->setHorizontalHeaderLabels(list);

    int row = 0;
    foreach (QuickTask item, quickTask) {
        int col = 0;
        model->setItem(row, col++, new QStandardItem(item.getOrderDetail().getNumber()));
        model->setItem(row, col++, new QStandardItem(item.getLanguage()));
        model->setItem(row, col++, new QStandardItem(QString::number(item.getWordNumber())));
        model->setItem(row, col++, new QStandardItem(item.getAbstract()));
        model->setItem(row, col++, new QStandardItem(item.getFinishTime()));
        model->setItem(row, col++, new QStandardItem(item.getPay()));
        model->setItem(row, col++, new QStandardItem(item.getBonus()));

        ++row;
    }


    ui->quickTaskTable->setModel(model);
}

void MainWindow::updateFileTasksTable(const QList<FileTask> &fileTask)
{
    QStandardItemModel *model = new QStandardItemModel();
    QStringList list;
    list << "Id" << "Language" << "Word Number" << "Field" << "Usage" << "Time Left" << "Deadline" << "Pay" << "Bonus";
    model->setHorizontalHeaderLabels(list);

    int row = 0;
    foreach (FileTask item, fileTask) {
        int col = 0;
        model->setItem(row, col++, new QStandardItem(item.getOrderDetail().getNumber()));
        model->setItem(row, col++, new QStandardItem(item.getLanguage()));
        model->setItem(row, col++, new QStandardItem(QString::number(item.getWordNumber())));
        model->setItem(row, col++, new QStandardItem(item.getArea()));
        model->setItem(row, col++, new QStandardItem(item.getUsage()));
        model->setItem(row, col++, new QStandardItem(item.getTimeLeft()));
        model->setItem(row, col++, new QStandardItem(item.getDeadline()));
        model->setItem(row, col++, new QStandardItem(item.getPay()));
        model->setItem(row, col++, new QStandardItem(item.getBonus()));

        ++row;
    }


    ui->fileTaskTable->setModel(model);
}

void MainWindow::onTasksRetrieved(TaskRetrievalResult result, const QList<UnfinishedTask> &unfinishedTask, const QList<QuickTask> &quickTask, const QList<FileTask> &fileTask)
{
    if (result == TaskRetrievalResult::SESSION_EXPIRED)
    {
        showSessionExpiryDialog();
        return;
    }

    auto unfinishedTaskHandle = std::async(std::launch::async,
                             &MainWindow::updateUnfinishedTasksTable, this, unfinishedTask);

    auto quickTaskHandle = std::async(std::launch::async,
                             &MainWindow::updateQuickTasksTable, this, quickTask);

    auto fileTaskHandle = std::async(std::launch::async,
                             &MainWindow::updateFileTasksTable, this, fileTask);

    unfinishedTaskHandle.get();
    quickTaskHandle.get();
    fileTaskHandle.get();
}
