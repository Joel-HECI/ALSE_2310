#include "dividiag.h"
#include "ui_dividiag.h"

Dividiag::Dividiag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dividiag)
{
    ui->setupUi(this);
}

Dividiag::~Dividiag()
{
    delete ui; 
}

void Dividiag::on_rdb_AE_clicked(bool checked)
{
    ui->txt_Escalar->setEnabled( checked );
}


void Dividiag::on_rdb_BE_clicked(bool checked)
{
    ui->txt_Escalar->setEnabled( checked );
}


void Dividiag::on_rdb_AB_clicked(bool checked)
{
    ui->txt_Escalar->setEnabled( false );
}


void Dividiag::on_rdb_BA_clicked(bool checked)
{
    ui->txt_Escalar->setEnabled( false );
}


void Dividiag::on_buttonBox_accepted()
{
    int t;
    double e;
    if( ui->rdb_AB->isChecked()) t = 0;
    if( ui->rdb_BA->isChecked()) t = 1;
    if( ui->rdb_AE->isChecked()) t = 2;
    if( ui->rdb_BE->isChecked() ) t = 3 ;

    e = ui->txt_Escalar->text().toDouble();
    emit senalDivi( t, e );
}

