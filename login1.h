#ifndef LOGIN1_H
#define LOGIN1_H

#include <QMainWindow>

namespace Ui {
class login1;
}

class login1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit login1(QWidget *parent = nullptr);
    ~login1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login1 *ui;
};

#endif // LOGIN1_H
