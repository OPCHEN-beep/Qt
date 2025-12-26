#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QTextEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QKeySequence>
#include <fstream>
#include <string>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 文件菜单槽函数
    void onActNewTriggered();      // 新建文件
    void onActOpenTriggered();     // 打开文件
    void onActSaveTriggered();     // 保存文件
    void onActSaveAsTriggered();   // 另存为
    void onActExitTriggered();     // 退出程序

    // 编辑菜单槽函数
    void onActCopyTriggered();     // 复制
    void onActPasteTriggered();    // 粘贴
    void onActUndoTriggered();     // 撤销
    void onActRedoTriggered();     // 重做
    void onActFindTriggered();     // 查找

    // 帮助菜单槽函数
    void onActAboutTriggered();    // 关于记事本

private:
    Ui::MainWindow *ui;
    QTextEdit *m_textEdit;         // 文本编辑区域
    QString m_currentFileName;     // 当前打开的文件名（含路径）
};

#endif // MAINWINDOW_H

