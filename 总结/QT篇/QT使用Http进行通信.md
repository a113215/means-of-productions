## QT使用Http进行通信

#### 依赖QT中的internet模块

> Qt += network

#### http中的请求类型分类：

> 1. 多个独立参数get请求
> 2. 参数数组Get请求
> 3. 上传参数数据POST请求
> 4. 上传参数和文件POST请求
> 5. 下载文件GET请求

#### 认识QNetworkAccessManager

>该对象包含代理和缓存配置，以及与此类问题相关的信号，以及可用于监控网络操作进度的回复信号。此类对象提供一组标准函数，来接收请求和可选数据，每个函数返回一个QNetworkReply对象，该对象用于获取响应相应请求而返回的任何数据。
>
>//构建一个manager对象
>QNetworkAccessManager *manager = new QNetworkAccessManager(this); 
>
>//manager具有异步API，当http请求完成后，会通过finished信号进行通知
>connect(manager,&QNetworkAccessManager::finished,this,&MyClass::replyFinished); 
>
>//发送异步get请求
>manager->get(QNetworkRequest(QUrl("http://qt-project.org")));
>
>//这里也可以用一个QEventLoop来等待请求完成，但是我更爱用槽函数
>//QNetworkReply *reply=manager->get(request);
>//QEventLoop eventLoop;
>//connect(reply, &QNetworkReply ::finished, &eventLoop, &QEventLoop::quit);
>//eventLoop.exec();
>//QByteArray reply_data=reply->readAll();

```
void MyClass::replyFinished(QNetworkReply *reply)
{
    if(reply->error()!=QNetworkReply::NoError){
        //处理中的错误信息
        qDebug()<<"reply error:"<<reply->errorString();
    }else{
        //请求方式
        qDebug()<<"operation:"<<reply->operation();
        //状态码
        qDebug()<<"status code:"<<reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug()<<"url:"<<reply->url();
        //qDebug()<<"raw header:"<<reply->rawHeaderList();
 
        //获取响应信息
        const QByteArray reply_data=reply->readAll();
        qDebug()<<"read all:"<<reply_data;
 
        //解析json
        QJsonParseError json_error;
        QJsonDocument document=QJsonDocument::fromJson(reply_data, &json_error);
        if(json_error.error==QJsonParseError::NoError){
            if(document.isObject()){
                const QJsonObject obj=document.object();
                qDebug()<<obj;
                if(obj.contains("args")){
                    QJsonValue value=obj.value("args");
                    qDebug()<<value;
                    //QJsonValue(object, QJsonObject({"ie":"utf-8"}))
                }
            }
        }else{
            qDebug()<<"json error:"<<json_error.errorString();
        }
    }
    reply->deleteLater();
}
```



#### 服务请求QNetworkRequest

> //构建请求对象
> QNetworkRequest request;
> request.setUrl(QUrl("http://httpbin.org/get"));
> request.setRawHeader("Content-Type","application/json");
>
> //发送请求
> //manager->get(request);
> //manager->post(request, QByteArray());
> //manager->put(request, QByteArray());

IDispatch