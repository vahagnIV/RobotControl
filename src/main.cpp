//
// Created by vahagn on 21/08/20.
//
#include <QApplication>

#include "main_window.h"
#include <ros/ros.h>
int main(int argc, char *argv[]) {

  QApplication a(argc, argv);
  ros::init(argc, argv, "robot_control");
  gago::MainWindow mainWindow;
  mainWindow.show();
  return QApplication::exec();
}
