#ifndef COUNTIP_H
#define COUNTIP_H

#include <QFile>
#include <QMainWindow>
#include <QString>

namespace UI
{
    class CountIP;
}

class CountIP : public QMainWindow
{
    Q_OBJECT

    public:
        explicit CountIP(QWidget * parent = 0);
        ~CountIP();

    private slots:
        void on_pushButton_load_clicked();

    private:
        UI::CountIP * ui;
};

#endif //COUNTIP_H