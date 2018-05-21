#include "visualization.h"

Visualization::Visualization()
{
  //TODO
}

void Visualization::markerInit(visualization_msgs::Marker& marker)
{
  marker.header.frame_id = "/base_link";
  marker.header.stamp =  ros::Time::now();
  marker.ns = "points_and_lines";
  marker.action = visualization_msgs::Marker::ADD;
  marker.pose.orientation.w =  1.0;
  marker.id = 1;
}

void Visualization::publishPoints(const ros::Publisher& pub, int showType, std::tuple<double,double,double,double,double,double> feature, 
                   const std::vector<Bezier::Point>& points)
{
    visualization_msgs::Marker marker;
    markerInit(marker);

    marker.type = showType;

    marker.scale.x = std::get<0>(feature);
    marker.scale.y = std::get<1>(feature);

    marker.color.r = std::get<2>(feature);
    marker.color.g = std::get<3>(feature);
    marker.color.b = std::get<4>(feature);
    marker.color.a = std::get<5>(feature);

    for(int i=0; i<points.size(); ++i)
    {
        geometry_msgs::Point p;
        p.x = points[i].x;
        p.y = points[i].y;
        p.z = 0.0;
        marker.points.push_back(p);
    }
    pub.publish(marker);
}

void Visualization::publishLines(const ros::Publisher& pub, int showType, std::tuple<double,double,double,double,double,double> feature, 
                   const std::vector<Bezier::Point>& points)
{
    visualization_msgs::Marker  marker;
    markerInit(marker);
    marker.type = showType;
    marker.scale.x = std::get<0>(feature);

    marker.color.r = std::get<2>(feature);
    marker.color.g = std::get<3>(feature);
    marker.color.b = std::get<4>(feature);
    marker.color.a = std::get<5>(feature);

    for(int i=0; i<points.size(); ++i)
    {
        geometry_msgs::Point p;
        p.x = points[i].x;
        p.y = points[i].y;
        p.z = 0.0;
        marker.points.push_back(p);
    }
    pub.publish(marker);
}