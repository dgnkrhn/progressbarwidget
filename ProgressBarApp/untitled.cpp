#include "mainwindow.h"
#include "ui_mainwindow.h"

// Default per items
double per_column1 = 0.1;
double per_column2 = 0.3;
double per_column3 = 0.5;
double per_column4 = 0.9;

double per_row1 = 0.1;
double per_row2 = 0.35;
double per_row3 = 0.47;
double per_row4 = 0.6;
double per_row5 = 0.85;

double per_itemMargin = 0.009;
double per_itemHeight = 0.12;
double per_itemWidth = 0.08;

double per_batteryHeight = 0.4;
double per_batteryWidth = 0.13;

double per_networkLoadHeight = 0.25;
double per_networkLoadWidth = 0.15;

int parentWidth;
int parentHeight;

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

int itemRound = 15; // Default value
double itemMargin = per_itemMargin;
double itemHeight = per_itemHeight;
double itemWidth = per_itemWidth;

double itemGrid1X = per_column1;
double itemGrid1Y = per_row1;

double itemGrid2X = per_column4;
double itemGrid2Y = per_row1;

double itemACDCX = per_column1;
double itemACDCY = per_row2;

double itemDCACX = per_column1;
double itemDCACY = per_row5;

double itemACACX = per_column4;
double itemACACY = per_row2;

double itemBatteryDirectionX = per_column2;
double itemBatteryDirectionY = per_row4;

double batteryHeight = per_batteryHeight;
double batteryWidth = per_batteryWidth;
double batteryX = per_column3;
double batteryY = per_row3;

double networkLoadHeight = per_networkLoadHeight;
double networkLoadWidth = per_networkLoadWidth;
double networkLoadX = per_column3;
double networkLoadY = per_row5;

int runMode = 0; // Default value
float batteryLevel = 0.0;
float networkLoadLevel = 0.0;

QColor color_path_inactive = QColor("0x3a404d");
QColor color_path_active_bypass = QColor("0x06CAAC");
QColor color_path_active_battery = QColor("0xe17b15");
QColor color_network_load = QColor("0x35a9a9");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qApp->setStyle("fusion");

    ui->setupUi(this);

    //    QGradientStops gradientPoints;
    //    gradientPoints << QGradientStop(0, Qt::green) << QGradientStop(0.5, Qt::yellow) << QGradientStop(1, Qt::red);

    //    QPalette p1;
    //    p1.setBrush(QPalette::Base, Qt::lightGray);
    //    p1.setColor(QPalette::Text, Qt::black);
    //    p1.setColor(QPalette::Shadow, Qt::green);
    //    //p1.setBrush(QPalette::AlternateBase, Qt::blue);
    //    ui->RoundBar1->setPalette(p1);
    //    ui->RoundBar1->setNullPosition(QRoundProgressBar::PositionRight);
    //    ui->RoundBar1->setBarStyle(QRoundProgressBar::StyleLine);
    //    ui->RoundBar1->setDataColors(gradientPoints);
    //    ui->RoundBar1->setOutlinePenWidth(15);
    //    ui->RoundBar1->setDataPenWidth(15);
    //    ui->RoundBar1->setDecimals(0);
    //    connectToSlider(ui->RoundBar1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectToSlider(QRoundProgressBar *bar)
{
    bar->setRange(ui->Slider->minimum(), ui->Slider->maximum());
    bar->setValue(ui->Slider->value());
    connect(ui->Slider, SIGNAL(valueChanged(int)), bar, SLOT(setValue(int)));
}

void MainWindow::paintEvent(QPaintEvent *)
{
    //QPainter painter(this);
    //p.setPen(QPen(QColor(0x31, 0x36, 0x3b)));
    //p.setBrush(QBrush(QColor(0x31, 0x36, 0x3b)));

    //QStylePainter painter(ui->frame);
    QPen pen;
    pen.setWidth(5);
    pen.setBrush(Qt::blue);

    //    painter.setRenderHint(QPainter::Antialiasing);
    //    painter.setPen(pen);
    //    painter.drawRect(20, 20, 100, 100);

    //    painter.setRenderHint(QPainter::Antialiasing);
    //    painter.setPen(Qt::darkBlue);
    //    painter.setBrush(Qt::darkBlue);
    //    painter.drawLine(30, 30, 100, 100);

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    qDebug()<< event->size();

    parentWidth = event->size().width();
    parentHeight = event->size().height();

    itemMargin = per_itemMargin * (double) parentHeight;
    itemHeight = per_itemHeight * parentHeight;
    itemWidth = per_itemWidth * parentWidth;

    itemGrid1X = per_column1 * parentWidth;
    itemGrid1Y = per_row1 * parentHeight;

    itemGrid2X = per_column4 * parentWidth;
    itemGrid2Y = per_row1 * parentHeight;

    itemACDCX = per_column1 * parentWidth;
    itemACDCY = per_row2 * parentHeight;

    itemDCACX = per_column1 * parentWidth;
    itemDCACY = per_row5 * parentHeight;

    itemACACX = per_column4 * parentWidth;
    itemACACY = per_row2 * parentHeight;

    itemBatteryDirectionX = per_column2 * parentWidth;
    itemBatteryDirectionY = per_row4 * parentHeight;

    batteryHeight = per_batteryHeight * parentHeight;
    batteryWidth = per_batteryWidth * parentWidth;
    batteryX = per_column3 * parentWidth;
    batteryY = per_row3 * parentHeight;

    networkLoadHeight = per_networkLoadHeight * parentHeight;
    networkLoadWidth = per_networkLoadWidth * parentWidth;
    networkLoadX = per_column3 * parentWidth;
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
}

void MainWindow::updateUI(){
    QStylePainter canvas(ui->frame);
    drawPaths(runMode, canvas);
    drawBattery(batteryLevel, canvas);
    drawItems(runMode, canvas);
    drawNetworkLoad(runMode, networkLoadLevel, canvas);
}

void MainWindow::drawNetworkLoad(int mode, float percent) {
    switch (mode) {
    case 2: {

        QPen pen;
        pen.setWidth(5);
        pen.setBrush(Qt::blue);


        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_inactive));
        paint.setStrokeWidth(30.0f);
        paint.setStyle(Paint.Style.STROKE);

        RectF loadBound = getItemRectF(networkLoadX, networkLoadY, networkLoadWidth, networkLoadWidth);
        canvas.drawArc(loadBound, -90.0f, 0.0f * percent, false, paint);

        paint.setStrokeWidth(5.0f);
        canvas.drawCircle(loadBound.centerX(), loadBound.centerY(), loadBound.height() / 1.9f + itemMargin, paint);

        paint.setStyle(Paint.Style.FILL);
        canvas.drawCircle(loadBound.centerX(), loadBound.centerY(), loadBound.height() / 2.5f, paint);

        paint.setColor(Color.RED);
        paint.setTextAlign(Paint.Align.CENTER);
        paint.setTextSize(85.0f);
        canvas.drawText("Off",
                        loadBound.centerX(), loadBound.centerY() + 3.0f * itemMargin, paint);
        break;
    }
    default: {
        paint.setColor(getContext().getResources().getColor(R.color.graphic_network_load));
        paint.setStrokeWidth(30.0f);
        paint.setStyle(Paint.Style.STROKE);

        RectF loadBound = getItemRectF(networkLoadX, networkLoadY, networkLoadWidth, networkLoadWidth);
        canvas.drawArc(loadBound, -90.0f, 360.0f * percent, false, paint);

        paint.setStrokeWidth(5.0f);
        canvas.drawCircle(loadBound.centerX(), loadBound.centerY(), loadBound.height() / 1.9f + itemMargin, paint);

        paint.setStyle(Paint.Style.FILL);
        canvas.drawCircle(loadBound.centerX(), loadBound.centerY(), loadBound.height() / 2.5f, paint);

        paint.setColor(Color.BLACK);
        paint.setTextAlign(Paint.Align.CENTER);
        paint.setTextSize(85.0f);
        canvas.drawText(String.format("%% %s", String.valueOf((int) (percent * 100.0f))),
                        loadBound.centerX(), loadBound.centerY() + 3.0f * itemMargin, paint);
    }
    }
}

void MainWindow::drawPaths(int mode) {
    float lineWith = itemWidth / 5.0f;
    float lineHalf = lineWith / 2.0f;

    paint.setColor(getContext().getResources().getColor(R.color.graphic_path_inactive));
    paint.setStrokeWidth(lineWith);

    switch (mode) {
    case 0: {
        // Battery to Load lines
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_inactive));
        canvas.drawLine(pos_column1, pos_row4 - lineHalf, pos_column1, pos_row5, paint);
        canvas.drawLine(pos_column1, pos_row5, pos_column3, pos_row5, paint);

        // Grid to Battery lines
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_inactive));
        canvas.drawLine(pos_column1, pos_row1, pos_column1, pos_row4 + lineHalf, paint);
        canvas.drawLine(pos_column1 - lineHalf, pos_row4, pos_column3, pos_row4, paint);

        // Grid to Load lines
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_active_bypass));
        canvas.drawLine(pos_column3, pos_row5, pos_column4 + lineHalf, pos_row5, paint);
        canvas.drawLine(pos_column4, pos_row5 + lineHalf, pos_column4, pos_row1, paint);
        break;
    }
    case 1: {
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_inactive));
        // Grid to Battery lines
        canvas.drawLine(pos_column1, pos_row1, pos_column1, pos_row4 + lineHalf, paint);

        // Battery to Load lines
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_active_battery));
        canvas.drawLine(pos_column1 - lineHalf, pos_row4, pos_column3, pos_row4, paint);
        canvas.drawLine(pos_column1, pos_row4 - lineHalf, pos_column1, pos_row5, paint);
        canvas.drawLine(pos_column1, pos_row5, pos_column3, pos_row5, paint);

        // Grid to Load lines
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_inactive));
        canvas.drawLine(pos_column3, pos_row5, pos_column4 + lineHalf, pos_row5, paint);
        canvas.drawLine(pos_column4, pos_row5 + lineHalf, pos_column4, pos_row1, paint);
        break;
    }
    case 2: {
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_inactive));

        // Grid to Battery lines
        canvas.drawLine(pos_column1, pos_row1, pos_column1, pos_row4 + lineHalf, paint);
        canvas.drawLine(pos_column1 - lineHalf, pos_row4, pos_column3, pos_row4, paint);

        // Battery to Load lines
        canvas.drawLine(pos_column1, pos_row4 - lineHalf, pos_column1, pos_row5, paint);
        canvas.drawLine(pos_column1, pos_row5, pos_column3, pos_row5, paint);

        // Grid to Load lines
        canvas.drawLine(pos_column3, pos_row5, pos_column4 + lineHalf, pos_row5, paint);
        canvas.drawLine(pos_column4, pos_row5 + lineHalf, pos_column4, pos_row1, paint);
        break;
    }
    case 3: {
        // Battery to Load lines
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_active_battery));
        canvas.drawLine(pos_column1, pos_row4 - lineHalf, pos_column1, pos_row5, paint);
        canvas.drawLine(pos_column1, pos_row5, pos_column3, pos_row5, paint);

        // Grid to Battery lines
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_active_battery));
        canvas.drawLine(pos_column1, pos_row1, pos_column1, pos_row4 + lineHalf, paint);
        canvas.drawLine(pos_column1 - lineHalf, pos_row4, pos_column3, pos_row4, paint);

        // Grid to Load lines
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_inactive));
        canvas.drawLine(pos_column3, pos_row5, pos_column4 + lineHalf, pos_row5, paint);
        canvas.drawLine(pos_column4, pos_row5 + lineHalf, pos_column4, pos_row1, paint);
        break;
    }
    }

}

void MainWindow::drawItems(int mode) {
    RectF itemG1 = getItemRectF(itemGrid1X, itemGrid1Y, itemWidth, itemHeight);
    Bitmap iconG1 = BitmapFactory.decodeResource(getResources(), R.drawable.grid);

    RectF itemG2 = getItemRectF(itemGrid2X, itemGrid2Y, itemWidth, itemHeight);
    Bitmap iconG2 = BitmapFactory.decodeResource(getResources(), R.drawable.grid);

    RectF itemACDC = getItemRectF(itemACDCX, itemACDCY, itemWidth, itemHeight);
    RectF itemBoundACDC = new RectF(itemACDC.left - itemMargin, itemACDC.top - itemMargin, itemACDC.right + itemMargin, itemACDC.bottom + itemMargin);
    Bitmap iconACDC = BitmapFactory.decodeResource(getResources(), R.drawable.acdc);

    RectF itemDCAC = getItemRectF(itemDCACX, itemDCACY, itemWidth, itemHeight);
    RectF itemBoundDCAC = new RectF(itemDCAC.left - itemMargin, itemDCAC.top - itemMargin, itemDCAC.right + itemMargin, itemDCAC.bottom + itemMargin);
    Bitmap iconDCAC = BitmapFactory.decodeResource(getResources(), R.drawable.dcac);

    RectF itemACAC = getItemRectF(itemACACX, itemACACY, itemWidth, itemHeight);
    RectF itemBoundACAC = new RectF(itemACAC.left - itemMargin, itemACAC.top - itemMargin, itemACAC.right + itemMargin, itemACAC.bottom + itemMargin);
    Bitmap iconACAC = BitmapFactory.decodeResource(getResources(), R.drawable.acac);

    RectF itemBD = getItemRectF(itemBatteryDirectionX, itemBatteryDirectionY, itemWidth, itemHeight);
    RectF itemBoundBD = new RectF(itemBD.left - itemMargin, itemBD.top - itemMargin, itemBD.right + itemMargin, itemBD.bottom + itemMargin);
    Bitmap iconBDRight = BitmapFactory.decodeResource(getResources(), R.drawable.right_arrow);
    Bitmap iconBDLeft = BitmapFactory.decodeResource(getResources(), R.drawable.left_arrow);

    switch (mode) {
    case 0: {
        // Active battery items
        paint.setStyle(Paint.Style.FILL);
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_inactive));

        canvas.drawCircle(itemGrid1X, itemGrid1Y, itemHeight / 2.0f, paint);
        canvas.drawBitmap(iconG1, null, itemG1, paint);

        canvas.drawRoundRect(itemACDC, itemRound, itemRound, paint);
        canvas.drawBitmap(iconACDC, null, itemACDC, paint);

        canvas.drawRoundRect(itemBD, itemRound, itemRound, paint);
        canvas.drawBitmap(iconBDRight, null, itemBD, paint);

        // Active battery items bound
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_inactive));
        paint.setStyle(Paint.Style.STROKE);
        paint.setStrokeWidth(5.0f);

        canvas.drawCircle(itemGrid1X, itemGrid1Y, itemHeight / 2.0f + itemMargin, paint);
        canvas.drawRoundRect(itemBoundACDC, itemRound, itemRound, paint);
        canvas.drawRoundRect(itemBoundBD, itemRound, itemRound, paint);

        // Active bypass items
        paint.setStyle(Paint.Style.FILL);
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_active_bypass));

        canvas.drawCircle(itemGrid2X, itemGrid2Y, itemHeight / 2.0f, paint);
        canvas.drawBitmap(iconG2, null, itemG2, paint);

        canvas.drawRoundRect(itemACAC, itemRound, itemRound, paint);
        canvas.drawBitmap(iconACAC, null, itemACAC, paint);

        // Active bypass items bound
        paint.setStyle(Paint.Style.STROKE);
        paint.setStrokeWidth(5.0f);

        canvas.drawCircle(itemGrid2X, itemGrid2Y, itemHeight / 2.0f + itemMargin, paint);
        canvas.drawRoundRect(itemBoundACAC, itemRound, itemRound, paint);

        // Inactive items
        paint.setStyle(Paint.Style.FILL);
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_inactive));

        canvas.drawRoundRect(itemDCAC, itemRound, itemRound, paint);
        canvas.drawBitmap(iconDCAC, null, itemDCAC, paint);

        // Active bypass items bound
        paint.setStyle(Paint.Style.STROKE);
        paint.setStrokeWidth(5.0f);

        canvas.drawRoundRect(itemBoundDCAC, itemRound, itemRound, paint);
        break;
    }
    case 1: {
        // Active battery items
        paint.setStyle(Paint.Style.FILL);
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_active_battery));

        canvas.drawRoundRect(itemBD, itemRound, itemRound, paint);
        canvas.drawBitmap(iconBDLeft, null, itemBD, paint);

        canvas.drawRoundRect(itemDCAC, itemRound, itemRound, paint);
        canvas.drawBitmap(iconDCAC, null, itemDCAC, paint);

        // Active battery items bound
        paint.setStyle(Paint.Style.STROKE);
        paint.setStrokeWidth(5.0f);

        canvas.drawRoundRect(itemBoundBD, itemRound, itemRound, paint);
        canvas.drawRoundRect(itemBoundDCAC, itemRound, itemRound, paint);

        // Inactive items
        paint.setStyle(Paint.Style.FILL);
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_inactive));

        canvas.drawCircle(itemGrid1X, itemGrid1Y, itemHeight / 2.0f, paint);
        canvas.drawBitmap(iconG1, null, itemG1, paint);

        canvas.drawRoundRect(itemACDC, itemRound, itemRound, paint);
        canvas.drawBitmap(iconACDC, null, itemACDC, paint);

        canvas.drawCircle(itemGrid2X, itemGrid2Y, itemHeight / 2.0f, paint);
        canvas.drawBitmap(iconG2, null, itemG2, paint);

        canvas.drawRoundRect(itemACAC, itemRound, itemRound, paint);
        canvas.drawBitmap(iconACAC, null, itemACAC, paint);


        // Active bypass items bound
        paint.setStyle(Paint.Style.STROKE);
        paint.setStrokeWidth(5.0f);

        canvas.drawCircle(itemGrid1X, itemGrid1Y, itemHeight / 2.0f + itemMargin, paint);
        canvas.drawRoundRect(itemBoundACDC, itemRound, itemRound, paint);
        canvas.drawCircle(itemGrid2X, itemGrid2Y, itemHeight / 2.0f + itemMargin, paint);
        canvas.drawRoundRect(itemBoundACAC, itemRound, itemRound, paint);
        break;
    }
    case 2: {
        // Inactive items
        paint.setStyle(Paint.Style.FILL);
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_inactive));

        canvas.drawRoundRect(itemBD, itemRound, itemRound, paint);
        canvas.drawBitmap(iconBDLeft, null, itemBD, paint);

        canvas.drawRoundRect(itemDCAC, itemRound, itemRound, paint);
        canvas.drawBitmap(iconDCAC, null, itemDCAC, paint);

        canvas.drawCircle(itemGrid1X, itemGrid1Y, itemHeight / 2.0f, paint);
        canvas.drawBitmap(iconG1, null, itemG1, paint);

        canvas.drawRoundRect(itemACDC, itemRound, itemRound, paint);
        canvas.drawBitmap(iconACDC, null, itemACDC, paint);

        canvas.drawCircle(itemGrid2X, itemGrid2Y, itemHeight / 2.0f, paint);
        canvas.drawBitmap(iconG2, null, itemG2, paint);

        canvas.drawRoundRect(itemACAC, itemRound, itemRound, paint);
        canvas.drawBitmap(iconACAC, null, itemACAC, paint);


        // Active bypass items bound
        paint.setStyle(Paint.Style.STROKE);
        paint.setStrokeWidth(5.0f);

        canvas.drawRoundRect(itemBoundBD, itemRound, itemRound, paint);
        canvas.drawRoundRect(itemBoundDCAC, itemRound, itemRound, paint);
        canvas.drawCircle(itemGrid1X, itemGrid1Y, itemHeight / 2.0f + itemMargin, paint);
        canvas.drawRoundRect(itemBoundACDC, itemRound, itemRound, paint);
        canvas.drawCircle(itemGrid2X, itemGrid2Y, itemHeight / 2.0f + itemMargin, paint);
        canvas.drawRoundRect(itemBoundACAC, itemRound, itemRound, paint);
        break;
    }
    case 3: {
        // Active battery items
        paint.setStyle(Paint.Style.FILL);
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_active_battery));

        canvas.drawCircle(itemGrid1X, itemGrid1Y, itemHeight / 2.0f, paint);
        canvas.drawBitmap(iconG1, null, itemG1, paint);

        canvas.drawRoundRect(itemACDC, itemRound, itemRound, paint);
        canvas.drawBitmap(iconACDC, null, itemACDC, paint);

        canvas.drawRoundRect(itemBD, itemRound, itemRound, paint);
        canvas.drawBitmap(iconBDRight, null, itemBD, paint);

        canvas.drawRoundRect(itemDCAC, itemRound, itemRound, paint);
        canvas.drawBitmap(iconDCAC, null, itemDCAC, paint);

        // Active battery items bound
        paint.setStyle(Paint.Style.STROKE);
        paint.setStrokeWidth(5.0f);

        canvas.drawCircle(itemGrid1X, itemGrid1Y, itemHeight / 2.0f + itemMargin, paint);
        canvas.drawRoundRect(itemBoundACDC, itemRound, itemRound, paint);
        canvas.drawRoundRect(itemBoundBD, itemRound, itemRound, paint);
        canvas.drawRoundRect(itemBoundDCAC, itemRound, itemRound, paint);

        // Active bypass items
        paint.setStyle(Paint.Style.FILL);
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_inactive));

        canvas.drawCircle(itemGrid2X, itemGrid2Y, itemHeight / 2.0f, paint);
        canvas.drawBitmap(iconG2, null, itemG2, paint);

        canvas.drawRoundRect(itemACAC, itemRound, itemRound, paint);
        canvas.drawBitmap(iconACAC, null, itemACAC, paint);

        // Active bypass items bound
        paint.setColor(getContext().getResources().getColor(R.color.graphic_path_inactive));
        paint.setStyle(Paint.Style.STROKE);
        paint.setStrokeWidth(5.0f);

        canvas.drawCircle(itemGrid2X, itemGrid2Y, itemHeight / 2.0f + itemMargin, paint);
        canvas.drawRoundRect(itemBoundACAC, itemRound, itemRound, paint);
        break;
    }
    }
}

RectF MainWindow::getItemRectF(float x, float y, float w, float h) {
    return new RectF(x - (w / 2.0f), y - (h / 2.0f), x + (w / 2.0f), y + (h / 2.0f));
}

void MainWindow::drawBattery(float percent) {
    float batteryItemMargin = batteryHeight * 0.026f;
    RectF bnd = getItemRectF(batteryX, batteryY, batteryWidth, batteryHeight);

    paint.setStyle(Paint.Style.FILL);
    paint.setColor(getContext().getResources().getColor(R.color.theme_color_window_background));
    canvas.drawRoundRect(bnd, itemRound, itemRound, paint);

    paint.setStyle(Paint.Style.STROKE);
    paint.setColor(Color.RED);
    paint.setStrokeWidth(3);
    canvas.drawRoundRect(bnd, itemRound, itemRound, paint);
    float bi = bnd.width() / 3.0f;
    RectF biR = new RectF(bnd.left + bi, bnd.top - itemMargin * 2.0f, bnd.right - bi, bnd.top);
    canvas.drawRoundRect(biR, itemRound, itemRound, paint);

    float H = (batteryHeight / 6.0f) + batteryItemMargin;
    float X0 = bnd.left + batteryItemMargin,
            Y0 = bnd.bottom - H,
            X1 = bnd.right - batteryItemMargin,
            Y1 = bnd.bottom - batteryItemMargin;

    int value = 0;

    if (percent > 1.0f)
        percent = 1.0f;
    if (percent < 0.0f)
        percent = 0.0f;

    if (0.0f <= percent && percent < 0.2f)
        value = 1;
    else if (0.2f <= percent && percent < 0.4f)
        value = 2;
    else if (0.4f <= percent && percent < 0.6f)
        value = 3;
    else if (0.6f <= percent && percent < 0.8f)
        value = 4;
    else if (0.8f <= percent && percent <= 1.0f)
        value = 5;
    else
        value = 0;

    for (int i = 0; i < value; i++) {
        paint.setStyle(Paint.Style.FILL);
        paint.setColor(Color.GREEN);
        canvas.drawRoundRect(new RectF(X0, Y0, X1, Y1), 10, 10, paint);
        Y0 -= H;
        Y1 -= H;
    }

    paint.setColor(Color.RED);
    paint.setTextAlign(Paint.Align.CENTER);
    paint.setTextSize(85.0f);
    canvas.drawText(String.format("%% %s", String.valueOf((int) (percent * 100.0f))),
                    bnd.centerX(), bnd.top - itemMargin * 5.0f, paint);
}

int MainWindow::getRunMode() {
    return runMode;
}

void MainWindow::setRunningMode(int mode) {
    runMode = mode;
    // TODO: update uı
}

float MainWindow::getBatteryLevel() {
    return batteryLevel;
}

void MainWindow::setBatteryLevel(float mbatteryLevel) {
    batteryLevel = mbatteryLevel;
    // TODO: update uı
}

float MainWindow::getNetworkLoadLevel() {
    return networkLoadLevel;
}

void MainWindow::setNetworkLoadLevel(float mnetworkLoadLevel) {
    networkLoadLevel = mnetworkLoadLevel;
    // TODO: update uı
}

