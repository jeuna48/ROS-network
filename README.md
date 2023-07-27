# ROS-network
ROS Network

Jetson Nano를 Master로 설정하고, Jetson AGX Xavier가 Master에 연결되도록 하여,
ROS Sever-Client 통신 진행<br/>

## 목차
* [코드 설명](#코드-설명)
* [실헹 방법](#실행-방법)
## 코드 설명
#### ros_tutorial_srv_server.cpp
* ROS Master(Jetson Nano)에서 구동하는 server 코드
* client에서 받아온 두 수를 더해서 결과값을 client에게 전송<br/>
  
#### ros_tutorial_srv_client.cpp
* Jetson Xavier에서 구동하는 client 코드
* 두 개의 수를 보내서 server에서 결과값을 받아오면 결과값을 출력<br/>

## 실행 방법
#### Terminal 1 (in Jetson Nano)
```
$ roscore
```
명령어를 통해 ROS Master 구동<br/>

#### Terminal 2 (in Jetson Nano)
```
$ rosrun ros_test ros_tutorial_srv_server.cpp
```
명령어를 통해 client에서 보낼 데이터를 기다리기<br/>

#### Terminal 3 (in Jetson AGX Xavier)
```
$ rosrun ros_test ros_tutorial_srv_client.cpp
```
명령어를 통해 server에 두 개의 숫자를 전송한 후 결과값을 받아 출력<br/>
