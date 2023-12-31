#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "task.h"

namespace Ui
{
    class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    public slots:
        void addTask();
        void removeTask(Task* task);

    private:
        Ui::MainWindow *ui;
        QVector<Task*> mTasks;

};


#endif // MAINWINDOW_H
