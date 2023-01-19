#ifndef SRC_OPENGL_H_
#define SRC_OPENGL_H_

#include <QOpenGLFunctions>
#include <QOpenGLWidget>

class OpenGL : public QOpenGLWidget, public QOpenGLFunctions {
  Q_OBJECT

 public:
  explicit OpenGL(QWidget *parent = nullptr);
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  int edges_type_ = 0;
  int edges_thickness_ = 1;
  int edges_color_ = 1;
  int vertices_type_ = 0;
  int vertices_thickness_ = 1;
  int vertices_color_ = 0;
  int projection_type_ = 0;
  int background_color_ = 0;

 public slots:
  void receive_data(double arr_coords_facets[],
                    unsigned int input_len_arr_coords_facets);

 private:
  double *input_arr_coords_facets_ = 0;
  unsigned int input_len_arr_coords_facets_ = 0;

 signals:
  void send_edges_color(int);
};

#endif  // SRC_OPENGL_H_
