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
    void onChangeTextColor();  
    void onZoomIn();           
    void onZoomOut();          

private:
    QTextEdit *textEditor; 
    int zoomLevel;         
};

#endif // MAINWINDOW_H
