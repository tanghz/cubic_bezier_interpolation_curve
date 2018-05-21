#pragma once

#include <vector>
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "bezier.h"

class Visualization
{
public:
	Visualization();
	~Visualization(){};
	
	void publishPoints(const ros::Publisher& pub, int showType, std::tuple<double,double,double,double,double,double> feature, 
                   const std::vector<Bezier::Point>& points);
	void publishLines(const ros::Publisher& pub, int showType, std::tuple<double,double,double,double,double,double> feature, 
                   const std::vector<Bezier::Point>& points);
private:
	void markerInit(visualization_msgs::Marker& marker);
	
};