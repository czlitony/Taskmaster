#include "settingdialog.h"
#include "ui_settingdialog.h"
#include"musicsetting/musicsettingitem.h"
#include "musicsetting/musicsetting.h"
#include "utils/fileutils.h"
#include <QString>
#include <QFileDialog>
#include <QSettings>

static const QString LAST_MUSIC_FILE_PATH = "LastMusicFilePath";
static const QString COOKIE = "Cookie";

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    initSettingDialog();
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::initSettingDialog()
{
    MusicSettingItem musicSettings = MusicSetting::getInstance()->getMusicSettings();

    ui->musicSwitch->setChecked(musicSettings.isMusicOn());

    bool isDefaultQuickTaskMusic = musicSettings.getQuickTaskMusic().isDefaultMusic();
    ui->defaultQuickTaskMusicButton->setChecked(isDefaultQuickTaskMusic);
    ui->selfQuickTaskMusicButton->setChecked(!isDefaultQuickTaskMusic);
    ui->selfQuickTaskMusicLineEdit->setText(musicSettings.getQuickTaskMusic().getFile());

    bool isDefaultFileTaskMusic = musicSettings.getFileTaskMusic().isDefaultMusic();
    ui->defaultFileTaskMusicButton->setChecked(isDefaultFileTaskMusic);
    ui->selfFileTaskMusicButton->setChecked(!isDefaultFileTaskMusic);
    ui->selfFileTaskMusicLineEdit->setText(musicSettings.getFileTaskMusic().getFile());
}

void SettingDialog::on_musicSwitch_clicked(bool checked)
{
    MusicSetting::getInstance()->switchMusic(checked);
}

void SettingDialog::on_defaultQuickTaskMusicButton_clicked()
{
    MusicSetting::getInstance()->setDefaultQuickTaskMusic();
}

void SettingDialog::on_selfQuickTaskMusicButton_clicked()
{
    QString selfQuickTaskMusicFile = ui->selfQuickTaskMusicLineEdit->text();
    if (!selfQuickTaskMusicFile.isEmpty())
    {
        MusicSetting::getInstance()->setSelfQuickTaskMusic(selfQuickTaskMusicFile);
    }
}

void SettingDialog::on_selectQuickTaskMusicButton_clicked()
{
    QSettings setting(FileUtils::getGeneralSettingFile(), QSettings::IniFormat);
    QString lastPath = setting.value(LAST_MUSIC_FILE_PATH).toString();

    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("Select Music"));
    fileDialog->setNameFilter(tr("Music Files(*.mp3 *.wav)"));
    if (!lastPath.isEmpty())
    {
        fileDialog->setDirectory(lastPath);
    }

    if (fileDialog->exec() == QDialog::Accepted)
    {
        if (!fileDialog->selectedFiles().empty())
        {
            QString file = fileDialog->selectedFiles()[0];
            ui->selfQuickTaskMusicLineEdit->setText(file);

            MusicSetting::getInstance()->setSelfQuickTaskMusic(file);
        }
    }

    setting.setValue(LAST_MUSIC_FILE_PATH, fileDialog->directory().absolutePath());
}

void SettingDialog::on_defaultFileTaskMusicButton_clicked()
{
    MusicSetting::getInstance()->setDefaultFileTaskMusic();
}

void SettingDialog::on_selfFileTaskMusicButton_clicked()
{
    QString selfFileTaskMusicFile = ui->selfFileTaskMusicLineEdit->text();
    if (!selfFileTaskMusicFile.isEmpty())
    {
        MusicSetting::getInstance()->setSelfFileTaskMusic(selfFileTaskMusicFile);
    }
}

void SettingDialog::on_selectFileTaskMusicButton_clicked()
{
    QSettings setting(FileUtils::getGeneralSettingFile(), QSettings::IniFormat);
    QString lastPath = setting.value(LAST_MUSIC_FILE_PATH).toString();

    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("Select Music"));
    fileDialog->setNameFilter(tr("Music Files(*.mp3 *.wav)"));
    if (!lastPath.isEmpty())
    {
        fileDialog->setDirectory(lastPath);
    }

    if (fileDialog->exec() == QDialog::Accepted)
    {
        if (!fileDialog->selectedFiles().empty())
        {
            QString file = fileDialog->selectedFiles()[0];
            ui->selfFileTaskMusicLineEdit->setText(file);

            MusicSetting::getInstance()->setSelfFileTaskMusic(file);
        }
    }

    setting.setValue(LAST_MUSIC_FILE_PATH, fileDialog->directory().absolutePath());
}

void SettingDialog::on_updateCookieButton_clicked()
{
    QString cookie = ui->cookieTextEdit->toPlainText();
    if (!cookie.isEmpty())
    {
        QSettings setting(FileUtils::getCookieFile(), QSettings::IniFormat);
        setting.setValue(COOKIE, cookie);
    }
}
