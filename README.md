# Robotics Project

Project of the course of __Robotics__ held by Professor __Matteo Matteucci__ at __Politecnico di Milano__, academic year 2017-18

## Goal

The goal of the project is to develop a simple autonomous mobile robot which performs a simple task. 
The first part of the project consists in building the robot whilst the second consists in programming it.

### Building the robot

The robot is a differential drive robot that you can see in the pictur below. I called it __No Name__, because when i asked the name of the robot, nobody replied me. Thus, i assumed it has no name!

![Robot](/images/robot.png)

We are just provided with the Inventor model, which is useful in order to measure distances, masses, inertias, etc. We are also required to develop an encoder plugin, in order to measure the speed of the wheels, and to add the differential drive plugin to the model of the robot, in order to control it via keyboard.

### Robot task

Yet to come!

### Prerequisites

This robot doesn't require a particular version of ROS or a particular Linux distro. However, for simplicity, this installation steps will refer to an Ubuntu distro and to the kinetic version of ROS.

* Gazebo: http://gazebosim.org/tutorials?tut=install_ubuntu
* ROS: http://wiki.ros.org/kinetic/Installation
* Basic configuration of ROS and catkin.
* Turtlebot 3 teleop. You can install it with the command:

<pre>
$ sudo apt-get install ros-kinetic-turtlebot3-teleop
</pre>

### Installation instructions

* Copy the __noname__ directory (model/noname) inside the __models__ directory of your gazebo workspace.
* Change the {PATH_TO_MODELS} variables inside the chassis link with the absolute path of your __models__ directory. (example: in my case is &lt;uri&gt;file:///home/lorenzo/.gazebo/models/noname/meshes/chassis.stl&lt;/uri&gt;)

<pre>
&lt;collision name="collision"&gt;
    &lt;geometry&gt;
        &lt;mesh&gt;
            &lt;uri&gt;file://{PATH_TO_MODELS}/models/noname/meshes/chassis.stl&lt;/uri&gt;
        &lt;/mesh&gt;
    &lt;/geometry&gt;
&lt;/collision&gt;
&lt;visual name="visual"&gt;
    &lt;geometry&gt;
        &lt;mesh&gt;
            &lt;uri&gt;file://{PATH_TO_MODELS}/models/noname/meshes/chassis.stl&lt;/uri&gt;
        &lt;/mesh&gt;
    &lt;/geometry&gt;
&lt;/visual&gt;
</pre>

* Install the encoder plugin following one of these two ways:
  * Copy the __libgazebo_speed_sensor_plugin.so__ file (model/plugin/bin) inside the /opt/ros/&lt;ros_version&gt;/lib/ directory.
  * Copy the __gazebo_speed_sensor_plugin__ directory (model/plugin) inside the __src__ directory of your catkin workspace and compile it with the command:

<pre>
$ catkin_make
</pre>

### Move the robot

In order to use the differential drive plugin you need to start gazebo as a ros node.

* Open a terminal and start Turtlebot 3 telop:

<pre>
$ roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
</pre>

* Open another terminal and start Gazebo server:

<pre>
$ rosrun gazebo_ros gzserver
</pre>

* Start Gazebo client on the last terminal:

<pre>
$ rosrun gazebo_ros gzclient
</pre>

* Place the robot in the world and move it!
* You can see the speed of its wheels on the terminal in which you launched Gazebo server.

![Robot](/images/no_name.png)