#include "qtprogressbar.h"

// Default per items
const double per_column1 = 0.1;
const double per_column2 = 0.23;
const double per_column3 = 0.45;
const double per_column4 = 0.9;
const double per_column5 = 0.06;
const double per_column6 = 0.86;


const double per_row1 = 0.1;
const double per_row2 = 0.25;
const double per_row3 = 0.2;
const double per_row4 = 0.5;
const double per_row5 = 0.85;
const double per_row6 = 0.04;
const double per_row7 = 0.6;
const double per_row8 = 0.438;

const double per_itemMargin = 0.009;
const double per_itemHeight = 0.12;
const double per_itemWidth = 0.08;

const double per_batteryHeight = 0.4;
const double per_batteryWidth = 0.13;

const double per_networkLoadHeight = 0.25;
const double per_networkLoadWidth = 0.15;

double parentWidth;
double parentHeight;

// Default position global dimens
double pos_column1 = per_column1;
double pos_column2 = per_column2;
double pos_column3 = per_column3;
double pos_column4 = per_column4;

double pos_row1 = per_row1;
double pos_row2 = per_row2;
double pos_row3 = per_row3;
double pos_row4 = per_row4;
double pos_row5 = per_row5;

int itemRound = 5; // Default value
double itemMargin = per_itemMargin;
double itemHeight = per_itemHeight;
double itemWidth = per_itemWidth;

double itemGrid1X = per_column5;
double itemGrid1Y = per_row6;

double itemGrid2X = per_column6;
double itemGrid2Y = per_row6;

double itemACDCX = per_column5;
double itemACDCY = per_row2;

double itemDCACX = per_column5;
double itemDCACY = per_row7;

double itemACACX = per_column6;
double itemACACY = per_row6;

double itemBatteryDirectionX = per_column2;
double itemBatteryDirectionY = per_row8;

double batteryHeight = per_batteryHeight;
double batteryWidth = per_batteryWidth;
double batteryX = per_column3;
double batteryY = per_row3;

double networkLoadHeight = per_networkLoadHeight;
double networkLoadWidth = per_networkLoadWidth;
double networkLoadX = per_column3;
double networkLoadY = per_row5;

int runMode = 0; // Default value
float batteryLevel = 0.0f;
float networkLoadLevel = 0.0f;


QColor color_path_inactive = QColor(0x4E, 0x56, 0x63);
QColor color_path_active_bypass = QColor(0x00, 0xCD, 0xAE);
QColor color_path_active_battery = QColor(0xE4, 0x7B, 0x3D);
QColor color_network_load = QColor(0x4E, 0x56, 0x63);

QtProgressBar::QtProgressBar(QWidget *parent) : QWidget(parent)
{

}

void QtProgressBar::paintEvent(QPaintEvent *)
{
    updateUI();
}

void QtProgressBar::resizeEvent(QResizeEvent *event)
{
    qDebug()<< event->size();

    const double parentWidth = (double) event->size().width();
    const double parentHeight = (double) event->size().height();

    itemMargin = per_itemMargin * parentHeight;
    itemHeight = per_itemHeight * parentHeight;
    itemWidth = per_itemWidth * parentWidth;

    itemGrid1X = per_column5 * parentWidth;
    itemGrid1Y = per_row6 * parentHeight;

    itemGrid2X = per_column6 * parentWidth;
    itemGrid2Y = per_row6 * parentHeight;

    itemACDCX = per_column5 * parentWidth;
    itemACDCY = per_row2 * parentHeight;

    itemDCACX = per_column5 * parentWidth;
    itemDCACY = per_row7 * parentHeight;

    itemACACX = per_column6 * parentWidth;
    itemACACY = per_row2 * parentHeight;

    itemBatteryDirectionX = per_column2 * parentWidth;
    itemBatteryDirectionY = per_row8 * parentHeight;

    batteryHeight = per_batteryHeight * parentHeight;
    batteryWidth = per_batteryWidth * parentWidth;
    batteryX = per_column3 * parentWidth;
    batteryY = per_row3 * parentHeight;

    networkLoadHeight = per_networkLoadHeight * parentHeight;
    networkLoadWidth = per_networkLoadWidth * parentWidth;
    networkLoadX = per_column3 * parentWidth * 0.98;
    networkLoadY = per_row5 * parentHeight;

    pos_column1 = per_column1 * parentWidth;
    pos_column2 = per_column2 * parentWidth;
    pos_column3 = per_column3 * parentWidth;
    pos_column4 = per_column4 * parentWidth;

    pos_row1 = per_row1 * parentHeight;
    pos_row2 = per_row2 * parentHeight;
    pos_row3 = per_row3 * parentHeight;
    pos_row4 = per_row4 * parentHeight;
    pos_row5 = per_row5 * parentHeight;

    updateUI();
}

void QtProgressBar::updateUI(){
    drawPaths(runMode);
    drawBattery(batteryLevel);
    drawItems(runMode);
    drawNetworkLoad(runMode, networkLoadLevel);
}

void QtProgressBar::drawNetworkLoad(int mode, float percent) {
    QPen pen;
    QStylePainter canvas(this);
    canvas.setPen(pen);
    canvas.setRenderHint(QStylePainter::Antialiasing);

    percent = 0.9;

    mode = 0;

    int startAngle = 0 * 16;
    int spanAngle = -360 * 16 * percent;

    switch (mode) {
    case 2: {
        pen.setBrush(color_path_inactive);
        pen.setCapStyle(Qt::SquareCap);
        pen.setJoinStyle(Qt::RoundJoin);
        //canvas.setBrush(Qt::blue);

        QRectF loadBound = getItemRectF(networkLoadX, networkLoadY, networkLoadWidth, networkLoadWidth);
        canvas.drawArc(loadBound, -90, (int) percent*0.0);

        pen.setWidth(5);
        pen.setCapStyle(Qt::SquareCap);
        pen.setJoinStyle(Qt::RoundJoin);
        canvas.setPen(color_network_load);
        canvas.setBrush(color_network_load);
        canvas.drawEllipse(QPoint(loadBound.center().x(), loadBound.center().y() * 0.9),(int)(loadBound.height() / 1.3 + itemMargin),(int)(loadBound.height() / 1.3 + itemMargin));

        canvas.setPen(QColor(0x36, 0x36, 0x4C));
        canvas.setBrush(QColor(0x36, 0x36, 0x4C));
        canvas.drawEllipse(QPoint(loadBound.center().x(), loadBound.center().y() * 0.9),(int)(loadBound.height() / 1.7),(int)(loadBound.height() / 1.7));

        canvas.setPen(QColor(0x36, 0x36, 0x4C));
        canvas.setBrush(QColor(0x00, 0xCD, 0xAE));
        canvas.drawEllipse(QPoint(loadBound.center().x(), loadBound.center().y() * 0.9),(int)(loadBound.height() / 2),(int)(loadBound.height() / 2));

        break;
    }
    default: {
        pen.setBrush(color_path_inactive);
        pen.setCapStyle(Qt::SquareCap);
        pen.setJoinStyle(Qt::RoundJoin);

        QRectF loadBound(networkLoadX, networkLoadY, networkLoadWidth, networkLoadWidth);

        pen.setWidth(5);
        pen.setCapStyle(Qt::SquareCap);
        pen.setJoinStyle(Qt::RoundJoin);
        canvas.setPen(color_network_load);
        canvas.setBrush(color_network_load);
        canvas.drawEllipse(QPoint(loadBound.center().x(), loadBound.center().y() * 0.9),(int)(loadBound.width() / 1.3 + itemMargin),(int)(loadBound.height() / 1.3 + itemMargin));

        canvas.setPen(QColor(0x36, 0x36, 0x4C));
        canvas.setBrush(QColor(0x36, 0x36, 0x4C));
        canvas.drawEllipse(QPoint(loadBound.center().x(), loadBound.center().y() * 0.9),(int)(loadBound.width() / 1.7),(int)(loadBound.height() / 1.7));

        canvas.setPen(QColor(0x36, 0x36, 0x4C));
        canvas.setBrush(QColor(0x00, 0xCD, 0xAE));
        canvas.drawEllipse(QPoint(loadBound.center().x(), loadBound.center().y() * 0.9),(int)(loadBound.width() / 2),(int)(loadBound.height() / 2));

        canvas.setPen(Qt::white);
        canvas.setFont(QFont("arial", networkLoadWidth / 5, QFont::Bold));
        canvas.drawText(loadBound , Qt::AlignHCenter, "00 %");

        QRectF loadBound2(networkLoadX * 0.935, networkLoadY * 0.84, networkLoadWidth * 1.4, networkLoadWidth * 1.4);

        canvas.setPen(QPen((QColor(0x00, 0xCD, 0xAE)), networkLoadWidth / 4.8));

        canvas.drawArc(loadBound2, startAngle, spanAngle);

    }
    }
}

void QtProgressBar::drawPaths(int mode) {

    QPen pen;
    pen.setWidth(8);
    QStylePainter canvas(this);
    canvas.setPen(pen);
    canvas.setRenderHint(QStylePainter::Antialiasing);

    float lineWith = itemWidth / 5.0;
    float lineHalf = lineWith / 2.0;

    mode = 0;

    switch (mode) {
    case 0: {   //only bypass
        // Grid to Battery lines
        canvas.setPen(QPen(color_path_inactive, 8)); //inactive
        canvas.drawLine(pos_column1, pos_row1, pos_column1, pos_row4 + lineHalf);
        canvas.drawLine(pos_column1 - lineHalf + 10, pos_row4, pos_column3 * 0.99, pos_row4);

        // Battery to Load lines
        canvas.setPen(QPen(color_path_inactive, 8)); //inactive
        canvas.drawLine(pos_column1, pos_row4 - lineHalf, pos_column1, pos_row5);
        canvas.drawLine(pos_column1, pos_row5, pos_column3 * 0.9, pos_row5);

        // Grid to Load lines
        canvas.setPen(QPen(color_path_active_bypass, 8)); //bypass active
        canvas.drawLine(pos_column3 * 1.4, pos_row5, pos_column4 + lineHalf - 5, pos_row5);
        canvas.drawLine(pos_column4, pos_row5 + lineHalf - 7, pos_column4, pos_row1);
        break;
    }
    case 1: {   //only battery
        // Grid to Battery lines
        canvas.setPen(QPen(color_path_inactive, 8)); //inactive
        canvas.drawLine(pos_column1, pos_row1, pos_column1, pos_row4 + lineHalf);

        // Battery to Load lines
        canvas.setPen(QPen(color_path_active_battery, 8)); //battery active
        canvas.drawLine(pos_column1 - lineHalf * 0.05, pos_row4, pos_column3 * 0.99, pos_row4);
        canvas.drawLine(pos_column1, pos_row4 - lineHalf * 0.01, pos_column1, pos_row5);
        canvas.drawLine(pos_column1, pos_row5, pos_column3 * 0.9, pos_row5);

        // Grid to Load lines
        canvas.setPen(QPen(color_path_inactive, 8)); //inactive
        canvas.drawLine(pos_column3 * 1.4, pos_row5, pos_column4 + lineHalf - 5, pos_row5);
        canvas.drawLine(pos_column4, pos_row5 + lineHalf - 7, pos_column4, pos_row1);
        break;
    }
    case 2: { //off

        // Grid to Battery lines
        canvas.setPen(QPen(color_path_inactive, 8)); //inactive
        canvas.drawLine(pos_column1, pos_row1, pos_column1, pos_row4 + lineHalf);
        canvas.drawLine(pos_column1 - lineHalf + 10, pos_row4, pos_column3 * 0.99, pos_row4);

        // Battery to Load lines
        canvas.drawLine(pos_column1, pos_row4 - lineHalf, pos_column1, pos_row5);
        canvas.drawLine(pos_column1, pos_row5, pos_column3 * 0.9, pos_row5);
        canvas.drawLine(pos_column1 - lineHalf + 10, pos_row4, pos_column3 * 0.99, pos_row4);

        // Grid to Load lines
        canvas.drawLine(pos_column3 * 1.4, pos_row5, pos_column4 + lineHalf - 5, pos_row5);
        canvas.drawLine(pos_column4, pos_row5 + lineHalf - 7, pos_column4, pos_row1);
        break;
    }
    case 3: {   //batt charge, bypass active
        // Battery to Load lines
        canvas.setPen(QPen(color_path_inactive, 8)); //inactive
        canvas.drawLine(pos_column1, pos_row4 - lineHalf, pos_column1, pos_row5);
        canvas.drawLine(pos_column1, pos_row5, pos_column3 * 0.9, pos_row5);

        // Grid to Battery lines
        canvas.setPen(QPen(color_path_active_battery, 8)); //battery active
        canvas.drawLine(pos_column1, pos_row1, pos_column1, pos_row4 + lineHalf * 0.1);
        canvas.drawLine(pos_column1 - lineHalf + 10, pos_row4, pos_column3 * 0.99, pos_row4);

        // Grid to Load lines
        canvas.setPen(QPen(color_path_active_bypass, 8)); //bypass active
        canvas.drawLine(pos_column3 * 1.4, pos_row5, pos_column4 + lineHalf - 5, pos_row5);
        canvas.drawLine(pos_column4, pos_row5 + lineHalf - 7, pos_column4, pos_row1);
        break;
    }
    }

}


void QtProgressBar::drawItems(int mode) {

    QPen pen;
    pen.setWidth(2);
    QStylePainter canvas(this);
    canvas.setPen(pen);
    canvas.setRenderHint(QStylePainter::Antialiasing);

    QRectF itemG1 = getItemRectF(itemGrid1X, itemGrid1Y, itemWidth, itemHeight);
    QRectF itemG2 = getItemRectF(itemGrid2X, itemGrid2Y, itemWidth, itemHeight);
    QRectF itemACDC = getItemRectF(itemACDCX, itemACDCY, itemWidth, itemHeight);
    QRectF itemDCAC = getItemRectF(itemDCACX, itemDCACY, itemWidth, itemHeight);
    QRectF itemACAC = getItemRectF(itemACACX, itemACACY, itemWidth, itemHeight);
    QRectF itemBD = getItemRectF(itemBatteryDirectionX, itemBatteryDirectionY, itemWidth, itemHeight);

    mode = 0;

    switch (mode) {
    case 0: {               //  Only bypass
        //  active items

        canvas.setPen(QPen(QColor(0x00, 0xCD, 0xAE), 4));
        canvas.setBrush(QColor(0x46, 0x4E, 0x5B));
        canvas.drawEllipse(QPoint(itemG2.center().x(), itemG2.center().y()),(int)(itemG2.width() * 0.5 + itemMargin),(int)(itemG2.height() * 0.5 + itemMargin));
        canvas.drawRoundedRect(itemACAC, itemRound, itemRound, Qt::AbsoluteSize);

        //  inactive items

        canvas.setPen(QPen(QColor(0x4E, 0x56, 0x63), 4));
        canvas.setBrush(QColor(0x46, 0x4E, 0x5B));
        canvas.drawEllipse(QPoint(itemG1.center().x(), itemG1.center().y()),(int)(itemG1.width() * 0.5 + itemMargin),(int)(itemG1.height() * 0.5 + itemMargin));
        canvas.drawRoundedRect(itemACDC, itemRound, itemRound, Qt::AbsoluteSize);
        canvas.drawRoundedRect(itemBD, itemRound, itemRound, Qt::AbsoluteSize);
        canvas.drawRoundedRect(itemDCAC, itemRound, itemRound, Qt::AbsoluteSize);

//        canvas.drawEllipse(QPoint(itemG1.center().x(), itemG1.center().y()));

        break;
    }
    case 1: {               // only battery
        // Active items

        canvas.setPen(QPen(QColor(0xE4, 0x7B, 0x3D), 4));
        canvas.setBrush(QColor(0x46, 0x4E, 0x5B));
        canvas.drawRoundedRect(itemBD, itemRound, itemRound, Qt::AbsoluteSize);
        canvas.drawRoundedRect(itemDCAC, itemRound, itemRound, Qt::AbsoluteSize);

        // inactive items

        canvas.setPen(QPen(QColor(0x4E, 0x56, 0x63), 4));
        canvas.setBrush(QColor(0x46, 0x4E, 0x5B));
        canvas.drawEllipse(QPoint(itemG1.center().x(), itemG1.center().y()),(int)(itemG1.width() * 0.5 + itemMargin),(int)(itemG1.height() * 0.5 + itemMargin));
        canvas.drawRoundedRect(itemACDC, itemRound, itemRound, Qt::AbsoluteSize);
        canvas.drawEllipse(QPoint(itemG2.center().x(), itemG2.center().y()),(int)(itemG2.width() * 0.5 + itemMargin),(int)(itemG2.height() * 0.5 + itemMargin));
        canvas.drawRoundedRect(itemACAC, itemRound, itemRound, Qt::AbsoluteSize);
        break;
    }
    case 2: {               // offline

        // inactive items

        canvas.setPen(QPen(QColor(0x4E, 0x56, 0x63), 4));
        canvas.setBrush(QColor(0x46, 0x4E, 0x5B));
        canvas.drawRoundedRect(itemBD, itemRound, itemRound, Qt::AbsoluteSize);
        canvas.drawRoundedRect(itemDCAC, itemRound, itemRound, Qt::AbsoluteSize);
        canvas.drawEllipse(QPoint(itemG1.center().x(), itemG1.center().y()),(int)(itemG1.width() * 0.5 + itemMargin),(int)(itemG1.height() * 0.5 + itemMargin));
        canvas.drawRoundedRect(itemACDC, itemRound, itemRound, Qt::AbsoluteSize);
        canvas.drawEllipse(QPoint(itemG2.center().x(), itemG2.center().y()),(int)(itemG2.width() * 0.5 + itemMargin),(int)(itemG2.height() * 0.5 + itemMargin));
        canvas.drawRoundedRect(itemACAC, itemRound, itemRound, Qt::AbsoluteSize);

        break;
    }
    case 3: {               // batt charge, bypass active
        // Active items

        // battery
        canvas.setPen(QPen(QColor(0xE4, 0x7B, 0x3D), 4));
        canvas.setBrush(QColor(0x46, 0x4E, 0x5B));
        canvas.drawEllipse(QPoint(itemG1.center().x(), itemG1.center().y()),(int)(itemG1.width() * 0.5 + itemMargin),(int)(itemG1.height() * 0.5 + itemMargin));
        canvas.drawRoundedRect(itemACDC, itemRound, itemRound, Qt::AbsoluteSize);
        canvas.drawRoundedRect(itemBD, itemRound, itemRound, Qt::AbsoluteSize);

        // bypass
        canvas.setPen(QPen(QColor(0x00, 0xCD, 0xAE), 4));
        canvas.setBrush(QColor(0x46, 0x4E, 0x5B));
        canvas.drawEllipse(QPoint(itemG2.center().x(), itemG2.center().y()),(int)(itemG2.width() * 0.5 + itemMargin),(int)(itemG2.height() * 0.5 + itemMargin));
        canvas.drawRoundedRect(itemACAC, itemRound, itemRound, Qt::AbsoluteSize);

        // inactive items

        canvas.setPen(QPen(QColor(0x4E, 0x56, 0x63), 4));
        canvas.setBrush(QColor(0x46, 0x4E, 0x5B));
        canvas.drawRoundedRect(itemDCAC, itemRound, itemRound, Qt::AbsoluteSize);

        break;
    }
    }
    canvas.setPen(Qt::white);
    canvas.setFont(QFont("arial", sqrt(itemWidth * itemHeight) * 0.5, QFont::Light));
    canvas.drawText(itemG1, Qt::AlignCenter, "~");
    canvas.drawText(itemG2, Qt::AlignCenter, "~");
    //    canvas.drawText(itemACAC, Qt::AlignTop, "~");
    //    canvas.drawText(itemACAC, Qt::AlignCenter, "/");
    //    canvas.drawText(itemACAC, Qt::AlignBottom, "   ~");
}

QRectF QtProgressBar::getItemRectF(double x, double y, double w, double h) {
    return QRectF(x, y, w, h);
}

void QtProgressBar::drawBattery(float percent) {

    QPen pen;
    pen.setColor(QColor(0xB3, 0xB3, 0xB3));
    pen.setWidth(4);
    QStylePainter canvas(this);
    canvas.setPen(pen);
    canvas.setRenderHint(QStylePainter::Antialiasing);

    QPalette bgpal = palette();
    bgpal.setColor (QPalette::Window, QColor(0x36, 0x36, 0x4C));
    setPalette(bgpal);

    QRectF bnd = getItemRectF(batteryX, batteryY, batteryWidth, batteryHeight);

    //  pen.setColor(getContext().getResources().getColor(R.color.theme_color_window_background));
    canvas.drawRoundedRect(bnd, itemRound, itemRound);

    //pen.setColor(QColor(0x36, 0x45, 0x4B));
    //    pen.setWidth(2);
    //    canvas.setPen(QColor(0xE4, 0x7B, 0x3D));
    //    canvas.drawRoundedRect(bnd, itemRound, itemRound);
    float bi = bnd.width() / 3;
    QRectF biR = QRectF(bnd.left()+ bi, bnd.top() * 0.97 - itemMargin * 2.0, bnd.right() * 0.155 - bi, bnd.top() * 0.1);

    canvas.drawRoundRect(biR, itemRound, itemRound);

    float batteryItemMargin = batteryHeight * 0.026;

    float H = (batteryHeight / 6.0) + batteryItemMargin;
    float X0 = bnd.left() + batteryItemMargin;
    float Y0 = bnd.bottom() - H;
    float X1 = bnd.right() * 0.21 - batteryItemMargin;
    float Y1 = bnd.bottom() * 0.12 - batteryItemMargin;

    int value = 0;

    percent = 0.5;

    int percentint = percent * 100;

    if (percent > 1.0)
        percent = 1.0;
    if (percent < 0.0)
        percent = 0.0;

    if (0.0 <= percent && percent < 0.2)
        value = 1;
    else if (0.2 <= percent && percent < 0.4)
        value = 2;
    else if (0.4 <= percent && percent < 0.6)
        value = 3;
    else if (0.6 <= percent && percent < 0.8)
        value = 4;
    else if (0.8 <= percent && percent <= 1.0)
        value = 5;
    else
        value = 0;

    for (int i = 0; i < value; i++) {


        canvas.setPen(QColor(0x31, 0xA5, 0x00));
        canvas.setBrush(QColor(0x31, 0xA5, 0x00));

        QRectF biR2 = QRectF(X0, Y0, X1, Y1);

        canvas.drawRoundedRect(biR2, itemRound, itemRound);

        Y0 -= H;
        Y1 -= H / 30;
    }

    canvas.setPen(QColor(0x93, 0xA2, 0xB5));
    canvas.setFont(QFont("arial", sqrt(batteryWidth * batteryHeight) * 0.1, QFont::Bold));
    canvas.drawText(bnd.center().x() * 0.82, bnd.center().y() * 0.22, "BATTERY LEVEL");
    canvas.setFont(QFont("arial", sqrt(batteryWidth * batteryHeight) * 0.15, QFont::Bold));
    canvas.drawText(bnd.center().x() * 0.93, bnd.center().y() * 0.35, QString("%1 %").arg(percent*100.0));

    //canvas.drawText( "00 %d", (int)(percent * 100) , bnd.center().x() * 0.94, bnd.center().y() * 0.35);

    //    canvas.setPen(Qt::white);
    //    canvas.setFont(QFont("arial", 24, QFont::Bold));
    //    canvas.drawText(("%% %s",(percent * 100)), bnd.center().x(), bnd.top() - itemMargin * 5.0);

    //    canvas.drawText(per_column2, per_row1, "deneme");


    //canvas.drawText(("%% %s", (int)value((int) (percent * 100.0))), bnd.center().x(), bnd.top() - itemMargin * 5.0);


    //    paint.setColor(Color.RED);
    //    paint.setTextAlign(Paint.Align.CENTER);
    //    paint.setTextSize(85.0f);
    //    canvas.drawText(String.format("%% %s", String.valueOf((int) (percent * 100.0f))),
    //                    bnd.centerX(), bnd.top - itemMargin * 5.0f, paint);

}



int QtProgressBar::getRunMode() {
    return runMode;
}

void QtProgressBar::setRunningMode(int mode) {
    runMode = mode;
    // TODO: update uı
}

float QtProgressBar::getBatteryLevel() {
    return batteryLevel;
}

void QtProgressBar::setBatteryLevel(float mbatteryLevel) {
    batteryLevel = mbatteryLevel;
    // TODO: update uı
}

float QtProgressBar::getNetworkLoadLevel() {
    return networkLoadLevel;
}

void QtProgressBar::setNetworkLoadLevel(float mnetworkLoadLevel) {
    networkLoadLevel = mnetworkLoadLevel;
    // TODO: update uı
}

