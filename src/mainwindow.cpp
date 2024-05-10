#include "mainwindow.hpp"
#include "file_parser.hpp"
#include "interpolation_calc.hpp"
#include <QWidget>
#include <cmath>
#include <iomanip>
#include <qpushbutton.h>
#include <sstream>
#include <vector>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  ui->setupUi(this);

  QString html = R"(
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <script src="https://www.desmos.com/api/v1.8/calculator.js?apiKey=dcb31709b452b1cf9dc26972add0fda6"></script>
</head>
<body>
    <div id="calculator" style="height: 958px; width: 100%;"></div>
    <script>
        var elt = document.getElementById('calculator');
        var calculator = Desmos.GraphingCalculator(elt);
    </script>
</body>
</html>
)";
  ui->webview->setHtml(html);

  table_event_handler = std::make_unique<TableEventHandler>(ui->tableWidget);

  connect(ui->calculate_func_btn, &QPushButton::clicked, this,
          &MainWindow::on_calculation_func_btn_clicked);
  connect(ui->calculation_file_btn, &QPushButton::clicked, this,
          &MainWindow::on_calculation_file_btn_clicked);
  connect(ui->calculation_xy_btn, &QPushButton::clicked, this,
          &MainWindow::on_calculation_table_btn_clicked);
  connect(ui->sinx_rb, &QRadioButton::clicked, this,
          &MainWindow::on_sinx_rbtn_clicked);

  connect(ui->cosx_rb, &QRadioButton::clicked, this,
          &MainWindow::on_cosx_rbtn_clicked);

  connect(ui->browse_btn, &QPushButton::clicked, this,
          &MainWindow::on_browse_file_btn_clicked);

  connect(ui->add_point_btn, &QPushButton::clicked, this,
          &MainWindow::on_add_btn_clicked);
  connect(ui->remove_point_btn, &QPushButton::clicked, this,
          &MainWindow::on_remove_btn_clicked);
}

void MainWindow::on_calculation_func_btn_clicked() {
  ui->textBrowser->clear();
  double start = ui->start_sb->value();
  double end = ui->end_sb->value();
  int nodes = ui->nodes_count_sb->value();
  double point = ui->point_y_value_box->value();

  if (start >= end) {
    ui->statusbar->showMessage("Start must be less than end");
    return;
  }

  if (start > point || end < point) {
    ui->statusbar->showMessage("Point must be in interval [start, end]");
    return;
  }

  std::function<double(double)> func;

  if (ui->sinx_rb->isChecked()) {
    func = [](double x) { return std::sin(x); };
  } else {
    func = [](double x) { return std::cos(x); };
  }

  auto [x, y] =
      IntepolationCalculator::generate_func_values(func, start, end, nodes);

  for (auto &method :
       {IntepolationCalculator::Lagrange,
        IntepolationCalculator::NewtonSeparated,
        IntepolationCalculator::NewtonFinite, IntepolationCalculator::Bessel,
        IntepolationCalculator::Stirling}) {
    auto calculator = IntepolationCalculator(method, x, y);
    auto interpolated_value = calculator.interpolate()(point);
    auto latex = calculator.to_latex();
    auto difference_table = calculator.difference_table();
    auto nodes = calculator.get_nodes();
    auto method_name = IntepolationCalculator::method_to_string(method);

    ui->textBrowser->append("<h3>Method: " + QString(method_name.c_str()) +
                            "</h3>");
    ui->textBrowser->append("<b>Interpolated value: </b>" +
                            QString::number(interpolated_value));
    ui->textBrowser->append("<b>Function: </b>" + QString(latex.c_str()));
    ui->textBrowser->append("<b>Nodes: </b>");
    for (auto [x, y] : nodes) {
      ui->textBrowser->append(
          "(" + (QString::number(x) + " " + QString::number(y) + ")"));
    }
    ui->textBrowser->append("<b>Difference table: </b>");
    for (const auto &row : difference_table) {
      std::stringstream ss;
      for (const auto &x : row) {
        ss << std::setw(8) << std::fixed << std::setprecision(2) << x << " ";
      }
      ui->textBrowser->append(ss.str().c_str());
    }

    if (method == IntepolationCalculator::NewtonSeparated) {
      draw_chart(nodes, latex);
    }

    ui->textBrowser->append("");
  }
}

void MainWindow::on_calculation_file_btn_clicked() {
  auto parsing_result =
      parse_file(ui->file_path_edit->toPlainText().toStdString());
  if (!parsing_result.status) {
    ui->statusbar->showMessage(QString::fromStdString("Failed to parse file"));
    return;
  }

  if (parsing_result.x_values.size() < 3) {
    ui->statusbar->showMessage("Table must have at least 3 rows");
    return;
  }

  for (auto &method :
       {IntepolationCalculator::Lagrange,
        IntepolationCalculator::NewtonSeparated,
        IntepolationCalculator::NewtonFinite, IntepolationCalculator::Bessel,
        IntepolationCalculator::Stirling}) {
    auto calculator = IntepolationCalculator(method, parsing_result.x_values,
                                             parsing_result.y_values);
    auto interpolated_value =
        calculator.interpolate()(parsing_result.firstValue);
    auto latex = calculator.to_latex();
    auto difference_table = calculator.difference_table();
    auto nodes = calculator.get_nodes();
    auto method_name = IntepolationCalculator::method_to_string(method);

    ui->textBrowser->append("<h3>Method: " + QString(method_name.c_str()) +
                            "</h3>");
    ui->textBrowser->append("<b>Interpolated value: </b>" +
                            QString::number(interpolated_value));
    ui->textBrowser->append("<b>Function: </b>" + QString(latex.c_str()));
    ui->textBrowser->append("<b>Nodes: </b>");
    for (auto [x, y] : nodes) {
      ui->textBrowser->append(
          "(" + (QString::number(x) + " " + QString::number(y) + ")"));
    }
    if (method != IntepolationCalculator::Lagrange) {
      ui->textBrowser->append("<b>Difference table: </b>");
      for (const auto &row : difference_table) {
        std::stringstream ss;
        for (const auto &x : row) {
          ss << std::setw(8) << std::fixed << std::setprecision(2) << x << " ";
        }
        ui->textBrowser->append(ss.str().c_str());
      }
    }

    if (method == IntepolationCalculator::NewtonSeparated) {
      draw_chart(nodes, latex);
    }

    ui->textBrowser->append("");
  }
}

void MainWindow::on_calculation_table_btn_clicked() {
  ui->textBrowser->clear();
  double point = ui->point_y_value_box->value();

  if (ui->tableWidget->rowCount() < 3) {
    ui->statusbar->showMessage("Table must have at least 3 rows");
    return;
  }

  for (auto &method :
       {IntepolationCalculator::Lagrange,
        IntepolationCalculator::NewtonSeparated,
        IntepolationCalculator::NewtonFinite, IntepolationCalculator::Bessel,
        IntepolationCalculator::Stirling}) {
    std::vector<double> x(ui->tableWidget->rowCount());
    std::vector<double> y(ui->tableWidget->rowCount());
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
      x[i] = ui->tableWidget->item(i, 0)->text().toDouble();
      y[i] = ui->tableWidget->item(i, 1)->text().toDouble();
    }
    auto calculator = IntepolationCalculator(method, x, y);
    auto interpolated_value = calculator.interpolate()(point);
    auto latex = calculator.to_latex();
    auto difference_table = calculator.difference_table();
    auto nodes = calculator.get_nodes();
    auto method_name = IntepolationCalculator::method_to_string(method);

    ui->textBrowser->append("<h3>Method: " + QString(method_name.c_str()) +
                            "</h3>");
    ui->textBrowser->append("<b>Interpolated value: </b>" +
                            QString::number(interpolated_value));
    ui->textBrowser->append("<b>Function: </b>" + QString(latex.c_str()));
    ui->textBrowser->append("<b>Nodes: </b>");
    for (auto [x, y] : nodes) {
      ui->textBrowser->append(
          "(" + (QString::number(x) + " " + QString::number(y) + ")"));
    }
    if (method != IntepolationCalculator::Lagrange) {
      ui->textBrowser->append("<b>Difference table: </b>");
      for (const auto &row : difference_table) {
        std::stringstream ss;
        for (const auto &x : row) {
          ss << std::setw(8) << std::fixed << std::setprecision(2) << x << " ";
        }
        ui->textBrowser->append(ss.str().c_str());
      }
    }

    if (method == IntepolationCalculator::NewtonSeparated) {
      draw_chart(nodes, latex);
    }

    ui->textBrowser->append("");
  }
}

void MainWindow::on_cosx_rbtn_clicked() {
  ui->cosx_rb->setChecked(true);
  ui->sinx_rb->setChecked(false);
}

void MainWindow::on_sinx_rbtn_clicked() {
  ui->cosx_rb->setChecked(false);
  ui->sinx_rb->setChecked(true);
}

void MainWindow::on_browse_file_btn_clicked() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                                  tr("txt files (*.txt)"));
  if (!fileName.isEmpty()) {
    ui->file_path_edit->setText(fileName);
  }
}

void MainWindow::on_add_btn_clicked() {
  ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

void MainWindow::on_remove_btn_clicked() {
  if (ui->tableWidget->rowCount() > 0) {
    ui->tableWidget->removeRow(ui->tableWidget->rowCount() - 1);
  }
}

void MainWindow::draw_chart(
    const std::vector<std::pair<double, double>> &points,
    std::string function) {
  ui->webview->page()->runJavaScript("calculator.setBlank()");
  int i = 0;
  std::replace(function.begin(), function.end(), ',', '.');
  for (const auto &point : points) {
    auto v = QString("calculator.setExpression({ id: '%1', latex: '(%2, %3)'})")
                 .arg(i++)
                 .arg(point.first)
                 .arg(point.second);
    ui->webview->page()->runJavaScript(v);
  }

  auto v = QString("calculator.setExpression({ id: 'graph', latex: '%1'})")
               .arg(function.c_str());
  ui->webview->page()->runJavaScript(v);
}
