# ROS-network
ROS Network

Jetson Nano를 Master로 설정하고, Jetson AGX Xavier가 Master에 연결되도록 하여,
ROS Sever-Client 통신 진행<br/>

## 목차
* [기본 설정 - ROS 설치](#ROS-설치-방법)
* [기본 설정 - ROS Workspace 설정](#ROS-Workspace-설정)
* [코드 설명](#코드-설명)
* [실행 방법](#실행-방법)

## ROS 설치 방법
Ubuntu기반으로 되어 있는 Jetson Nano 및 Jetson Xavier에 ROS를 설치하는 방법

ROS 설치는 공식 홈페이지에 있는 내용을 기반으로 진행
  ```
  $ sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
  $ sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
  $ sudo apt update
  $ sudo apt install ros-melodic-desktop-full
  $ sudo apt-get install python-pip
  $ sudo pip install -U rosdep
  $ sudo rosdep init
  $ rosdep update
  $ echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
  source ~/.bashrc
  $ source /opt/ros/melodic/setup.bash
  $ sudo apt install python-rosinstall python-rosinstall-generator python-wstool build-essential
  ```
  위의 명령어를 Terminal에 차례대로 작성한다.

위의 과정을 진행했다면, 새로운 Terminal을 열고,
```
$ roscore
```
명령어를 실행해 정상적으로 동작한다면 ROS가 정상적으로 설치되었음을 확인 가능
## ROS Workspace 설정
ROS의 Workspace인 catkin을 설치 및 설정하는 방법
```
$ source /opt/ros/melodic/setup.bash
```

catkin 작업공간 만들기
```
$ mkdir ~p ~/catkin_ws/src
$ cd ~/catkin_ws/src
$ catkin_init_workspace
```

작업공간 빌드해주기
```
$ cd ~/catkin_ws/
$ catkin_make
```
위 과정을 통해 'build'와 'devel'폴더가 생성된 것을 확인할 수 있다.

새로운 setup.sh 파일 쉘에 적용하기
```
$ source devel/setup.bash
```


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
