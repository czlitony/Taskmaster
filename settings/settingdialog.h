#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>

namespace Ui {
class SettingDialog;
}

class MusicSetting;

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();

private slots:
    void on_musicSwitch_clicked(bool checked);

private:
    Ui::SettingDialog *ui;

    MusicSetting* m_musicSetting;
};

#endif // SETTINGDIALOG_H
