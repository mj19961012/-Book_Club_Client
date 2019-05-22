﻿#ifndef BCMESSAGEMANAHER_H
#define BCMESSAGEMANAHER_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QPixmap>
#include <QByteArray>
#include "BookClubEntity.hpp"
#include "BCCommonApiDef.hpp"
#include "BCCommonEnumData.h"


class BCMessageManager : public QObject
{
    Q_OBJECT
public :

    ~BCMessageManager();
    static BCMessageManager * getInstance();
public slots:
    void getPageVlaues(Page::BCPageEnum pageEnum);
private:

<<<<<<< HEAD
    QMap<QString, QMap<QString,QString>> mBCChildCityInfoMap;
=======
	QString BCHttpRequestHandle(QString requrl,QString parameter,QString contenttype = BC_CONTENTTYPE_HEADER);
	QByteArray BCImageToBase64(QString imgpath);
    QPixmap BCBase64ToImage(QByteArray data, bool issave);
	QString BCUpLoadSimpleFile(QString filepath);
	QString BCGetFileInfo(QString filemd5);
	QByteArray BCDownLoadSimpleFile(QString filemd5);
public:
    QMap<QString, QMap<QString, QString>> mBCChildCityInfoMap;
>>>>>>> bda03bf3c304fee0325c2f3451f1a7c606bf1442
    QMap<QString, QString> mBCParentCityInfoMap;
	QMap<QString, message_info> mBCMessageListMap;
	QMap<QString, article_info> mBCArticlesListMap;
	QMap<QString, action_info> mBCActivitiesListMap;
	QMap<QString, QMap<QString, message_info>> mBCCommentListMap;
	QMap<QString, file_base_info> mBCFileListMap;
	QMap<QString, interest_list> mBCInterestListMap;

    QString mCurrentCatchArticlesListAuthor;
    QList<article_info> mCurrentCatchArticlesList;

    QString mCurrentCatchActivitiesLisAuthor;
    QList<action_info> mCurrentCatchActivitiesList;

private:

    bool BCLoginHandle(QString username,QString password);
    bool BCRegistHandle(QString username, QString password, QString nickname, QString school, QString headimage, QString city);
    bool BCGetMessageListHandle();
    bool BCGetArticlesListHandle(int type, int pagenum = -1,int pagesize = 20);
    bool BCReleaseArticleHandle(QString title,QString content,int type);
    bool BCReleaseActionHandle(QString title,QString content,QString city,QString begintime,QString endtime,QString first,QString second,QString third);
    bool BCGetDetailsOfTheArticle(QString articleid);
    bool BCGetActivitiesListHandle(QString begintime, QString endtime, QString selectcity, int pagenum = -1, int pagesize = 20);
    bool BCGetDetailsOfTheAction(QString actionid);
    bool BCSendMessageHandle(QString messgae_body, QString sender_id, QString accepter_id, QString session_id, int message_type);
    bool BCSystemInit();
    bool BCGetSomebodyPostArticlesHandle(QString user_id, int pagenum = -1, int pagesize = 20);
    bool BCGetSomebodyPostActivitiesHandle(QString user_id, int pagenum = -1, int pagesize = 20);
    bool BCFollowSomeBodyHandle(QString user_id, QString follow_id);
    bool BCFollowCancleSomeBodyHandle(QString interest_id);
    bool BCGetInterestListWithSomeoneHandle(QString user_id);

    QString BCHttpRequestHandle(QString requrl,QString parameter,QString contenttype = BC_CONTENTTYPE_HEADER);
    QByteArray BCImageToBase64(QString imgpath);
    QPixmap BCBase64ToImage(QByteArray data, bool issave);
    QString BCUpLoadSimpleFile(QString filepath);
    QString BCGetFileInfo(QString filemd5);
    QByteArray BCDownLoadSimpleFile(QString filemd5);

private:
    explicit BCMessageManager(QObject *parent = nullptr);
    static BCMessageManager* mMessageManager;

    user_info current_user;
    int mMainActivitiesPageNum;
    int mMainArticlesPageNum;

    int mCatchActivitiesPageNum;
    int mCatchArticlesPageNum;
};

#endif // BCMESSAGEMANAHER_H
