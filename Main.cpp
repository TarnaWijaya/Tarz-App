#include <QApplication>
#include <QMainWindow>
#include <QListWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        QWidget *centralWidget = new QWidget;
        QVBoxLayout *mainLayout = new QVBoxLayout;

        // Search bar
        QLineEdit *searchBar = new QLineEdit;
        searchBar->setPlaceholderText("Search for apps...");
        mainLayout->addWidget(searchBar);

        // List of apps
        QListWidget *appList = new QListWidget;
        appList->addItem("App 1");
        appList->addItem("App 2");
        appList->addItem("App 3");
        mainLayout->addWidget(appList);

        // App details view (initially hidden)
        QStackedWidget *appDetails = new QStackedWidget;
        QLabel *appInfo = new QLabel("App Details Here");
        appDetails->addWidget(appInfo);
        mainLayout->addWidget(appDetails);

        // Back button
        QPushButton *backButton = new QPushButton("Back");
        backButton->setVisible(false);
        mainLayout->addWidget(backButton);

        connect(appList, &QListWidget::itemClicked, [=](QListWidgetItem *item) {
            appInfo->setText("Details for " + item->text());
            appList->setVisible(false);
            appDetails->setVisible(true);
            backButton->setVisible(true);
        });

        connect(backButton, &QPushButton::clicked, [=]() {
            appList->setVisible(true);
            appDetails->setVisible(false);
            backButton->setVisible(false);
        });

        centralWidget->setLayout(mainLayout);
        setCentralWidget(centralWidget);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}

#include "main.moc"