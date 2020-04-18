1. wget 或者 git clone 下载第三方库
2. 在第三方库中创建 build 文件夹
3. 进入 build 后 cmake 上级目录
4. make 安装当前目录
5. 进入 include 
6. 安装
```shell
    wget url
    cd /path/to/your/repo/dir;mkdir build;cd build
    cmake ..
    make -jN
    cd include
    make install 
    [查看/usr/local/lib,是否有当前库相关的.{a,so},如果没有,执行如下语句]
        mv(或者cp) *.{a,so} /usr/local/lib
```
