#include "operationsmanager.h"
#include "commontools.h"
#include <QDebug>
#include <QStringList>

OperationsManager::OperationsManager(QObject *parent):
     NetworkManager(parent)
{
}

void OperationsManager::del(const QString& url)
{
    qDebug() << "OperationsManager::del" << getFileQuery(url);
    CommonTools::setHeader(request);
    request.setRawHeader("If-Match", "*");
    delRes(getFileQuery(url));
}

QString OperationsManager::getFileQuery(const QString& url)
{
    QString query(DELETE_FILE);
    QStringList queryStrs(url.split("/"));
    QString lastParam(queryStrs[queryStrs.count()  - 1]);

    queryStrs = lastParam.split("%3A");
    query += queryStrs[queryStrs.count()  - 1];

    return query;
}

void OperationsManager::slotReplyFinished(QNetworkReply* reply)
{
  qDebug() << "OperationsManager::slotReplyFinished";
  emit signalDelFinished();
}
