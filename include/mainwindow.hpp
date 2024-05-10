#ifndef FE96EFC8_016F_4D7C_8140_8879DA85361A
#define FE96EFC8_016F_4D7C_8140_8879DA85361A

#include "ui_mainwindow.hpp"
#include <QDateTime>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QToolTip>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow final : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override = default;

private:
  std::unique_ptr<Ui::MainWindow> ui = std::make_unique<Ui::MainWindow>();
private slots:

};


#endif /* FE96EFC8_016F_4D7C_8140_8879DA85361A */
