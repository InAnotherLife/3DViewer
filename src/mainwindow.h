#ifndef SRC_MAINWINDOW_H_
#define SRC_MAINWINDOW_H_

#include <QApplication>
#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <memory>

#include "matrix.h"
#include "opengl.h"
#include "parser.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_open_file_clicked();
  void on_pushButton_scale_plus_clicked();
  void on_pushButton_scale_minus_clicked();
  void on_spinBox_line_width_valueChanged(int arg);
  void on_comboBox_line_color_currentIndexChanged(int index);
  void on_comboBox_background_color_currentIndexChanged(int index);
  void on_comboBox_line_type_currentIndexChanged(int index);
  void on_pushButton_move_x_minus_clicked();
  void on_pushButton_move_x_plus_clicked();
  void on_pushButton_move_y_plus_clicked();
  void on_pushButton_move_y_minus_clicked();
  void on_pushButton_rotate_y_plus_clicked();
  void on_pushButton_rotate_y_minus_clicked();
  void on_pushButton_rotate_x_minus_clicked();
  void on_pushButton_rotate_x_plus_clicked();
  void on_comboBox_vertices_type_currentIndexChanged(int index);
  void on_spinBox_vertices_wight_valueChanged(int arg);
  void on_comboBox_vertices_color_currentIndexChanged(int index);
  void on_comboBox_projection_type_currentIndexChanged(int index);
  void receive_line_color(int line_color);
  void receive_vertices_color(int vertices_color);
  void on_pushButton_set_default_settings_clicked();

 private:
  std::unique_ptr<Ui::MainWindow> ui_;
  std::unique_ptr<OpenGL> opengl_window_;
  data_t file_info_;
  double *arr_coords_facets_;
  unsigned int *arr_indexes_facets_;
  matrix_t matrix_vertexes_;
  double scale_plus_;
  double scale_minus_;
  double move_x_plus_;
  double move_x_minus_;
  double move_y_plus_;
  double move_y_minus_;
  int rotate_x_plus_;
  int rotate_x_minus_;
  int rotate_y_plus_;
  int rotate_y_minus_;
  double scale_value_;
  double move_value_;
  double rotate_value_;
  QString save_settings_file_;
  QString home_path_;
  void ClearVars();
  void SaveSettings();
  void LoadSettings();

 signals:
  void send_data(double[], unsigned int);
};

#endif  // SRC_MAINWINDOW_H_
