# ROS-network
ROS Network

Jetson Nano를 Master로 설정하고, Jetson AGX Xavier가 Master에 연결되도록 하여,
ROS Sever-Client 통신 진행
     
## 코드 설명
#### ros_tutorial_srv_server.cpp
* ROS Master(Jetson Nano)에서 구동하는 server 코드
* client에서 받아온 두 수를 더해서 결과값을 client에게 전송
  
#### ros_tutorial_srv_client.cpp
* Jetson Xavier에서 구동하는 client 코드
* 두 개의 수를 보내서 server에서 결과값을 받아오면 결과값을 출력
