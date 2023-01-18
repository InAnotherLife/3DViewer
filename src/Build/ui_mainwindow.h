/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <opengl.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_14;
    QFrame *line_21;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_line;
    QComboBox *comboBox_line_type;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_line_color_2;
    QComboBox *comboBox_line_color;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_line_width;
    QSpinBox *spinBox_line_width;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_17;
    QFrame *line_22;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_18;
    QComboBox *comboBox_vertices_type;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_19;
    QComboBox *comboBox_vertices_color;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_20;
    QSpinBox *spinBox_vertices_wight;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_23;
    QFrame *line_20;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_12;
    QComboBox *comboBox_projection_type;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_background_color;
    QComboBox *comboBox_background_color;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_5;
    QFrame *line;
    QHBoxLayout *horizontalLayout_26;
    QPushButton *pushButton_open_file;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_file_name;
    QLabel *file_name;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_count_vertexes;
    QLabel *count_vertexes;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_count_facets;
    QLabel *count_facets;
    QFrame *line_13;
    QPushButton *pushButton_set_default_settings;
    OpenGL *widget;
    QPushButton *pushButton_move_x_plus;
    QPushButton *pushButton_move_x_minus;
    QPushButton *pushButton_rotate_x_minus;
    QPushButton *pushButton_rotate_x_plus;
    QPushButton *pushButton_rotate_y_plus;
    QPushButton *pushButton_rotate_y_minus;
    QPushButton *pushButton_scale_plus;
    QPushButton *pushButton_move_y_minus;
    QPushButton *pushButton_scale_minus;
    QPushButton *pushButton_move_y_plus;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1040, 860);
        MainWindow->setMinimumSize(QSize(1040, 860));
        MainWindow->setMaximumSize(QSize(1040, 860));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(530, 10, 241, 128));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(verticalLayoutWidget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setScaledContents(true);
        label_14->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_14);

        line_21 = new QFrame(verticalLayoutWidget_2);
        line_21->setObjectName(QString::fromUtf8("line_21"));
        line_21->setFrameShape(QFrame::HLine);
        line_21->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_21);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_line = new QLabel(verticalLayoutWidget_2);
        label_line->setObjectName(QString::fromUtf8("label_line"));

        horizontalLayout_19->addWidget(label_line);

        comboBox_line_type = new QComboBox(verticalLayoutWidget_2);
        comboBox_line_type->addItem(QString());
        comboBox_line_type->addItem(QString());
        comboBox_line_type->setObjectName(QString::fromUtf8("comboBox_line_type"));

        horizontalLayout_19->addWidget(comboBox_line_type);


        verticalLayout_4->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_line_color_2 = new QLabel(verticalLayoutWidget_2);
        label_line_color_2->setObjectName(QString::fromUtf8("label_line_color_2"));

        horizontalLayout_20->addWidget(label_line_color_2);

        comboBox_line_color = new QComboBox(verticalLayoutWidget_2);
        comboBox_line_color->addItem(QString());
        comboBox_line_color->addItem(QString());
        comboBox_line_color->addItem(QString());
        comboBox_line_color->addItem(QString());
        comboBox_line_color->addItem(QString());
        comboBox_line_color->addItem(QString());
        comboBox_line_color->setObjectName(QString::fromUtf8("comboBox_line_color"));

        horizontalLayout_20->addWidget(comboBox_line_color);


        verticalLayout_4->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_line_width = new QLabel(verticalLayoutWidget_2);
        label_line_width->setObjectName(QString::fromUtf8("label_line_width"));

        horizontalLayout_21->addWidget(label_line_width);

        spinBox_line_width = new QSpinBox(verticalLayoutWidget_2);
        spinBox_line_width->setObjectName(QString::fromUtf8("spinBox_line_width"));
        spinBox_line_width->setMinimum(1);
        spinBox_line_width->setMaximum(10);

        horizontalLayout_21->addWidget(spinBox_line_width);


        verticalLayout_4->addLayout(horizontalLayout_21);

        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(790, 10, 241, 128));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(verticalLayoutWidget_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_17);

        line_22 = new QFrame(verticalLayoutWidget_4);
        line_22->setObjectName(QString::fromUtf8("line_22"));
        line_22->setFrameShape(QFrame::HLine);
        line_22->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_22);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_18 = new QLabel(verticalLayoutWidget_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_22->addWidget(label_18);

        comboBox_vertices_type = new QComboBox(verticalLayoutWidget_4);
        comboBox_vertices_type->addItem(QString());
        comboBox_vertices_type->addItem(QString());
        comboBox_vertices_type->addItem(QString());
        comboBox_vertices_type->setObjectName(QString::fromUtf8("comboBox_vertices_type"));

        horizontalLayout_22->addWidget(comboBox_vertices_type);


        verticalLayout_8->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_19 = new QLabel(verticalLayoutWidget_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_23->addWidget(label_19);

        comboBox_vertices_color = new QComboBox(verticalLayoutWidget_4);
        comboBox_vertices_color->addItem(QString());
        comboBox_vertices_color->addItem(QString());
        comboBox_vertices_color->addItem(QString());
        comboBox_vertices_color->addItem(QString());
        comboBox_vertices_color->addItem(QString());
        comboBox_vertices_color->addItem(QString());
        comboBox_vertices_color->setObjectName(QString::fromUtf8("comboBox_vertices_color"));

        horizontalLayout_23->addWidget(comboBox_vertices_color);


        verticalLayout_8->addLayout(horizontalLayout_23);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_20 = new QLabel(verticalLayoutWidget_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_24->addWidget(label_20);

        spinBox_vertices_wight = new QSpinBox(verticalLayoutWidget_4);
        spinBox_vertices_wight->setObjectName(QString::fromUtf8("spinBox_vertices_wight"));
        spinBox_vertices_wight->setMinimum(1);
        spinBox_vertices_wight->setMaximum(15);

        horizontalLayout_24->addWidget(spinBox_vertices_wight);


        verticalLayout_8->addLayout(horizontalLayout_24);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(270, 10, 244, 94));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(verticalLayoutWidget_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_23);

        line_20 = new QFrame(verticalLayoutWidget_3);
        line_20->setObjectName(QString::fromUtf8("line_20"));
        line_20->setFrameShape(QFrame::HLine);
        line_20->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_20);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_12 = new QLabel(verticalLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_9->addWidget(label_12);

        comboBox_projection_type = new QComboBox(verticalLayoutWidget_3);
        comboBox_projection_type->addItem(QString());
        comboBox_projection_type->addItem(QString());
        comboBox_projection_type->setObjectName(QString::fromUtf8("comboBox_projection_type"));

        horizontalLayout_9->addWidget(comboBox_projection_type);


        verticalLayout_7->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_background_color = new QLabel(verticalLayoutWidget_3);
        label_background_color->setObjectName(QString::fromUtf8("label_background_color"));

        horizontalLayout_10->addWidget(label_background_color);

        comboBox_background_color = new QComboBox(verticalLayoutWidget_3);
        comboBox_background_color->addItem(QString());
        comboBox_background_color->addItem(QString());
        comboBox_background_color->addItem(QString());
        comboBox_background_color->addItem(QString());
        comboBox_background_color->addItem(QString());
        comboBox_background_color->addItem(QString());
        comboBox_background_color->setObjectName(QString::fromUtf8("comboBox_background_color"));

        horizontalLayout_10->addWidget(comboBox_background_color);


        verticalLayout_7->addLayout(horizontalLayout_10);

        verticalLayoutWidget_5 = new QWidget(centralwidget);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(10, 10, 241, 176));
        verticalLayout_9 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_5);

        line = new QFrame(verticalLayoutWidget_5);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(line);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        pushButton_open_file = new QPushButton(verticalLayoutWidget_5);
        pushButton_open_file->setObjectName(QString::fromUtf8("pushButton_open_file"));

        horizontalLayout_26->addWidget(pushButton_open_file);


        verticalLayout_9->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        label_file_name = new QLabel(verticalLayoutWidget_5);
        label_file_name->setObjectName(QString::fromUtf8("label_file_name"));

        horizontalLayout_27->addWidget(label_file_name);

        file_name = new QLabel(verticalLayoutWidget_5);
        file_name->setObjectName(QString::fromUtf8("file_name"));
        file_name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        file_name->setWordWrap(false);

        horizontalLayout_27->addWidget(file_name);


        verticalLayout_9->addLayout(horizontalLayout_27);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        label_count_vertexes = new QLabel(verticalLayoutWidget_5);
        label_count_vertexes->setObjectName(QString::fromUtf8("label_count_vertexes"));

        horizontalLayout_28->addWidget(label_count_vertexes);

        count_vertexes = new QLabel(verticalLayoutWidget_5);
        count_vertexes->setObjectName(QString::fromUtf8("count_vertexes"));
        count_vertexes->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_28->addWidget(count_vertexes);


        verticalLayout_9->addLayout(horizontalLayout_28);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        label_count_facets = new QLabel(verticalLayoutWidget_5);
        label_count_facets->setObjectName(QString::fromUtf8("label_count_facets"));

        horizontalLayout_29->addWidget(label_count_facets);

        count_facets = new QLabel(verticalLayoutWidget_5);
        count_facets->setObjectName(QString::fromUtf8("count_facets"));
        count_facets->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_29->addWidget(count_facets);


        verticalLayout_9->addLayout(horizontalLayout_29);

        line_13 = new QFrame(verticalLayoutWidget_5);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(line_13);

        pushButton_set_default_settings = new QPushButton(verticalLayoutWidget_5);
        pushButton_set_default_settings->setObjectName(QString::fromUtf8("pushButton_set_default_settings"));

        verticalLayout_9->addWidget(pushButton_set_default_settings);

        widget = new OpenGL(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 200, 1021, 651));
        pushButton_move_x_plus = new QPushButton(widget);
        pushButton_move_x_plus->setObjectName(QString::fromUtf8("pushButton_move_x_plus"));
        pushButton_move_x_plus->setGeometry(QRect(890, 610, 40, 25));
        QFont font;
        font.setPointSize(15);
        pushButton_move_x_plus->setFont(font);
        pushButton_move_x_minus = new QPushButton(widget);
        pushButton_move_x_minus->setObjectName(QString::fromUtf8("pushButton_move_x_minus"));
        pushButton_move_x_minus->setGeometry(QRect(840, 610, 40, 25));
        pushButton_move_x_minus->setFont(font);
        pushButton_rotate_x_minus = new QPushButton(widget);
        pushButton_rotate_x_minus->setObjectName(QString::fromUtf8("pushButton_rotate_x_minus"));
        pushButton_rotate_x_minus->setGeometry(QRect(20, 610, 25, 25));
        QFont font1;
        font1.setPointSize(12);
        pushButton_rotate_x_minus->setFont(font1);
        pushButton_rotate_x_plus = new QPushButton(widget);
        pushButton_rotate_x_plus->setObjectName(QString::fromUtf8("pushButton_rotate_x_plus"));
        pushButton_rotate_x_plus->setGeometry(QRect(50, 610, 25, 25));
        pushButton_rotate_x_plus->setFont(font1);
        pushButton_rotate_y_plus = new QPushButton(widget);
        pushButton_rotate_y_plus->setObjectName(QString::fromUtf8("pushButton_rotate_y_plus"));
        pushButton_rotate_y_plus->setGeometry(QRect(980, 610, 25, 25));
        pushButton_rotate_y_plus->setFont(font1);
        pushButton_rotate_y_minus = new QPushButton(widget);
        pushButton_rotate_y_minus->setObjectName(QString::fromUtf8("pushButton_rotate_y_minus"));
        pushButton_rotate_y_minus->setGeometry(QRect(950, 610, 25, 25));
        pushButton_rotate_y_minus->setFont(font1);
        pushButton_scale_plus = new QPushButton(widget);
        pushButton_scale_plus->setObjectName(QString::fromUtf8("pushButton_scale_plus"));
        pushButton_scale_plus->setGeometry(QRect(950, 580, 25, 25));
        pushButton_scale_plus->setFont(font1);
        pushButton_move_y_minus = new QPushButton(widget);
        pushButton_move_y_minus->setObjectName(QString::fromUtf8("pushButton_move_y_minus"));
        pushButton_move_y_minus->setGeometry(QRect(980, 520, 25, 40));
        pushButton_move_y_minus->setFont(font);
        pushButton_scale_minus = new QPushButton(widget);
        pushButton_scale_minus->setObjectName(QString::fromUtf8("pushButton_scale_minus"));
        pushButton_scale_minus->setGeometry(QRect(980, 580, 25, 25));
        pushButton_scale_minus->setFont(font1);
        pushButton_move_y_plus = new QPushButton(widget);
        pushButton_move_y_plus->setObjectName(QString::fromUtf8("pushButton_move_y_plus"));
        pushButton_move_y_plus->setGeometry(QRect(980, 470, 25, 40));
        pushButton_move_y_plus->setFont(font);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \321\200\320\265\320\261\320\265\321\200", nullptr));
        label_line->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277:", nullptr));
        comboBox_line_type->setItemText(0, QCoreApplication::translate("MainWindow", "\320\241\320\277\320\273\320\276\321\210\320\275\320\260\321\217", nullptr));
        comboBox_line_type->setItemText(1, QCoreApplication::translate("MainWindow", "\320\237\321\203\320\275\320\272\321\202\320\270\321\200\320\275\320\260\321\217", nullptr));

        label_line_color_2->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202:", nullptr));
        comboBox_line_color->setItemText(0, QCoreApplication::translate("MainWindow", "\320\221\320\265\320\273\321\213\320\271", nullptr));
        comboBox_line_color->setItemText(1, QCoreApplication::translate("MainWindow", "\320\247\320\265\321\200\320\275\321\213\320\271", nullptr));
        comboBox_line_color->setItemText(2, QCoreApplication::translate("MainWindow", "\320\232\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        comboBox_line_color->setItemText(3, QCoreApplication::translate("MainWindow", "\320\227\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        comboBox_line_color->setItemText(4, QCoreApplication::translate("MainWindow", "\320\241\320\270\320\275\320\270\320\271", nullptr));
        comboBox_line_color->setItemText(5, QCoreApplication::translate("MainWindow", "\320\226\320\265\320\273\321\202\321\213\320\271", nullptr));

        label_line_width->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\262\320\265\321\200\321\210\320\270\320\275", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277:", nullptr));
        comboBox_vertices_type->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265\321\202", nullptr));
        comboBox_vertices_type->setItemText(1, QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        comboBox_vertices_type->setItemText(2, QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));

        label_19->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202:", nullptr));
        comboBox_vertices_color->setItemText(0, QCoreApplication::translate("MainWindow", "\320\221\320\265\320\273\321\213\320\271", nullptr));
        comboBox_vertices_color->setItemText(1, QCoreApplication::translate("MainWindow", "\320\247\320\265\321\200\320\275\321\213\320\271", nullptr));
        comboBox_vertices_color->setItemText(2, QCoreApplication::translate("MainWindow", "\320\232\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        comboBox_vertices_color->setItemText(3, QCoreApplication::translate("MainWindow", "\320\227\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        comboBox_vertices_color->setItemText(4, QCoreApplication::translate("MainWindow", "\320\241\320\270\320\275\320\270\320\271", nullptr));
        comboBox_vertices_color->setItemText(5, QCoreApplication::translate("MainWindow", "\320\226\320\265\320\273\321\202\321\213\320\271", nullptr));

        label_20->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200:", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\277\321\200\320\276\320\265\320\272\321\206\320\270\320\270:", nullptr));
        comboBox_projection_type->setItemText(0, QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));
        comboBox_projection_type->setItemText(1, QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\321\214\320\275\320\260\321\217", nullptr));

        label_background_color->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260:", nullptr));
        comboBox_background_color->setItemText(0, QCoreApplication::translate("MainWindow", "\320\221\320\265\320\273\321\213\320\271", nullptr));
        comboBox_background_color->setItemText(1, QCoreApplication::translate("MainWindow", "\320\247\320\265\321\200\320\275\321\213\320\271", nullptr));
        comboBox_background_color->setItemText(2, QCoreApplication::translate("MainWindow", "\320\232\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        comboBox_background_color->setItemText(3, QCoreApplication::translate("MainWindow", "\320\227\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        comboBox_background_color->setItemText(4, QCoreApplication::translate("MainWindow", "\320\241\320\270\320\275\320\270\320\271", nullptr));
        comboBox_background_color->setItemText(5, QCoreApplication::translate("MainWindow", "\320\226\320\265\320\273\321\202\321\213\320\271", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276\320\261 \320\276\320\261\321\212\320\265\320\272\321\202\320\265", nullptr));
        pushButton_open_file->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        label_file_name->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260:", nullptr));
        file_name->setText(QString());
        label_count_vertexes->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\262\320\265\321\200\321\210\320\270\320\275:", nullptr));
        count_vertexes->setText(QString());
        label_count_facets->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\200\320\265\320\261\320\265\321\200:", nullptr));
        count_facets->setText(QString());
        pushButton_set_default_settings->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        pushButton_move_x_plus->setText(QCoreApplication::translate("MainWindow", "\342\207\250", nullptr));
        pushButton_move_x_minus->setText(QCoreApplication::translate("MainWindow", "\342\207\246", nullptr));
        pushButton_rotate_x_minus->setText(QCoreApplication::translate("MainWindow", "\342\244\272", nullptr));
        pushButton_rotate_x_plus->setText(QCoreApplication::translate("MainWindow", "\342\244\273", nullptr));
        pushButton_rotate_y_plus->setText(QCoreApplication::translate("MainWindow", "\342\206\272", nullptr));
        pushButton_rotate_y_minus->setText(QCoreApplication::translate("MainWindow", "\342\206\273", nullptr));
        pushButton_scale_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_move_y_minus->setText(QCoreApplication::translate("MainWindow", "\342\207\251", nullptr));
        pushButton_scale_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_move_y_plus->setText(QCoreApplication::translate("MainWindow", "\342\207\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
