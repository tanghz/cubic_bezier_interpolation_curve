#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <iostream>
#include <vector>
#include <cmath>
#include "bezier.h"
#include "bezier_adapter.h"
#include "visualization.h"

using namespace std;

int main(int argc, char **argv) 
{
    ros::init(argc, argv, "cubic_bezier_interpolation_curve_node");
    ros::NodeHandle nh;

    ros::Rate loop_rate(1);
    ros::Publisher bezier_curve_pub       = nh.advertise<visualization_msgs::Marker>("markers_bezier_curve", 1);
    ros::Publisher reference_line_pub     = nh.advertise<visualization_msgs::Marker>("reference_line", 1);
    ros::Publisher new_reference_line_pub = nh.advertise<visualization_msgs::Marker>("new_reference_line", 1);
    
    vector<Bezier::Point> originControlPoints;
    originControlPoints.push_back(Bezier::Point(0.0,0.0));
    originControlPoints.push_back(Bezier::Point(5.0,5.0));
    originControlPoints.push_back(Bezier::Point(10.0,5.0));
    originControlPoints.push_back(Bezier::Point(10.0,0.0));
    originControlPoints.push_back(Bezier::Point(15.0,-5.0));

    double time_begin =ros::Time::now().toSec();
    BezierAdapter bezierAdapter(originControlPoints);
    vector<Bezier::Point> bezierPoints = bezierAdapter.getBezierPoints();
    double time_end =ros::Time::now().toSec();//thz

    //do it
    //just to test
    //thz1

    while (ros::ok())
    {
        ROS_INFO("  ros: cost time: %.3f ms\n",(time_end-time_begin)*1000.0);
        
        Visualization visualization;
        visualization.publishLines ( reference_line_pub,
                       visualization_msgs::Marker::LINE_STRIP,
                       make_tuple(0.1,0.1,0,0,1,1), 
                       originControlPoints);
        visualization.publishLines ( new_reference_line_pub,
                       visualization_msgs::Marker::LINE_STRIP,
                       make_tuple(0.1,0.1,0,1,0,1), 
                       bezierAdapter.getNewControlPoints());
        visualization.publishPoints( bezier_curve_pub, 
                       visualization_msgs::Marker::POINTS, 
                       make_tuple(0.1,0.1,1,0,0,1), 
                       bezierPoints);

        loop_rate.sleep();
    }

}
