#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();

private slots:
    void on_musicSwitch_clicked(bool checked);

    void on_defaultQuickTaskMusicButton_clicked();

    void on_selfQuickTaskMusicButton_clicked();

    void on_selectQuickTaskMusicButton_clicked();

    void on_defaultFileTaskMusicButton_clicked();

    void on_selfFileTaskMusicButton_clicked();

    void on_selectFileTaskMusicButton_clicked();

    void on_updateCookieButton_clicked();

private:
    void initSettingDialog();

    Ui::SettingDialog *ui;
};

#endif // SETTINGDIALOG_H
