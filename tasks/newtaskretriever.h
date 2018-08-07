#ifndef NEWTASKRETRIEVER_H
#define NEWTASKRETRIEVER_H
#include <QObject>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

class NewTaskRetriever : public QObject
{
    Q_OBJECT

public:
    NewTaskRetriever();

    void getNewTasks();

public slots:
    void serverResponse(QNetworkReply *reply);

private:
    QNetworkRequest httpRequest;
    QNetworkAccessManager networkAccessManager;
};

#endif // NEWTASKRETRIEVER_H
