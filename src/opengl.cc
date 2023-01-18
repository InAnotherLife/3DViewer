#define GL_SILENCE_DEPRECATION
#include "opengl.h"

opengl::opengl(QWidget *parent) : QOpenGLWidget(parent) {}

void opengl::initializeGL() {
  initializeOpenGLFunctions();
  glClearColor(1, 1, 1, 1);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);
}

void opengl::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void opengl::paintGL() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (projection_type_ == 0)
    glFrustum(-5, 5, -5, 5, 5, 100);
  else
    glOrtho(-15, 15, -15, 15, 5, 100);
  if (background_color_ == 0)
    glClearColor(1, 1, 1, 1);
  else if (background_color_ == 1)
    glClearColor(0, 0, 0, 1);
  else if (background_color_ == 2)
    glClearColor(1, 0, 0, 1);
  else if (background_color_ == 3)
    glClearColor(0, 1, 0, 1);
  else if (background_color_ == 4)
    glClearColor(0, 0, 1, 1);
  else if (background_color_ == 5)
    glClearColor(1, 1, 0, 1);
  if (line_color_ == background_color_) {
    if (background_color_ == 5)
      line_color_ = 0;
    else
      line_color_ = background_color_ + 1;
  }
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslated(0, 0, -15);
  glRotated(0, 0, 0, 1);
  glVertexPointer(3, GL_DOUBLE, 0, input_arr_coords_facets_);
  // Отрисовка вершин
  if (vertices_type_ != 0) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnable(GL_POINT_SMOOTH);
    if (vertices_type_ == 2) glDisable(GL_POINT_SMOOTH);
    if (vertices_color_ == background_color_) {
      if (background_color_ == 5)
        vertices_color_ = 0;
      else
        vertices_color_ = background_color_ + 1;
      emit send_vertices_color(vertices_color_);
    }
    if (vertices_color_ == 0)
      glColor3f(1, 1, 1);
    else if (vertices_color_ == 1)
      glColor3f(0, 0, 0);
    else if (vertices_color_ == 2)
      glColor3f(1, 0, 0);
    else if (vertices_color_ == 3)
      glColor3f(0, 1, 0);
    else if (vertices_color_ == 4)
      glColor3f(0, 0, 1);
    else if (vertices_color_ == 5)
      glColor3f(1, 1, 0);
    glPointSize(vertices_wight_);
    glDrawArrays(GL_POINTS, 0, input_len_arr_coords_facets_ / 3);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisable(GL_POINT_SMOOTH);
  }
  // Отрисовка граней
  glEnableClientState(GL_VERTEX_ARRAY);
  if (line_type_ == 1) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 100);
  }
  glLineWidth(line_width_);

  if (line_color_ == 0)
    glColor3f(1, 1, 1);
  else if (line_color_ == 1)
    glColor3f(0, 0, 0);
  else if (line_color_ == 2)
    glColor3f(1, 0, 0);
  else if (line_color_ == 3)
    glColor3f(0, 1, 0);
  else if (line_color_ == 4)
    glColor3f(0, 0, 1);
  else if (line_color_ == 5)
    glColor3f(1, 1, 0);
  glDrawArrays(GL_LINE_LOOP, 0, input_len_arr_coords_facets_ / 3);
  if (line_type_ == 1) glDisable(GL_LINE_STIPPLE);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void opengl::receive_data(double arr_coords_facets[],
                          unsigned int arr_len_coords_facets) {
  input_arr_coords_facets_ = arr_coords_facets;
  input_len_arr_coords_facets_ = arr_len_coords_facets * 3;
}
