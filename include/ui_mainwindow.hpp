/********************************************************************************
** Form generated from reading UI file 'designerRheYmj.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DESIGNERRHEYMJ_H
#define DESIGNERRHEYMJ_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
public:
  QWidget *centralwidget;
  QHBoxLayout *horizontalLayout;
  QFrame *frame;
  QVBoxLayout *verticalLayout;
  QGroupBox *groupBox_input_file;
  QVBoxLayout *verticalLayout_2;
  QLabel *label;
  QTextEdit *file_path_edit;
  QGroupBox *groupBox_2;
  QHBoxLayout *horizontalLayout_3;
  QPushButton *browse_btn;
  QPushButton *laod_btn;
  QPushButton *calculation_file_btn;
  QTabWidget *tabWidget_xy;
  QWidget *table_tab;
  QVBoxLayout *verticalLayout_4;
  QLabel *label_2;
  QTableWidget *tableWidget;
  QGroupBox *button_groupBox_group;
  QHBoxLayout *horizontalLayout_2;
  QPushButton *add_point_btn;
  QPushButton *remove_point_btn;
  QPushButton *calculation_xy_btn;
  QWidget *func_tab;
  QVBoxLayout *verticalLayout_10;
  QGroupBox *groupBox_21;
  QVBoxLayout *verticalLayout_8;
  QLabel *label_5;
  QFrame *frame_5;
  QHBoxLayout *horizontalLayout_5;
  QRadioButton *radioButton_2;
  QLabel *label_8;
  QFrame *frame_4;
  QHBoxLayout *horizontalLayout_4;
  QRadioButton *radioButton;
  QLabel *label_7;
  QGroupBox *groupBox_6;
  QVBoxLayout *verticalLayout_9;
  QLabel *label_9;
  QFrame *frame_7;
  QHBoxLayout *horizontalLayout_6;
  QDoubleSpinBox *doubleSpinBox_2;
  QDoubleSpinBox *doubleSpinBox;
  QGroupBox *groupBox_3;
  QVBoxLayout *verticalLayout_7;
  QLabel *label_6;
  QSpinBox *spinBox;
  QPushButton *calculate_func_btn;
  QGroupBox *groupBox_point;
  QVBoxLayout *verticalLayout_5;
  QLabel *label_4;
  QDoubleSpinBox *point_y_value_box;
  QFrame *frame_result;
  QVBoxLayout *verticalLayout_3;
  QLabel *label_3;
  QTextBrowser *textBrowser;
  QGroupBox *groupBox_22;
  QVBoxLayout *verticalLayout_6;
  QWebEngineView *webview;
  QMenuBar *menubar;
  QStatusBar *statusbar;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(1308, 1039);
    QFont font;
    font.setBold(false);
    font.setWeight(50);
    font.setStrikeOut(false);
    MainWindow->setFont(font);
    MainWindow->setAutoFillBackground(false);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setMinimumSize(QSize(1308, 986));
    horizontalLayout = new QHBoxLayout(centralwidget);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    frame = new QFrame(centralwidget);
    frame->setObjectName(QString::fromUtf8("frame"));
    frame->setMinimumSize(QSize(500, 0));
    frame->setMaximumSize(QSize(500, 16777215));
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Raised);
    verticalLayout = new QVBoxLayout(frame);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    groupBox_input_file = new QGroupBox(frame);
    groupBox_input_file->setObjectName(
        QString::fromUtf8("groupBox_input_file"));
    groupBox_input_file->setMaximumSize(QSize(478, 200));
    verticalLayout_2 = new QVBoxLayout(groupBox_input_file);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    label = new QLabel(groupBox_input_file);
    label->setObjectName(QString::fromUtf8("label"));
    label->setMinimumSize(QSize(0, 50));
    label->setMaximumSize(QSize(16777215, 50));
    QFont font1;
    font1.setPointSize(15);
    font1.setBold(true);
    font1.setWeight(75);
    font1.setStrikeOut(false);
    label->setFont(font1);

    verticalLayout_2->addWidget(label);

    file_path_edit = new QTextEdit(groupBox_input_file);
    file_path_edit->setObjectName(QString::fromUtf8("file_path_edit"));
    file_path_edit->setMaximumSize(QSize(16777215, 25));
    file_path_edit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    verticalLayout_2->addWidget(file_path_edit);

    groupBox_2 = new QGroupBox(groupBox_input_file);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    groupBox_2->setMaximumSize(QSize(16777215, 50));
    horizontalLayout_3 = new QHBoxLayout(groupBox_2);
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    browse_btn = new QPushButton(groupBox_2);
    browse_btn->setObjectName(QString::fromUtf8("browse_btn"));
    QFont font2;
    font2.setBold(true);
    font2.setWeight(75);
    font2.setStrikeOut(false);
    browse_btn->setFont(font2);

    horizontalLayout_3->addWidget(browse_btn);

    laod_btn = new QPushButton(groupBox_2);
    laod_btn->setObjectName(QString::fromUtf8("laod_btn"));
    laod_btn->setFont(font2);
    laod_btn->setCheckable(false);
    laod_btn->setChecked(false);
    laod_btn->setAutoDefault(false);
    laod_btn->setFlat(false);

    horizontalLayout_3->addWidget(laod_btn);

    verticalLayout_2->addWidget(groupBox_2);

    calculation_file_btn = new QPushButton(groupBox_input_file);
    calculation_file_btn->setObjectName(
        QString::fromUtf8("calculation_file_btn"));
    calculation_file_btn->setFont(font2);

    verticalLayout_2->addWidget(calculation_file_btn);

    verticalLayout->addWidget(groupBox_input_file);

    tabWidget_xy = new QTabWidget(frame);
    tabWidget_xy->setObjectName(QString::fromUtf8("tabWidget_xy"));
    tabWidget_xy->setMaximumSize(QSize(478, 16777215));
    tabWidget_xy->setTabShape(QTabWidget::Rounded);
    table_tab = new QWidget();
    table_tab->setObjectName(QString::fromUtf8("table_tab"));
    verticalLayout_4 = new QVBoxLayout(table_tab);
    verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
    label_2 = new QLabel(table_tab);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setMinimumSize(QSize(0, 50));
    label_2->setMaximumSize(QSize(16777215, 50));
    label_2->setFont(font1);

    verticalLayout_4->addWidget(label_2);

    tableWidget = new QTableWidget(table_tab);
    tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
    tableWidget->setMinimumSize(QSize(0, 250));

    verticalLayout_4->addWidget(tableWidget);

    button_groupBox_group = new QGroupBox(table_tab);
    button_groupBox_group->setObjectName(
        QString::fromUtf8("button_groupBox_group"));
    button_groupBox_group->setMaximumSize(QSize(16777215, 50));
    horizontalLayout_2 = new QHBoxLayout(button_groupBox_group);
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    add_point_btn = new QPushButton(button_groupBox_group);
    add_point_btn->setObjectName(QString::fromUtf8("add_point_btn"));
    add_point_btn->setFont(font2);

    horizontalLayout_2->addWidget(add_point_btn);

    remove_point_btn = new QPushButton(button_groupBox_group);
    remove_point_btn->setObjectName(QString::fromUtf8("remove_point_btn"));
    remove_point_btn->setFont(font2);

    horizontalLayout_2->addWidget(remove_point_btn);

    verticalLayout_4->addWidget(button_groupBox_group);

    calculation_xy_btn = new QPushButton(table_tab);
    calculation_xy_btn->setObjectName(QString::fromUtf8("calculation_xy_btn"));
    calculation_xy_btn->setMaximumSize(QSize(16777215, 50));
    calculation_xy_btn->setFont(font2);

    verticalLayout_4->addWidget(calculation_xy_btn);

    tabWidget_xy->addTab(table_tab, QString());
    func_tab = new QWidget();
    func_tab->setObjectName(QString::fromUtf8("func_tab"));
    verticalLayout_10 = new QVBoxLayout(func_tab);
    verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
    groupBox_21 = new QGroupBox(func_tab);
    groupBox_21->setObjectName(QString::fromUtf8("groupBox_21"));
    verticalLayout_8 = new QVBoxLayout(groupBox_21);
    verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
    label_5 = new QLabel(groupBox_21);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setMaximumSize(QSize(16777215, 25));
    QFont font3;
    font3.setPointSize(15);
    font3.setBold(true);
    font3.setWeight(75);
    label_5->setFont(font3);

    verticalLayout_8->addWidget(label_5);

    frame_5 = new QFrame(groupBox_21);
    frame_5->setObjectName(QString::fromUtf8("frame_5"));
    frame_5->setFrameShape(QFrame::StyledPanel);
    frame_5->setFrameShadow(QFrame::Raised);
    horizontalLayout_5 = new QHBoxLayout(frame_5);
    horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
    radioButton_2 = new QRadioButton(frame_5);
    radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
    radioButton_2->setMaximumSize(QSize(20, 16777215));
    radioButton_2->setChecked(true);

    horizontalLayout_5->addWidget(radioButton_2);

    label_8 = new QLabel(frame_5);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    QFont font4;
    font4.setPointSize(12);
    label_8->setFont(font4);

    horizontalLayout_5->addWidget(label_8);

    verticalLayout_8->addWidget(frame_5);

    frame_4 = new QFrame(groupBox_21);
    frame_4->setObjectName(QString::fromUtf8("frame_4"));
    frame_4->setFrameShape(QFrame::StyledPanel);
    frame_4->setFrameShadow(QFrame::Raised);
    horizontalLayout_4 = new QHBoxLayout(frame_4);
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
    radioButton = new QRadioButton(frame_4);
    radioButton->setObjectName(QString::fromUtf8("radioButton"));
    radioButton->setMaximumSize(QSize(20, 16777215));

    horizontalLayout_4->addWidget(radioButton);

    label_7 = new QLabel(frame_4);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setFont(font4);

    horizontalLayout_4->addWidget(label_7);

    verticalLayout_8->addWidget(frame_4);

    verticalLayout_10->addWidget(groupBox_21);

    groupBox_6 = new QGroupBox(func_tab);
    groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
    verticalLayout_9 = new QVBoxLayout(groupBox_6);
    verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
    label_9 = new QLabel(groupBox_6);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setMaximumSize(QSize(16777215, 25));
    label_9->setFont(font3);

    verticalLayout_9->addWidget(label_9);

    frame_7 = new QFrame(groupBox_6);
    frame_7->setObjectName(QString::fromUtf8("frame_7"));
    frame_7->setFrameShape(QFrame::StyledPanel);
    frame_7->setFrameShadow(QFrame::Raised);
    horizontalLayout_6 = new QHBoxLayout(frame_7);
    horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
    doubleSpinBox_2 = new QDoubleSpinBox(frame_7);
    doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
    doubleSpinBox_2->setMinimum(-1000.000000000000000);
    doubleSpinBox_2->setMaximum(1000.000000000000000);

    horizontalLayout_6->addWidget(doubleSpinBox_2);

    doubleSpinBox = new QDoubleSpinBox(frame_7);
    doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
    doubleSpinBox->setMinimum(-1000.000000000000000);
    doubleSpinBox->setMaximum(1000.000000000000000);

    horizontalLayout_6->addWidget(doubleSpinBox);

    verticalLayout_9->addWidget(frame_7);

    verticalLayout_10->addWidget(groupBox_6);

    groupBox_3 = new QGroupBox(func_tab);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    verticalLayout_7 = new QVBoxLayout(groupBox_3);
    verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
    label_6 = new QLabel(groupBox_3);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setMaximumSize(QSize(16777215, 25));
    QFont font5;
    font5.setPointSize(16);
    font5.setBold(true);
    font5.setWeight(75);
    label_6->setFont(font5);

    verticalLayout_7->addWidget(label_6);

    spinBox = new QSpinBox(groupBox_3);
    spinBox->setObjectName(QString::fromUtf8("spinBox"));
    spinBox->setMinimum(2);

    verticalLayout_7->addWidget(spinBox);

    verticalLayout_10->addWidget(groupBox_3);

    calculate_func_btn = new QPushButton(func_tab);
    calculate_func_btn->setObjectName(QString::fromUtf8("calculate_func_btn"));
    calculate_func_btn->setMinimumSize(QSize(0, 0));
    QFont font6;
    font6.setBold(true);
    font6.setWeight(75);
    calculate_func_btn->setFont(font6);

    verticalLayout_10->addWidget(calculate_func_btn);

    tabWidget_xy->addTab(func_tab, QString());

    verticalLayout->addWidget(tabWidget_xy);

    groupBox_point = new QGroupBox(frame);
    groupBox_point->setObjectName(QString::fromUtf8("groupBox_point"));
    groupBox_point->setMaximumSize(QSize(478, 16777215));
    verticalLayout_5 = new QVBoxLayout(groupBox_point);
    verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
    label_4 = new QLabel(groupBox_point);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setMinimumSize(QSize(0, 50));
    label_4->setMaximumSize(QSize(16777215, 50));
    label_4->setFont(font1);

    verticalLayout_5->addWidget(label_4);

    point_y_value_box = new QDoubleSpinBox(groupBox_point);
    point_y_value_box->setObjectName(QString::fromUtf8("point_y_value_box"));
    QFont font7;
    font7.setPointSize(12);
    font7.setBold(false);
    font7.setWeight(50);
    font7.setStrikeOut(false);
    point_y_value_box->setFont(font7);
    point_y_value_box->setMinimum(-10000000.000000000000000);
    point_y_value_box->setMaximum(100000000.000000000000000);

    verticalLayout_5->addWidget(point_y_value_box);

    verticalLayout->addWidget(groupBox_point);

    frame_result = new QFrame(frame);
    frame_result->setObjectName(QString::fromUtf8("frame_result"));
    frame_result->setMaximumSize(QSize(478, 16777215));
    frame_result->setFrameShape(QFrame::StyledPanel);
    frame_result->setFrameShadow(QFrame::Raised);
    verticalLayout_3 = new QVBoxLayout(frame_result);
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    label_3 = new QLabel(frame_result);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setMinimumSize(QSize(0, 25));
    label_3->setMaximumSize(QSize(16777215, 50));
    label_3->setFont(font1);

    verticalLayout_3->addWidget(label_3);

    textBrowser = new QTextBrowser(frame_result);
    textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

    verticalLayout_3->addWidget(textBrowser);

    verticalLayout->addWidget(frame_result);

    horizontalLayout->addWidget(frame);

    groupBox_22 = new QGroupBox(centralwidget);
    groupBox_22->setObjectName(QString::fromUtf8("groupBox_22"));
    groupBox_22->setMinimumSize(QSize(500, 0));
    verticalLayout_6 = new QVBoxLayout(groupBox_22);
    verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
    webview = new QWebEngineView(groupBox_22);
    webview->setObjectName(QString::fromUtf8("webview"));
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(webview->sizePolicy().hasHeightForWidth());
    webview->setSizePolicy(sizePolicy);
    webview->setUrl(QUrl(QString::fromUtf8("about:blank")));

    verticalLayout_6->addWidget(webview);

    horizontalLayout->addWidget(groupBox_22);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 1308, 30));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);

    laod_btn->setDefault(false);
    tabWidget_xy->setCurrentIndex(1);

    QMetaObject::connectSlotsByName(MainWindow);
  } // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(QCoreApplication::translate(
        "MainWindow", "Laboratory work 5", nullptr));
    label->setText(QCoreApplication::translate(
        "MainWindow", "Load points from file:", nullptr));
    browse_btn->setText(
        QCoreApplication::translate("MainWindow", "Browse", nullptr));
    laod_btn->setText(
        QCoreApplication::translate("MainWindow", "Load", nullptr));
    calculation_file_btn->setText(
        QCoreApplication::translate("MainWindow", "Calculate", nullptr));
#if QT_CONFIG(accessibility)
    tabWidget_xy->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
    label_2->setText(
        QCoreApplication::translate("MainWindow", "Input X Y:", nullptr));
    add_point_btn->setText(
        QCoreApplication::translate("MainWindow", "Add", nullptr));
    remove_point_btn->setText(
        QCoreApplication::translate("MainWindow", "Remove", nullptr));
    calculation_xy_btn->setText(
        QCoreApplication::translate("MainWindow", "Calculate", nullptr));
    tabWidget_xy->setTabText(
        tabWidget_xy->indexOf(table_tab),
        QCoreApplication::translate("MainWindow", "(X, Y) Input", nullptr));
    label_5->setText(QCoreApplication::translate(
        "MainWindow", "Select the function", nullptr));
    radioButton_2->setText(QString());
    label_8->setText(
        QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    radioButton->setText(QString());
    label_7->setText(
        QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    label_9->setText(
        QCoreApplication::translate("MainWindow", "Interval", nullptr));
    label_6->setText(
        QCoreApplication::translate("MainWindow", "Points count", nullptr));
    calculate_func_btn->setText(
        QCoreApplication::translate("MainWindow", "Calculate", nullptr));
    tabWidget_xy->setTabText(
        tabWidget_xy->indexOf(func_tab),
        QCoreApplication::translate("MainWindow", "Function", nullptr));
    label_4->setText(QCoreApplication::translate(
        "MainWindow", "Calculate F(Y) in point with Y:", nullptr));
    label_3->setText(QCoreApplication::translate(
        "MainWindow", "Calculation result", nullptr));
  } // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DESIGNERRHEYMJ_H
