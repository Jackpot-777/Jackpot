// Copyright (c) 2017 The PIVX developers
// Copyright (c) 2017-2018 The Jackpot developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZJACKPOTCONTROLDIALOG_H
#define ZJACKPOTCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "primitives/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZJackpotControlDialog;
}

class ZJackpotControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZJackpotControlDialog(QWidget *parent);
    ~ZJackpotControlDialog();

    void setModel(WalletModel* model);

    static std::list<std::string> listSelectedMints;
    static std::list<CZerocoinMint> listMints;
    static std::vector<CZerocoinMint> GetSelectedMints();

private:
    Ui::ZJackpotControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZJACKPOTCONTROLDIALOG_H
