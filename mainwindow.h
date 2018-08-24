#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTimer>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class SettingDialog;
class TaskMaster;
class UnfinishedTask;
class QuickTask;
class FileTask;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_settingButton_clicked();

    void on_switchButton_clicked(bool checked);

    void onTaskRetrievalStarted();
    void onTasksRetrieved(enum TaskRetrievalResult result,
                          const QList<UnfinishedTask>& unfinishedTask,
                          const QList<QuickTask>& quickTask,
                          const QList<FileTask>& fileTask);

    void updateTimeSinceLastRefresh();

private:
    void showSessionExpiryDialog();
    void updateUnfinishedTasksTable(const QList<UnfinishedTask>& unfinishedTask);
    void updateQuickTasksTable(const QList<QuickTask>& quickTask);
    void updateFileTasksTable(const QList<FileTask>& fileTask);

    void updateTaskNumber(int quickTaskNumber, int fileTaskNumber);

    void startTaskMaster();
    void stopTaskMaster();

    Ui::MainWindow *ui;

    SettingDialog* m_settingDialog;
    TaskMaster* m_taskMaster;

    int m_timeSecSinceLastRefresh;
    QTimer* m_timeSinceLastRefreshTimer;

};

#endif // MAINWINDOW_H
