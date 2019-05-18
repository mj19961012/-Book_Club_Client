﻿#ifndef BCLISTWIDGET_H
#define BCLISTWIDGET_H

#include <QListWidget>
#include <QMap>
#include <QScrollBar>
#include <QEvent>
#include <QMouseEvent>
#include <QResizeEvent>
#include "BCCommonEnumData.h"

class BCListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit BCListWidget(QWidget *parent = nullptr);
    void addListItem(ListItem::BCListWidgetType type);

signals:
    void sigItemClicked();

protected:
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    void clearData();
    void addPostingItem(const QString& id, const QString& name, const QString& content);
    void addActivityItem(const QString &id);
    void addMinePostingItem(const QString &id);
    void addMineAvtivityItem(const QString &id);
    void addMineInterestItem(const QString &id);

private:
    QMap<QString,QListWidgetItem*> mListMap{};
    QSet<QString> mListSet{};
    QListWidgetItem *mCurrentItem{};
    ListItem::BCListWidgetType mCurrentItemType{};
};

#endif // BCLISTWIDGET_H
