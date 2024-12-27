#include "MainWindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QColorDialog>

MainWindow::MainWindow() {
    
    // Central Widget: QTextEdit
    textEditor = new QTextEdit(this);
    setCentralWidget(textEditor);
    zoomLevel = 0;  // Zoom level 
    // Make transparent windows
    setAttribute(Qt::WA_TranslucentBackground);
    // Central Widget: QTextEdit
    textEditor = new QTextEdit(this);
    setCentralWidget(textEditor);

    // Setup semi transparent background with blur  
    textEditor->setStyleSheet("background: rgba(20, 20, 20, 0.4); color: cyan; font-size: 16px;");
    // Menu Bar
    QMenuBar *menuBar = this->menuBar();

    QMenu *fileMenu = menuBar->addMenu("&File");
    QMenu *editMenu = menuBar->addMenu("&Edit");
    QMenu *helpMenu = menuBar->addMenu("&Help");

    // File menu actions
    QAction *newAction = fileMenu->addAction("&New");
    QAction *openAction = fileMenu->addAction("&Open");
    QAction *saveAction = fileMenu->addAction("&Save");
    fileMenu->addSeparator();
    QAction *exitAction = fileMenu->addAction("&Exit");

    // Edit menu actions
    QAction *colorAction = editMenu->addAction("&Change Text Color");
    QAction *zoomInAction = editMenu->addAction("Zoom &In");
    QAction *zoomOutAction = editMenu->addAction("Zoom &Out");

    // Help menu action
    QAction *aboutAction = helpMenu->addAction("&About");

    // Tool Bar
    QToolBar *toolBar = addToolBar("Main Toolbar");
    toolBar->addAction(newAction);
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);
    toolBar->addAction(colorAction);
    toolBar->addAction(zoomInAction);
    toolBar->addAction(zoomOutAction);

    // Status Bar
    QStatusBar *statusBar = this->statusBar();
    statusBar->showMessage("Ready");

    // Connect actions to slots
    connect(newAction, &QAction::triggered, this, &MainWindow::onNewFile);
    connect(openAction, &QAction::triggered, this, &MainWindow::onOpenFile);
    connect(saveAction, &QAction::triggered, this, &MainWindow::onSaveFile);
    connect(exitAction, &QAction::triggered, this, &QWidget::close);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::onAbout);
    connect(colorAction, &QAction::triggered, this, &MainWindow::onChangeTextColor);
    connect(zoomInAction, &QAction::triggered, this, &MainWindow::onZoomIn);
    connect(zoomOutAction, &QAction::triggered, this, &MainWindow::onZoomOut);
}

void MainWindow::onNewFile() {
    textEditor->clear();
    statusBar()->showMessage("New file created", 2000);
}

void MainWindow::onOpenFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly | QFile::Text)) {
            QTextStream in(&file);
            textEditor->setText(in.readAll());
            file.close();
            statusBar()->showMessage("File opened", 2000);
        }
    }
}

void MainWindow::onSaveFile() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::WriteOnly | QFile::Text)) {
            QTextStream out(&file);
            out << textEditor->toPlainText();
            file.close();
            statusBar()->showMessage("File saved", 2000);
        }
    }
}

void MainWindow::onAbout() {
    QMessageBox::about(this, "About", "Bam vao day lam gi.");
}

void MainWindow::onChangeTextColor() {
    QColor color = QColorDialog::getColor(Qt::black, this, "Choose Text Color");
    if (color.isValid()) {
        QTextCharFormat format;
        format.setForeground(color);
        QTextCursor cursor = textEditor->textCursor();
        cursor.mergeCharFormat(format);
        textEditor->mergeCurrentCharFormat(format);
        statusBar()->showMessage("Text color changed", 2000);
    }
}

void MainWindow::onZoomIn() {
    QFont font = textEditor->font();
    int currentSize = font.pointSize();
    font.setPointSize(currentSize + 2);  // Tăng kích thước font
    textEditor->setFont(font);
    zoomLevel++;
    statusBar()->showMessage("Zoom In", 2000);
}

void MainWindow::onZoomOut() {
    QFont font = textEditor->font();
    int currentSize = font.pointSize();
    font.setPointSize(currentSize - 2);  // Giảm kích thước font
    textEditor->setFont(font);
    zoomLevel--;
    statusBar()->showMessage("Zoom Out", 2000);
}
