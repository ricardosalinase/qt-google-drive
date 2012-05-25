#ifndef OPERATIONSMANAGER_H
#define OPERATIONSMANAGER_H

#include "networkmanager.h"
#include "Def.h"

class OperationsManager : public NetworkManager
{
     Q_OBJECT
public:
    OperationsManager(QObject *parent = 0);

public:
    void del(const QString& url);

public slots:
    virtual void slotReplyFinished(QNetworkReply* reply);

signals:
    void signalDelFinished(void);

private:
    QString getFileQuery(const QString& url);

};

#endif // OPERATIONSMANAGER_H