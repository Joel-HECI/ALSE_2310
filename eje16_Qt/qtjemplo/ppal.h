#ifndef PPAL_H
#define PPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PPal; }
QT_END_NAMESPACE

class PPal : public QMainWindow
{
    Q_OBJECT

public:
    PPal(QWidget *parent = nullptr);
    ~PPal();

public slots:
    void tipoDivi(int tipo, double esc);

private slots:
    void on_btn_Operar_clicked();

private:
    Ui::PPal *ui;
    int _tipo;
    double _escalar;
};
#endif // PPAL_H
