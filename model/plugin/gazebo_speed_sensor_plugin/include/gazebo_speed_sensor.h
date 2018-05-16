#ifndef GAZEBO_SPEED_SENSOR_H
#define GAZEBO_SPEED_SENSOR_H

#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>

namespace gazebo
{
    class GazeboSpeedSensor: public ModelPlugin
    {
        public:
            GazeboSpeedSensor();
            void Load(physics::ModelPtr, sdf::ElementPtr);
            void OnUpdate();
            ~GazeboSpeedSensor();

        private:
            physics::ModelPtr model;
            event::ConnectionPtr updateConnection;
            physics::JointPtr right_joint;
            physics::JointPtr left_joint;
            int sleep_iterations;
            int ticks;
    };
}

#endif