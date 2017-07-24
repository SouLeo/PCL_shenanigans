/////////////////////////////////////////////////////////////////////////////// 
////      Title     : <CODE TITLE HERE>.cpp 
////      Project   : <PROJ DESCRIP> 
////      Created   : <DATE CREATED> 
////      Author    : Selma Wanna 
////      Platforms : Ubuntu 64-bit 
////      Copyright : Copyright© The University of Texas at Austin, 2014-2017. All rights reserved. 
//// 
////          All files within this directory are subject to the following, unless an alternative 
////          license is explicitly included within the text of each file. 
//// 
////          This software and documentation constitute an unpublished work 
////          and contain valuable trade secrets and proprietary information 
////          belonging to the University. None of the foregoing material may be 
////          copied or duplicated or disclosed without the express, written 
////          permission of the University. THE UNIVERSITY EXPRESSLY DISCLAIMS ANY 
////          AND ALL WARRANTIES CONCERNING THIS SOFTWARE AND DOCUMENTATION, 
////          INCLUDING ANY WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A 
////          PARTICULAR PURPOSE, AND WARRANTIES OF PERFORMANCE, AND ANY WARRANTY 
////          THAT MIGHT OTHERWISE ARISE FROM COURSE OF DEALING OR USAGE OF TRADE. 
////          NO WARRANTY IS EITHER EXPRESS OR IMPLIED WITH RESPECT TO THE USE OF 
////          THE SOFTWARE OR DOCUMENTATION. Under no circumstances shall the 
////          University be liable for incidental, special, indirect, direct or 
////          consequential damages or loss of profits, interruption of business, 
////          or related expenses which may arise from use of software or documentation, 
////          including but not limited to those resulting from defects in software 
////          and/or documentation, or loss or inaccuracy of data of any kind. 
//// 
/////////////////////////////////////////////////////////////////////////////////

#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl_ros/transforms.h>
#include <pcl_conversions/pcl_conversions.h>

//ros::Publisher pub;
ros::Publisher pcl_generator;
/*
void cloud_cb (const sensor_msgs::PointCloud2ConstPtr& input){
		// Create a container for the data.
		sensor_msgs::PointCloud2 output;

		// Do data processing here...
		output = *input;

		// Publish the data.
		pub.publish (output);
}
*/
int main (int argc, char** argv){
		// Initialize ROS
		ros::init (argc, argv, "pcl_tutorial");
		ros::NodeHandle nh;
		
		pcl::PointCloud<pcl::PointXYZ> *cloud_ptr;

		cloud_ptr->width = 5;
		cloud_ptr->height = 1;
		cloud_ptr->is_dense = false;

		cloud_ptr->push_back ( pcl::PointXYZ (rand(), rand (), rand()));
		
		sensor_msgs::PointCloud2 *output_ptr;

		pcl::toROSMsg(*cloud_ptr, *output_ptr);

		// Create a ROS subscriber for the input point cloud
//		ros::Subscriber sub = nh.subscribe("input", 1, cloud_cb);
		

		// Create a ROS publisher for the output point cloud
//		pub = nh.advertise<sensor_msgs::PointCloud2> ("output", 1);
//	pcl_generator = nh.advertise<sensor_msgs::PointCloud2>("input", 1);

		// Published the data.
//		pcl_generator.publish(output);
		
		// Spin
		ros::spin();
}
