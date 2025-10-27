#include "DataGenerator.h"
#include <chrono>
#include <cmath>
#include <random>

DataGenerator::DataGenerator(QObject *parent)
    : QObject(parent) , m_stopFlag(false) {}

DataGenerator::~DataGenerator() {
    stopGeneration();
}

void DataGenerator::startGeneration() {
    if (m_thread.joinable()) return; // must already be running
    m_stopFlag = false;

    // Launch the run() function
    m_thread = std::thread(&DataGenerator::run, this);
}

void DataGenerator::stopGeneration() {
    m_stopFlag = true;
    if (m_thread.joinable()) 
    {
        // Wait for thread to finish current loop before destroying oject.
        m_thread.join();
    }
}


void DataGenerator::run(){
    // Basic setup for random noise
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-0.5, 0.5);

    // The main loop that runs in the background
    while (!m_stopFlag) {
        // Simulate new data point
        double y_val = 5.0 * std::sin(m_timeCounter * 0.5) + dist(gen);
        m_timeCounter += 0.1;

        QPointF newPoint(m_timeCounter, y_val);

        { // Thread-safe operation
            // Lock the mutex before writing 
            std::lock_guard<std::mutex> lock(m_dataMutex);
            m_latestPoint = newPoint;
        }
        
        // For GUI
        emit newDataReady();

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

QPointF DataGenerator::getLatestPoint(){
    // Thread-safe read operation
    std::lock_guard<std::mutex> lock(m_dataMutex);
    return m_latestPoint;
}