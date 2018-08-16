#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class SettingDialog;
class TaskMaster;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_settingButton_clicked();

    void on_switchButton_clicked(bool checked);

private:
    Ui::MainWindow *ui;

    SettingDialog* m_settingDialog;
    TaskMaster* m_taskMaster;

};

#endif // MAINWINDOW_H
