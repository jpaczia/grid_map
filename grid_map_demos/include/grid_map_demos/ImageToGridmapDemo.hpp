/*
 * ImageToGridmapDemo.hpp
 *
 *  Created on: May 4, 2015
 *      Author: Martin Wermelinger
 *	 Institute: ETH Zurich, Autonomous Systems Lab
 *
 */

#pragma once

// ROS
#include <ros/ros.h>
#include <sensor_msgs/Image.h>

#include <grid_map/grid_map.hpp>

#include <string>

namespace grid_map_demos {

/*!
 * Loads an image and saves it as layer 'elevation' of a grid map.
 * The grid map is published and can be viewed in Rviz.
 */
class ImageToGridmapDemo
{
 public:

  /*!
   * Constructor.
   * @param nodeHandle the ROS node handle.
   */
  ImageToGridmapDemo(ros::NodeHandle& nodeHandle);

  /*!
   * Destructor.
   */
  virtual ~ImageToGridmapDemo();

  /*!
  * Reads and verifies the ROS parameters.
  * @return true if successful.
  */
  bool readParameters();

  void imageCallback(const sensor_msgs::Image& msg);
  void maskCallback(const sensor_msgs::Image& msg);

 private:

  //! ROS nodehandle.
  ros::NodeHandle& nodeHandle_;

  //! Grid map publisher.
  ros::Publisher gridMapPublisher_;

  //! Point cloud publisher.
  ros::Publisher pointCloudPublisher_;

  //! Grid map data.
  grid_map::GridMap map_;

  ros::Subscriber grayscaleMaskSub_;
  ros::Subscriber imageSub_;

  //! Name of the grid map topic.
  std::string imageTopic_;

  //! Length of the grid map in x direction.
  double mapLengthX_;
  double resolution_;

  //! Range of the height values.
  double minHeight_;
  double maxHeight_;

  //! Frame id of the grid map.
  std::string mapFrameId_;

  bool mapInitialized_;
};

} /* namespace */
