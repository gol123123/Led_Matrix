#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QPushButton>
#include "port.h"

#define HI(x)             ((x)>>8)
#define LO(x)             ((x)& 0xFF)

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

signals:

    void savesettings(QString name, int baudrate, int DataBits, int Parity, int StopBits, int FlowControl);
    void writeData(QByteArray data);

private slots:
    void on_Btn_Serch_clicked();
    void checkCustomBaudRatePolicy(int idx);
    void Print(QString data);
    void Print_2(QString data);
    void on_cEnterText_returnPressed();
    void on_BtnSave_clicked();
    void set_calor();

    void on_LED_1_toggled(bool checked);
    void on_LED_2_toggled(bool checked);
    void on_LED_3_toggled(bool checked);
    void on_LED_4_toggled(bool checked);
    void on_LED_5_toggled(bool checked);
    void on_LED_6_toggled(bool checked);
    void on_LED_7_toggled(bool checked);
    void on_LED_8_toggled(bool checked);
    void on_LED_9_toggled(bool checked);
    void on_LED_10_toggled(bool checked);
    void on_LED_11_toggled(bool checked);
    void on_LED_12_toggled(bool checked);
    void on_LED_13_toggled(bool checked);
    void on_LED_14_toggled(bool checked);
    void on_LED_15_toggled(bool checked);
    void on_LED_16_toggled(bool checked);
    void on_LED_17_toggled(bool checked);
    void on_LED_18_toggled(bool checked);
    void on_LED_19_toggled(bool checked);
    void on_LED_20_toggled(bool checked);
    void on_LED_21_toggled(bool checked);
    void on_LED_22_toggled(bool checked);
    void on_LED_23_toggled(bool checked);
    void on_LED_24_toggled(bool checked);
    void on_LED_25_toggled(bool checked);
    void on_LED_26_toggled(bool checked);
    void on_LED_27_toggled(bool checked);
    void on_LED_28_toggled(bool checked);
    void on_LED_29_toggled(bool checked);
    void on_LED_30_toggled(bool checked);
    void on_LED_31_toggled(bool checked);
    void on_LED_32_toggled(bool checked);
    void on_LED_33_toggled(bool checked);
    void on_LED_34_toggled(bool checked);
    void on_LED_35_toggled(bool checked);
    void on_LED_36_toggled(bool checked);
    void on_LED_37_toggled(bool checked);
    void on_LED_38_toggled(bool checked);
    void on_LED_39_toggled(bool checked);
    void on_LED_40_toggled(bool checked);
    void on_LED_41_toggled(bool checked);
    void on_LED_42_toggled(bool checked);
    void on_LED_43_toggled(bool checked);
    void on_LED_44_toggled(bool checked);
    void on_LED_45_toggled(bool checked);
    void on_LED_46_toggled(bool checked);
    void on_LED_47_toggled(bool checked);
    void on_LED_48_toggled(bool checked);
    void on_LED_49_toggled(bool checked);
    void on_LED_50_toggled(bool checked);
    void on_LED_51_toggled(bool checked);
    void on_LED_52_toggled(bool checked);
    void on_LED_53_toggled(bool checked);
    void on_LED_54_toggled(bool checked);
    void on_LED_55_toggled(bool checked);
    void on_LED_56_toggled(bool checked);
    void on_LED_57_toggled(bool checked);
    void on_LED_58_toggled(bool checked);
    void on_LED_59_toggled(bool checked);
    void on_LED_60_toggled(bool checked);
    void on_LED_61_toggled(bool checked);
    void on_LED_62_toggled(bool checked);
    void on_LED_63_toggled(bool checked);
    void on_LED_64_toggled(bool checked);
    void on_LED_65_toggled(bool checked);
    void on_LED_66_toggled(bool checked);
    void on_LED_67_toggled(bool checked);
    void on_LED_68_toggled(bool checked);
    void on_LED_69_toggled(bool checked);
    void on_LED_70_toggled(bool checked);
    void on_LED_71_toggled(bool checked);
    void on_LED_72_toggled(bool checked);
    void on_LED_73_toggled(bool checked);
    void on_LED_74_toggled(bool checked);
    void on_LED_75_toggled(bool checked);
    void on_LED_76_toggled(bool checked);
    void on_LED_77_toggled(bool checked);
    void on_LED_78_toggled(bool checked);
    void on_LED_79_toggled(bool checked);
    void on_LED_80_toggled(bool checked);
    void on_LED_81_toggled(bool checked);
    void on_LED_82_toggled(bool checked);
    void on_LED_83_toggled(bool checked);
    void on_LED_84_toggled(bool checked);
    void on_LED_85_toggled(bool checked);
    void on_LED_86_toggled(bool checked);
    void on_LED_87_toggled(bool checked);
    void on_LED_88_toggled(bool checked);
    void on_LED_89_toggled(bool checked);
    void on_LED_90_toggled(bool checked);
    void on_LED_91_toggled(bool checked);
    void on_LED_92_toggled(bool checked);
    void on_LED_93_toggled(bool checked);
    void on_LED_94_toggled(bool checked);
    void on_LED_95_toggled(bool checked);
    void on_LED_96_toggled(bool checked);
    void on_LED_97_toggled(bool checked);
    void on_LED_98_toggled(bool checked);
    void on_LED_99_toggled(bool checked);
    void on_LED_100_toggled(bool checked);
    void on_LED_101_toggled(bool checked);
    void on_LED_102_toggled(bool checked);
    void on_LED_103_toggled(bool checked);
    void on_LED_104_toggled(bool checked);
    void on_LED_105_toggled(bool checked);
    void on_LED_106_toggled(bool checked);
    void on_LED_107_toggled(bool checked);
    void on_LED_108_toggled(bool checked);
    void on_LED_109_toggled(bool checked);
    void on_LED_110_toggled(bool checked);
    void on_LED_111_toggled(bool checked);
    void on_LED_112_toggled(bool checked);
    void on_LED_113_toggled(bool checked);
    void on_LED_114_toggled(bool checked);
    void on_LED_115_toggled(bool checked);
    void on_LED_116_toggled(bool checked);
    void on_LED_117_toggled(bool checked);
    void on_LED_118_toggled(bool checked);
    void on_LED_119_toggled(bool checked);
    void on_LED_120_toggled(bool checked);
    void on_LED_121_toggled(bool checked);
    void on_LED_122_toggled(bool checked);
    void on_LED_123_toggled(bool checked);
    void on_LED_124_toggled(bool checked);
    void on_LED_125_toggled(bool checked);
    void on_LED_126_toggled(bool checked);
    void on_LED_127_toggled(bool checked);
    void on_LED_128_toggled(bool checked);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    uint8_t DataLed[8][2];

};

#endif // MAINWINDOW_H
