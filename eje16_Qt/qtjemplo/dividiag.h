#ifndef DIVIDIAG_H
#define DIVIDIAG_H

#include <QDialog>

namespace Ui {
class Dividiag;
}

class Dividiag : public QDialog
{
    Q_OBJECT

public:
    explicit Dividiag(QWidget *parent = nullptr);
    ~Dividiag();

private slots:
    void on_rdb_AE_clicked(bool checked);

    void on_rdb_BE_clicked(bool checked);

    void on_rdb_AB_clicked(bool checked);

    void on_rdb_BA_clicked(bool checked);

    void on_buttonBox_accepted();

signals:
    void senalDivi(int tipo, double escalar);


private:
    Ui::Dividiag *ui;
};

#endif // DIVIDIAG_H
