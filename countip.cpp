#include "countip.h"

#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QStringList>
#include <QTextEdit>
#include <QTextStream>

#include "ui_testing.h"

CountIP::CountIP(QWidget * parent) : QMainWindow(parent), ui(new Ui::CountIP)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Подсчёт IP-адресов"));
}

CountIP::~CountIP()
{
    delete ui;
}

void CountIP::on_pushButton_load_clicked()
{
    int colIp, colUnik, sizeMap; //переменные для подсчета значений
    QMap<int, QString> map; //словарь для данных из файла

    auto filename = QFileDialog::getOpenFileName(this, tr("Открытие документа"), "/tmp", DOCX file (*.*)");

    if(filename.isEmpty)
    {
        return;
    }

    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly | QOIDevice::Text)) //если не открыт файл
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Icon::Warning);
        msgBox.setText(tr("Ошибка открытия файла '%1'").arg(file.filename()));
        msgBox.exec();
        return;
    }

    else 
    {
        QTextStream in(&file);
        
        for(int i = 0; !in.atEnd(); i++)
        {
            map.insert(i, in.readLine());
        }
            sizeMap = map.size();

            if(!map.isEmpty)
            {
                for(int i = 0; i < sizeMap; i++)
                {
                    QString currentValue = map.value(i);

                    for(int j = 0; j < sizeMap; j++)
                    {
                        if(i != j && currentValue == map.value(j))
                        {
                            colIp++;
                        }

                        colUnik = sizeMap - colIp;
                    }
                }
            }
        
            else 
            {
                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Icon::Warning);
                msgBox.setText(tr("Данные из файла '%1' не записаны").arg(file.filename));
                msgBox.exec();
            }
        }
        
        ui->textEdit->append(tr("Количество одинаковых адресов: '%1'").arg(colIp));
        ui->textEdit->append(tr("Количество уникальных адресов: '%1'").arg(colUnik));
        ui->textEdit->append(tr("Количество адресов: '%1'").arg(sizeMap));
        ui->textEdit->append(tr("Размер файла: '%1'").arg(file.size()));

        file.close();        
}