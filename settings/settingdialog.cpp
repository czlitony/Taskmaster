#include "settingdialog.h"
#include "ui_settingdialog.h"
#include "musicsetting/musicsetting.h"

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog),
    m_musicSetting(new MusicSetting())
{
    ui->setupUi(this);
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::on_musicSwitch_clicked(bool checked)
{
    m_musicSetting->switchMusic(checked);
}
