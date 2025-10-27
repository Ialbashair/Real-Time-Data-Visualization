#pragma once
#include <QObject>
#include <QPointF> 
#include <thread>
#include <mutex>
#include <atomic>

class DataGenerator : public QObject {
    Q_OBJECT // Must be present for QObject-dervied classes
    public:
        explicit DataGenerator(QObject *parent = nullptr);
        ~DataGenerator();

        void startGeneration();
        void stopGeneration();

        // Thread-safe way
        QPointF getLatestPoint();

    signals:
        void newDataReady();
    
    private:
        std::thread m_thread; //The dedicated thread for data generation
        std::atomic<bool> m_stopFlag; // Thread-safe way to signal the thread to exit/stop
        std::mutex m_dataMutex; // Protects access to the shared data member

        QPointF m_latestPoint; // Shared, thread-safe data buffer
        double m_timeCounter = 0.0; // Counter for x-axis value

        void run(); // Function containg the lopp that runs on the thread
};          