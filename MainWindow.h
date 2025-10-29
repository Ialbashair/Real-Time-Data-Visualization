#pragma once
#include <QMainWindow>
#include <QPointF>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include "DataGenerator.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateChart();

private:
    // FIX: Removed the 'QtCharts::' prefix to resolve the latest MOC/namespace errors
    QLineSeries *m_series; 
    QChart *m_chart;
    DataGenerator *m_generator;
    
    // Member variables for axis range
    double m_maxX = 10.0;
    double m_minX = 0.0; // Added for dynamic X-axis range calculation

    // Function signature uses the correct type QPointF
    void addPoint(const QPointF &point); 
};