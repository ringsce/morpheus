#ifndef SECWINDOW_H
#define SECWINDOW_H

#include <QDialog>

namespace Ui {
class SecWindow;
}

class SecWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecWindow(QWidget *parent = 0);
    ~SecWindow();

private:
    Ui::SecWindow *ui;
};

#endif // SECDIALOG_H
