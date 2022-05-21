#include <QApplication>
#include "tvRemote.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    TVRemote window(nullptr);
    Ui::MainWindow tv_remote;
    tv_remote.setupUi(&window);
    window.label = tv_remote.label;
    window.progressBar = tv_remote.progressBar;
    window.resize(240, 680);
    window.show();
    return QApplication::exec();
}
