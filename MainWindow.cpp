#include "MainWindow.h"
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView> // Added for QChartView definition
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QTime>
#include <QPainter>          // Needed for QPainter::Antialiasing

//using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_series(new QLineSeries()), 
        m_chart(new QChart()),
        m_generator(new DataGenerator(this))
        
{
    setWindowTitle("Real-Time Data Visualizer");

    m_chart->addSeries(m_series); 
    m_chart->setTitle("Live Sine Wave Data");
    m_chart->legend()->hide();

    QValueAxis *axisX = new QValueAxis();
    axisX->setRange(m_minX, m_maxX); // 
    axisX->setLabelFormat("%g");
    axisX->setTitleText("Time");
    m_chart->setAxisX(axisX, m_series);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(-6,6);
    axisY->setTitleText("Value");
    m_chart->setAxisY(axisY, m_series);

    QChartView *chartView = new QChartView(m_chart); 
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
    resize(800,400);

    connect(m_generator, &DataGenerator::newDataReady, this, &MainWindow::updateChart);

    m_generator->startGeneration();
}

MainWindow::~MainWindow()
{    
}

void MainWindow::updateChart()
{
    QPointF newPoint = m_generator->getLatestPoint(); 
    addPoint(newPoint);
}

void MainWindow::addPoint(const QPointF &point)
{
    m_series->append(point);

    double currentX = point.x();

    if (currentX > m_maxX){
        double shift = currentX - m_maxX;
        m_maxX = currentX;
        m_minX += shift;

        // FIX: Explicitly set the range on axisX()
        m_chart->axisX()->setRange(m_minX, m_maxX); 

        if (m_series->count() > 500){
            m_series->removePoints(0,m_series->count() - 500);
        }
    }
}