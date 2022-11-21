# Qt6QuickMongoDB
this is a c++/qml plugin for Qt6
tested on linux ubuntu
installation :
open as normal project from qtcreator
and us build all to install it

after installation you can use it from any qml resource file 
usage:

import QtQuick.MongoDB

    MongoDB{
        id:mongo
        uri: "mongodb://localhost:27017/"
        onMongoMessage:(msg)=>{
                           console.log(msg)
                       }
    }


// can used from any js code inside the qml js blocks
Component.onCompleted: {
  mongo.connectDB()
  var obj= {
    "name" : "user",
    "age" : 30
    }
    
  mongo.insertOne("database","users",obj,{})
  // where :
  // database -> is database name
  // users    -> is collection name
  // obj      -> object nedded to insert
  // {}       -> options
  
}

#all functions
-----------------------------------------------------------------------           
   Function name :
            connectDB();
   usages:
          to connect database 
   return values:
           no return value
           
-----------------------------------------------------------------------           
   Function name :
            disConnectDB();
   usages:
          to connect database 
   return values:
           no return value
-----------------------------------------------------------------------           
   Function name :
            insertOne(database name  ,collection name  ,document  ,opts);
   usages:
          database name : string 
          collection name : string
          document : json object
          opts : json object
   return values:
           return bool value
           true  for success 
           false for error
-----------------------------------------------------------------------           

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
