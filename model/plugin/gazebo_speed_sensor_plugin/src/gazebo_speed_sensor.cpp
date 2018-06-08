#include <string>
#include <boost/bind.hpp>
#include "../include/gazebo_speed_sensor.h"

namespace gazebo
{
    //Register this plugin with the simulator
    GZ_REGISTER_MODEL_PLUGIN(GazeboSpeedSensor)

    ///////////////////////////////////////////////////////
    //////////////////// Constructor //////////////////////
    ///////////////////////////////////////////////////////
    GazeboSpeedSensor::GazeboSpeedSensor()
    {
        // 20 Heartz = 50 ms
        this->sleep_iterations = 50;
        this->ticks = 0;
    }

    ///////////////////////////////////////////////////////
    //////////////////// Destructor ///////////////////////
    ///////////////////////////////////////////////////////

    GazeboSpeedSensor::~GazeboSpeedSensor()
    {

    }

    // Inherited method
    void GazeboSpeedSensor::Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf)
    {
        this->model = _parent;
        this->left_joint = this->model->GetJoint("left_back_wheel_hinge");
        this->right_joint = this->model->GetJoint("right_back_wheel_hinge");
        this->updateConnection = event::Events::ConnectWorldUpdateBegin(boost::bind(&GazeboSpeedSensor::OnUpdate, this));
    }

    // On update method. By default, this method is called every 1ms.
    void GazeboSpeedSensor::OnUpdate()
    {
        if(this->ticks == 0)
        {
            printf("\nLeft wheel: %f rad/s\nRight wheel: %f rad/s\n", (this->left_joint->GetVelocity(0)), (this->right_joint->GetVelocity(0)));
        }
        this->ticks++;
        this->ticks = this->ticks % this->sleep_iterations;
    }
}
