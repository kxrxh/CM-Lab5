#ifndef FE96EFC8_016F_4D7C_8140_8879DA85361A
#define FE96EFC8_016F_4D7C_8140_8879DA85361A

#include "table_event_handler.hpp"
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
  std::unique_ptr<TableEventHandler> table_event_handler;
  void draw_chart(const std::vector<std::pair<double, double>>& points, std::string function);

private slots:
  void on_calculation_func_btn_clicked();
  void on_calculation_file_btn_clicked();
  void on_calculation_table_btn_clicked();

  void on_cosx_rbtn_clicked();
  void on_sinx_rbtn_clicked();

  void on_browse_file_btn_clicked();

  void on_add_btn_clicked();
  void on_remove_btn_clicked();

};

#endif /* FE96EFC8_016F_4D7C_8140_8879DA85361A */
