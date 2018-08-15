#include "taskretriever.h"
#include "utils/fileutils.h"
#include "tasks/taskparser.h"
#include "settings/cookiesetting/cookiesetting.h"
#include <QSettings>
#include <QSslConfiguration>
#include <QNetworkReply>
#include <QFile>
#include <QString>
#include <QTextCodec>


static const QString DEFAULT_COOKIE = "OUTFOX_SEARCH_USER_ID=310822447@113.108.225.251; NTES_SESS=uFtYx58yRLaj9gXVCHaGEoMgrWPQH_90_PF21HdEQc0mpvFRpWZ9_iWVHdVhuKjFqRSaNGgnNS5zxq.GJWhVFTUAThMQ.t9JoR..XUAeAUW5SQ_M8Pb8sjdPzocjmvzRi0v1hSQVHPR3IjihVBEp.P3Pws5_8D0XU3qkvEULyHfvqMrorjHdcQF33c5KQPxinhAE8wqs8Vxoi; S_INFO=1533266440|0|3&80##|szhgloria#m15651635739_1#m18625085971; P_INFO=szhgloria@163.com|1533266440|0|dict_hts|00&99|jis&1533257113&dict_hts#US&null#10#0#0|&0|dict_hts&search&youdaodict_client|szhgloria@163.com; SESSION_FROM_COOKIE=unknown; JSESSIONID=aaaC_aDobhpl2hDNtZ9tw";

TaskRetriever::TaskRetriever():
    m_taskParser(new TaskParser),
    m_lastRetrievalInProgress(false),
    m_result(RetrievalResult::UNKNOWN)
{
    m_httpRequest.setUrl(QUrl("https://f.youdao.com/ds/task.do?method=index"));

    m_httpRequest.setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/7.0; rv:11.0) like Gecko");
    m_httpRequest.setRawHeader("Connection", "Keep-Alive");

    QString cookie = CookieSetting::getInstance()->getCookie();
    if (cookie.isEmpty())
    {
        m_httpRequest.setRawHeader("Cookie", DEFAULT_COOKIE.toUtf8());
    }
    else
    {
        m_httpRequest.setRawHeader("Cookie", cookie.toUtf8());
    }

    auto sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
    m_httpRequest.setSslConfiguration(sslConfig);

    QObject::connect(&m_networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResponseReceived(QNetworkReply*)));

}

void TaskRetriever::retrieveTasks()
{
//    if (m_lastRetrievalInProgress)
//    {
//        return;
//    }

//    m_networkAccessManager.get(m_httpRequest);

    QString response = getResponseFromCacheFile();
    if (!response.contains("unfinsh-task", Qt::CaseInsensitive))
    {
        m_result = RetrievalResult::SESSION_EXPIRED;
        return;
    }
    QList<UnfinishedTask> unfinishedTask;
    QList<QuickTask> quickTask;
    QList<FileTask> fileTask;
    m_taskParser->parse(response, unfinishedTask, quickTask, fileTask);

    m_lastRetrievalInProgress = true;
}

void TaskRetriever::onResponseReceived(QNetworkReply *reply)
{
    m_lastRetrievalInProgress = false;

    m_result = RetrievalResult::UNKNOWN;

    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    if (statusCode != 200)
    {
        m_result = RetrievalResult::NETWORK_ERROR;
    }
    else if (reply->error() != QNetworkReply::NoError)
    {
        m_result = RetrievalResult::NETWORK_ERROR;
    }

    m_result = RetrievalResult::SUCCEED;

    QString response(reply->readAll());

    QList<UnfinishedTask> unfinishedTask;
    QList<QuickTask> quickTask;
    QList<FileTask> fileTask;

    emit finished(m_result, unfinishedTask, quickTask, fileTask);

    writeResponseToCacheFile(response.toUtf8());

    reply->deleteLater();
}

void TaskRetriever::writeResponseToCacheFile(const QByteArray &response)
{
    QString cacheFile = FileUtils::taskResponseFile();

    static int count = 0;
    cacheFile = cacheFile + "_" + QString::number(count) + ".html";
    if (count == 4)
    {
        count = 0;
    }

    QFile file(cacheFile);
    file.open(QIODevice::WriteOnly);
    file.write(response);
    file.close();
}

QString TaskRetriever::getResponseFromCacheFile() const
{
    QString cacheFile = FileUtils::taskResponseFile();

    static int count = 0;
    cacheFile = cacheFile + "_" + QString::number(count) + ".html";
    if (count == 4)
    {
        count = 0;
    }

    QFile file(cacheFile);
    file.open(QIODevice::ReadOnly);
    QString response = file.readAll();
    file.close();

    return response;
}
