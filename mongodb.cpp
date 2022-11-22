#include "mongodb.h"

#include <QPainter>

MongoDB::MongoDB(QQuickItem *parent)
    : QObject(parent)
{
    _client = nullptr;
    _json_engine = new QJSEngine ;
    _connection_status = false;
}

MongoDB::~MongoDB()
{
    delete _json_engine;
    mongoc_client_destroy(_client);
    mongoc_cleanup();
}

void MongoDB::setUri(QString u)
{
    _uri = u;
    emit uriChanged();
}

QString MongoDB::uri()
{
    return _uri;
}

bool MongoDB::insertOne(QString dbStr, QString collectionStr,QJSValue document,QJSValue opts)
{
    if(!_connection_status)
        return false;
    bson_error_t error;
    bson_t *bson_document = nullptr;
    bson_t *bson_opts = nullptr;
    bool ret = false;

    mongoc_collection_t *collection = mongoc_client_get_collection(_client
                                                                   , dbStr.toStdString().c_str()
                                                                   , collectionStr.toStdString().c_str());

    if(!document.isNull() && !document.isError())
        bson_document = QJSValueToBson(document);

    if(!opts.isNull() && !opts.isError())
        bson_opts = QJSValueToBson(opts);

    ret = mongoc_collection_insert_one (
                collection, bson_document,bson_opts, NULL,&error);


    bson_destroy(bson_document);
    bson_destroy(bson_opts);
    mongoc_collection_destroy(collection);
    return ret;
}


bool MongoDB::updateOne(QString dbStr, QString collectionStr, QJSValue selector, QJSValue update, QJSValue opts)
{
    if(!_connection_status)
        return false;
    bson_error_t error;
    bson_t *bson_selector = nullptr;
    bson_t *bson_update = nullptr;
    bson_t *bson_opts = nullptr;
    bool ret = false;

    mongoc_collection_t *collection = mongoc_client_get_collection(_client
                                                                   , dbStr.toStdString().c_str()
                                                                   , collectionStr.toStdString().c_str());

    if(!selector.isNull() && !selector.isError()
            && !update.isNull() && !update.isError()) {
        bson_selector = QJSValueToBson(selector);
        bson_update = QJSValueToBson(update);
    }


    if(!opts.isNull() && !opts.isError())
        bson_opts = QJSValueToBson(opts);

    ret = mongoc_collection_update_one (
                collection, bson_selector,bson_update,bson_opts, NULL,&error);


    bson_destroy(bson_selector);
    bson_destroy(bson_update);
    bson_destroy(bson_opts);
    mongoc_collection_destroy(collection);
    return ret;
}

bool MongoDB::updateMany(QString dbStr, QString collectionStr, QJSValue selector, QJSValue update, QJSValue opts)
{
    if(!_connection_status)
        return false;
    bson_error_t error;
    bson_t *bson_selector = nullptr;
    bson_t *bson_update = nullptr;
    bson_t *bson_opts = nullptr;
    bool ret = false;
    mongoc_collection_t *collection = mongoc_client_get_collection(_client
                                                                   , dbStr.toStdString().c_str()
                                                                   , collectionStr.toStdString().c_str());

    if(!selector.isNull() && !selector.isError()
            && !update.isNull() && !update.isError()) {
        bson_selector = QJSValueToBson(selector);
        bson_update = QJSValueToBson(update);
    }

    if(!opts.isNull() && !opts.isError())
        bson_opts = QJSValueToBson(opts);

    ret = mongoc_collection_update_many (
                collection, bson_selector,bson_update,bson_opts, NULL,&error);

    bson_destroy(bson_selector);
    bson_destroy(bson_update);
    bson_destroy(bson_opts);
    mongoc_collection_destroy(collection);
    return ret;
}

bool MongoDB::deleteOne(QString dbStr, QString collectionStr, QJSValue selector, QJSValue opts)
{
    if(!_connection_status)
        return false;
    bson_error_t error;
    bson_t *bson_selector = nullptr;
    bson_t *bson_opts = nullptr;
    bool ret = false;
    mongoc_collection_t *collection = mongoc_client_get_collection(_client
                                                                   , dbStr.toStdString().c_str()
                                                                   , collectionStr.toStdString().c_str());

    if(!selector.isNull() && !selector.isError())
        bson_selector = QJSValueToBson(selector);

    if(!opts.isNull() && !opts.isError())
        bson_opts = QJSValueToBson(opts);

    ret = mongoc_collection_delete_one (
                collection, bson_selector,bson_opts, NULL,&error);

    bson_destroy(bson_selector);
    bson_destroy(bson_opts);
    mongoc_collection_destroy(collection);
    return ret;
}

bool MongoDB::deleteMany(QString dbStr, QString collectionStr, QJSValue selector, QJSValue opts)
{
    if(!_connection_status)
        return false;
    bson_error_t error;
    bson_t *bson_selector = nullptr;
    bson_t *bson_opts = nullptr;
    bool ret = false;
    mongoc_collection_t *collection = mongoc_client_get_collection(_client
                                                                   , dbStr.toStdString().c_str()
                                                                   , collectionStr.toStdString().c_str());

    if(!selector.isNull() && !selector.isError())
        bson_selector = QJSValueToBson(selector);

    if(!opts.isNull() && !opts.isError())
        bson_opts = QJSValueToBson(opts);

    ret = mongoc_collection_delete_many (
                collection, bson_selector,bson_opts, NULL,&error);

    bson_destroy(bson_selector);
    bson_destroy(bson_opts);
    mongoc_collection_destroy(collection);
    return ret;
}

bool MongoDB::replaceOne(QString dbStr, QString collectionStr, QJSValue selector, QJSValue replancement, QJSValue opts)
{
    if(!_connection_status)
        return false;
    bson_error_t error;
    bson_t *bson_selector = nullptr;
    bson_t *bson_replancement = nullptr;
    bson_t *bson_opts = nullptr;
    bool ret = false;
    mongoc_collection_t *collection = mongoc_client_get_collection(_client
                                                                   , dbStr.toStdString().c_str()
                                                                   , collectionStr.toStdString().c_str());

    if(!selector.isNull() && !selector.isError()
            && !replancement.isNull() && !replancement.isError()) {
        bson_selector = QJSValueToBson(selector);
        bson_replancement = QJSValueToBson(replancement);
    }

    if(!opts.isNull() && !opts.isError())
        bson_opts = QJSValueToBson(opts);

    ret = mongoc_collection_replace_one (
                collection, bson_selector,bson_replancement,bson_opts, NULL,&error);

    bson_destroy(bson_selector);
    bson_destroy(bson_replancement);
    bson_destroy(bson_opts);
    mongoc_collection_destroy(collection);
    return ret;
}


QVariant MongoDB::findOne(QString dbStr, QString collectionStr, QJSValue filter, QJSValue opts)
{
    if(!_connection_status)
        return false;
    bson_error_t error;
    bson_t *bson_filter = nullptr;
    bson_t *bson_opts = nullptr;
    const bson_t *doc = nullptr ;
    char *str;

    mongoc_collection_t *collection = mongoc_client_get_collection(_client
                                                                   , dbStr.toStdString().c_str()
                                                                   , collectionStr.toStdString().c_str());

    if(!filter.isNull() && !filter.isError())
        bson_filter = QJSValueToBson(filter);

    if(!opts.isNull() && !opts.isError())
        bson_opts = QJSValueToBson(opts);

    opts.setProperty("limit",1);

    mongoc_cursor_t *cursor = mongoc_collection_find_with_opts (
                collection, bson_filter,bson_opts, NULL);

    QJSValue myObject = _json_engine->newObject();

    while (mongoc_cursor_next (cursor, &doc)) {
        str = bson_as_json (doc, NULL);
        myObject =  QStringToQJSValue(QString(str));
        bson_free (str);
    }

    bson_destroy((bson_t *)doc);
    bson_destroy(bson_filter);
    bson_destroy(bson_opts);
    mongoc_collection_destroy(collection);
    return myObject.toVariant();
}

QVariant MongoDB::find(QString dbStr, QString collectionStr,  QJSValue filter,QJSValue opts)
{
    if(!_connection_status)
        return false;
    bson_error_t error;
    bson_t *bson_filter = nullptr;
    bson_t *bson_opts = nullptr;
    const bson_t *doc = nullptr ;
    char *str;
    int i = 0;

    mongoc_collection_t *collection = mongoc_client_get_collection(_client
                                                                   , dbStr.toStdString().c_str()
                                                                   , collectionStr.toStdString().c_str());

    if(!filter.isNull() && !filter.isError())
        bson_filter = QJSValueToBson(filter);

    if(!opts.isNull() && !opts.isError())
        bson_opts = QJSValueToBson(opts);

    mongoc_cursor_t *cursor = mongoc_collection_find_with_opts (
                collection, bson_filter,bson_opts, NULL);

    QJSValue myObject = _json_engine->newArray();

    while (mongoc_cursor_next (cursor, &doc)) {
        str = bson_as_json (doc, NULL);
        myObject.setProperty(i,QStringToQJSValue(QString(str)));
        bson_free (str);
        i++;
    }

    bson_destroy((bson_t *)doc);
    bson_destroy(bson_filter);
    bson_destroy(bson_opts);
    mongoc_collection_destroy(collection);
    return myObject.toVariant();
}

int MongoDB::count(QString dbStr, QString collectionStr, QJSValue filter, QJSValue opts)
{
    if(!_connection_status)
        return false;
    bson_error_t error;
    bson_t *bson_filter = nullptr;
    bson_t *bson_opts = nullptr;
    int i = 0;

    mongoc_collection_t *collection = mongoc_client_get_collection(_client
                                                                   , dbStr.toStdString().c_str()
                                                                   , collectionStr.toStdString().c_str());

    if(!filter.isNull() && !filter.isError())
        bson_filter = QJSValueToBson(filter);

    if(!opts.isNull() && !opts.isError())
        bson_opts = QJSValueToBson(opts);

    i = mongoc_collection_count_documents (collection,
                                       bson_filter,
                                       bson_opts,
                                       NULL,NULL,&error);

    bson_destroy(bson_filter);
    bson_destroy(bson_opts);
    mongoc_collection_destroy(collection);
    return i;
}

QVariant MongoDB::aggregate(QString dbStr, QString collectionStr, QJSValue pipeline, QJSValue opts)
{
    if(!_connection_status)
        return false;
    bson_error_t error;
    bson_t *bson_pipeline = nullptr;
    bson_t *bson_opts = nullptr;
    const bson_t *doc = nullptr ;
    char *str;
    int i = 0;

    mongoc_collection_t *collection = mongoc_client_get_collection(_client
                                                                   , dbStr.toStdString().c_str()
                                                                   , collectionStr.toStdString().c_str());
    if(!pipeline.isNull() && !pipeline.isError())
        bson_pipeline = QJSValueToBson(pipeline);

    if(!opts.isNull() && !opts.isError())
        bson_opts = QJSValueToBson(opts);

    mongoc_cursor_t *cursor =  mongoc_collection_aggregate (collection,
                                         MONGOC_QUERY_NONE,
                                         bson_pipeline,
                                         bson_opts,NULL);

    QJSValue myObject = _json_engine->newArray();
    while (mongoc_cursor_next (cursor, &doc)) {
        str = bson_as_json (doc, NULL);
        myObject.setProperty(i,QStringToQJSValue(QString(str)));
        bson_free (str);
        i++;
    }

    bson_destroy((bson_t *)doc);
    bson_destroy(bson_pipeline);
    bson_destroy(bson_opts);
    mongoc_collection_destroy(collection);
    return myObject.toVariant();
}


void MongoDB::connectDB()
{
    if(!_connection_status) {
        _client = mongoc_client_new(_uri.toStdString().c_str());
        if(!_client){
            _connection_status = false;
            emit mongoMessage("cannot connect to database");
        }
        else{
            _connection_status = true;
            emit connected();
            emit mongoMessage("database connection successed");
        }
    }
}

void MongoDB::disConnectDB()
{
    mongoc_client_destroy(_client);
    _connection_status = false;
    emit disConnected();
}

bson_t *MongoDB::QJSValueToBson(QJSValue jsv)
{
    bson_error_t error;
    QJsonObject obj = QJsonObject::fromVariantMap(jsv.toVariant().toMap());
    QJsonDocument doc(obj);
    QString str = doc.toJson(QJsonDocument::Compact);
    bson_t * bson = bson_new_from_json((const uint8_t *)str.toStdString().c_str()
                                   , str.size(), &error);
    return bson;
}

QJSValue MongoDB::QStringToQJSValue(QString str)
{
    QJSValue func = _json_engine->evaluate("JSON.parse");
    QJSValueList args;
    args.append(QString(str));
    return func.call(args);
}

