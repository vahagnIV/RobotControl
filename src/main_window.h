//
// Created by vahagn on 21/08/20.
//

#ifndef SRC_MAIN_WINDOW_H
#define SRC_MAIN_WINDOW_H
#include <QMainWindow>
#include "ros/ros.h"
#include <chrono>

namespace Ui {
class MainWindow;
}

namespace gago {

class MainWindow : public QMainWindow {
 Q_OBJECT
 public:
  MainWindow();
  virtual ~MainWindow();

 private:
  void keyPressEvent(QKeyEvent * event) override;
  void keyReleaseEvent(QKeyEvent * event) override;
  Ui::MainWindow *ui_;
  ros::NodeHandle node_;
  ros::Publisher publisher_;
  void Stop();
  void Forward();
  void Backward();
  void Right();
  void Left();
  int currently_pressed_;
  std::chrono::time_point<std::chrono::system_clock> last_pressed_time_;


};

}

#endif //SRC_MAIN_WINDOW_H
