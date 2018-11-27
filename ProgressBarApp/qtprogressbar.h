#ifndef QTPROGRESSBAR_H
#define QTPROGRESSBAR_H
#include <QWidget>
#include "qtprogressbar.h"
#include <QPainter>
#include <QStylePainter>
#include <QResizeEvent>
#include <QDebug>
#include <QBitmap>
#include <qmath.h>
#include <QString>

class QtProgressBar : public QWidget
{
    Q_OBJECT
public:
    explicit QtProgressBar(QWidget *parent = 0);
    void onMeasure(int widthMeasureSpec, int heightMeasureSpec);

    void updateUI();

private:
    QRectF getItemRectF(double x, double y, double w, double h);

protected:
    void paintEvent(QPaintEvent*);

    void drawNetworkLoad(int mode, float percent);
    void drawPaths(int mode);
    void drawItems(int mode);
    void drawBattery(float percent);

    int getRunMode();
    void setRunningMode(int mode);
    float getBatteryLevel();
    void setBatteryLevel(float batteryLevel);
    float getNetworkLoadLevel();
    void setNetworkLoadLevel(float networkLoadLevel);

private slots:
    void resizeEvent(QResizeEvent *event);

signals:

public slots:
};

#endif // QTPROGRESSBAR_H
