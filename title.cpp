#include <QPainter>

#include "title.h"
#include "ui_title.h"

#include "globalhelper.h"

Title::Title(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Title)
{
    ui->setupUi(this);

    connect(ui->CloseBtn, SIGNAL(clicked(bool)), this, SIGNAL(SigCloseBtnClicked()));
    connect(ui->MinBtn, SIGNAL(clicked(bool)), this, SIGNAL(SigMinBtnClicked()));
    connect(ui->MaxBtn, SIGNAL(clicked(bool)), this, SIGNAL(SigMaxBtnClicked()));

    InitUi();
}

Title::~Title()
{
    delete ui;
}

bool Title::InitUi()
{
    //保证窗口不被绘制上的部分透明
    setAttribute(Qt::WA_TranslucentBackground);

    setStyleSheet(GlobalHelper::GetQssStr(":/qss/title.css"));

    //ui->LogoBtn->setText("");

    GlobalHelper::SetIcon(ui->MaxBtn, 9, QChar(0xf2d0));
    GlobalHelper::SetIcon(ui->MinBtn, 9, QChar(0xf2d1));
    GlobalHelper::SetIcon(ui->CloseBtn, 9, QChar(0xf2d3));
}


void Title::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

}

void Title::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit SigDoubleClicked();
    }
}

void Title::OnChangeMaxBtnStyle(bool bIfMax)
{
    if (bIfMax)
    {
        ui->MaxBtn->setText(QChar(0xf2d2));
    }
    else
    {
        ui->MaxBtn->setText(QChar(0xf2d0));
    }
}

