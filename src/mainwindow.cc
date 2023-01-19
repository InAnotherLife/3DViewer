#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui_(std::make_unique<Ui::MainWindow>()),
      opengl_window_(std::make_unique<OpenGL>()) {
  ui_->setupUi(this);
  this->setWindowTitle("3DViewer");
  setlocale(LC_ALL, "en_US.UTF-8");
  home_path_ = QDir::homePath();
  save_settings_file_ = QDir::homePath() + "/" + "3dviewer.ini";
  file_info_ = {0, 0, 0, 0, 0};
  arr_coords_facets_ = NULL;
  arr_indexes_facets_ = NULL;
  matrix_vertexes_ = {0, 0, 0};
  scale_plus_ = 1;
  scale_minus_ = -1;
  move_x_plus_ = 0;
  move_x_minus_ = 0;
  move_y_plus_ = 0;
  move_y_minus_ = 0;
  rotate_x_plus_ = 0;
  rotate_x_minus_ = 0;
  rotate_y_plus_ = 0;
  rotate_y_minus_ = 0;
  LoadSettings();
  scale_value_ = 0.1;
  move_value_ = 0.7;
  rotate_value_ = 1.5;
  if (ui_->comboBox_edges_color->currentIndex() ==
      ui_->comboBox_background_color->currentIndex()) {
    int tmp_color = ui_->comboBox_background_color->currentIndex();
    ui_->comboBox_edges_color->setCurrentIndex(tmp_color + 1);
    ui_->widget->edges_color_ = tmp_color + 1;
  }
  connect(this, &MainWindow::send_data, ui_->widget, &OpenGL::receive_data);
  connect(ui_->widget, &OpenGL::send_edges_color, this,
          &MainWindow::receive_edges_color);
}

MainWindow::~MainWindow() {
  SaveSettings();
  remove_matrix(&matrix_vertexes_);
  free(arr_indexes_facets_);
  free(arr_coords_facets_);
}

void MainWindow::ClearVars() {
  file_info_ = {0, 0, 0, 0, 0};
  arr_coords_facets_ = NULL;
  arr_indexes_facets_ = NULL;
  matrix_vertexes_ = {0, 0, 0};
}

void MainWindow::on_pushButton_open_file_clicked() {
  QString file_path = QFileDialog::getOpenFileName(
      this, "Select the file with the extension .obj", home_path_,
      "OBJ Files (*.obj)");
  if (!file_path.isEmpty()) {
    ClearVars();
    home_path_ = QFileInfo(file_path).absolutePath();
    ui_->file_name->setText(QFileInfo(file_path).fileName());
    char *name_buffer = new char[file_path.length() + 1];
    memcpy(name_buffer, file_path.toStdString().c_str(),
           file_path.length() + 1);
    FILE *file_read = fopen(name_buffer, "r");
    get_file_info(file_read, &file_info_);
    matrix_vertexes_ = create_matrix(file_info_.count_rows_vertexes, 3);
    arr_indexes_facets_ = (unsigned int *)calloc(
        file_info_.count_indexes_facets, sizeof(unsigned int));
    arr_coords_facets_ =
        (double *)calloc(file_info_.count_indexes_facets * 3, sizeof(double));
    if (arr_indexes_facets_ == NULL || arr_coords_facets_ == NULL) {
      QMessageBox::about(this, "Warning", "Memory allocation error!");
    } else {
      get_str(name_buffer, &matrix_vertexes_, &file_info_, arr_indexes_facets_);
      get_coords_facets(&matrix_vertexes_, &file_info_, arr_indexes_facets_,
                        arr_coords_facets_);
    }
    ui_->count_vertexes->setText(
        QString::number(file_info_.count_rows_vertexes));
    ui_->count_facets->setText(QString::number(file_info_.count_rows_facets));

    emit send_data(arr_coords_facets_, file_info_.count_indexes_facets);
    ui_->widget->update();
  }
}

void MainWindow::on_pushButton_scale_plus_clicked() {
  scale_plus_ += scale_value_;
  scale_minus_ = -1;
  scale_matrix(&matrix_vertexes_, scale_plus_);
  get_coords_facets(&matrix_vertexes_, &file_info_, arr_indexes_facets_,
                    arr_coords_facets_);
  emit send_data(arr_coords_facets_, file_info_.count_indexes_facets);
  ui_->widget->update();
}

void MainWindow::on_pushButton_scale_minus_clicked() {
  scale_minus_ -= scale_value_;
  scale_plus_ = 1;
  scale_matrix(&matrix_vertexes_, scale_minus_);
  get_coords_facets(&matrix_vertexes_, &file_info_, arr_indexes_facets_,
                    arr_coords_facets_);
  emit send_data(arr_coords_facets_, file_info_.count_indexes_facets);
  ui_->widget->update();
}

void MainWindow::on_pushButton_move_x_minus_clicked() {
  move_x_minus_ -= move_value_;
  move_x_plus_ = 0;
  move_matrix(&matrix_vertexes_, move_x_minus_, 0, 0);
  get_coords_facets(&matrix_vertexes_, &file_info_, arr_indexes_facets_,
                    arr_coords_facets_);
  emit send_data(arr_coords_facets_, file_info_.count_indexes_facets);
  ui_->widget->update();
}

void MainWindow::on_pushButton_move_x_plus_clicked() {
  move_x_plus_ += move_value_;
  move_x_minus_ = 0;
  move_matrix(&matrix_vertexes_, move_x_plus_, 0, 0);
  get_coords_facets(&matrix_vertexes_, &file_info_, arr_indexes_facets_,
                    arr_coords_facets_);
  emit send_data(arr_coords_facets_, file_info_.count_indexes_facets);
  ui_->widget->update();
}

void MainWindow::on_pushButton_move_y_plus_clicked() {
  move_y_plus_ += move_value_;
  move_y_minus_ = 0;
  move_matrix(&matrix_vertexes_, 0, move_y_plus_, 0);
  get_coords_facets(&matrix_vertexes_, &file_info_, arr_indexes_facets_,
                    arr_coords_facets_);
  emit send_data(arr_coords_facets_, file_info_.count_indexes_facets);
  ui_->widget->update();
}

void MainWindow::on_pushButton_move_y_minus_clicked() {
  move_y_minus_ -= move_value_;
  move_y_plus_ = 0;
  move_matrix(&matrix_vertexes_, 0, move_y_minus_, 0);
  get_coords_facets(&matrix_vertexes_, &file_info_, arr_indexes_facets_,
                    arr_coords_facets_);
  emit send_data(arr_coords_facets_, file_info_.count_indexes_facets);
  ui_->widget->update();
}

void MainWindow::on_pushButton_rotate_y_plus_clicked() {
  rotate_y_plus_ -= rotate_value_;
  rotate_y_minus_ = 0;
  rotate_y(&matrix_vertexes_, rotate_y_plus_);
  get_coords_facets(&matrix_vertexes_, &file_info_, arr_indexes_facets_,
                    arr_coords_facets_);
  emit send_data(arr_coords_facets_, file_info_.count_indexes_facets);
  ui_->widget->update();
}

void MainWindow::on_pushButton_rotate_y_minus_clicked() {
  rotate_y_minus_ += rotate_value_;
  rotate_y_plus_ = 0;
  rotate_y(&matrix_vertexes_, rotate_y_minus_);
  get_coords_facets(&matrix_vertexes_, &file_info_, arr_indexes_facets_,
                    arr_coords_facets_);
  emit send_data(arr_coords_facets_, file_info_.count_indexes_facets);
  ui_->widget->update();
}

void MainWindow::on_pushButton_rotate_x_minus_clicked() {
  rotate_x_minus_ += rotate_value_;
  rotate_x_plus_ = 0;
  rotate_x(&matrix_vertexes_, rotate_x_minus_);
  get_coords_facets(&matrix_vertexes_, &file_info_, arr_indexes_facets_,
                    arr_coords_facets_);
  emit send_data(arr_coords_facets_, file_info_.count_indexes_facets);
  ui_->widget->update();
}

void MainWindow::on_pushButton_rotate_x_plus_clicked() {
  rotate_x_plus_ -= rotate_value_;
  rotate_x_minus_ = 0;
  rotate_x(&matrix_vertexes_, rotate_x_plus_);
  get_coords_facets(&matrix_vertexes_, &file_info_, arr_indexes_facets_,
                    arr_coords_facets_);
  emit send_data(arr_coords_facets_, file_info_.count_indexes_facets);
  ui_->widget->update();
}

void MainWindow::on_comboBox_vertices_type_currentIndexChanged(int index) {
  ui_->widget->vertices_type_ = index;
  ui_->widget->update();
}

void MainWindow::on_spinBox_vertices_thickness_valueChanged(int arg) {
  ui_->widget->vertices_thickness_ = arg;
  ui_->widget->update();
}

void MainWindow::on_comboBox_vertices_color_currentIndexChanged(int index) {
  ui_->widget->vertices_color_ = index;
  ui_->widget->update();
}

void MainWindow::on_spinBox_edges_thickness_valueChanged(int arg) {
  ui_->widget->edges_thickness_ = arg;
  ui_->widget->update();
}

void MainWindow::on_comboBox_edges_color_currentIndexChanged(int index) {
  ui_->widget->edges_color_ = index;
  ui_->widget->update();
}

void MainWindow::on_comboBox_background_color_currentIndexChanged(int index) {
  ui_->widget->background_color_ = index;
  ui_->widget->update();
}

void MainWindow::receive_edges_color(int color) {
  ui_->comboBox_edges_color->setCurrentIndex(color);
}

void MainWindow::on_comboBox_edges_type_currentIndexChanged(int index) {
  ui_->widget->edges_type_ = index;
  ui_->widget->update();
}

void MainWindow::on_comboBox_projection_type_currentIndexChanged(int index) {
  ui_->widget->projection_type_ = index;
  ui_->widget->update();
}

void MainWindow::SaveSettings() {
  QSettings settings(save_settings_file_, QSettings::IniFormat);
  settings.setValue("type_projection",
                    ui_->comboBox_projection_type->currentIndex());
  settings.setValue("background_color",
                    ui_->comboBox_background_color->currentIndex());
  settings.setValue("edges_type", ui_->comboBox_edges_type->currentIndex());
  settings.setValue("edges_color", ui_->comboBox_edges_color->currentIndex());
  settings.setValue("edges_thickness", ui_->spinBox_edges_thickness->value());
  settings.setValue("vertices_type",
                    ui_->comboBox_vertices_type->currentIndex());
  settings.setValue("vertices_color",
                    ui_->comboBox_vertices_color->currentIndex());
  settings.setValue("vertices_thickness",
                    ui_->spinBox_vertices_thickness->value());
}

void MainWindow::LoadSettings() {
  QSettings settings(save_settings_file_, QSettings::IniFormat);
  ui_->comboBox_projection_type->setCurrentIndex(
      settings.value("type_projection", "").toInt());
  ui_->comboBox_background_color->setCurrentIndex(
      settings.value("background_color", "").toInt());
  ui_->comboBox_edges_type->setCurrentIndex(
      settings.value("edges_type", "").toInt());
  ui_->comboBox_edges_color->setCurrentIndex(
      settings.value("edges_color", "").toInt());
  ui_->spinBox_edges_thickness->setValue(
      settings.value("edges_thickness", "").toInt());
  ui_->comboBox_vertices_type->setCurrentIndex(
      settings.value("vertices_type", "").toInt());
  ui_->comboBox_vertices_color->setCurrentIndex(
      settings.value("vertices_color", "").toInt());
  ui_->spinBox_vertices_thickness->setValue(
      settings.value("vertices_thickness", "").toInt());
}

void MainWindow::on_pushButton_set_default_settings_clicked() {
  scale_plus_ = 1;
  scale_minus_ = -1;
  move_x_plus_ = 0;
  move_x_minus_ = 0;
  move_y_plus_ = 0;
  move_y_minus_ = 0;
  rotate_y_plus_ = 0;
  rotate_y_minus_ = 0;
  rotate_x_plus_ = 0;
  rotate_x_minus_ = 0;
  ui_->widget->edges_type_ = 0;
  ui_->comboBox_edges_type->setCurrentIndex(0);
  ui_->widget->edges_thickness_ = 1;
  ui_->spinBox_edges_thickness->setValue(1);
  ui_->widget->edges_color_ = 1;
  ui_->comboBox_edges_color->setCurrentIndex(1);
  ui_->widget->background_color_ = 0;
  ui_->comboBox_background_color->setCurrentIndex(0);
  ui_->widget->vertices_color_ = 0;
  ui_->comboBox_vertices_color->setCurrentIndex(0);
  ui_->widget->vertices_type_ = 0;
  ui_->comboBox_vertices_type->setCurrentIndex(0);
  ui_->widget->vertices_thickness_ = 1;
  ui_->spinBox_vertices_thickness->setValue(1);
  ui_->widget->projection_type_ = 0;
  ui_->comboBox_projection_type->setCurrentIndex(0);
  ui_->widget->update();
}
