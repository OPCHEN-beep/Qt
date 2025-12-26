#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_currentFileName("")  // 初始化当前文件名为空
{
    ui->setupUi(this);

    // 1. 设置主窗口属性
    this->setWindowTitle("我的记事本 - Qt菜单栏实战");
    this->resize(800, 600);  // 设置窗口大小

    // 2. 创建中央文本编辑控件
    m_textEdit = new QTextEdit(this);
    m_textEdit->setPlaceholderText("请在此输入文本内容...");
    m_textEdit->setFont(QFont("微软雅黑", 12));  // 设置默认字体
    this->setCentralWidget(m_textEdit);         // 设置为中央控件

    // 3. 创建菜单栏
    QMenuBar *menubar = this->menuBar();
    this->setMenuBar(menubar);

    // 4. 创建菜单
    QMenu *menuFile = new QMenu("文件(&F)", menubar);
    QMenu *menuEdit = new QMenu("编辑(&E)", menubar);
    QMenu *menuHelp = new QMenu("帮助(&H)", menubar);
    menubar->addMenu(menuFile);
    menubar->addMenu(menuEdit);
    menubar->addMenu(menuHelp);

    // 5. 创建文件菜单的菜单项
    QAction *actNew = new QAction(QIcon(":/icons/new.png"), "新建(&N)", menuFile);
    QAction *actOpen = new QAction(QIcon(":/icons/open.png"), "打开(&O)", menuFile);
    QAction *actSave = new QAction(QIcon(":/icons/save.png"), "保存(&S)", menuFile);
    QAction *actSaveAs = new QAction("另存为(&A)", menuFile);
    QAction *actExit = new QAction(QIcon(":/icons/exit.png"), "退出(&X)", menuFile);

    // 设置文件菜单项快捷键
    actNew->setShortcut(QKeySequence::New);
    actOpen->setShortcut(QKeySequence::Open);
    actSave->setShortcut(QKeySequence::Save);
    actSaveAs->setShortcut(QKeySequence::SaveAs);
    actExit->setShortcut(QKeySequence::Quit);

    // 设置文件菜单项提示信息
    actNew->setToolTip("新建空白文件（Ctrl+N）");
    actOpen->setToolTip("打开已存在的文件（Ctrl+O）");
    actSave->setToolTip("保存当前文件（Ctrl+S）");
    actSaveAs->setToolTip("将当前文件另存为（Ctrl+Shift+S）");
    actExit->setToolTip("退出记事本应用（Ctrl+Q）");

    // 添加文件菜单项和分割线
    menuFile->addAction(actNew);
    menuFile->addAction(actOpen);
    menuFile->addAction(actSave);
    menuFile->addAction(actSaveAs);
    menuFile->addSeparator();
    menuFile->addAction(actExit);

    // 6. 创建编辑菜单的菜单项
    QAction *actUndo = new QAction("撤销(&U)", menuEdit);
    QAction *actRedo = new QAction("重做(&R)", menuEdit);
    QAction *actCopy = new QAction("复制(&C)", menuEdit);
    QAction *actPaste = new QAction("粘贴(&V)", menuEdit);
    QAction *actFind = new QAction("查找(&F)", menuEdit);

    // 设置编辑菜单项快捷键
    actUndo->setShortcut(QKeySequence::Undo);
    actRedo->setShortcut(QKeySequence::Redo);
    actCopy->setShortcut(QKeySequence::Copy);
    actPaste->setShortcut(QKeySequence::Paste);
    actFind->setShortcut(QKeySequence::Find);

    // 设置编辑菜单项提示信息
    actUndo->setToolTip("撤销上一步操作（Ctrl+Z）");
    actRedo->setToolTip("重做上一步操作（Ctrl+Shift+Z）");
    actCopy->setToolTip("复制选中的文本（Ctrl+C）");
    actPaste->setToolTip("粘贴复制的文本（Ctrl+V）");
    actFind->setToolTip("查找文本内容（Ctrl+F）");

    // 添加编辑菜单项和分割线
    menuEdit->addAction(actUndo);
    menuEdit->addAction(actRedo);
    menuEdit->addSeparator();
    menuEdit->addAction(actCopy);
    menuEdit->addAction(actPaste);
    menuEdit->addSeparator();
    menuEdit->addAction(actFind);

    // 7. 创建帮助菜单的菜单项
    QAction *actAbout = new QAction("关于记事本(&A)", menuHelp);
    actAbout->setToolTip("查看记事本的版本信息和作者");
    menuHelp->addAction(actAbout);

    // 8. 关联所有菜单项的信号槽
    // 文件菜单
    connect(actNew, &QAction::triggered, this, &MainWindow::onActNewTriggered);
    connect(actOpen, &QAction::triggered, this, &MainWindow::onActOpenTriggered);
    connect(actSave, &QAction::triggered, this, &MainWindow::onActSaveTriggered);
    connect(actSaveAs, &QAction::triggered, this, &MainWindow::onActSaveAsTriggered);
    connect(actExit, &QAction::triggered, this, &MainWindow::onActExitTriggered);

    // 编辑菜单
    connect(actUndo, &QAction::triggered, this, &MainWindow::onActUndoTriggered);
    connect(actRedo, &QAction::triggered, this, &MainWindow::onActRedoTriggered);
    connect(actCopy, &QAction::triggered, this, &MainWindow::onActCopyTriggered);
    connect(actPaste, &QAction::triggered, this, &MainWindow::onActPasteTriggered);
    connect(actFind, &QAction::triggered, this, &MainWindow::onActFindTriggered);

    // 帮助菜单
    connect(actAbout, &QAction::triggered, this, &MainWindow::onActAboutTriggered);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 新建文件槽函数
void MainWindow::onActNewTriggered()
{
    // 询问用户是否保存当前文件（如果有内容）
    if (!m_textEdit->toPlainText().isEmpty()) {
        QMessageBox::StandardButton ret = QMessageBox::question(this, "提示", "当前文件内容未保存，是否保存？",
                                                                QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (ret == QMessageBox::Save) {
            onActSaveTriggered();  // 调用保存文件函数
        } else if (ret == QMessageBox::Cancel) {
            return;  // 取消新建操作
        }
        // 若选择Discard，则直接放弃保存，继续新建
    }

    // 清空文本编辑区域和当前文件名
    m_textEdit->clear();
    m_currentFileName = "";
    this->setWindowTitle("我的记事本 - Qt菜单栏实战");
}

// 打开文件槽函数
void MainWindow::onActOpenTriggered()
{
    // 弹出文件选择对话框，只允许选择文本文件
    QString fileName = QFileDialog::getOpenFileName(this, "打开文件", QDir::homePath(),
                                                  "文本文件 (*.txt);;所有文件 (*.*)");
    if (fileName.isEmpty()) {
        return;  // 用户取消选择
    }

    // 询问用户是否保存当前文件（如果有内容）
    if (!m_textEdit->toPlainText().isEmpty()) {
        QMessageBox::StandardButton ret = QMessageBox::question(this, "提示", "当前文件内容未保存，是否保存？",
                                                                QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (ret == QMessageBox::Save) {
            onActSaveTriggered();  // 调用保存文件函数
        } else if (ret == QMessageBox::Cancel) {
            return;  // 取消打开操作
        }
    }

    // 读取选中的文件内容
    std::ifstream file(fileName.toStdString().c_str());
    if (!file.is_open()) {
        QMessageBox::critical(this, "错误", "无法打开文件！");
        return;
    }

    // 读取文件内容到字符串
    std::string content;
    std::string line;
    while (std::getline(file, line)) {
        content += line + "\n";
    }
    file.close();

    // 将内容显示到文本编辑区域
    m_textEdit->setPlainText(QString::fromStdString(content));
    m_currentFileName = fileName;

    // 更新窗口标题，显示当前打开的文件名
    this->setWindowTitle(QString("我的记事本 - %1").arg(fileName));
}

// 保存文件槽函数
void MainWindow::onActSaveTriggered()
{
    // 如果当前文件未保存过（文件名为空），则调用另存为
    if (m_currentFileName.isEmpty()) {
        onActSaveAsTriggered();
        return;
    }

    // 写入文件
    std::ofstream file(m_currentFileName.toStdString().c_str());
    if (!file.is_open()) {
        QMessageBox::critical(this, "错误", "无法保存文件！");
        return;
    }

    // 将文本编辑区域的内容写入文件
    QString text = m_textEdit->toPlainText();
    file << text.toStdString();
    file.close();

    // 显示保存成功提示
    QMessageBox::information(this, "提示", "文件保存成功！");
}

// 另存为槽函数
void MainWindow::onActSaveAsTriggered()
{
    // 弹出保存文件对话框
    QString fileName = QFileDialog::getSaveFileName(this, "另存为", QDir::homePath(),
                                                  "文本文件 (*.txt);;所有文件 (*.*)");
    if (fileName.isEmpty()) {
        return;  // 用户取消保存
    }

    // 写入文件
    std::ofstream file(fileName.toStdString().c_str());
    if (!file.is_open()) {
        QMessageBox::critical(this, "错误", "无法保存文件！");
        return;
    }

    // 将文本编辑区域的内容写入文件
    QString text = m_textEdit->toPlainText();
    file << text.toStdString();
    file.close();

    // 更新当前文件名和窗口标题
    m_currentFileName = fileName;
    this->setWindowTitle(QString("我的记事本 - %1").arg(fileName));

    // 显示保存成功提示
    QMessageBox::information(this, "提示", "文件保存成功！");
}

// 退出程序槽函数
void MainWindow::onActExitTriggered()
{
    // 询问用户是否保存当前文件（如果有内容）
    if (!m_textEdit->toPlainText().isEmpty()) {
        QMessageBox::StandardButton ret = QMessageBox::question(this, "提示", "当前文件内容未保存，是否保存？",
                                                                QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (ret == QMessageBox::Save) {
            onActSaveTriggered();  // 调用保存文件函数
        } else if (ret == QMessageBox::Cancel) {
            return;  // 取消退出操作
        }
    }

    // 关闭主窗口（退出程序）
    this->close();
}

// 撤销槽函数
void MainWindow::onActUndoTriggered()
{
    m_textEdit->undo();
}

// 重做槽函数
void MainWindow::onActRedoTriggered()
{
    m_textEdit->redo();
}

// 复制槽函数
void MainWindow::onActCopyTriggered()
{
    m_textEdit->copy();
}

// 粘贴槽函数
void MainWindow::onActPasteTriggered()
{
    m_textEdit->paste();
}

// 查找槽函数（简易实现）
void MainWindow::onActFindTriggered()
{
    // 弹出输入对话框，让用户输入要查找的文本
    QString findText = QInputDialog::getText(this, "查找", "请输入要查找的文本：");
    if (findText.isEmpty()) {
        return;
    }

    // 在文本编辑区域中查找文本
    bool found = m_textEdit->find(findText, QTextDocument::FindCaseSensitively);
    if (!found) {
        QMessageBox::information(this, "提示", "未找到指定文本！");
    }
}

// 关于记事本槽函数
void MainWindow::onActAboutTriggered()
{
    // 弹出关于对话框
    QMessageBox::about(this, "关于我的记事本",
                      "<h2>我的记事本 v1.0</h2>"
                      "<p>基于Qt 5.14开发的简易记事本应用</p>"
                      "<p>核心功能：文件读写、文本编辑、查找</p>"
                      "<p>作者：Qt学习爱好者</p>"
                      "<p>版权所有 © 2024</p>");
}

