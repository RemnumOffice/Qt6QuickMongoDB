#ifndef MONGODB_H
#define MONGODB_H

#include <QtQuick/QQuickPaintedItem>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJSEngine>

#include <mongoc/mongoc.h>
#include <bson/bson.h>

class MongoDB : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString uri READ uri WRITE setUri NOTIFY uriChanged REQUIRED)
    QML_NAMED_ELEMENT(MongoDB)

public:
    explicit MongoDB(QQuickItem *parent = nullptr);
    ~MongoDB() override;

signals:
    void uriChanged();
    void connected();
    void disConnected();
    void mongoMessage(QString);

public slots:
    void setUri(QString);
    QString uri();

    bool insertOne(QString dbStr,QString collectionStr,QJSValue document,QJSValue opts);

    bool updateOne(QString dbStr,QString collectionStr, QJSValue selector, QJSValue update,QJSValue opts);
    bool updateMany(QString dbStr,QString collectionStr, QJSValue selector, QJSValue update,QJSValue opts);

    bool deleteOne(QString dbStr,QString collectionStr, QJSValue selector, QJSValue opts);
    bool deleteMany(QString dbStr,QString collectionStr, QJSValue selector, QJSValue opts);



    bool replaceOne(QString dbStr,QString collectionStr, QJSValue selector, QJSValue update,QJSValue opts);


    QVariant findOne(QString dbStr,QString collectionStr, QJSValue filter,QJSValue opts);
    QVariant find(QString dbStr,QString collectionStr, QJSValue filter,QJSValue opts);
    int count(QString dbStr,QString collectionStr, QJSValue filter,QJSValue opts);

    QVariant aggregate(QString dbStr,QString collectionStr, QJSValue pipeline,QJSValue opts);


    void connectDB();
    void disConnectDB();


private :
    bson_t *QJSValueToBson(QJSValue);
    QJSValue QStringToQJSValue(QString);


private:
    QString _uri;
    bool _connection_status;


private:
    mongoc_client_t *_client;
    QJSEngine *_json_engine;

};

#endif // MONGODB_H
