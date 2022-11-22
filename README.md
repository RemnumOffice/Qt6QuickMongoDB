  <h2> Qt6QuickMongoDB </h2>



<!-- ABOUT THE PROJECT -->
## About 
##### This is a C++-Qml Plugin Create for Qt6 Tested On Linux Ubuntu 
### Built With
##  
* [Qt6](https://www.qt.io/product/qt6)
* [MongoDB C Driver](https://www.mongodb.com/docs/drivers/c/)
* [Cmake](https://cmake.org/)



## Installation


##### 1. Clone the repo
```
git clone https://github.com/RemnumOffice/Qt6QuickMongoDB.git  
```

##### 2. build
```
Open As Normal Project From Qtcreator And Use Build All To Install It

```



## Getting Started
##### 1 . Import Qt6QuickMongoDB 

```
import QtQuick.MongoDB
 ```

##### 2 . Mongodb Connection Function 
```
    MongoDB{
        id:mongo
        uri: "mongodb://localhost:27017/"
        onMongoMessage:(msg)=>{
                           console.log(msg)
                       }
    }

```


##### 3 . Component 
```
Component.onCompleted: {
  mongo.connectDB()
  var obj= {
    "name" : "user",
    "age" : 30
    }
```




#####  4 . Insert One 
```
  mongo.insertOne("database","users",obj,{})
  // where :
  // database -> is database name
  // users    -> is collection name
  // obj      -> object nedded to insert
  // {}       -> options
  
}
```
## All Functions




























<!-- Installation : Open As Normal Project From Qtcreator and use build all to install it
 -->

<!-- this is a c++/qml plugin for Qt6
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
          to disconnect database 
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
           true  for success 
           false for error
-----------------------------------------------------------------------           

    bool updateOne( dbStr, collectionStr,  selector,  update, opts);
    
       Function name :
            updateOne(database name  ,collection name  ,selector,  update, opts)
   usages:
          database name : string 
          collection name : string
          document : json object
          
          opts : json object
   return values:
           true  for success 
           false for error
-----------------------------------------------------------------------   
    
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
 -->
