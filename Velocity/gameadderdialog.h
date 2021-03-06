#ifndef GAMEADDERDIALOG_H
#define GAMEADDERDIALOG_H

// qt
#include <QDialog>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTreeWidgetItem>
#include <QDateTime>
#include <QMenu>
#include <QMessageBox>
#include <QStringList>
#include <QMutex>

// other
#include "json.h"
#include "qthelpers.h"
#include "GPD/DashboardGPD.h"
#include "gpddownloader.h"
#include "Stfs/StfsPackage.h"

namespace Ui {
class GameAdderDialog;
}

class GameAdderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameAdderDialog(StfsPackage *package, QWidget *parent = 0, bool dispose = true);
    ~GameAdderDialog();

private slots:
    void on_treeWidgetAllGames_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
    void gameReplyFinished(QNetworkReply*);
    void showRemoveContextMenu_QueuedGames(QPoint point);
    void showRemoveContextMenu_AllGames(QPoint point);
    void finishedDownloadingGPD(QString gamePath, QString awardPath, TitleEntry entry, bool error);
    void thumbnailReplyFinished(QNetworkReply *aReply);
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_btnShowAll_clicked();
    void on_txtSearch_textChanged(const QString &arg1);
    void on_btnShowAll_2_clicked(bool checked);

private:
    Ui::GameAdderDialog *ui;
    QString mainDir;
    QNetworkAccessManager *manager;
    DashboardGPD *dashGPD;
    QString dashGPDTempPath, pecTempPath;
    QStringList notSuccessful;
    StfsPackage *package, *pecPackage;

    bool allowInjection, existed, dispose;
    int totalDownloadCount, downloadedCount;

    void showAllItems();
};

#endif // GAMEADDERDIALOG_H
