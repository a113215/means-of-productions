### GIT相关用法

#### 上传超100M文件

```csharp
$ cd 项目工程文件夹
$ git lfs install
$ git lfs track "*.psd"//这里表示添加后缀为 psd 的文件,按照自己的项目替换相应的文件
$ git add .gitattributes
//好了,上面三条命令已为我们成功添加了大文件 lfs仓库; 下面是正常的git提交操作
$ git add .
$ git commit -m "添加.gitattributes文件"
$ git push origin master
```

#### git完整克隆包括子模块

```
1.克隆的时候可以带上参数--recursive，这样会迭代克隆子模块
 git clone --recursive [https://xxxxxxxx.git](https://links.jianshu.com/go?to=https%3A%2F%2Fxxxxxxxx.git)

2.如果已经克隆完的项目，忘记加参数--recursive，也可以在克隆完后手动运行下面命令
 git submodule update --init --recursive
```

#### git删除某个文件

```
1.先更新本地至最新git pull。
2.git rm 文件名
3.git commit -m "说明" //提交到本地仓库
4.git push //将操作推送到远程仓库
```

