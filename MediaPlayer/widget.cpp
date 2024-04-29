#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_player = new QMediaPlayer();
    m_player->setVolume(70);
    ui->labelVolume->setText(QString("Volume: ").append(QString::number(m_player->volume())));
    ui->horizontalSliderProgress->setValue(m_player->volume());
}

Widget::~Widget()
{
    delete m_player;
    delete ui;
}

void Widget::on_pushButtonOpen_clicked()
{
    QString file = QFileDialog::getOpenFileName
            (
             this,
                "Open File",
                NULL,
                "Audio files (*mp3 *.flac)"
             );
    ui->labelFile->setText(file);
    m_player->setMedia(QUrl::fromLocalFile(file));
    m_player->play();
}

