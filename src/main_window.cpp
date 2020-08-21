//
// Created by vahagn on 21/08/20.
//

#include "main_window.h"
#include "ui_mainwindow.h"
#include "std_msgs/String.h"
#include <QKeyEvent>

namespace gago {
MainWindow::MainWindow() : QMainWindow(nullptr), ui_(new Ui::MainWindow), currently_pressed_(-1) {
  ui_->setupUi(this);
  publisher_ = node_.advertise<std_msgs::String>("robot_control", 1);

}

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->isAutoRepeat()) {
    if (currently_pressed_ == event->key()
        && std::chrono::system_clock::now() - last_pressed_time_ < std::chrono::seconds(4))
      return;
  }

  if (event->key() != currently_pressed_)
    Stop();

  switch (event->key()) {
    case Qt::Key::Key_Up:
      Forward();
      break;
    case Qt::Key::Key_Down:
      Backward();
      break;
    case Qt::Key::Key_Right:
      Right();
      break;
    case Qt::Key::Key_Left:
      Left();
      break;
  }
  QWidget::keyPressEvent(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
  if (event->isAutoRepeat())
    return;
  if (event->key() == Qt::Key::Key_Up || event->key() == Qt::Key::Key_Down || event->key() == Qt::Key::Key_Right
      || event->key() == Qt::Key::Key_Left)
    Stop();
  QWidget::keyReleaseEvent(event);
}

MainWindow::~MainWindow() {
  delete ui_;
}

void MainWindow::Stop() {
  std_msgs::String msg;
  msg.data = "STOP";
  publisher_.publish(msg);
  currently_pressed_ = -1;
}

void MainWindow::Forward() {
  std_msgs::String msg;
  msg.data = "FORWARD";
  publisher_.publish(msg);
  last_pressed_time_ = std::chrono::system_clock::now();
  currently_pressed_ = Qt::Key::Key_Up;
}

void MainWindow::Backward() {
  std_msgs::String msg;
  msg.data = "BACKWARD";
  publisher_.publish(msg);
  last_pressed_time_ = std::chrono::system_clock::now();
  currently_pressed_ = Qt::Key::Key_Down;

}

void MainWindow::Right() {
  std_msgs::String msg;
  msg.data = "RIGHT";
  publisher_.publish(msg);
  last_pressed_time_ = std::chrono::system_clock::now();
  currently_pressed_ = Qt::Key::Key_Right;
}

void MainWindow::Left() {
  std_msgs::String msg;
  msg.data = "LEFT";
  publisher_.publish(msg);
  last_pressed_time_ = std::chrono::system_clock::now();
  currently_pressed_ = Qt::Key::Key_Left;
}

}