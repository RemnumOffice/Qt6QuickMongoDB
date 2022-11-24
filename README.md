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

##### 2 . Mongodb Qml Object 
```
    MongoDB{
        id:mongo
        uri: "mongodb://localhost:27017/"
        onMongoMessage:(msg)=>{
                           console.log(msg)
                       }
    }

```


## All Functions


##### 1 .  Function name : connectDB

```
   connectDB()
   
   usage :
          to connect database.
          
   parameters : 
          no parameters.
          
   return :
           no return value.
```

##### 2 .  Function name : disConnectDB
 
```
   disConnectDB()
   
   usage :
          to disconnect database.
   
   parameters : 
          no parameters.
   
   return :
          no return value.
```


##### 3 .  Function name : insertOne
 
```
   insertOne(database name  ,collection name  ,document  ,opts);
   
   usage :
        to insert one document into [ database name/collection name ].
        
   parameters : 
          database name : string .
          collection name : string .
          document : json object .
          opts : json object .
          
   return :
          true  for success.
          false for error.
```

##### 4 .  Function name : updateOne
 
```
   updateOne(database name  ,collection name  ,selector,  update, opts)
    
   usage :
        to update one document from [ database name/collection name ].
        
   parameters : 
          database name : string .
          collection name : string .
          selector : json object .
          update : json object .
          opts : json object .
          
   return  :
           true  for success.
           false for error.
```

##### 5 .  Function name : updateMany

```
   updateMany(database name  ,collection name  ,selector,  update, opts)
   
   usage :
        to update many documents from [ database name/collection name ].
        
   parameters : 
          database name : string .
          collection name : string .
          selector : json object .
          update : json object .
          opts : json object .
          
   return :
           true  for success.
           false for error.
```

##### 6 .  Function name : deleteOne 

```
   deleteOne(database name  ,collection name  ,selector, opts)
    
   usage :
        to delete one document from [ database name/collection name ].
        
   parameters : 
          database name : string .
          collection name : string .
          selector : json object .
          opts : json object .
          
   return :
           true  for success.
           false for error.
```

##### 7 .  Function name : deleteMany

```
   deleteMany(database name  ,collection name  ,selector, opts)
    
   usage :
        to delete many documents from [ database name/collection name ].
        
   parameters :
          database name : string .
          collection name : string .
          selector : json object .
          opts : json object .
          
   return :
           true  for success.
           false for error.
```

##### 8 .  Function name : replaceOne
 
```
   replaceOne(database name  ,collection name  ,selector, update , opts)
    
   usage :
        to replace one document from [ database name/collection name ].
        
   parameters : 
          database name : string .
          collection name : string .
          selector : json object .
          update : json object .
          opts : json object .
          
   return :
           true  for success.
           false for error.
```

##### 9 .  Function name : findOne
 
```
    findOne(database name  ,collection name  ,selector, update , opts)
    
   usage :
        to find one document from [ database name/collection name ].
        
   parameters :
          database name : string 
          collection name : string
          selector : json object
          opts : json object
          
   return :
           true  for success 
           false for error
```
##### 10 .  Function name : find
 
```   
   find(database name  ,collection name  ,filter , opts)
    
   usage :
          database name : string 
          collection name : string
          filter : json object
          opts : json object
          
   return :
           true  for success 
           false for error
```

##### 11 .  Function name : count
 
```
   count(database name  ,collection name  ,filter , opts)
    
   usage :
          database name : string 
          collection name : string
          filter : json object
          opts : json object
          
   return :
           true  for success 
           false for error
```

##### 12 .  Function name : aggregate
 
```
   aggregate(database name  ,collection name  ,pipeline , opts)
    
   usage :
          database name : string 
          collection name : string
          pipeline : json object
          opts : json object
          
   return :
           true  for success 
           false for error
```




<!--
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

-->
