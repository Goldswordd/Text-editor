#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QMenuBar>
#include <QColorDialog>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

private slots:
    void onNewFile();
    void onOpenFile();
    void onSaveFile();
    void onAbout();
    void onChangeTextColor();  // Thêm slot để thay đổi màu chữ
    void onZoomIn();           // Thu phóng vào
    void onZoomOut();          // Thu phóng ra

private:
    QTextEdit *textEditor; // Central widget
    int zoomLevel;         // Biến lưu mức thu phóng hiện tại
};

#endif // MAINWINDOW_H
