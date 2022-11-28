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
   usage :
          connectDB()
   
   description :
          to connect database.
          
   parameters : 
          no parameters.
          
   return :
           no return value.
```

##### 2 .  Function name : disConnectDB
 
```
   usage :
     disConnectDB()
   
   description :
          to disconnect database.
   
   parameters : 
          no parameters.
   
   return :
          no return value.
```


##### 3 .  Function name : insertOne
 
```
   usage :
   insertOne(database name  ,collection name  ,document  ,opts);
   
   description :
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
   usage :
   updateOne(database name  ,collection name  ,selector,  update, opts)
    
   description :
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
   usage :
   updateMany(database name  ,collection name  ,selector,  update, opts)

   
   description :
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
   usage :
   deleteOne(database name  ,collection name  ,selector, opts)
    
   description :
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
   usage :
   deleteMany(database name  ,collection name  ,selector, opts)
    
   description :
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
    usage :
  replaceOne(database name  ,collection name  ,selector, update , opts)
    
   description :
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
   usage :
    findOne(database name  ,collection name  ,filter , opts)

    
   description :
        to find one document from [ database name/collection name ].
        
   parameters :
          database name : string 
          collection name : string
          filter : json object
          opts : json object
          
   return :
           resutl of find in json object data
           false for error
```
##### 10 .  Function name : find
 
```   
   usage :
   find(database name  ,collection name  ,filter , opts)
    
   description : to find all documents from [ database name/collection name ].

   
   parameters:
          database name : string 
          collection name : string
          filter : json object
          opts : json object
          
   return :
           resutl of find in json object data
           false for error
```

##### 11 .  Function name : count
 
```
   usage :
   count(database name  ,collection name  ,filter , opts)

    
   description : count  all documents numbers from [ database name/collection name ].
   
   parameters:
          database name : string 
          collection name : string
          filter : json object
          opts : json object
          
   return :
           resutl of count in int data
           false for error
```

##### 12 .  Function name : aggregate
 
```
   usage :
   aggregate(database name  ,collection name  ,pipeline , opts)

    
   description : 
   parameters:
          database name : string 
          collection name : string
          pipeline : json object
          opts : json object
          
   return :
           true  for success 
           false for error
```
##### See More About Aggregate [here]([myLib/README.md](https://github.com/RemnumOffice/Qt6QuickMongoDB/edit/main/README.md))


## Contact

* #### Ahmed El Banna  - ahbanna@gmail.com

* #### Linkedin : (https://www.linkedin.com/in/ahmed-el-banna-3a30324b)


* #### Abdalla yahya - abdallayahya158@gmail.com

* #### Linkedin : (https://www.linkedin.com/in/abdalla-yahya-560a861b7/)


* #### Project Link: (https://github.com/RemnumOffice/Qt6QuickMongoDB)


