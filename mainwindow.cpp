#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mdiArea->setViewMode(QMdiArea::TabbedView);
    // Create model
    model = new QStringListModel(this);
    d =  new Dictionary();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showFileSubWindow(const QString &text, const QString &title){
    FileSubWindow *fileSubWindow = new FileSubWindow(ui->mdiArea, text);
    fileSubWindow->setAttribute(Qt::WA_DeleteOnClose);
    fileSubWindow->setWindowTitle(title);
    fileSubWindow->show();
}

void MainWindow::showErrorDialog(const QString &text) {
    QErrorMessage *errorDialog = new QErrorMessage(this);
    errorDialog->setAttribute(Qt::WA_DeleteOnClose);
    errorDialog->showMessage(text);
}

void MainWindow::showDictionary(const QString &text, const QString &title){
    QVector<QString> l = text.split('\n', QString::SkipEmptyParts).toVector();
    d = new Dictionary(l);
    model->setStringList(d->getDictionary());
    ui->listView->setModel(model);
}


    //-----------------------------SLOTS-----------------------------//
void MainWindow::actionNewDoc(){
     showFileSubWindow();
}

void MainWindow::actionOpen(){
    QString fileName = QFileDialog::getOpenFileName(this, "Open file", "/", "Text files (*.txt)");
    cout << "Selected file: " << fileName.toStdString() << endl;
    if (fileName.trimmed().length() != 0)
        showFileSubWindow(QString::fromStdString(Utils::readFile(fileName.toStdString())), fileName);
}

void MainWindow::actionOpenDictionary(){
    QString fileName = QFileDialog::getOpenFileName(this, "Open file", "/", "Text files (*.txt)");
    cout << "Selected file: " << fileName.toStdString() << endl;
    if (fileName.trimmed().length() != 0)
        showDictionary(QString::fromStdString(Utils::readFile(fileName.toStdString())), fileName);
}

void MainWindow::actionSave_as(){
    QString text = d->getTextForSave();
    QString path = QFileDialog::getSaveFileName(this, "Save as", "/", "All Files (*)");
    if (path.trimmed().size() == 0)
        return;
    QFileInfo fileInfo(path);
    if (!(fileInfo.exists() && fileInfo.isFile())) {
        QFile file(fileInfo.absoluteFilePath());
        if (file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
            QTextStream textStram(&file);
            textStram << text;
        }
    }
}

void MainWindow::on_addToDict_clicked()
{
    FileSubWindow *activeWindow = dynamic_cast<FileSubWindow*>(ui->mdiArea->activeSubWindow());
    if (activeWindow == nullptr) {
        showErrorDialog("No file selected");
        return;
    }
    QFileInfo fileInfo(activeWindow->windowTitle());
    QString text = activeWindow->getText();
    d->addWordsToDictionary(text);
    model->setStringList(d->getDictionary());
    ui->listView->setModel(model);
}

void MainWindow::on_sortByAlphabet_clicked()
{
    model->setStringList(d->getDictionary());
    ui->listView->setModel(model);
}

void MainWindow::on_sortByFreq_clicked()
{
    model->setStringList(d->getOrderedByFreqDict());
    ui->listView->setModel(model);
}
