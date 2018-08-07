#include "newtaskretriever.h"
#include <QSettings>
#include <QSslConfiguration>
#include <QNetworkReply>
#include <QFile>
#include <QString>
#include <QTextCodec>

static const QString defaultCookie = "OUTFOX_SEARCH_USER_ID=310822447@113.108.225.251; NTES_SESS=uFtYx58yRLaj9gXVCHaGEoMgrWPQH_90_PF21HdEQc0mpvFRpWZ9_iWVHdVhuKjFqRSaNGgnNS5zxq.GJWhVFTUAThMQ.t9JoR..XUAeAUW5SQ_M8Pb8sjdPzocjmvzRi0v1hSQVHPR3IjihVBEp.P3Pws5_8D0XU3qkvEULyHfvqMrorjHdcQF33c5KQPxinhAE8wqs8Vxoi; S_INFO=1533266440|0|3&80##|szhgloria#m15651635739_1#m18625085971; P_INFO=szhgloria@163.com|1533266440|0|dict_hts|00&99|jis&1533257113&dict_hts#US&null#10#0#0|&0|dict_hts&search&youdaodict_client|szhgloria@163.com; SESSION_FROM_COOKIE=unknown; JSESSIONID=aaaC_aDobhpl2hDNtZ9tw";

NewTaskRetriever::NewTaskRetriever()
{
    httpRequest.setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/7.0; rv:11.0) like Gecko");
    httpRequest.setRawHeader("Connection", "Keep-Alive");

    QSettings setting("./cookie.ini", QSettings::IniFormat);
    QString cookie = setting.value("Cookie").toString();
    if (cookie.isEmpty())
    {
        httpRequest.setRawHeader("Cookie", defaultCookie.toUtf8());
    }
    else
    {
        httpRequest.setRawHeader("Cookie", cookie.toUtf8());
    }

    auto sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
    httpRequest.setSslConfiguration(sslConfig);

    QObject::connect(&networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(serverResponse(QNetworkReply*)));

}

void NewTaskRetriever::getNewTasks()
{
    httpRequest.setUrl(QUrl("https://f.youdao.com/ds/task.do?method=index"));
    networkAccessManager.get(httpRequest);
}

void NewTaskRetriever::serverResponse(QNetworkReply *reply)
{
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    qDebug() << "BaseAPI...serviceRequestFinished...statusCode:" << statusCode;

    if(reply->error() == QNetworkReply::NoError)
    {
        QFile file("youdao_response.html");
        file.open(QIODevice::WriteOnly);
        file.write(reply->readAll());
        file.close();

//      requestFinished(reply, reply->readAll(), statusCode);

        QList<QNetworkReply::RawHeaderPair> headers = reply->rawHeaderPairs();
        QNetworkReply::RawHeaderPair header;
        foreach (header, headers) {
            qDebug() << header.first << header.second;
        }
    }
    else
    {
//        requestFinished(reply, "", statusCode);
    }

    // At the end of that slot, we won't need it anymore
    reply->deleteLater();
}
