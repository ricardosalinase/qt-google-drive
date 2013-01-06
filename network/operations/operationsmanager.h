#ifndef OPERATIONSMANAGER_H
#define OPERATIONSMANAGER_H

#include "network/networkmanager.h"
#include "gui/items.h"
#include "settings/accountinfo.h"
#include "share/singleton.h"
#include "share/defs.h"
#include "network/queries.h"
#include "gui/forms/createfolderdialog.h"
#include "network/operations/copy.h"
#include "network/operations/delete.h"
#include "network/operations/move.h"
#include "network/operations/create.h"
#include "network/operations/rename.h"
#include "network/operations/share.h"

class OperationsManager : public NetworkManager
{
    Q_OBJECT
public:
    OperationsManager(QObject *parent = 0);

public slots:
    void slotDelete(void);
    void slotNewFolder(void);
    void slotCopyWebFile(void);
    void slotMoveWebFile(void);
    void slotRenameWebFile(void);
    void slotItemEditDone(void);
    void slotShareWebFile(void);
    void slotAcceptCreateFolder(const QString &name);
    void slotRejectCreateFolder(void);
    void slotFinishedCreateFolder(int result);

public:
    void setAccountInfo(const QString &accessToken, const QString &refreshToken = QString());
    bool operationPossible(void);
    void updatePanelContent(bool opposite);

signals:
    void signalAccountInfoReadyToUse(void);

private slots:  
    void slotAccountInfoReceived(AccountInfo::Data &postData);

private:
    Items::Data fileUrlToDeleteForMoveOperation;
    AccountInfo *accountInfo;
    Queries queries;
    CreateFolderDialog* createFolderDialog;
    QString editingItemText;
    Copy copy;
    Delete del;
    Move move;
    Create create;
    Rename rename;
    Share share;
};

typedef TSingleton<OperationsManager> SOperationsManager;

#endif // OPERATIONSMANAGER_H
